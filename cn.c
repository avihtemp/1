Implement the data link layer framing methods such as character, character-stuffing and bit stuffing.   

/*
Bit stuffing
*/
#include <stdio.h>
#include <string.h>
void bitStuffing(char input[], char output[]) {
    int i = 0, j = 0, count = 0;
    // Add starting flag
    strcpy(output, "01111110");
    j = 8;
    while (input[i] != '\0') {
        if (input[i] == '1') {
            count++;
            output[j++] = input[i];
        } else {
            output[j++] = input[i];
            count = 0;
        }
        if (count == 5) {
            output[j++] = '0'; // Stuff 0
            count = 0;
        }
        i++;
    }
    // Add ending flag
    strcat(output, "01111110");
}
int main() {
    char input[100], output[200];
    printf("Enter binary data stream: ");
    scanf("%s", input);
    bitStuffing(input, output);
    printf("Stuffed Frame: %s\n", output);
    return 0;
}
Output:-

/*
Character stuffing
*/
#include <stdio.h>
#include <string.h>
void charStuffing(char data[], char flag, char esc, char result[]) {
    int i = 0, j = 0;
    result[j++] = flag; // Start flag
    while (data[i] != '\0') {
        if (data[i] == flag || data[i] == esc) {
            result[j++] = esc; // Stuff escape char
        }
        result[j++] = data[i];
        i++;
    }
    result[j++] = flag; // End flag
    result[j] = '\0';
}
int main() {
    char data[100], result[200];
    char flag = 'F';
    char esc = 'E';
    printf("Enter data string: ");
    scanf("%s", data);
    charStuffing(data, flag, esc, result);
    printf("Stuffed Frame: %s\n", result);
    return 0;
}
Output:-


Write a program to compute CRC code for the polynomials CRC-12, CRC-16 and CRC CCIP   

#include <stdio.h>
#include <string.h>
// Function to perform Modulo-2 division to find the CRC remainder
void compute_crc(const char *data, const char *generator, char *checksum) {
    int data_len = strlen(data);
    int gen_len = strlen(generator);
    char temp[200];
    // Copy original data into temporary workspace
    strcpy(temp, data);
    // Append (gen_len - 1) zeros to the data as padding
    for (int i = 0; i < gen_len - 1; i++) {
        temp[data_len + i] = '0';
    }
    temp[data_len + gen_len - 1] = '\0';
    int total_len = strlen(temp);
    // Perform Binary Modulo-2 Division (XOR operation)
    for (int i = 0; i <= total_len - gen_len; i++) {
        // If the current bit is 1, perform XOR with the generator polynomial
        if (temp[i] == '1') {
            for (int j = 0; j < gen_len; j++) {
                temp[i + j] = (temp[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }
    // The remaining bits at the end of the temporary array form the checksum
    strncpy(checksum, &temp[total_len - (gen_len - 1)], gen_len - 1);
    checksum[gen_len - 1] = '\0';
}
int main() {
    char data[100];
    char checksum[32];
    int choice;
    // Define standard generator polynomials as binary strings
    const char *crc12 = "1100000001111";       // x^12 + x^11 + x^3 + x^2 + x + 1
    const char *crc16 = "11000000000000101";   // x^16 + x^15 + x^2 + 1
    const char *ccitt = "11000100000010001";   // x^16 + x^12 + x^5 + 1
    printf("--- CRC Code Computation ---\n");
    printf("Enter data bits (binary format, e.g., 1101011): ");
    scanf("%s", data);
    // Input validation for binary format
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] != '0' && data[i] != '1') {
            printf("Error: Invalid binary sequence string.\n");
            return 1;
        }
    }
    printf("\nSelect the Polynomial protocol:\n");
    printf("1. CRC-12\n");
    printf("2. CRC-16\n");
    printf("3. CRC-CCITT (CCIP)\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            compute_crc(data, crc12, checksum);
            printf("\nUsing CRC-12 Polynomial: %s\n", crc12);
            break;
        case 2:
            compute_crc(data, crc16, checksum);
            printf("\nUsing CRC-16 Polynomial: %s\n", crc16);
            break;
        case 3:
            compute_crc(data, ccitt, checksum);
            printf("\nUsing CRC-CCITT Polynomial: %s\n", ccitt);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    // Output final results
    printf("Generated Checksum (CRC Code): %s\n", checksum);
    printf("Final Codeword to Transmit  : %s%s\n", data, checksum);

    return 0;
}
OUTPUT:-

Develop a simple data link layer that performs the flow control using the sliding window protocol, and loss recovery using the Go-Back-N mechanism.  

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    int window_size, total_frames;
    
    printf("Enter window size: ");
    if (scanf("%d", &window_size) != 1) return 1;
    
    printf("Enter total number of frames to transmit: ");
    if (scanf("%d", &total_frames) != 1) return 1;

    srand(time(NULL));
    int current_frame = 0;

    while (current_frame < total_frames) {
        // Send a batch of frames up to the window size
        int send_up_to = current_frame + window_size;
        if (send_up_to > total_frames) {
            send_up_to = total_frames;
        }

        printf("\n--- Sending Window --- \n");
        for (int i = current_frame; i < send_up_to; i++) {
            printf("Sending Frame %d\n", i);
        }

        // Simulate acknowledgment and loss detection
        bool loss_detected = false;
        int failed_frame = -1;

        for (int i = current_frame; i < send_up_to; i++) {
            // Randomly simulate frame loss (1 in 4 chance of loss)
            int ack_received = rand() % 4; 
            if (ack_received == 0) {
                printf("Acknowledgment lost for Frame %d! Retransmitting from this frame.\n", i);
                loss_detected = true;
                failed_frame = i;
                break;
            } else {
                printf("Acknowledgment received for Frame %d\n", i);
            }
        }

        if (loss_detected) {
            // Go-Back-N: Resets the base pointer to the first unacknowledged frame
            current_frame = failed_frame;
            printf("Go-Back-N triggered. Resending from Frame %d\n", current_frame);
        } else {
            // Slide window forward completely for this batch
            current_frame = send_up_to;
            printf("Window slid forward successfully.\n");
        }
    }

    printf("\nAll frames transmitted successfully!\n");
    return 0;
}OUTPUT:-



Implement Dijsktra’s algorithm to compute the shortest path through a  network   

#include <stdio.h>
#include <stdbool.h>

#define MAX 10
#define INF 9999

// Function to implement Dijkstra's algorithm for a graph represented using adjacency matrix
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    bool visited[MAX];
    
    // Initialize distances as infinity and visited status as false
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    
    // Distance from source to itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;
        
        // Pick the minimum distance vertex from the set of vertices not yet processed
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }
        
        // If no valid vertex is found, break
        if (u == -1) break;
        
        // Mark the picked vertex as processed
        visited[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Print the constructed distance array
    printf("\nVertex\t\tDistance from Source (%d)\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int n, src;
    int graph[MAX][MAX];
    
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix (use 0 for no connection):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    
    dijkstra(graph, n, src);
    
    return 0;
}
OUTPUT:-

Take an example subnet of hosts and obtain a broadcast tree for the subnet.  

 #include <stdio.h>
#include <stdlib.h>

#define MAX_HOSTS 20

int adjMatrix[MAX_HOSTS][MAX_HOSTS];
int visited[MAX_HOSTS];
int numHosts;

// Function to generate and print the broadcast tree using BFS
void generateBroadcastTree(int sourceHost) {
    int queue[MAX_HOSTS];
    int front = 0, rear = 0;

    // Initialize all hosts as unvisited
    for (int i = 0; i < numHosts; i++) {
        visited[i] = 0;
    }

    // Mark the source host as visited and enqueue it
    visited[sourceHost] = 1;
    queue[rear++] = sourceHost;

    printf("\n--- Broadcast Tree Edges (Transmission Paths) ---\n");
    
    int edgeCount = 0;
    while (front < rear) {
        int current = queue[front++];

        // Check all adjacent hosts
        for (int neighbor = 0; neighbor < numHosts; neighbor++) {
            // If there is a connection and the neighbor hasn't been visited yet
            if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                printf("Host %d  ===>  Host %d\n", current, neighbor);
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
                edgeCount++;
            }
        }
    }

    if (edgeCount < numHosts - 1) {
        printf("\nWarning: The subnet graph is disconnected. Some hosts cannot be reached.\n");
    }
}

int main() {
    int sourceHost;

    printf("Enter the number of hosts in the subnet (Max %d): ", MAX_HOSTS);
    if (scanf("%d", &numHosts) != 1 || numHosts <= 0 || numHosts > MAX_HOSTS) {
        printf("Invalid number of hosts.\n");
        return 1;
    }

    printf("\nEnter the adjacency matrix for the subnet (0 for no connection, 1 for connection):\n");
    for (int i = 0; i < numHosts; i++) {
        for (int j = 0; j < numHosts; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("\nEnter the source host index to originate the broadcast (0 to %d): ", numHosts - 1);
    if (scanf("%d", &sourceHost) != 1 || sourceHost < 0 || sourceHost >= numHosts) {
        printf("Invalid source host.\n");
        return 1;
    }

    generateBroadcastTree(sourceHost);

    return 0;
}
OUTPUT:-


Implement distance vector routing algorithm for obtaining routing tables at each node.   

#include <stdio.h>
// Structure to represent the routing table entry for each router node
struct Node {
    unsigned dist[20];    // Distance vector array to store costs to destinations
    unsigned nextHop[20]; // Array to store the next hop node for each destination
} routingTable[20];

int main() {
    int costMatrix[20][20];
    int numNodes;
    int i, j, k;
    int updateCount;

    // 1. Input the total number of network nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // 2. Input the cost matrix (use a large value like 999 for infinity/no direct link)
    printf("\nEnter the cost matrix (Use 999 for infinity):\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            scanf("%d", &costMatrix[i][j]);
            
            // Distance from a node to itself is always 0
            if (i == j) {
                costMatrix[i][j] = 0;
            }
            
            // Initialize the routing table with default configurations
            routingTable[i].dist[j] = costMatrix[i][j];
            routingTable[i].nextHop[j] = j;
        }
    }

    // 3. Iterative calculation loop using Bellman-Ford algorithm
    // Loop runs until no more updates occur (convergence)
    do {
        updateCount = 0;
        for (i = 0; i < numNodes; i++) {           // i: source node
            for (j = 0; j < numNodes; j++) {       // j: destination node
                for (k = 0; k < numNodes; k++) {   // k: intermediate neighbor node
                    
                    // Check if a shorter path exists via neighbor k
                    if (routingTable[i].dist[j] > costMatrix[i][k] + routingTable[k].dist[j]) {
                        routingTable[i].dist[j] = costMatrix[i][k] + routingTable[k].dist[j];
                        routingTable[i].nextHop[j] = k;
                        updateCount++; // Track that an update happened
                    }
                }
            }
        }
    } while (updateCount != 0);

    // 4. Output the final converged routing tables for all nodes
    for (i = 0; i < numNodes; i++) {
        printf("\n-----------------------------------------");
        printf("\n Routing Table for Node %d", i + 1);
        printf("\n-----------------------------------------");
        printf("\n Destination\t Distance\t Next Hop");
        printf("\n-----------------------------------------");
        for (j = 0; j < numNodes; j++) {
            printf("\n   Node %d \t    %d   \t   Node %d", j + 1, routingTable[i].dist[j], routingTable[i].nextHop[j] + 1);
        }
        printf("\n-----------------------------------------\n");
    }

    return 0;
}
OUTPUT:-

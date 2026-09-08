#include <stdio.h>
#include <conio.h>

#define INF 999

void main()
{
    int n, i, j, k;
    int cost[10][10];
    int dist[10][10];
    int next[10][10];

    clrscr();

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;

            dist[i][j] = cost[i][j];

            if(i != j && cost[i][j] != INF)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    /* Distance Vector Algorithm */
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    /* Print routing tables */
    for(i = 0; i < n; i++)
    {
        printf("\n\nRouting Table for Node %d", i + 1);
        printf("\nDestination\tCost\tNext Hop");

        for(j = 0; j < n; j++)
        {
            printf("\n%d\t\t%d\t", j + 1, dist[i][j]);

            if(i == j)
                printf("-");
            else
                printf("%d", next[i][j] + 1);
        }
    }

    getch();
}

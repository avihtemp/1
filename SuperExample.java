// Parent class
class XYZ {
    int value = 5555;
}

// Child class
class ABC extends XYZ {
    int value = 9999;

    public void display() {
        System.out.println("Child value = " + value);
        System.out.println("Parent value = " + super.value);
    }
}

// Main class
public class SuperExample {
    public static void main(String[] args) {
        ABC obj = new ABC();
        obj.display();
    }
}

 
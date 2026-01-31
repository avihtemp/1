public class ThisExample {
    int x = 10;

    // Constructor with parameter
    public ThisExample(int x) {
        this.x = x;   // 'this' refers to the current object
    }

    public static void main(String[] args) {
        ThisExample obj = new ThisExample(55); // pass a value
        System.out.println("Value of x = " + obj.x);
    }
}

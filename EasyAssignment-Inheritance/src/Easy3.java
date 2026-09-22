class Rectangle {

    protected float length;
    protected float breadth;

    // Parameterized constructor
    Rectangle(float length, float breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Method to print area
    void printArea() {
        System.out.println("Area of Rectangle: " + (length * breadth));
    }

    // Method to print perimeter
    void printPerimeter() {
        System.out.println("Perimeter of Rectangle: " + (2 * (length + breadth)));
    }
}


class Square extends Rectangle {

    // Constructor
    Square(float side) {
        super(side, side);
    }
}


public class Easy3 {

    public static void main(String[] args) {

        // Input for Rectangle
        System.out.print("Enter length of Rectangle: ");
        float length = ConsoleInput.getFloat();

        System.out.print("Enter breadth of Rectangle: ");
        float breadth = ConsoleInput.getFloat();

        // Create Rectangle object
        Rectangle rectangle = new Rectangle(length, breadth);

        System.out.println("\n--- Rectangle ---");
        rectangle.printArea();
        rectangle.printPerimeter();


        // Input for Square
        System.out.print("\nEnter side of Square: ");
        float side = ConsoleInput.getFloat();

        // Create Square object
        Square square = new Square(side);

        System.out.println("\n--- Square ---");
        square.printArea();
        square.printPerimeter();
    }
}
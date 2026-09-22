//package question4;

class Shape {

    void printShape() {
        System.out.println("This is shape");
    }
}

class Rectangle4 extends Shape {

    void printRectangle() {
        System.out.println("This is rectangular shape");
    }
}

class Circle extends Shape {

    void printCircle() {
        System.out.println("This is circular shape");
    }
}

class Square4 extends Rectangle4 {

    void printSquare() {
        System.out.println("Square is a rectangle");
    }
}

public class Easy4 {

    public static void main(String[] args) {

        Square4 square = new Square4();

        square.printShape();
        square.printRectangle();
    }
}
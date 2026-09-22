
class Parent {
    void parentMethod() {
        System.out.println("This is parent class");
    }
}

class Child extends Parent {
    void childMethod() {
        System.out.println("This is child class");
    }
}

public class Easy1 {
    public static void main(String[] args) {

        // Object of Parent class
        Parent p = new Parent();

        // Object of Child class
        Child c = new Child();

        // 1. Method of parent class by object of parent class
        p.parentMethod();

        // 2. Method of child class by object of child class
        c.childMethod();

        // 3. Method of parent class by object of child class
        c.parentMethod();
    }
}
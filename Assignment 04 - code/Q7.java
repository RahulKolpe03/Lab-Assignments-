import java.util.Scanner;

class Q7 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[5];
        int sum = 0;

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            numbers[i] = sc.nextInt();
        }

        for (int number : numbers) {
            sum = sum + number;
        }

        System.out.println("The sum of all numbers is: " + sum);
    }
}
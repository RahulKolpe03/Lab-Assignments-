import java.util.Scanner;

class MultiplicationTable
{
    static void printMultiplicationTable(int number)
    {
        for(int i = 1; i <= 10; i++)
        {
            System.out.println(number + " x " + i + " = " + (number * i));
        }
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = sc.nextInt();

        printMultiplicationTable(number);
    }
}
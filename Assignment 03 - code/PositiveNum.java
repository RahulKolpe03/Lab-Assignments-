import java.util.Scanner;

class PositiveNum
{
    static int askForPositiveNumber()
    {
        Scanner sc = new Scanner(System.in);

        int number;

        do
        {
            System.out.print("Enter a number: ");
            number = sc.nextInt();
        }
        while(number <= 0);

        return number;
    }

    public static void main(String args[])
    {
        int result = askForPositiveNumber();

        System.out.println("You entered a positive number: " + result);
    }
}
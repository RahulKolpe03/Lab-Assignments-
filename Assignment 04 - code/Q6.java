import java.util.Scanner;

class Q6{
public static void main(String args []){
Scanner sc = new Scanner(System.in);
int numbers [] = new int[5];
System.out.println("Enter number");

for (int i = 0; i < 5; i++) {
            numbers[i] = sc.nextInt();
        }

for (int number : numbers) {
            System.out.println(number);
        }

}

}
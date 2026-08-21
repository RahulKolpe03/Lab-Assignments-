import java.util.Scanner;

class sumOftwoNum {

static  int sumOftwoNum(int a, int b){
int sum = a + b;
return sum ;
}
public static void main (String args[]){
Scanner sc = new Scanner(System.in);

System.out.println("Enter First number");
int num1 = sc. nextInt();

System.out.println("Enter Second Number");
int num2 = sc.nextInt();

int result =  sumOftwoNum(num1 , num2 );

System.out.println("The Sum Of " + num1 + "And " + num2 + " is " + result );

}
}
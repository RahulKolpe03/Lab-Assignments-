import  java.util.Scanner;

class AgeCategory{
static  void checkAgeCategory(int age){
if ( age <18 ){
System.out.println("You are minor");
}else if ( age < 60){
System.out.println("you are and adult ");
}else {
System.out.println(" you are sr. citizen");
}
}
public static void main(String args[]){
Scanner sc = new Scanner ( System.in);
System.out.println("Enter Your age ");
int age = sc.nextInt();

checkAgeCategory(age);


}
}
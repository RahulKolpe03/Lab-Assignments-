
public class Student {
	String name;
	int roll_no;
	String phone_no;
	String address;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s =  new Student();
		s.roll_no = 2;
		s.name = "John";
		
		System.out.println("Roll no :"  + s.roll_no);
		System.out.println("Name of Student : " + s.name);
		
	
		Student s1 = new Student();
		Student s2 = new Student();
		
		s1.name = "Sam";
		s1.roll_no = 1;
		s1.phone_no = "9829394555";
		s1.address = "Pune";
		System.out.println("Name of Student : " + s1.name);
		System.out.println("Roll Number : " + s1.roll_no);
		System.out.println("Phone number : " + s1.phone_no);
		System.out.println("Address : " + s1.address);
		
		s2.name = "Jhon";
		s2.roll_no = 2;
		s2.phone_no = "2939455590";
		s2.address = "Mumbai";
		System.out.println("Name of Student : " + s2.name);
		System.out.println("Roll Number : " + s2.roll_no);
		System.out.println("Phone number : " + s2.phone_no);
		System.out.println("Address : " + s2.address);
		

	}

}

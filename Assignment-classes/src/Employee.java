
public class Employee {
	String name ;
	int yearOfJoining;
	double salary;
	String address;
	
	Employee(String  name, int yearOfJoining, double salary,String address ){
		this.name= name;
		this.yearOfJoining= yearOfJoining;
		this.salary = salary;
		this.address= address;
	}
	
	void display() {
		System.out.println(name + "\t\t" +  yearOfJoining  +"\t\t"  + salary +"\t\t" + address);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Employee e1 = new Employee("Robert" , 1994, 50000, "64C - WallStreet");
		Employee e2 = new Employee("Sam" , 2000, 60000, "68C -WallStreet ");
		Employee e3 = new Employee("John" , 1999 , 55000, "26B - WallStreet");
		
		e1.display();
		e2.display();
		e3.display();
		
		

	}

}

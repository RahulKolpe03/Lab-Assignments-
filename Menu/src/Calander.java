
public class Calander {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Date objDate = new Date();
		
		System.out.println("Enter Day: ");
		int day = ConsoleInput.getInt();
		
		System.out.println("Enter Month: ");
		int month = ConsoleInput.getInt();

		System.out.println("Enter Year: ");
		int year = ConsoleInput.getInt();
		
		objDate.setDate(day, month, year);
		
		System.out.println(objDate.getDay() + "/" + objDate.getMonth() + "/" + objDate.getYear());
		
		
		
		System.out.println("\nHow Many Days to Add: ");
		int totalDays = ConsoleInput.getInt();
		
		objDate.setDays(totalDays);
		
		System.out.println(objDate.getDay() + "/" + objDate.getMonth() + "/" + objDate.getYear());
		
		
		
		System.out.println("\nHow Many Months to Add: ");
		int totalMonths = ConsoleInput.getInt();

		objDate.setMonth(totalMonths);
		System.out.println(objDate.getDay() + "/" + objDate.getMonth() + "/" + objDate.getYear());
		
		
		
		System.out.println("\nHow Many Years to Add: ");
		int addyear = ConsoleInput.getInt();
		
		objDate.setYear(addyear);
		System.out.println(objDate.getDay() + "/" + objDate.getMonth() + "/" + objDate.getYear());

	


	}

}

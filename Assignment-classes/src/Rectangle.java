
public class Rectangle {
	
	int length ;
	int breadth;
	
	//consrructor
	Rectangle(int l , int b){
		length = l;
		breadth = b;
	}
	
	//  method for Area 
	int area() {
		return length* breadth;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Rectangle r1 = new Rectangle(4,5);
		System.out.println("Area of rectangle 1 :" + r1.area());
		
		Rectangle r2 = new Rectangle(5,8);
		System.out.println("Area of rectanlge 2 :" + r2.area());

	}

}

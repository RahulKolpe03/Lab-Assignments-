
public class Triangle {
	
	int side1;
	int side2;
	int side3;
	
	//constructor
	Triangle(int s1, int s2, int s3)
	{
		side1 =s1;
		side2 = s2;
		side3 = s3;
	}
	
	//perimeter of the triangle
	
	int getPerimeter() {
		return side1 + side2 + side3; 
	}
	
	//Area using heron's formula
	
	double getArea() {
		
		double s = (side1 + side2 + side3)/2.0;
		double area = Math.sqrt(
				s* (s-side1)*
				(s-  side2) *
				(s- side3));
		
		return area;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Triangle t = new Triangle(3,4,5);
		
		System.out.println("Perimeter : " + t.getPerimeter());
		System.out.println("Area :" + t.getArea());
		

	}

}

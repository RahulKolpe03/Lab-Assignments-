
public class Complex {
	
	int real ;
	int imaginary;
	
	//constructor
	Complex(int r, int i ){
		real = r;
		imaginary = i;
	}
	
	// Addition (Method)
	Complex sum (Complex c) {
		
		int r = real + c.real;
		int i = imaginary + c.imaginary;
		return new Complex(r,i);
	}
	
	//Difference - method 
	
Complex difference (Complex c) {
		
		int r = real - c.real;
		int i = imaginary - c.imaginary;
		return new Complex(r,i);
	}

// Multiplication
Complex  product (Complex c) {
	
	int r = (real * c.real) - (imaginary *c.imaginary);
	int i = (real * c.imaginary) + (imaginary * c.real) ;
	return new Complex(r,i);
}

//Display complex

void display() {
	if (imaginary >= 0)
		System.out.println(real + " + " + imaginary + "i");
	else 
		System.out.println(real + " - " + (-imaginary) + "i");
}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("Enter real part of first number:");
		int r1 = ConsoleInput.getInt(); 
		System.out.println("Enter imaginary part of first number:"); 
		int i1 = ConsoleInput.getInt();

		
		System.out.println("Enter real part of second number:");
		int r2 = ConsoleInput.getInt(); 
		System.out.println("Enter imaginary part of second number:");
		int i2 = ConsoleInput.getInt();
		
		Complex c1 = new Complex(r1, i1);
		Complex c2 = new Complex(r2, i2);
		
		
		Complex addition = c1.sum(c2);
		Complex subtraction = c1.difference(c2); 
		Complex multiplication = c1.product(c2);
		
		System.out.print("\nSum = "); 
		addition.display();
		
		System.out.print("Difference = ");
		subtraction.display(); 
		
		System.out.print("Product = ");
		multiplication.display();

	}

}

package A2_104502518;

/* Triangle.java */
public class Triangle {
	// a,b,c denote the three side length of triangle 
	private double a, b, c;
	
	/*-- Create 1st Constructor to set default value of three side length --*/
	Triangle(){
		a=1;
		b=1;
		c=1;
	}
	/*-- Create 2nd Constructor with given three side length 
	      from user input in main function --*/
	Triangle(double x,double y,double z){
		a=x;
		b=y;
		c=z;
	}
	/*-- Create a public method named getArea() for computing area of triangle and returning to caller. 
	     hint: implement mathematical method that only use three side length of triangle to get area  --*/
	public double getArea(){
		double s=(a+b+c)/2;
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}
	
}

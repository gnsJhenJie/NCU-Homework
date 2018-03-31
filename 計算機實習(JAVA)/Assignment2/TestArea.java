package A2_104502518;
import java.util.Scanner;
/* You can choose any IO method in JAVA to get the input */
public class TestArea {
	/* main function better to be only one in all java files,
	   so most(? maybe..I think) developer will put main function in Test class. */
	
	 public static void main(String[] args) {
		 /*-- Create a Rectangle class object name r1 with default value --*/
		 Rectangle r1=new Rectangle();
		 /*-- Create a Triangle class object name t1 with default value --*/
		 Triangle t1=new Triangle();
		 /*-- Let user input defined value to Rectangle class object name r2 --*/
		 System.out.println("Rectangle r1 has area of "+r1.getArea());
		 System.out.println("Triangle t1 has area of "+t1.getArea());
		 Scanner scan=new Scanner(System.in);
		 System.out.print("Enter height: ");
		 double rh=scan.nextDouble();
		 System.out.print("Enter weight: ");
		 double rw=scan.nextDouble();
		 Rectangle r2=new Rectangle(rh,rw);
		 System.out.println("Rectangle r2 has area of "+r2.getArea());
		 System.out.print("Enter length of sideA: ");
		 double ta=scan.nextDouble();
		 System.out.print("Enter length of sideB: ");
		 double tb=scan.nextDouble();
		 System.out.print("Enter length of sideC: ");
		 double tc=scan.nextDouble();
		 Triangle t2=new Triangle(ta,tb,tc);
		 System.out.println("Triangle t2 has area of "+t2.getArea());
		 /*-- Let user input defined value to Triangle class object name t2 --*/
		 
		 
	 }
}

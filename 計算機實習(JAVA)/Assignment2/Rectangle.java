package A2_104502518;

/* Rectangle.java */
public class Rectangle {
	// retangle's height and width
	private double height, width;
	Rectangle(){
		height=1;
		width=1;
	}
	/*-- Create 1st Constructor to set default value of height and width --*/
	Rectangle(double x,double y){
		height=x;
		width=y;
	}
	/*-- Create 2nd Constructor with given height and width 
	      from user input in main function --*/
	public double getArea(){
		return height*width;
	}
	/*-- Create a public method named getArea() for computing area of rectangle and returning to caller --*/
	
}

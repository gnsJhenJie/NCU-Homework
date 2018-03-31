package A3_104502518;

public class Triangle {
	private double a,b,c;

	/*-- Create Constructor to set default value --*/
	public Triangle() {
		a = b = c = 1;
	}

	/*-- Get point's coordinate --*/
	public void getPoint(int x1, int y1, int x2, int y2, int x3, int y3) {
		a = Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b = Math.sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		c = Math.sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	}

	/*--Calculate area  --*/
	public double getArea() {
		double s = (a+b+c)/2;
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}

}
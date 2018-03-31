package A4_104502518;

public class Tetrahedron extends Triangle{
	private double height;
	
	public Tetrahedron (int x1,int y1,int x2,int y2,int x3,int y3,int h) {
		super(x1,y1,x2,y2,x3,y3);
		setHeight(h);
	}
	
	public void setHeight(int n){
		height = (double) n;
	}

	public double getHeight(){
		return height;
	}
	
	public double getVolume(){
		return (getArea()*height)/3;
	}
	
	//override method speak
	public void speak(){
		System.out.println("This is message from Triangle:");
		super.speak();
		System.out.println("This is message from Tetrahedron:");
		System.out.println("Height is " + this.getHeight() + " ,and the volum is " + this.getVolume());
	}
}

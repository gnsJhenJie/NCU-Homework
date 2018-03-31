package A3_104502518;

import java.util.Random;

public class Main {
	public static void main(String[] args) {

		Random ran = new Random();

		/*-- Create a 6x11 map--*/
		int map[][] = new int[6][11];
		/*-- Create a Triangle class object name with default value --*/
		Triangle r = new Triangle(); 
		/*-- Generate points by random--*/
		int a[] = new int[6];
		for(int i=0;i<6;i=i+2){
			a[i] = ran.nextInt(6);
			a[i+1] = ran.nextInt(11);
		}
		map[a[0]][a[1]]=1;
		map[a[2]][a[3]]=2;
		map[a[4]][a[5]]=3;
		/*-- Transfer points to triangle object--*/
		r.getPoint(a[0],a[1],a[2],a[3],a[4],a[5]);
		/*-- Show map--*/
		for(int i=0;i<6;i++){
			for(int j=0;j<11;j++){
				System.out.print(map[i][j]);
			}
			System.out.println("");
		}
		/*-- Show points coordinate--*/
		System.out.println("Point 1 is at ("+a[0]+","+a[1]+").");
		System.out.println("Point 2 is at ("+a[2]+","+a[3]+").");
		System.out.println("Point 3 is at ("+a[4]+","+a[5]+").");
		/*-- Show area--*/
		if(r.getArea()==0){
			System.out.println("It's not a triangle.");
		}
		else{
			System.out.println("The area is "+r.getArea());
		}
	}

}

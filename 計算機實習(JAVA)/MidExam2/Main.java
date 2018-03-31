package M2_104502518;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		
		//first number is array of prime size
		//second number is range of your input
		prime test=new prime(2000,10000); 
		
		// scanner initialization
		Scanner scanner = new Scanner(System.in);
		
		//input number
		int n;
		
		while(true){
			
			n=scanner.nextInt(); 
			if(n==0)break;  //if input 0 , break
			
			//show answer
			System.out.println("ans: "+test.getCountAns(n));
		}	
	

	}
	
}

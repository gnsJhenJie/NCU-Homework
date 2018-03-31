//BufferedReader
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class calculator{
	private String MathF;//Mathematical Forms
	private int Num[]=new int[2];//=new int[2];//left number, right number
	private char MathSymbol;//Math Symbol
	
	//constructor -> save user's Mathematical Forms
	calculator(String ss)	{
		MathF=ss;
		different();
	}
	
	int GetAns(){//result
		 return compute();
	}
	
	int compute(){// compute answer
		if(MathSymbol=='+'){
			return Add();
		}
		if(MathSymbol=='-'){
			return Sub();
		}
		if(MathSymbol=='*'){
			return Mul();
		}
		if(MathSymbol=='/'){
			return Div();
		}
		else{
			return 0;
		}
	}
	
	void different(){//find left number, right number and math symbol
		int i,j;
		for(i=0;i<MathF.length();i++){
			if(MathF.charAt(i)<48){
				if(MathF.charAt(i)=='+'){
					MathSymbol='+';
				}
				if(MathF.charAt(i)=='-'){
					MathSymbol='-';
				}
				if(MathF.charAt(i)=='*'){
					MathSymbol='*';
				}
				if(MathF.charAt(i)=='/'){
					MathSymbol='/';
				}
				for(j=0;j<i;j++){
					Num[0]=Num[0]*10+MathF.charAt(j)-48;
				}
				for(j=i+1;j<MathF.length();j++){
					Num[1]=Num[1]*10+MathF.charAt(j)-48;
				}
				return;
			}
		}
	}		
	
	int Add(){//do Addition 
		return (Num[0]+Num[1]);
	}
	
	int Sub(){//do Subtraction
		return (Num[0]-Num[1]);
	}
	
	int Mul(){//do Multiplication
		return (Num[0]*Num[1]);
	}
	
	int Div(){//do Division
		return (Num[0]/Num[1]);
	}
	
}


public class main_104502518 {	
	public static void main(String[] args) throws IOException {
		
		calculator Calcul;	// new class calculator	
		BufferedReader keyin=new BufferedReader(new InputStreamReader(System.in));//preparation of input  
		String F="";
		
		while(true){
			F=keyin.readLine();//input Mathematical Forms
						
			if(F.equals("out"))break;//over
			
			Calcul=new calculator(F);
			
			System.out.println("Ans: "+Calcul.GetAns());

		
	
		}
	}		

}

package A5_104502518;
import java.math.BigDecimal;
import java.text.DecimalFormat;

class FinalCalculator extends SimpleCalculator{
	
	DecimalFormat df1 = new DecimalFormat("##################.##################");
	int c = 0;
	double x;
	int mode = 0;
	FinalCalculator(){
		super();
		MathSymbol = '0';
	}
	
	String Delete(String str){ //退格動作
		if(str.length() >= 2){
			return str.substring(0, str.length()-1);
		}
		else{
			return "0";
		}
		
	}
	
	String expand(String str,int i){ //擴充動作
		if(MathSymbol == '0'){
			if(Double.valueOf(str) == 0){
				x = (double) i;
				Num[0] = BigDecimal.valueOf(x);
				return String.valueOf(i);
			}
			else{
				x = Double.valueOf(str+String.valueOf(i));
				Num[0] = BigDecimal.valueOf(x);
				return str+String.valueOf(i);
			}
		}
		else{
			if(c == 0){
				x = (double) i;
				Num[1] = BigDecimal.valueOf(x);
				c++;
				return String.valueOf(i);
			}
			x = Double.valueOf(str+String.valueOf(i));
			Num[1] = BigDecimal.valueOf(x);
			return str+String.valueOf(i);
		}
	}
	
	String expandPoint (String str,char c){ //擴充小數點動作
		if(MathSymbol == '0'){
				x = Double.valueOf(str+c);
				Num[0] = BigDecimal.valueOf(x);
				return str+c;
		}
		else{
			if(c == 0){
				Num[1] = BigDecimal.valueOf(c);
				c++;
				return "0." + c;
			}
			x = Double.valueOf(str+c);
			Num[1] = BigDecimal.valueOf(x);
			return str+c;
		}
	}
	
	String Remove(String str){ //刪除動作
		Num[0] = BigDecimal.valueOf(0);
		Num[1] = BigDecimal.valueOf(0);
		MathSymbol = '0';
		c = mode = 0;
		return "0";
		
	}
	String Check (String str){
		return df1.format(Double.valueOf(str));
	}
	
}
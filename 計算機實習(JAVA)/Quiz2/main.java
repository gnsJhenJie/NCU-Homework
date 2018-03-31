package Q2_104502518;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 int[] a = new int[102];
		 int i,j,x;
		 int n = 0;
		 Scanner scan = new Scanner(System.in);
		 while(true){  //重複輸入
			 a[n] = scan.nextInt();
			 if((n+1)%2 == 0){  //判斷個數(偶)
				 for(i=0;i<n;i++){  //排序
					 for(j=0;j<n-i;j++){
						 if(a[j+1]<a[j]){
							 x = a[j];
							 a[j] = a[j+1];
							 a[j+1] = x;
						 }
					 }
				 }
				 System.out.print((a[((n+1)/2)-1]+a[((n+1)/2)])/2 + " ");  //結果輸出
			 }
			 else{  //判斷個數(奇)
				 for(i=0;i<n;i++){  //排序
					 for(j=0;j<n-i;j++){
						 if(a[j+1]<a[j]){
							 x = a[j];
							 a[j] = a[j+1];
							 a[j+1] = x;
						 }
					 }
				 }
				 System.out.print(a[((n+1)/2)] + " ");  //結果輸出
			 }
			 
			 n++;
		 }
	}

}

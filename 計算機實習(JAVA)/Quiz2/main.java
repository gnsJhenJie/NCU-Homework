package Q2_104502518;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 int[] a = new int[102];
		 int i,j,x;
		 int n = 0;
		 Scanner scan = new Scanner(System.in);
		 while(true){  //���ƿ�J
			 a[n] = scan.nextInt();
			 if((n+1)%2 == 0){  //�P�_�Ӽ�(��)
				 for(i=0;i<n;i++){  //�Ƨ�
					 for(j=0;j<n-i;j++){
						 if(a[j+1]<a[j]){
							 x = a[j];
							 a[j] = a[j+1];
							 a[j+1] = x;
						 }
					 }
				 }
				 System.out.print((a[((n+1)/2)-1]+a[((n+1)/2)])/2 + " ");  //���G��X
			 }
			 else{  //�P�_�Ӽ�(�_)
				 for(i=0;i<n;i++){  //�Ƨ�
					 for(j=0;j<n-i;j++){
						 if(a[j+1]<a[j]){
							 x = a[j];
							 a[j] = a[j+1];
							 a[j+1] = x;
						 }
					 }
				 }
				 System.out.print(a[((n+1)/2)] + " ");  //���G��X
			 }
			 
			 n++;
		 }
	}

}

package Q1_104502518;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int angle=0;
		int input1,input2,input3,input4;
		Scanner scan = new Scanner(System.in);
		input1 = scan.nextInt();
		input2 = scan.nextInt();
		input3 = scan.nextInt();
		input4 = scan.nextInt();
		while(true){
			if((input1 == 0)&&(input2 == 0)&&(input3 == 0)&&(input4 == 0)){//���X���� 0 0 0 0
				break;
			}
			if(input2 > input1){
				angle = angle+(40-(input2-input1))*9; //����1
			}
			else if(input1>input2){
				angle = angle+(input1-input2)*9; //����1
			}
			else{
				angle = angle +360; //����1
			}
			
			if(input3>input2){
				angle = angle+(input3-input2)*9; //����2
			}
			else if(input2>input3){
				angle = angle+(40-(input2-input3))*9; //����2
			}
			else{
				angle = angle+360; //����2
			}
			
			if(input4 > input3){
				angle = angle+(40-(input4-input3))*9; //����3
			}
			else if(input3>input4){
				angle = angle+(input3-input4)*9; //����3
			}
			else{
				angle = angle +360; //����3
			}
			
			System.out.println(angle+1080); //�̫ᨤ��
			
			input1 = scan.nextInt(); //���s��J
			input2 = scan.nextInt();
			input3 = scan.nextInt();
			input4 = scan.nextInt();
			angle = 0; //���m����
			
			
		}
		
	}

}

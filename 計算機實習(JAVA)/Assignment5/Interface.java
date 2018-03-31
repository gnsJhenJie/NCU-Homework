package A5_104502518;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.math.BigDecimal;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

class win extends JFrame implements ActionListener{
	
	Font font = new Font("OK", 1, 30); //�r��
	JButton btn[] = new JButton[10]; //�x�s0~9���ƭ�
	JButton btnPoint,btnDel,btnRem,btnEqu; //�p���I �h�� �R�� ����
	JButton btnDiv,btnMul,btnSub,btnAdd; //+ - * /
	JTextField txtMF = new JTextField("0"); //��J��r��
	FinalCalculator Cal = new FinalCalculator(); //�s�X�p���
	
	win() {
		
		//�̷Ӵ�ĳ���������]�p
		
		txtMF.setFont(font);
		txtMF.setBackground(Color.WHITE);
		txtMF.setEditable(false);
		txtMF.setBounds(10,5,295,50); //�]�w��j�p��m
		txtMF.setHorizontalAlignment(4); //����k��
		txtMF.addActionListener(this);  add(txtMF);
		
		btn[7] = new JButton("7"); //���s7
		btn[7].setFont(font);
		btn[7].setBounds(10,65,55,50); //�]�w���äj�p��m
		btn[7].addActionListener(this);  add(btn[7]); //�i�Q��
		
		btn[8] = new JButton("8"); //���s8
		btn[8].setFont(font);
		btn[8].setBounds(70,65,55,50); //�]�w���äj�p��m
		btn[8].addActionListener(this);  add(btn[8]); //�i�Q��
		
		btn[9] = new JButton("9"); //���s9
		btn[9].setFont(font);
		btn[9].setBounds(130,65,55,50); //�]�w���äj�p��m
		btn[9].addActionListener(this);  add(btn[9]); //�i�Q��
		
		btn[4] = new JButton("4"); //���s4
		btn[4].setFont(font);
		btn[4].setBounds(10,120,55,50); //�]�w���äj�p��m
		btn[4].addActionListener(this);  add(btn[4]); //�i�Q��
		
		btn[5] = new JButton("5"); //���s5
		btn[5].setFont(font);
		btn[5].setBounds(70,120,55,50); //�]�w���äj�p��m
		btn[5].addActionListener(this);  add(btn[5]); //�i�Q��
		
		btn[6] = new JButton("6"); //���s6
		btn[6].setFont(font);
		btn[6].setBounds(130,120,55,50); //�]�w���äj�p��m
		btn[6].addActionListener(this);  add(btn[6]); //�i�Q��
		
		btn[1] = new JButton("1"); //���s1
		btn[1].setFont(font);
		btn[1].setBounds(10,175,55,50); //�]�w���äj�p��m
		btn[1].addActionListener(this);  add(btn[1]); //�i�Q��
		
		btn[2] = new JButton("2"); //���s2
		btn[2].setFont(font);
		btn[2].setBounds(70,175,55,50); //�]�w���äj�p��m
		btn[2].addActionListener(this);  add(btn[2]); //�i�Q��
		
		btn[3] = new JButton("3"); //���s3
		btn[3].setFont(font);
		btn[3].setBounds(130,175,55,50); //�]�w���äj�p��m
		btn[3].addActionListener(this);  add(btn[3]); //�i�Q��
		
		btn[0] = new JButton("0"); //���s0
		btn[0].setFont(font);
		btn[0].setBounds(10,230,115,50); //�]�w���äj�p��m
		btn[0].addActionListener(this);  add(btn[0]); //�i�Q��
		
		btnDiv = new JButton("/"); //���s/
		btnDiv.setFont(font);
		btnDiv.setBounds(190,65,55,50); //�]�w���äj�p��m
		btnDiv.addActionListener(this);  add(btnDiv); //�i�Q��
		
		btnDel = new JButton("B"); //���s�R��
		btnDel.setFont(font);
		btnDel.setBounds(250,65,55,50); //�]�w���äj�p��m
		btnDel.addActionListener(this);  add(btnDel); //�i�Q��
		
		btnMul = new JButton("*"); //���s*
		btnMul.setFont(font);
		btnMul.setBounds(190,120,55,50); //�]�w���äj�p��m
		btnMul.addActionListener(this);  add(btnMul); //�i�Q��
		
		btnRem = new JButton("c"); //���s�R��
		btnRem.setFont(font);
		btnRem.setBounds(250,120,55,50); //�]�w���äj�p��m
		btnRem.addActionListener(this);  add(btnRem); //�i�Q��
		
		btnSub = new JButton("-"); //���s-
		btnSub.setFont(font);
		btnSub.setBounds(190,175,55,50); //�]�w���äj�p��m
		btnSub.addActionListener(this);  add(btnSub); //�i�Q��
		
		btnAdd = new JButton("+"); //���s+
		btnAdd.setFont(font);
		btnAdd.setBounds(190,230,55,50); //�]�w���äj�p��m
		btnAdd.addActionListener(this);  add(btnAdd); //�i�Q��
		
		btnPoint = new JButton("."); //���s.
		btnPoint.setFont(font);
		btnPoint.setBounds(130,230,55,50); //�]�w���äj�p��m
		btnPoint.addActionListener(this);  add(btnPoint); //�i�Q��
		
		btnEqu = new JButton("="); //���s=
		btnEqu.setFont(font);
		btnEqu.setBounds(250,175,55,105); //�]�w���äj�p��m
		btnEqu.addActionListener(this);  add(btnEqu); //�i�Q��
		
		setTitle("�p��L"); //���D�W��
		setLocation(0,0); //�]�w������m
		setLayout(null); //���ƪ�
		setSize(330,340); //�]�w�������e
		setVisible(true); //�i��
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //�{���P�����@�_����
	}
	
	public void actionPerformed(ActionEvent e){
		if(e.getSource() == btnAdd){
			Cal.MathSymbol = '+';
			if(Cal.Num[1].doubleValue() != 0 && Cal.mode == 0){
				txtMF.setText(Cal.Check(Cal.GetAns()));
				Cal.Num[0] = BigDecimal.valueOf(Double.valueOf(txtMF.getText()));
			}
		}
		else if(e.getSource() == btnSub){
			Cal.MathSymbol = '-';
			if(Cal.Num[1].doubleValue() != 0 && Cal.mode == 0){
				txtMF.setText(Cal.Check(Cal.GetAns()));
				Cal.Num[0] = BigDecimal.valueOf(Double.valueOf(txtMF.getText()));
			}
		}
		else if(e.getSource() == btnMul){
			Cal.MathSymbol = '*';
			if(Cal.Num[1].doubleValue() != 0 && Cal.mode == 0){
				txtMF.setText(Cal.Check(Cal.GetAns()));
				Cal.Num[0] = BigDecimal.valueOf(Double.valueOf(txtMF.getText()));
			}
		}
		else if(e.getSource() == btnDiv){
			Cal.MathSymbol = '/';
			if(Cal.Num[1].doubleValue() != 0 && Cal.mode == 0){
				txtMF.setText(Cal.Check(Cal.GetAns()));
				Cal.Num[0] = BigDecimal.valueOf(Double.valueOf(txtMF.getText()));
			}
		}
		else if(e.getSource() == btnPoint){
			txtMF.setText(Cal.expandPoint(txtMF.getText(), '.'));
		}
		else if(e.getSource() == btnDel){
			txtMF.setText(Cal.Delete(txtMF.getText()));
		}
		else if(e.getSource() == btnRem){
			txtMF.setText(Cal.Remove(""));
		}
		else if(e.getSource() == btnEqu){
			if(Cal.Num[1].doubleValue() == 0 && Cal.MathSymbol == '/'){
				txtMF.setText("Division by zero");
			}
			else if(Cal.Check(Cal.GetAns()).length() > 17){
				txtMF.setText("Error : Overflow !");
			}
			else{
				txtMF.setText(Cal.Check(Cal.GetAns()));
				Cal.c = 0;
				Cal.mode = 1;
			}
			Cal.Num[0] = BigDecimal.valueOf(Double.valueOf(txtMF.getText()));
		}
		else if(e.getSource() == btn[0]){
			txtMF.setText(Cal.expand(txtMF.getText(), 0));
		}
		else if(e.getSource() == btn[1]){
			txtMF.setText(Cal.expand(txtMF.getText(), 1));
		}
		else if(e.getSource() == btn[2]){
			txtMF.setText(Cal.expand(txtMF.getText(), 2));
		}
		else if(e.getSource() == btn[3]){
			txtMF.setText(Cal.expand(txtMF.getText(), 3));
		}
		else if(e.getSource() == btn[4]){
			txtMF.setText(Cal.expand(txtMF.getText(), 4));
		}
		else if(e.getSource() == btn[5]){
			txtMF.setText(Cal.expand(txtMF.getText(), 5));
		}
		else if(e.getSource() == btn[6]){
			txtMF.setText(Cal.expand(txtMF.getText(), 6));
		}
		else if(e.getSource() == btn[7]){
			txtMF.setText(Cal.expand(txtMF.getText(), 7));
		}
		else if(e.getSource() == btn[8]){
			txtMF.setText(Cal.expand(txtMF.getText(), 8));
		}
		else if(e.getSource() == btn[9]){
			txtMF.setText(Cal.expand(txtMF.getText(), 9));
		}
		//�����\����
		
	}
}
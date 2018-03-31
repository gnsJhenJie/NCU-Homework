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
	
	Font font = new Font("OK", 1, 30); //字型
	JButton btn[] = new JButton[10]; //儲存0~9的數值
	JButton btnPoint,btnDel,btnRem,btnEqu; //小數點 退格 刪除 等於
	JButton btnDiv,btnMul,btnSub,btnAdd; //+ - * /
	JTextField txtMF = new JTextField("0"); //輸入文字欄
	FinalCalculator Cal = new FinalCalculator(); //叫出計算機
	
	win() {
		
		//依照提議完成介面設計
		
		txtMF.setFont(font);
		txtMF.setBackground(Color.WHITE);
		txtMF.setEditable(false);
		txtMF.setBounds(10,5,295,50); //設定欄大小位置
		txtMF.setHorizontalAlignment(4); //對齊右邊
		txtMF.addActionListener(this);  add(txtMF);
		
		btn[7] = new JButton("7"); //按鈕7
		btn[7].setFont(font);
		btn[7].setBounds(10,65,55,50); //設定按紐大小位置
		btn[7].addActionListener(this);  add(btn[7]); //可被按
		
		btn[8] = new JButton("8"); //按鈕8
		btn[8].setFont(font);
		btn[8].setBounds(70,65,55,50); //設定按紐大小位置
		btn[8].addActionListener(this);  add(btn[8]); //可被按
		
		btn[9] = new JButton("9"); //按鈕9
		btn[9].setFont(font);
		btn[9].setBounds(130,65,55,50); //設定按紐大小位置
		btn[9].addActionListener(this);  add(btn[9]); //可被按
		
		btn[4] = new JButton("4"); //按鈕4
		btn[4].setFont(font);
		btn[4].setBounds(10,120,55,50); //設定按紐大小位置
		btn[4].addActionListener(this);  add(btn[4]); //可被按
		
		btn[5] = new JButton("5"); //按鈕5
		btn[5].setFont(font);
		btn[5].setBounds(70,120,55,50); //設定按紐大小位置
		btn[5].addActionListener(this);  add(btn[5]); //可被按
		
		btn[6] = new JButton("6"); //按鈕6
		btn[6].setFont(font);
		btn[6].setBounds(130,120,55,50); //設定按紐大小位置
		btn[6].addActionListener(this);  add(btn[6]); //可被按
		
		btn[1] = new JButton("1"); //按鈕1
		btn[1].setFont(font);
		btn[1].setBounds(10,175,55,50); //設定按紐大小位置
		btn[1].addActionListener(this);  add(btn[1]); //可被按
		
		btn[2] = new JButton("2"); //按鈕2
		btn[2].setFont(font);
		btn[2].setBounds(70,175,55,50); //設定按紐大小位置
		btn[2].addActionListener(this);  add(btn[2]); //可被按
		
		btn[3] = new JButton("3"); //按鈕3
		btn[3].setFont(font);
		btn[3].setBounds(130,175,55,50); //設定按紐大小位置
		btn[3].addActionListener(this);  add(btn[3]); //可被按
		
		btn[0] = new JButton("0"); //按鈕0
		btn[0].setFont(font);
		btn[0].setBounds(10,230,115,50); //設定按紐大小位置
		btn[0].addActionListener(this);  add(btn[0]); //可被按
		
		btnDiv = new JButton("/"); //按鈕/
		btnDiv.setFont(font);
		btnDiv.setBounds(190,65,55,50); //設定按紐大小位置
		btnDiv.addActionListener(this);  add(btnDiv); //可被按
		
		btnDel = new JButton("B"); //按鈕刪除
		btnDel.setFont(font);
		btnDel.setBounds(250,65,55,50); //設定按紐大小位置
		btnDel.addActionListener(this);  add(btnDel); //可被按
		
		btnMul = new JButton("*"); //按鈕*
		btnMul.setFont(font);
		btnMul.setBounds(190,120,55,50); //設定按紐大小位置
		btnMul.addActionListener(this);  add(btnMul); //可被按
		
		btnRem = new JButton("c"); //按鈕刪除
		btnRem.setFont(font);
		btnRem.setBounds(250,120,55,50); //設定按紐大小位置
		btnRem.addActionListener(this);  add(btnRem); //可被按
		
		btnSub = new JButton("-"); //按鈕-
		btnSub.setFont(font);
		btnSub.setBounds(190,175,55,50); //設定按紐大小位置
		btnSub.addActionListener(this);  add(btnSub); //可被按
		
		btnAdd = new JButton("+"); //按鈕+
		btnAdd.setFont(font);
		btnAdd.setBounds(190,230,55,50); //設定按紐大小位置
		btnAdd.addActionListener(this);  add(btnAdd); //可被按
		
		btnPoint = new JButton("."); //按鈕.
		btnPoint.setFont(font);
		btnPoint.setBounds(130,230,55,50); //設定按紐大小位置
		btnPoint.addActionListener(this);  add(btnPoint); //可被按
		
		btnEqu = new JButton("="); //按鈕=
		btnEqu.setFont(font);
		btnEqu.setBounds(250,175,55,105); //設定按紐大小位置
		btnEqu.addActionListener(this);  add(btnEqu); //可被按
		
		setTitle("小算盤"); //標題名稱
		setLocation(0,0); //設定視窗位置
		setLayout(null); //不排版
		setSize(330,340); //設定視窗長寬
		setVisible(true); //可視
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //程式與視窗一起結束
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
		//完成功能鍵
		
	}
}
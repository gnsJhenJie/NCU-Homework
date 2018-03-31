package M3_104502518;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

public class SimpleCalculator extends JFrame implements ActionListener{
	
	private char sign='0';
	private int n[] = new int[2];
	JTextField text = new JTextField(20);
	JButton btn1 = new JButton("1");
	JButton btn2 = new JButton("2");
	JButton btn4 = new JButton("4");
	JButton btn8 = new JButton("8");
	JButton add = new JButton("+");
	JButton sub = new JButton("-");
	JButton mul = new JButton("*");
	JButton div = new JButton("/");
	JButton enter = new JButton("Enter");
	
	SimpleCalculator(){
		setLayout(null);
		text.setHorizontalAlignment(4);
		text.setBounds(10, 20, 260, 25);
		add(text);
		
		
		btn1.setBounds(5, 50, 80, 80);
		btn1.addActionListener(this);
		add(btn1);
		
		btn2.setBounds(90, 50, 80, 80);
		btn2.addActionListener(this);
		add(btn2);
		
		btn4.setBounds(5, 140, 80, 80);
		btn4.addActionListener(this);
		add(btn4);
		
		btn8.setBounds(90, 140, 80, 80);
		btn8.addActionListener(this);
		add(btn8);
		
		add.setBounds(170, 50, 50, 50);
		add.addActionListener(this);
		add(add);
		
		sub.setBounds(220, 50, 50, 50);
		sub.addActionListener(this);
		add(sub);
		
		mul.setBounds(170, 100, 50, 50);
		mul.addActionListener(this);
		add(mul);
		
		div.setBounds(220, 100, 50, 50);
		div.addActionListener(this);
		add(div);
		
		enter.setBounds(170, 150, 110, 90);
		enter.addActionListener(this);
		add(enter);
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == btn1){
			text.setText("1");
			if(sign == '0'){
				n[0] = 1;
			}
			else{
				n[1] = 1;
			}
		}
		
		if(e.getSource() == btn2){
			text.setText("2");
			if(sign == '0'){
				n[0] = 2;
			}
			else{
				n[1] = 2;
			}
		}
		
		if(e.getSource() == btn4){
			text.setText("4");
			if(sign == '0'){
				n[0] = 4;
			}
			else{
				n[1] = 4;
			}
		}
		
		if(e.getSource() == btn8){
			text.setText("8");
			if(sign == '0'){
				n[0] = 8;
			}
			else{
				n[1] = 8;
			}
		}
		
		if(e.getSource() == add){
			text.setText("+");
			sign = '+';
		}
		
		if(e.getSource() == sub){
			text.setText("-");
			sign = '-';
		}
		
		if(e.getSource() == mul){
			text.setText("*");
			sign = '*';
		}
		
		if(e.getSource() == div){
			text.setText("/");
			sign = '/';
		}
		
		if(e.getSource() == enter){
			if(sign == '+'){
				text.setText(String.valueOf(n[0]+n[1]));
			}
			if(sign == '-'){
				text.setText(String.valueOf(n[0]-n[1]));
			}
			if(sign == '*'){
				text.setText(String.valueOf(n[0]*n[1]));
			}
			if(sign == '/'){
				text.setText(String.valueOf(n[0]/n[1]));
			}
			sign = '0';
		}
	}

	
}

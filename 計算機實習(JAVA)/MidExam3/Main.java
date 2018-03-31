package M3_104502518;

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args)  {
		SimpleCalculator cal = new SimpleCalculator();
		cal.setTitle("Very Easy");
		cal.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// set window on the central of screen
		cal.setLocationRelativeTo(null);
		// You can change the size you want
		cal.setSize(300, 300);
		cal.setVisible(true);
	}
}

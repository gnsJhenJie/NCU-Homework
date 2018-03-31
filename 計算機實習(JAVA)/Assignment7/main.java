package A7_104502518;

import java.awt.GridLayout;

import javax.swing.JFrame;

public class main {
	public static void main(String args[]) {

		Scene Minigame = new Scene();
		Minigame.setTitle("Minigame");
		Minigame.setSize(670, 670);
		Minigame.setLocationRelativeTo(null);
		Minigame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Minigame.setVisible(true);
		Minigame.setLayout(new GridLayout(10,10));
	}
}

package A6_104502518;

import javax.swing.JButton;
// import GUI object 
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextPane;

import javax.swing.text.DefaultStyledDocument;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;

import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.BufferedReader;
import java.io.FileReader;

import javax.swing.Timer;


@SuppressWarnings("serial")
public class TypingTutor extends JFrame implements KeyListener, ActionListener{
	// Declare variables of several GUI type that you will use in constructor to build the interface
	private JPanel timerJP;
	private JPanel keyboardJP;
	private JPanel textfileJP;
	private JTextPane textPane;
	private Timer countingTimer = new Timer(1000,this);
	private JLabel secondsJL = new JLabel("00");
	private JLabel minutesJL = new JLabel("00");
	int second = 0;
	int minute = 0;
	Font f = new Font(Font.SANS_SERIF, 1, 20);
	private JButton firstKeyboardBtn[];
	private JButton secondKeyboardBtn[];
	private JButton thirdKeyboardBtn[];
	private int keyboardInputCode;
	private Color originalBackgroundColor;
	private boolean capcolor = false;
	private SimpleAttributeSet set = new SimpleAttributeSet();
	private int ca = 0;
	private boolean timestart = false;
	private StyledDocument doc;
	char bug = '?';
	
	// 宣告會填到JButton的字串
	String firstContentRow [] = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "Caps"};// 11 items
	String secondContentRow[] = {"A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "Enter"};   // 11 items
	String thirdContentRow [] = {"Z", "X", "C", "V", "B", "N", "M", ",", ".", "?",  "Space"};   // 11 items
	
	// 要改變JTextPane的Document Style所需要的Object
	
	
	// TypingTutor constructor doesn't need to be changed anything.
	public TypingTutor() {
		super("Typing Application"); // 丟給JFrame(視窗), 建立視窗名字
		
		// Layout object (排版)
		setLayout(new BorderLayout());
		
		/* IMPLEMENTAION NOTES : 
		 * following code have three Function with JPanel(timerJP、textfileJP、keyboardJP).
		 * Their layout position are NORTH、CENTER、SOUTH.
		 * So the main layout I already done for you. Your job is to fill these JPanel.
		 * The three example code I provide are highly relative to this assignment.
		 */
		TimerGUI();
		TextFileGUI();
		KeyboardGUI();
		
	}
	
	private void TimerGUI(){
		// Timer GUI
		timerJP = new JPanel();
		add(timerJP, BorderLayout.NORTH);
		minutesJL.setFont(f);
		secondsJL.setFont(f);
		timerJP.add(minutesJL);
		timerJP.add(secondsJL);
		// write your code
	}
	private void TextFileGUI(){
		// text file GUI
		textfileJP = new JPanel(new BorderLayout());
		add(textfileJP, BorderLayout.CENTER);
		
	    // set StyledDocument on JTextPane
		doc = new DefaultStyledDocument();
		textPane = new JTextPane(doc);
		textPane.addKeyListener(this);
		textfileJP.add(textPane);
		textPane.setFont(f);
		try{
			FileReader fr = new FileReader("long.txt");
			BufferedReader br = new BufferedReader(fr);
			String str = br.readLine();
			int len = textPane.getDocument().getLength();
			textPane.setCaretPosition(len);
			textPane.replaceSelection(str+'\0');
			br.close();
		}
		catch(Exception e){
			System.out.println(e);
		}
		textPane.setEditable(false);
		// Load text file on JTextPane in JPanel
		// write your code 
	}
	private void KeyboardGUI(){
		// Create keyboard JPanel in GridBagLayout 
		keyboardJP = new JPanel(new GridBagLayout());
		add(keyboardJP, BorderLayout.SOUTH);
		firstKeyboardBtn = new JButton[firstContentRow.length];
		secondKeyboardBtn = new JButton[secondContentRow.length];
		thirdKeyboardBtn = new JButton[thirdContentRow.length];
		addKeys(keyboardJP, 0, firstContentRow, firstKeyboardBtn);
		addKeys(keyboardJP, 1, secondContentRow, secondKeyboardBtn);
		addKeys(keyboardJP, 2, thirdContentRow, thirdKeyboardBtn);
		for(JButton button : firstKeyboardBtn){
			button.addKeyListener(this);
		}
		for(JButton button : secondKeyboardBtn){
			button.addKeyListener(this);
		}
		for(JButton button : thirdKeyboardBtn){
			button.addKeyListener(this);
		}
		originalBackgroundColor = firstKeyboardBtn[0].getBackground();
		// write your code
	}
	private void addKeys(JPanel parent, int row, String[] keys,JButton[] buttons){
		
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.gridy = row;
		gbc.gridx = 0;
		gbc.fill = GridBagConstraints.BOTH;
		int gap = 0;
		for(int index = 0;index < keys.length; index++){
			String key = keys[index];
			if("blank".equalsIgnoreCase(key)){
				gbc.gridx++;
			}
			else if("fill".equalsIgnoreCase(key)){
				gbc.gridwidth++;
				gap++;
			}
			else{
				JButton btn = new JButton(key);
				buttons[index] = btn;
				parent.add(btn, gbc);
				gbc.gridx += gap + 1;
				gbc.gridwidth = 1;
				gap = 0;
			}
		}
	}
	private void changeTextCharColor(int keychar) {
		/* Because original key char is a upper case character
		/* you need to change it to lower case when CapsLock is off
		/* when user finish typing, Timer should be stopped. */
		StyleConstants.setForeground(set, Color.RED);
		if((textPane.getText().charAt(keychar)) == ' '){
			StyleConstants.setBackground(set, Color.BLACK);
			doc.setCharacterAttributes(keychar,  1, set, true);
		}
		else{
			StyleConstants.setBackground(set, Color.WHITE);
			doc.setCharacterAttributes(keychar,  1, set, true);
		}
		// write your code 
	
	}
	/* ---------- keyboard event handler begin ---------- */ 
	public void keyPressed(KeyEvent event) {
		keyboardInputCode = event.getKeyCode();
		//System.out.print(keyboardInputCode);
		char getKeyboardchar = (char) keyboardInputCode;
		char getKeyboardchar1 = (char) (keyboardInputCode+32);
		
		if(keyboardInputCode == KeyEvent.VK_CAPS_LOCK){
			if(capcolor == false){
				firstKeyboardBtn[10].setBackground(Color.RED);
				capcolor = true;
			}
			else{
				firstKeyboardBtn[10].setBackground(originalBackgroundColor);
				capcolor = false;
			}
		}
		else{
			if(keyboardInputCode == KeyEvent.VK_Q)
				firstKeyboardBtn[0].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_W)
				firstKeyboardBtn[1].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_E)
				firstKeyboardBtn[2].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_R)
				firstKeyboardBtn[3].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_T)
				firstKeyboardBtn[4].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_Y)
				firstKeyboardBtn[5].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_U)
				firstKeyboardBtn[6].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_I)
				firstKeyboardBtn[7].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_O)
				firstKeyboardBtn[8].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_P)
				firstKeyboardBtn[9].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_A)
				secondKeyboardBtn[0].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_S)
				secondKeyboardBtn[1].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_D)
				secondKeyboardBtn[2].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_F)
				secondKeyboardBtn[3].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_G)
				secondKeyboardBtn[4].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_H)
				secondKeyboardBtn[5].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_J)
				secondKeyboardBtn[6].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_K)
				secondKeyboardBtn[7].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_L)
				secondKeyboardBtn[8].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_SEMICOLON)
				secondKeyboardBtn[9].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_ENTER){
				secondKeyboardBtn[10].setBackground(Color.RED);
				countingTimer.start();
				timestart = true;
			}
			else if(keyboardInputCode == KeyEvent.VK_Z)
				thirdKeyboardBtn[0].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_X)
				thirdKeyboardBtn[1].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_C)
				thirdKeyboardBtn[2].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_V)
				thirdKeyboardBtn[3].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_B)
				thirdKeyboardBtn[4].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_N)
				thirdKeyboardBtn[5].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_M)
				thirdKeyboardBtn[6].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_COMMA)
				thirdKeyboardBtn[7].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_PERIOD)
				thirdKeyboardBtn[8].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_SLASH)
				thirdKeyboardBtn[9].setBackground(Color.RED);
			else if(keyboardInputCode == KeyEvent.VK_SPACE){
				thirdKeyboardBtn[10].setBackground(Color.RED);
			}
			if(timestart == true){
				if((keyboardInputCode == 32) && (textPane.getText().charAt(ca) == ' ')){
					changeTextCharColor(ca);
					//System.out.print(keyboardInputCode);
					ca++;
				}
				else if((keyboardInputCode == 46) && (textPane.getText().charAt(ca) == '.')){
					changeTextCharColor(ca);
					//System.out.print(keyboardInputCode);
					ca++;
				}
				else if((keyboardInputCode == 59) && (textPane.getText().charAt(ca) == ';')){
					changeTextCharColor(ca);
					//System.out.print(keyboardInputCode);
					ca++;
				}
				else if((keyboardInputCode == 44) && (textPane.getText().charAt(ca) == ',')){
					changeTextCharColor(ca);
					//System.out.print(keyboardInputCode);
					ca++;
				}
				else if((getKeyboardchar == textPane.getText().charAt(ca))&&(textPane.getText().charAt(ca) == '-')){
					changeTextCharColor(ca);
					//System.out.print(keyboardInputCode);
					ca++;
				}
				else if((keyboardInputCode == 222) && (textPane.getText().charAt(ca) == '\'')){
					changeTextCharColor(ca);
					//System.out.print(keyboardInputCode);
					ca++;
				}
				else if((keyboardInputCode == 47) && (textPane.getText().charAt(ca) == '?')){
					changeTextCharColor(ca);
					//System.out.print(keyboardInputCode);
					ca++;
				}
				if(capcolor == false){
					
					if(getKeyboardchar1 == textPane.getText().charAt(ca)){
						changeTextCharColor(ca);
						//System.out.print('\'');
						ca++;
					}
				}
				else{
					if(getKeyboardchar == textPane.getText().charAt(ca)){
						changeTextCharColor(ca);
						//System.out.print(keyboardInputCode);
						ca++;
					}
				}
				if(ca == textPane.getText().length()-1){
					countingTimer.stop();
				}
			}
		}
		// write your code
	}
	public void keyReleased(KeyEvent event) {
		keyboardInputCode = event.getKeyCode();
		if(keyboardInputCode == KeyEvent.VK_Q)
			firstKeyboardBtn[0].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_W)
			firstKeyboardBtn[1].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_E)
			firstKeyboardBtn[2].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_R)
			firstKeyboardBtn[3].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_T)
			firstKeyboardBtn[4].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_Y)
			firstKeyboardBtn[5].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_U)
			firstKeyboardBtn[6].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_I)
			firstKeyboardBtn[7].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_O)
			firstKeyboardBtn[8].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_P)
			firstKeyboardBtn[9].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_A)
			secondKeyboardBtn[0].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_S)
			secondKeyboardBtn[1].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_D)
			secondKeyboardBtn[2].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_F)
			secondKeyboardBtn[3].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_G)
			secondKeyboardBtn[4].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_H)
			secondKeyboardBtn[5].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_J)
			secondKeyboardBtn[6].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_K)
			secondKeyboardBtn[7].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_L)
			secondKeyboardBtn[8].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_SEMICOLON)
			secondKeyboardBtn[9].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_ENTER)
			secondKeyboardBtn[10].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_Z)
			thirdKeyboardBtn[0].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_X)
			thirdKeyboardBtn[1].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_C)
			thirdKeyboardBtn[2].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_V)
			thirdKeyboardBtn[3].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_B)
			thirdKeyboardBtn[4].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_N)
			thirdKeyboardBtn[5].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_M)
			thirdKeyboardBtn[6].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_COMMA)
			thirdKeyboardBtn[7].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_PERIOD)
			thirdKeyboardBtn[8].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_SLASH)
			thirdKeyboardBtn[9].setBackground(originalBackgroundColor);
		else if(keyboardInputCode == KeyEvent.VK_SPACE)
			thirdKeyboardBtn[10].setBackground(originalBackgroundColor);
		// write your code
	}
	public void keyTyped(KeyEvent event) {
		// do nothing
	}
	/* ---------- keyboard event handler end ---------- */
	

	/* ---------- action event handler begin ---------- */ 
	// This action event is mainly for Timer trigger
	public void actionPerformed(ActionEvent e){
		if(e.getSource() == countingTimer){
			String secondString,minuteString;
			second++;
			if(second >= 60){
				minute++;
				second = 0;
				secondString = Integer.toString(second);
				minuteString = Integer.toString(minute);
				secondsJL.setText("0"+secondString);
				if(minute < 10){
					minuteString = Integer.toString(minute);
					minutesJL.setText("0"+minuteString);
				}
				else if(minute>=10){
					minuteString = Integer.toString(minute);
					minutesJL.setText(minuteString);
				}
			}
			else if(second < 10){
				secondString = Integer.toString(second);
				secondsJL.setText("0"+secondString);
			}
			else if(second >= 10){
				secondString = Integer.toString(second);
				secondsJL.setText(secondString);
			}
			
		}
		
		
		// write your code
	}
 
}
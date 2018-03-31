package A7_104502518;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;
import javax.swing.Timer;

public class Scene extends JFrame implements ActionListener, KeyListener {
	private JLabel[][] grounds = new JLabel[10][10]; //10x10����l
	private Timer timer = new Timer(1000,this);
	
	private Random ran = new Random();

	private ImageIcon ground; //�a������
	private ImageIcon player; //�D������
	private ImageIcon enemy; //�L�ͪ���
	private ImageIcon sword; //�C����
	private ImageIcon win; //�D���ӧQ����
	private ImageIcon loss; //�D���鱼����
	
	
	private int playerx = 9; //�D����row�y��
	private int playery = 9; //�D����column�y��
	private int enemyx = 0;  //���ͪ�row�y��
	private int enemyy = 0;  //���ͪ�column�y��
	private int swordx = 5;  //�C��row�y��
	private int swordy = 5;  //�C��column�y��

	private boolean havenosword = true; //�x�s�D���O�_���C
	private boolean touch = false; //�x�s�L�ͬO�_���C
	
	Scene(){
		ground = new ImageIcon("ground.png");
		player = new ImageIcon("Player.png");
		enemy = new ImageIcon("Enemy.png");
		sword = new ImageIcon("sword.png");
		win = new ImageIcon("Win.png");
		loss = new ImageIcon("Loss.png");
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				grounds[i][j] = new JLabel(ground);
				add(grounds[i][j]);
			}
		}
		grounds[swordy][swordx].setIcon(sword);
		grounds[playery][playerx].setIcon(player);
		grounds[enemyy][enemyx].setIcon(enemy);
		timer.start();
		this.addKeyListener(this);
	}
	
	void SwordMove(){
		if(ran.nextInt(4)%4 == 0){
			if(swordx<9){
				swordx+=1;
			}
		}
		else if(ran.nextInt(4)%4 == 1){
			if(swordx>0){
				swordx-=1;
			}
		}
		else if(ran.nextInt(4)%4 == 2){
			if(swordy<9){
				swordy+=1;
			}
		}
		else{
			if(swordy>0){
				swordy-=1;
			}
		}
		if((swordx == playerx)&&(swordy == playery)){
			havenosword = false;
		}
	}
	
	void EnemyMove(){
		if((enemyx != playerx)&&(enemyy != playery)){
			if(ran.nextInt(2)%2 == 1){
				if(playerx > enemyx){
					enemyx+=1;
				}
				else{
					enemyx-=1;
				}
			}
			else{
				if(playery > enemyy){
					enemyy+=1;
				}
				else{
					enemyy-=1;
				}
			}
		}
		else if((enemyx != playerx)&&(enemyy == playery)){
			if(playerx > enemyx){
				enemyx+=1;
			}
			else{
				enemyx-=1;
			}
		}
		else if((enemyy != playery)&&(enemyx == playerx)){
			if(playery > enemyy){
				enemyy+=1;
			}
			else{
				enemyy-=1;
			}
		}
	}
	
	//�ݭn�����Ʊ�:�D�������ʤ覡, ���ͪ����ʤ覡, �P�_�ӭt���G, �D���O�_������C......
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(havenosword){
			grounds[swordy][swordx].setIcon(ground);
		}
		grounds[enemyy][enemyx].setIcon(ground);
		EnemyMove();
		if(havenosword){
			SwordMove();
			grounds[swordy][swordx].setIcon(sword);
		}
		grounds[enemyy][enemyx].setIcon(enemy);
		if((enemyx == playerx)&&(enemyy == playery)){
			if(havenosword == true){
				grounds[playery][playerx].setIcon(loss);
				JOptionPane.showMessageDialog(this, "You Lose!");
				this.dispose();
				System.exit(1);
			}
			else{
				grounds[playery][playerx].setIcon(win);
				JOptionPane.showMessageDialog(this, "You Win!");
				this.dispose();
				System.exit(1);
			}
		}
	}
	
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		int keycode = e.getKeyCode();
		grounds[playery][playerx].setIcon(ground);
		if(touch == false){
			if(keycode == KeyEvent.VK_UP){
				if(playery > 0){
					grounds[playery][playerx].setIcon(ground);
					playery-=1;
				}
			}
			else if(keycode == KeyEvent.VK_RIGHT){
				if(playerx < 9){
					grounds[playery][playerx].setIcon(ground);
					playerx+=1;
				}
			}
			else if(keycode == KeyEvent.VK_LEFT){
				if(playerx > 0){
					grounds[playery][playerx].setIcon(ground);
					playerx-=1;
				}
			}
			else if(keycode == KeyEvent.VK_DOWN){
				if(playery < 9){
					grounds[playery][playerx].setIcon(ground);
					playery+=1;
				}
			}
			touch = true;
		}
		grounds[playery][playerx].setIcon(player);
		if((swordx == playerx)&&(swordy == playery)){
			havenosword = false;
		}
		if((enemyx == playerx)&&(enemyy == playery)){
			if(havenosword == true){
				grounds[playery][playerx].setIcon(loss);
				JOptionPane.showMessageDialog(this, "You Lose!");
				this.dispose();
				System.exit(1);
			}
			else{
				grounds[playery][playerx].setIcon(win);
				JOptionPane.showMessageDialog(this, "You Win!");
				this.dispose();
				System.exit(1);
			}
		}
	}
	
	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		int keycode = e.getKeyCode();
		if(keycode == KeyEvent.VK_UP){
			touch = false;
		}
		else if(keycode == KeyEvent.VK_RIGHT){
			touch = false;
		}
		else if(keycode == KeyEvent.VK_LEFT){
			touch = false;
		}
		else if(keycode == KeyEvent.VK_DOWN){
			touch = false;
		}
	}
	
	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

}

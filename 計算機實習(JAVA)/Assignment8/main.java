package A8_104502518;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.awt.image.RescaleOp;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.filechooser.FileNameExtensionFilter;

public class main {		//main���O

	public static void main(String[] args) {
		window w = new window();
	}
	
}
class AlphaPanel extends JPanel {  //�گu�����j���o��b�F��QAQ  �ϥ���z���צ���

	public BufferedImage bi;
	private float[] scales = { 1f, 1f, 1f, 1f };
	private float[] offsets = new float[4];
	private RescaleOp rop;
	

	public AlphaPanel(ImageIcon icon, double scale) {

		int width = (int) (scale * icon.getIconWidth());
		int height = (int) (scale * icon.getIconHeight());
		this.setPreferredSize(new Dimension(width, height));
		this.bi = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
		this.bi.createGraphics().drawImage(icon.getImage(), 0, 0, width, height, null);
		rop = new RescaleOp(scales, offsets, null);
	}

	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D) g;
		g2d.drawImage(bi, rop, 0, 0);
	}

	public void setAlpha(float alpha) {
		this.scales[3] = alpha;
		this.rop = new RescaleOp(scales, offsets, null);
	}
}
class window extends JFrame implements ActionListener, ChangeListener{		//�������O
	
	JButton open = new JButton("open the file");		//�ŧi��
	
	private Container all = this.getContentPane();
	
	AlphaPanel p;
	
	private boolean use = false;
	
	JSlider opecity = new JSlider(JSlider.HORIZONTAL, 0, 100, 20);
	
	Image iconI;
	ImageIcon iconIC;
	
	window(){
		
		open.addActionListener(this);
		all.add(open, BorderLayout.NORTH);
		
		opecity.setMajorTickSpacing(20);		//�]�wslider//�]�wbutton
		opecity.setMinorTickSpacing(5);
		opecity.setPaintTicks(true);
		opecity.setPaintLabels(true);
		opecity.addChangeListener(this);;
		all.add(opecity, BorderLayout.SOUTH);
		
		
		
		
		
		setTitle("wow");		//�]�w����
		setSize(300,300);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == open){
			//�ϥζ}�ҴM���ɮת��F��
			JFileChooser choose = new JFileChooser();		//���ɮ�
			FileNameExtensionFilter filter = new FileNameExtensionFilter("JPG & GF Images", "jpg", "gif");
			choose.setFileFilter(filter);
			int returnVal = choose.showOpenDialog(null);
			if(returnVal == JFileChooser.APPROVE_OPTION) {
				try {
					iconI = ImageIO.read(choose.getSelectedFile());
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			iconIC = new ImageIcon(iconI);
			if(use == true){
				all.remove(p);
			}
			else{
				use = true;
			}
			p = new AlphaPanel(iconIC, 1);
			all.add(p,BorderLayout.CENTER);
			this.setBounds(this.getX(), this.getY(), iconIC.getIconWidth()+17, iconIC.getIconHeight()+117);
		}
	}

	@Override
	public void stateChanged(ChangeEvent e) {		//slider�ƥ��ť��
		JSlider source = (JSlider)e.getSource();
		if(source == opecity){
			int value = (int) source.getValue();
			//���s�]�w�Ϫ��z����
			p.setAlpha((float) 1.0 - (float) value/opecity.getMaximum());
			p.repaint();
			this.repaint();
		}
		
	}
}

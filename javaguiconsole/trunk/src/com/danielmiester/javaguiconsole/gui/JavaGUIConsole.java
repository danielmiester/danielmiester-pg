package com.danielmiester.javaguiconsole.gui;
import gnu.io.CommPort;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JTextArea;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

import com.cloudgarden.layout.AnchorConstraint;
import com.cloudgarden.layout.AnchorLayout;
import com.danielmiester.EventBasedSerialWriter;


/**
* This code was edited or generated using CloudGarden's Jigloo
* SWT/Swing GUI Builder, which is free for non-commercial
* use. If Jigloo is being used commercially (ie, by a corporation,
* company or business for any purpose whatever) then you
* should purchase a license for each developer using Jigloo.
* Please visit www.cloudgarden.com for details.
* Use of Jigloo implies acceptance of these licensing terms.
* A COMMERCIAL LICENSE HAS NOT BEEN PURCHASED FOR
* THIS MACHINE, SO JIGLOO OR THIS CODE CANNOT BE USED
* LEGALLY FOR ANY CORPORATE OR COMMERCIAL PURPOSE.
*/
public class JavaGUIConsole extends javax.swing.JFrame implements SerialPortEventListener{

	private JMenuItem helpMenuItem;
	private JMenu jMenu5;
	private JScrollPane jScrollPane1;
	private Graph canvas1;
	private JTextArea jTextArea1;
	private JMenuItem deleteMenuItem;
	private JSeparator jSeparator1;
	private JMenuItem pasteMenuItem;
	private JMenuItem copyMenuItem;
	private JMenuItem cutMenuItem;
	private JMenu jMenu4;
	private JMenuItem exitMenuItem;
	private JSeparator jSeparator2;
	private JMenuItem closeFileMenuItem;
	private JMenuItem saveAsMenuItem;
	private JMenuItem saveMenuItem;
	private JMenuItem openFileMenuItem;
	private JMenuItem newFileMenuItem;
	private JMenu jMenu3;
	private JMenuBar jMenuBar1;

	/**
	* Auto-generated main method to display this JFrame
	*/
	public static void main(String[] args) {
		System.out.println(System.getProperty("java.library.path"));
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				JavaGUIConsole inst = new JavaGUIConsole();
				inst.setLocationRelativeTo(null);
				inst.setVisible(true);
			} 
		});
	}
	
	public JavaGUIConsole() {
		super();
		initGUI();
		//$hide>>$
		try {
			connect("/dev/ttyUSB1", 300);
		} catch (Exception e) {
			
			e.printStackTrace();
		}
		//$hide<<$
	}
	
	private void initGUI() {
		try {
			{
				AnchorLayout thisLayout = new AnchorLayout();
				getContentPane().setLayout(thisLayout);
				this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
				this.addWindowListener(new WindowAdapter() {
					public void windowClosing(WindowEvent evt) {
						System.out.println("this.windowClosing, event="+evt);
						com.close();
						//TODO add your code for this.windowClosing
					}
				});
				{
					jScrollPane1 = new JScrollPane();
					getContentPane().add(jScrollPane1, new AnchorConstraint(97, 556, 1671, 0, AnchorConstraint.ANCHOR_REL, AnchorConstraint.ANCHOR_REL, AnchorConstraint.ANCHOR_REL, AnchorConstraint.ANCHOR_REL));
					jScrollPane1.setPreferredSize(new java.awt.Dimension(359, 458));
					{
						jTextArea1 = new JTextArea();
						jScrollPane1.setViewportView(jTextArea1);
						jTextArea1.setBounds(0, 0, 482, 553);
						
					}
				}
				{
					canvas1 = new Graph();
					canvas1.addMouseListener(new MouseAdapter() {
						public void mouseClicked(MouseEvent evt) {
							canvas1MouseClicked(evt);
						}
					});
				}
				this.addKeyListener(new KeyAdapter() {
					@Override
					public void keyTyped(KeyEvent evt) {
						thisKeyTyped(evt);
					}
				});
			}
			{
				jMenuBar1 = new JMenuBar();
				setJMenuBar(jMenuBar1);
				{
					jMenu3 = new JMenu();
					jMenuBar1.add(jMenu3);
					jMenu3.setText("File");
					{
						newFileMenuItem = new JMenuItem();
						jMenu3.add(newFileMenuItem);
						newFileMenuItem.setText("New");
					}
					{
						openFileMenuItem = new JMenuItem();
						jMenu3.add(openFileMenuItem);
						openFileMenuItem.setText("Open");
					}
					{
						saveMenuItem = new JMenuItem();
						jMenu3.add(saveMenuItem);
						saveMenuItem.setText("Save");
					}
					{
						saveAsMenuItem = new JMenuItem();
						jMenu3.add(saveAsMenuItem);
						saveAsMenuItem.setText("Save As ...");
					}
					{
						closeFileMenuItem = new JMenuItem();
						jMenu3.add(closeFileMenuItem);
						closeFileMenuItem.setText("Close");
					}
					{
						jSeparator2 = new JSeparator();
						jMenu3.add(jSeparator2);
					}
					{
						exitMenuItem = new JMenuItem();
						jMenu3.add(exitMenuItem);
						exitMenuItem.setText("Exit");
					}
				}
				{
					jMenu4 = new JMenu();
					jMenuBar1.add(jMenu4);
					jMenu4.setText("Edit");
					{
						cutMenuItem = new JMenuItem();
						jMenu4.add(cutMenuItem);
						cutMenuItem.setText("Cut");
					}
					{
						copyMenuItem = new JMenuItem();
						jMenu4.add(copyMenuItem);
						copyMenuItem.setText("Copy");
					}
					{
						pasteMenuItem = new JMenuItem();
						jMenu4.add(pasteMenuItem);
						pasteMenuItem.setText("Paste");
					}
					{
						jSeparator1 = new JSeparator();
						jMenu4.add(jSeparator1);
					}
					{
						deleteMenuItem = new JMenuItem();
						jMenu4.add(deleteMenuItem);
						deleteMenuItem.setText("Delete");
					}
				}
				{
					jMenu5 = new JMenu();
					jMenuBar1.add(jMenu5);
					jMenu5.setText("Help");
					{
						helpMenuItem = new JMenuItem();
						jMenu5.add(helpMenuItem);
						helpMenuItem.setText("Help");
					}
				}
			}
			pack();
			this.setSize(652, 344);
		} catch (Exception e) { 
			e.printStackTrace();
		}
	}
	private InputStream in;
	private OutputStream out;
	private CommPort com;
	//$hide>>$
	private byte[] buffer = new byte[1024];
	@Override
	public void serialEvent(SerialPortEvent ev) {
		int data;
	      
        try
        {
            int len = 0;
            while ( ( data = in.read()) > -1 )
            {
                buffer[len++] = (byte) data;
                if ( (data & 0x0f) == 0x0f ) {
                	break;
                }

            }
            jTextArea1.append(new String(buffer,0,len));
            jTextArea1.append("\n");
        }
        catch ( IOException e )
        {
            e.printStackTrace();
            System.exit(-1);
        }  
		
	}
	private void connect ( String portName, int baud ) throws Exception
    {
        CommPortIdentifier portIdentifier = CommPortIdentifier.getPortIdentifier(portName);
        if ( portIdentifier.isCurrentlyOwned() )
        {
            System.out.println("Error: Port is currently in use");
        }
        else
        {
            com = portIdentifier.open(this.getClass().getName(),2000);
            
            if ( com instanceof SerialPort )
            {
                SerialPort serialPort = (SerialPort) com;
                serialPort.setSerialPortParams(baud,SerialPort.DATABITS_8,SerialPort.STOPBITS_1,SerialPort.PARITY_NONE);
                
                in = serialPort.getInputStream();
                out = serialPort.getOutputStream();
                               
                (new Thread(new EventBasedSerialWriter(out))).start();
                
                serialPort.addEventListener(this);
                serialPort.notifyOnDataAvailable(true);

            }  
            else
            { 
                System.out.println("Error: Only serial ports are handled by this example.");
            }
        }     
    }
	//$hide<<$
	
	private void thisKeyTyped(KeyEvent evt) {
		System.out.println("this.keyTyped, event="+evt);
		try {
			out.write((byte)evt.getKeyChar());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//TODO add your code for this.keyTyped
	}
	
	private void canvas1MouseClicked(MouseEvent evt) {
		System.out.println("canvas1.mouseClicked, event="+evt);
		//TODO add your code for canvas1.mouseClicked
		Graphics g = canvas1.getGraphics();
		g.setColor(Color.BLUE);
		g.drawLine(0, 0, evt.getX(), evt.getY());
	}

}

package com.danielmiester.javaguiconsole.gui;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Rectangle;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.geom.AffineTransform;
import java.awt.geom.Path2D;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.WindowConstants;

/**
 * This code was edited or generated using CloudGarden's Jigloo SWT/Swing GUI
 * Builder, which is free for non-commercial use. If Jigloo is being used
 * commercially (ie, by a corporation, company or business for any purpose
 * whatever) then you should purchase a license for each developer using Jigloo.
 * Please visit www.cloudgarden.com for details. Use of Jigloo implies
 * acceptance of these licensing terms. A COMMERCIAL LICENSE HAS NOT BEEN
 * PURCHASED FOR THIS MACHINE, SO JIGLOO OR THIS CODE CANNOT BE USED LEGALLY FOR
 * ANY CORPORATE OR COMMERCIAL PURPOSE.
 */
public class Graph extends javax.swing.JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 3346481203133831408L;
	private boolean firstRender = true;

	/**
	 * Auto-generated main method to display this JPanel inside a new JFrame.
	 */
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setLocation(500, 300);
		frame.getContentPane().add(new Graph());
		frame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		frame.pack();
		frame.setVisible(true);
	}

	private double[] rangex = { (float) 0.0, (float) 1.0 };
	private double[] rangey = { (float) 0.0, (float) 1.0 };
	private JLabel graphLabel;
	private JLabel xAxisLabel;
	private JLabel xAxisMaximumLabel;
	private String[] axisNames = { "Foo", "Bar" };
	private JLabel xAxisMinimumLabel;
	private JLabel yAxisLabel;
	private JLabel yAxisMinLabel;
	private JLabel yAxisMaxLabel;

	public Graph() {
		super();
		initGUI();
	}

	private void initGUI() {
		try {
			GridBagLayout thisLayout = new GridBagLayout();
			thisLayout.rowWeights = new double[] {0.0, 0.0, 0.0, 0.0, 0.1};
			thisLayout.rowHeights = new int[] {22, 233, 15, 15, 20};
			thisLayout.columnWeights = new double[] { 0.0, 0.1, 0.7, 0.1 };
			thisLayout.columnWidths = new int[] { 40, 7, 7, 7 };
			this.setLayout(thisLayout);
			setPreferredSize(new Dimension(400, 300));
			{
				xAxisLabel = new JLabel();
				this.add(xAxisLabel, new GridBagConstraints(2, 3, 1, 1, 1.0,
						0.0, GridBagConstraints.SOUTH, GridBagConstraints.BOTH,
						new Insets(0, 0, 0, 0), 0, 0));
				xAxisLabel.setText(axisNames[0]);
				xAxisLabel.setHorizontalAlignment(SwingConstants.CENTER);
			}
			{
				xAxisMaximumLabel = new JLabel();
				this.add(xAxisMaximumLabel, new GridBagConstraints(3, 3, 1, 1,
						0.0, 0.0, GridBagConstraints.SOUTH,
						GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0, 0));
				xAxisMaximumLabel.setText("1.00");
				xAxisMaximumLabel.setHorizontalAlignment(SwingConstants.RIGHT);
				xAxisMaximumLabel
						.setHorizontalTextPosition(SwingConstants.RIGHT);
			}
			{
				xAxisMinimumLabel = new JLabel();
				this.add(xAxisMinimumLabel, new GridBagConstraints(1, 3, 1, 1,
						0.0, 0.0, GridBagConstraints.SOUTHWEST,
						GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0, 0));
				xAxisMinimumLabel.setText("0.00");
			}
			{
				yAxisMinLabel = new JLabel();
				yAxisMinLabel.setText("0.00");
			}
			{
				yAxisMaxLabel = new JLabel();
				yAxisMaxLabel.setText("1.00");
			}
			{
				yAxisLabel = new JLabel();
				this.add(yAxisLabel, new GridBagConstraints(0, 1, 1, 1, 0.0,
						1.0, GridBagConstraints.WEST, GridBagConstraints.BOTH,
						new Insets(0, 0, 0, 0), 0, 0));
				this.add(yAxisMinLabel, new GridBagConstraints(0, 2, 1, 1, 0.0,
						0.0, GridBagConstraints.SOUTHWEST,
						GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0, 0),
						0, 0));
				this.add(yAxisMaxLabel, new GridBagConstraints(0, 0, 1, 1, 0.0,
						0.0, GridBagConstraints.NORTHWEST,
						GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0, 0),
						0, 0));
				{
					graphLabel = new JLabel();
					this.add(graphLabel, new GridBagConstraints(0, 4, 4, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0, 0));
					graphLabel.setText("Graph Name Here");
					graphLabel.setHorizontalTextPosition(SwingConstants.CENTER);
					graphLabel.setHorizontalAlignment(SwingConstants.CENTER);
					graphLabel.setFont(getFont().deriveFont(Font.BOLD));
				}
				yAxisLabel.setText(axisNames[1]);
				yAxisLabel.setHorizontalTextPosition(SwingConstants.CENTER);
				yAxisLabel.setHorizontalAlignment(SwingConstants.CENTER);

			}
			canvas = new Rectangle(yAxisLabel.getWidth(), xAxisLabel.getY(),
					getWidth() - yAxisLabel.getWidth(), xAxisLabel.getY());
		} catch (Exception e) {
			e.printStackTrace();

		}
	}

	Rectangle canvas;

	double[][] data = { { 0, 1 }, { 0, 0 }, { 1, 0 }, { 0, 1 },
			{ 50, 50 } };

	// $hide>>$
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		debug("PC");
		thisComponentResized(null);
		first_render(g);

		Graphics2D gg = (Graphics2D) g.create(canvas.x, canvas.y, canvas.width+1,
				canvas.height+1);
		
		drawGraph(gg);
		//g.draw3DRect(canvas.x, canvas.y, canvas.width,canvas.height,false);
		
		
	}

	private void drawGraph(Graphics2D gg) {
		Path2D.Double p = new Path2D.Double();
		boolean first = true;
		for (double[] d : data) {
			if (first) {
				first = false;
				p.moveTo(d[0], d[1]);
			} else {
				p.lineTo(d[0], d[1]);
			}
		}
		gg.setColor(Color.red);
		AffineTransform a = new AffineTransform();
		a.scale(((double) canvas.width) / (rangex[1] - rangex[0]),
				-((double) canvas.height) / (rangey[1] - rangey[0]));
		a.translate(0, -rangey[1]);
		gg.draw(a.createTransformedShape(p));
		
	}

	// $hide<<$
	private void first_render(Graphics g) {
		if (firstRender) {
			firstRender = false;
			if (!java.beans.Beans.isDesignTime()) {
				Font f = yAxisLabel.getFont();
				float h = f.getLineMetrics(yAxisLabel.getText(),
						((Graphics2D) getGraphics()).getFontRenderContext())
						.getHeight()/2;
				AffineTransform a = f.getTransform();
				a.quadrantRotate(-1, h, 0);
				f = f.deriveFont(a);
				yAxisLabel.setFont(f);
			}
		}
	}
	
	private void thisComponentResized(ComponentEvent evt) {
		canvas.x = yAxisLabel.getWidth();
		canvas.width = getWidth() - yAxisLabel.getWidth() ;
		canvas.height = getHeight()-xAxisLabel.getHeight();
	}
	private void debug(String out)
	{
		System.out.println(out+":"+ System.currentTimeMillis());
	}

}

import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ventana extends JFrame{
  static String datos[][];
  static JTable tabla;
  static String[] columnNames={"Dato","Valor"};
  static JPanel panelTable;
  public Ventana() {
  	super("Medidas de Tendencia");
  	setSize (800,500);
  	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setResizable(true);
    setLayout(new GridLayout(3,1));
    PIngresarDatos ingD=new PIngresarDatos();
    this.add(ingD);
    panelTable=new JPanel();
    panelTable.setLayout(new BorderLayout());
    this.add(panelTable);
    ManejadorEventos Eventos=new ManejadorEventos();
    PIngresarDatos.imprimir.addActionListener(Eventos);
    Calcular media=new Calcular();
    this.add(media);
    media.calcula.addActionListener(Eventos);
  }
}

import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class VentanaP extends JFrame{
  static JTextField formulaGUI;
  static JPanel panelRespuesta;
  static JPanel panelRespuesta1=new JPanel();
  static JButton calcula=new JButton("Calcular");
  static JButton calcula1=new JButton("Calcular");
  static JButton calcula2=new JButton("Calcular");
  static JTextField texto1=new JTextField(10);
  static JTextField texto2=new JTextField(10);
  static JTable tabla;
  static String datos[][];
  static String[] nombres={"Punto","Evaluada"};
  public VentanaP(){
    super("Radio");
  	setSize (800,500);
  	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setResizable(true);
    setLayout(new GridLayout(2,1));
    Panelarriba pan=new Panelarriba();
    add(pan);
    panelRespuesta=new JPanel();
    this.add(panelRespuesta);
    panelRespuesta.setLayout(new GridLayout(2,1));
    ManejadorEventos Eventos=new ManejadorEventos();
    Radio.aplicar.addActionListener(Eventos);
    calcula.addActionListener(Eventos);
    calcula1.addActionListener(Eventos);
    calcula2.addActionListener(Eventos);
  }
}

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

public class PIngresarDatos extends JPanel{
  static JLabel texto1;
  static JTextField numvalores;
  static JButton imprimir;
  PIngresarDatos(){
    texto1=new JLabel("Numero de Datos",SwingConstants.CENTER);
    texto1.setBounds(20,22,12,25);
    add(texto1);
    numvalores=new JTextField("Cantidad de valores",20);
    numvalores.setBounds(140,22,120,25);
    add(numvalores);
    imprimir=new JButton("Ingresar Datos");
    imprimir.setBounds(265,22,120,25);
    add(imprimir);
  }
}

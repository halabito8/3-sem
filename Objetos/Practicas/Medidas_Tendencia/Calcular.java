import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;

public class Calcular extends JPanel{
  static JButton calcula;
  static JLabel medida;
  public Calcular(){
    calcula=new JButton("Calc");
    add(calcula);
    medida=new JLabel("El valor de la media es: ");
    add(medida);
  }
}

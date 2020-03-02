import java.awt.Color;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

public class PanelCuadradoDatos extends JPanel
{
  static JTextField Lado;
  static JButton Area, Volumen;
  PanelCuadradoDatos()
  {
    setLayout(new GridLayout(4,2));
    add(new JLabel(""));
    add(new JLabel(""));
    add(new JLabel("LADO:",SwingConstants.CENTER));
    Lado = new JTextField("",3);
    add(Lado);
    Area = new JButton("Área");
    Volumen = new JButton("Volumen");
    add(Area);
    add(Volumen);
    add(new JLabel(""));
    add(new JLabel(""));
  }
}

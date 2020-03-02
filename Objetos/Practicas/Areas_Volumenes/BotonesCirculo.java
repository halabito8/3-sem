import java.awt.*;
import javax.swing.*;

public class BotonesCirculo extends JPanel{
  static JTextField Radio;
  static JButton Area, Volumen;
  BotonesCirculo(){
    setLayout(new GridLayout(4,2));
    add(new JLabel(""));
    add(new JLabel(""));
    add(new JLabel("Radio:",SwingConstants.CENTER));
    Radio = new JTextField("",3);
    add(Radio);
    Area = new JButton("Área");
    Volumen = new JButton("Volumen");
    add(Area);
    add(Volumen);
    add(new JLabel(""));
    add(new JLabel(""));
  }
}

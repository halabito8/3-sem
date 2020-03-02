import java.awt.*;
import javax.swing.*;

public class BotonesCuadrado extends JPanel{
  static JTextField Lado;
  static JButton Area, Volumen;
  BotonesCuadrado(){
    setLayout(new GridLayout(4,2));
    add(new JLabel(""));
    add(new JLabel(""));
    add(new JLabel("Lado:",SwingConstants.CENTER));
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

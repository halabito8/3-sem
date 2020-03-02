import java.awt.*;
import javax.swing.*;

public class BotonesTriangulo extends JPanel{
  static JTextField Base,Altura;
  static JButton Area, Volumen;
  BotonesTriangulo(){
    setLayout(new GridLayout(4,2));
    add(new JLabel("Altura:",SwingConstants.CENTER));
    Altura=new JTextField("",3);
    add(Altura);
    add(new JLabel("Base:",SwingConstants.CENTER));
    Base = new JTextField("",3);
    add(Base);
    Area = new JButton("Área");
    Volumen = new JButton("Volumen");
    add(Area);
    add(Volumen);
    add(new JLabel(""));
    add(new JLabel(""));
  }
}

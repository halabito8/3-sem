import javax.swing.*;
import java.awt.*;

public class Form extends JPanel{
  public Form(){
    VentanaP.formulaGUI=new JTextField("2X2-5X+3",30);
    add(VentanaP.formulaGUI);
  }
}

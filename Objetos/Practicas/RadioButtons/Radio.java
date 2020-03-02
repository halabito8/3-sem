import javax.swing.*;
import java.awt.*;

public class Radio extends JPanel{
  static JRadioButton integral,punto,parametros;
  static JButton aplicar;
  static JTextField formula;
  public Radio(){
    setLayout(new FlowLayout());
    integral=new JRadioButton("Integral");
    punto=new JRadioButton("Evaluar un Punto");
    parametros=new JRadioButton("Evaluar entre dos numeros");
    ButtonGroup grupo=new ButtonGroup();
    grupo.add(integral);
    grupo.add(punto);
    grupo.add(parametros);

    add(integral);
    add(punto);
    add(parametros);
    aplicar=new JButton("Aplicar");
    add(aplicar);
  }
}

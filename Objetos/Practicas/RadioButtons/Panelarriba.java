import javax.swing.*;
import java.awt.*;

public class Panelarriba extends JPanel{
  static JLabel Opciones;
  public Panelarriba(){
    setLayout(new GridLayout(3,1));
    Opciones=new JLabel("Ingrese una formula cuadratica y seleccione una opcion:");
    Font fuente=new Font("TimesRoman-Bold",1,25);
    Opciones.setFont(fuente);
    add(Opciones);
    Form hola=new Form();
    add(hola);
    Radio panelR=new Radio();
    add(panelR);
  }
}

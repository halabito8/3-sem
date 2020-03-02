import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ventana extends JFrame {
  public Ventana() {

  	super("Figuras");
  	setSize (800,500);
  	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setResizable(true);
    setLayout(new GridLayout(1,2));
    Imagenes obj=new Imagenes();
    Datos obj2=new Datos();
    this.add(obj);
    this.add(obj2);
  }
}

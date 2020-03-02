import java.awt.*;
import javax.swing.*;

class Imagenes extends JPanel{
  public Imagenes(){
    setSize(600,200);
    setLayout(new GridLayout(3,2));
    JLabel etiqueta=new JLabel();
    Icon imagen = new ImageIcon (getClass().getResource ("cuadrado.png"));
    etiqueta = new JLabel ("",imagen, SwingConstants.CENTER);
    this.add(etiqueta);
    Icon imagen4 = new ImageIcon (getClass().getResource ("cubo.jpg"));
    etiqueta = new JLabel ("",imagen4, SwingConstants.CENTER);
    this.add(etiqueta);
  	Icon imagen2 = new ImageIcon (getClass().getResource ("triangulo.png"));
    etiqueta = new JLabel ("",imagen2, SwingConstants.CENTER);
    this.add(etiqueta);
    Icon imagen5 = new ImageIcon (getClass().getResource ("piramide.jpg"));
    etiqueta = new JLabel ("",imagen5, SwingConstants.CENTER);
    this.add(etiqueta);
    Icon imagen3 = new ImageIcon (getClass().getResource ("Circulo.jpg"));
    etiqueta = new JLabel ("",imagen3, SwingConstants.CENTER);
    this.add(etiqueta);
    Icon imagen6 = new ImageIcon (getClass().getResource ("esfera.jpg"));
    etiqueta = new JLabel ("",imagen6, SwingConstants.CENTER);
    this.add(etiqueta);
  }
}

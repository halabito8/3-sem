import java.awt.*;
import javax.swing.*;

class Flow extends JPanel{
  public Flow(){
    setSize(600,200);
    setBackground(Color.yellow);
    JLabel etiqueta=new JLabel("Nombre: ");
    etiqueta.setToolTipText("Nombre del usuario: ");
    JTextField texto=new JTextField(10);
    JButton boton=new JButton("Aceptar");
    setLayout(new FlowLayout());
    this.add(etiqueta);
    this.add(texto);
    this.add(boton);
  }
}

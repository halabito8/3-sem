import java.awt.*;
import javax.swing.*;

class Border extends JPanel{
  public Border(){
    setSize(600,200);
    JButton boton1=new JButton("Izq");
    JButton boton2=new JButton("Der");
    JButton boton3=new JButton("Arriba");
    JButton boton4=new JButton("Abajo");
    JButton boton5=new JButton("Centro");
    setLayout(new BorderLayout(5,2));
    this.add(boton1,BorderLayout.WEST);
    this.add(boton2,BorderLayout.EAST);
    this.add(boton3,BorderLayout.NORTH);
    this.add(boton4,BorderLayout.SOUTH);
    this.add(boton5,BorderLayout.CENTER);
  }
}

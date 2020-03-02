import java.awt.*;
import javax.swing.*;

class Grid extends JPanel{
  public Grid(){
    setSize(600,200);
    setBackground(Color.green);
    JButton boton2=new JButton("B2");
    JButton boton5=new JButton("B5");
    setLayout(new GridLayout(2,3));
    Border obj3=new Border();
    Flow obj=new Flow();
    Border obj4=new Border();
    Flow obj5=new Flow();
    this.add(obj4);
    this.add(boton2);
    this.add(obj5);
    this.add(obj);
    this.add(boton5);
    this.add(obj3);
  }
}

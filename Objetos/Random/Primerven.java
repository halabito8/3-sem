import javax.swing.*;
import java.awt.*;

public class Primerven extends JFrame{
  public Primerven(){
    super("Titulo");
    setSize(700,700);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLocation(300,300);
    setResizable(true);
    Flow obj=new Flow();
    Grid obj2=new Grid();
    Border obj3=new Border();
    setLayout(new GridLayout(1,1));
    this.add(obj);
    this.add(obj2);
    this.add(obj3);
  }
}

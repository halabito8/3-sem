import java.awt.*;
import javax.swing.*;

public class Datos extends JPanel{
  public Datos(){
    ManejadorEventos Evento=new ManejadorEventos();
    setSize(600,200);
    setLayout(new GridLayout(3,2));
    BotonesCuadrado bcuadrado=new BotonesCuadrado();
    this.add(bcuadrado);
    ResCuadrado rcuadrado=new ResCuadrado();
    this.add(rcuadrado);
    BotonesTriangulo btriangulo=new BotonesTriangulo();
    this.add(btriangulo);
    ResTriangulo rtriangulo=new ResTriangulo();
    this.add(rtriangulo);
    BotonesCirculo bcirculo=new BotonesCirculo();
    this.add(bcirculo);
    ResCirculo rcirculo=new ResCirculo();
    this.add(rcirculo);
    BotonesCuadrado.Area.addActionListener(Evento);
    BotonesCuadrado.Volumen.addActionListener(Evento);
    BotonesTriangulo.Area.addActionListener(Evento);
    BotonesTriangulo.Volumen.addActionListener(Evento);
    BotonesCirculo.Area.addActionListener(Evento);
    BotonesCirculo.Volumen.addActionListener(Evento);
  }
}

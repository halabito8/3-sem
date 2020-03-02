import java.lang.*;
import java.util.ArrayList;

public class Practica14{
  public static void main(String []args){
    Thread clock=new Semaforo();
    ArrayList<Runnable> events=new ArrayList<>();
    events.add(new colores(30,"Verde"));
    events.add(new colores(10,"Amarillo"));
    events.add(new colores(5,"Rojo"));
    clock.start();
    for(Runnable e:events)
      new Thread(e).start();
  }
}

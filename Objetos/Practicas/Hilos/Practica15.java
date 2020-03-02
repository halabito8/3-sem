import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;

public class Practica15{
  public static void main(String [] args){
    ArregloSimple arrsmp =new ArregloSimple(8);
    EscritorArreglo escritor1=new EscritorArreglo(5,arrsmp,4);
    EscritorArreglo escritor2=new EscritorArreglo(10,arrsmp,3);
    EscritorArreglo escritor3=new EscritorArreglo(20,arrsmp,1);
    ExecutorService ejecutor = Executors.newCachedThreadPool();
    ejecutor.execute(escritor1);
    ejecutor.execute(escritor2);
    ejecutor.execute(escritor3);
    ejecutor.shutdown();
    try{
      boolean tareas=ejecutor.awaitTermination(1,TimeUnit.MINUTES);
      if(tareas)
        System.out.println(arrsmp);
      else
          System.out.println("Se acabo el tiempo");
    }catch(InterruptedException ex){
      System.out.println("Hola");
    }
  }
}

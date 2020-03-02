import java.lang.Runnable;

public class EscritorArreglo implements Runnable{
  private final ArregloSimple arregloCompartido;
  private final int valorInicial;
  private final int cantidad;
  public EscritorArreglo(int valor,ArregloSimple arreglo,int can){
    valorInicial=valor;
    arregloCompartido=arreglo;
    cantidad=can;
  }
  public void run(){
    for(int i=valorInicial;i<valorInicial+cantidad;i++)
      arregloCompartido.agregar(i);
  }
}

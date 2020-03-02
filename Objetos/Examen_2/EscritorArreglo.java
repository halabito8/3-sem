 import java.lang.Runnable;

public class EscritorArreglo implements Runnable{
  private final ArregloSimple arregloCompartido;
  private final int valorInicial;
  private final int cantidad,empieza;
  public EscritorArreglo(int valor,ArregloSimple arreglo,int can,int empiez){
    valorInicial=valor;
    arregloCompartido=arreglo;
    cantidad=can;
    empieza=empiez;
  }
  public void run(){
    for(int i=0;i<cantidad;i++)
      arregloCompartido.agregar(valorInicial,empieza+i);
  }
}

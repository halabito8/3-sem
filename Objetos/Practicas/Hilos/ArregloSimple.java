import java.util.Random;

public class ArregloSimple{
  private final int arreglo[];
  private int indice=0;
  private final static Random gen=new Random();
  public ArregloSimple(int tamano){
    arreglo=new int[tamano];
  }
  public synchronized void agregar(int valor){
    int posicion=indice;
    arreglo[posicion]=valor;
    System.out.printf("%s escribio %2d en el elemento %d\n",Thread.currentThread().getName(),valor,posicion);
    ++indice;
    System.out.printf("Siguiente indice de escritura: %d\n", indice);
  }
  public String toString(){
    String cadenaArreglo="\nContenido Arreglo\n";
    for(int i=0;i<arreglo.length;i++)
      cadenaArreglo+=arreglo[i]+" ";
    return cadenaArreglo;
  }
}

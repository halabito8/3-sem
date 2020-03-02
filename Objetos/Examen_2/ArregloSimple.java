 import java.util.Random;

public class ArregloSimple{
  private final int arreglo[];
  private int indice=0;
  private final static Random gen=new Random();
  private char letra='F';
  public ArregloSimple(int tamano){
    arreglo=new int[tamano];
  }
  public synchronized void agregar(int valor,int empieza){
    int posicion=empieza;
    arreglo[posicion]=valor;
    if(valor==1)
      letra='A';
    if(valor==2)
      letra='B';
    if(valor==3)
      letra='C';
    System.out.printf("%s UN AUTO %c en el cajon %d\n",Thread.currentThread().getName(),letra,posicion);
    ++empieza;
  }
  public String toString(){
    String cadenaArreglo="\nAsi quedaron estacionados\n";
    for(int i=0;i<arreglo.length;i++){
      if(arreglo[i]==1)
        letra='A';
      if(arreglo[i]==2)
        letra='B';
      if(arreglo[i]==3)
        letra='C';
      cadenaArreglo+=letra+" ";
    }
    return cadenaArreglo;
  }
}

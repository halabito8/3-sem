import java.util.*;

public class Estadistica{

  static Scanner scan=new Scanner(System.in);

  public static void main(String []args){
    int op,posicion;
    float[] arreglo={88,45,53,86,33,86,85,30,89,53,41,96,56,38,62,
                  71,51,86,68,29,28,47,33,37,25,36,33,94,73,46,
                  42,34,79,72,88,99,82,62,57,42,28,55,67,62,60,
                  96,61,57,75,93,34,75,53,32,28,73,51,69,91,35};
    int i;
    Metodos obj=new Metodos();
    arreglo=obj.ordenar(arreglo);
    // for(i=0;i<arreglo.length;i++)
    //   System.out.println(arreglo[i]);
    System.out.println("Que se quiere sacar?(Escribir el numero,percentil 100,cuartil 4,decil 10)");
    op=scan.nextInt();
    System.out.println("Que posicion?");
    posicion=scan.nextInt();
    if(op<posicion)
      System.out.println("Eso es imposible");
    else
      System.out.println("El numero que buscas es: "+obj.cuart(arreglo,op,posicion));
  }
}

import java.util.*;

public class Practica7{

  static Scanner scan=new Scanner(System.in);

  public static void main(String [] args){
    MetodosP7 obj=new MetodosP7();
    int max,suma=0,i;
    System.out.println("Cuantos datos se van a ingresar?");
    max=scan.nextInt();
    int[] arreglo=new int[max];
    int[][] frecuencias=new int[max][2];
    for(i=0;i<max;i++){
      System.out.println("Cual es el numero en la posicion "+i);
      arreglo[i]=scan.nextInt();
    }
    System.out.println("El promedio del arreglo es: "+obj.prom(arreglo));
    Arrays.sort(arreglo);
    frecuencias=obj.tablafrecuencias(arreglo,max);
    System.out.println("La media de frecuencia es: "+obj.mediaf(frecuencias));
    obj.median(arreglo);
  }
}

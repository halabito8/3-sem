import java.util.*;

public class Metodos{
  public static float [] ordenar(float arreglo[]){
    Arrays.sort(arreglo);
    return arreglo;
  }
  public static float cuart(float arreglo[],int op,int posicion){
    float i,comparar,resultado;
    int j;
    i=(60*posicion)/op;
    comparar=i;
    Math.ceil(comparar);
    if(i==comparar){
      j=Math.round(i);
      resultado=(arreglo[j-1]+arreglo[j])/2;
    }
    else{
      j=Math.round(comparar);
      resultado=arreglo[j];
    }
    return resultado;
  }
}

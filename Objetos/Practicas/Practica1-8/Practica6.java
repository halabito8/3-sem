import java.util.*;

public class Practica6{

static Scanner scan=new Scanner(System.in);

  public static void main(String [] args){
    double formula[]=new double[10];
    float intervalo,suma=0,xi,xf,area=0,i;
    int exponencial,j;
    System.out.println("Cual es el grado mayor de la ecuacion?");
    exponencial=scan.nextInt();
    for(j=exponencial;j>=0;j--){
      System.out.println("Cual es el numero x^"+j);
      formula[j]=scan.nextInt();
    }
    System.out.println("Desde que valor de x?");
    xi=scan.nextFloat();
    System.out.println("Hasta que valor de x?");
    xf=scan.nextFloat();
    System.out.println("Cual es el intervalo?");
    intervalo=scan.nextFloat();
    for(i=xi;i<=xf;i+=intervalo){
      suma=0;
      for(j=formula.length-1;j>=0;j--)
        suma+=(formula[j]*Math.pow(i,j));
      area+=intervalo*suma;
    }
    System.out.println("El area debajo de la curva es: "+area);
  }
}

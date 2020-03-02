import java.util.Scanner;

public class Practica5{

  static Scanner scan=new Scanner(System.in);

  public static void main(String [] args){
    double a,b,c;
    System.out.println("ingrese el valor de ax^2");
    a=scan.nextFloat();
    System.out.println("ingrese el valor de bx");
    b=scan.nextFloat();
    System.out.println("ingrese el valor de c");
    c=scan.nextFloat();
    MetodosP5 obj1= new MetodosP5();
    if(obj1.raiz(a,b,c)>0&&a!=0){
      System.out.println("Los puntos que corta al eje x son x1="+obj1.xpos(a,b,c)+" x2="+obj1.xneg(a,b,c));
      System.out.println("Las coordenadas del vertice son "+obj1.xver(a,b)+","+obj1.yver(a,b,c));
      if(a<0)
        System.out.println("La parabola abre para abajo");
      else
        System.out.println("La parabola abre para arriba");
    }
    else
      System.out.println("Error, me rompiste");
  }
}

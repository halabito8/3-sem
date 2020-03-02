import java.util.Scanner;

public class Practica3{
  static float x0,x1,y0,y1,m1,b1,m2,b2,interx,intery;
  static boolean paralela;
  static Scanner scan=new Scanner(System.in);

  public static void main(String[] args){
    MetodosP3 Obj1=new MetodosP3();
    System.out.println("Cual es el valor de x0, de la recta 1?");
    x0=scan.nextFloat();
    System.out.println("Cual es el valor de y0, de la recta 1?");
    y0=scan.nextFloat();
    System.out.println("Cual es el valor de x1, de la recta 1?");
    x1=scan.nextFloat();
    System.out.println("Cual es el valor de y1, de la recta 1?");
    y1=scan.nextFloat();
    m1=Obj1.setpendiente(x0,x1,y0,y1);
    b1=Obj1.setordenada(x0,y0,m1);
    System.out.println("Cual es el valor de x0, de la recta 2?");
    x0=scan.nextFloat();
    System.out.println("Cual es el valor de y0, de la recta 2?");
    y0=scan.nextFloat();
    System.out.println("Cual es el valor de x1, de la recta 2?");
    x1=scan.nextFloat();
    System.out.println("Cual es el valor de y1, de la recta 2?");
    y1=scan.nextFloat();
    m2=Obj1.setpendiente(x0,x1,y0,y1);
    b2=Obj1.setordenada(x0,y0,m2);
    interx=Obj1.intersectarx(m1,b1,m2,b2);
    intery=Obj1.intersectary(m1,b1,interx);
    System.out.println("La formula es y1="+Obj1.getpendiente(m1)+"x+"+Obj1.getordenada(b1));
    System.out.println("La formula es y2="+Obj1.getpendiente(m2)+"x+"+Obj1.getordenada(b2));
    if(m1==m2){
      System.out.println("Las rectas son paralelas");
      System.out.println("Las rectas no tienen iterseccion");
    }
    else{
      System.out.println("Las rectas no son paralelas");
      System.out.println("Las rectas tienen iterseccion en "+interx+","+intery);
      System.out.println("Y tienen un angulo entre ellas de "+Math.toDegrees(Math.atan((m2-m1)/(1+m1*m2))));
    }
  }
}

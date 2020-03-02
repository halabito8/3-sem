import java.util.Scanner;

public class Practica4{
  static Scanner scan=new Scanner(System.in);
  static final double g=9.81;
  public static void main(String [] args){
    float masa,altura,velocidad;
    System.out.println("Cual es la masa?");
    masa=scan.nextFloat();
    System.out.println("Cual es la altura?");
    altura=scan.nextFloat();
    System.out.println("Cual es la velocidad?");
    velocidad=scan.nextFloat();
    MetodosP4 obj1=new MetodosP4(masa,altura,velocidad);
    obj1.setpotencial(g);
    obj1.setcinetica();
    System.out.println("La energia potencial es: "+obj1.getpotencial()+" Joules");
    System.out.println("La energia cinetica es: "+obj1.getcinetica()+" Joules");
  }
}

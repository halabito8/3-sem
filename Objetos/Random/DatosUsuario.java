import java.util.Scanner;

public class DatosUsuario{
  static Scanner scan=new Scanner(System.in);

  public static void main(String[] args){
    System.out.print("Ingresa un valor entero: ");
    int x=scan.nextInt();
    System.out.println("Valor del entero ingresado: "+(x+4));
  }
}

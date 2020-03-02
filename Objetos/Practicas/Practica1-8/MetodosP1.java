import java.util.Scanner;
import java.lang.*;

public class MetodosP1{
  static Scanner sc=new Scanner(System.in);
  static String palabra;
  static int largo;
  CharSequence a="a";
  public void Comienzo(){
    System.out.print("Ingresa un enunciado: ");
    palabra=sc.next();
  }
  public void Cuantos(){
    largo=palabra.length();
    System.out.println("El String tiene "+largo);
  }
  public void PyU(){
    System.out.println("El primer caracter es: "+palabra.charAt(0));
    System.out.println("El ultimo caracter es: "+palabra.charAt(largo-1));
  }
  public void Checar(){
    boolean validar=palabra.contains(a);
    System.out.println("El caracter contine el caracter a: "+validar);
  }
}

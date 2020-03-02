import java.util.*;

public class Practica8{

  static Scanner scan=new Scanner(System.in);

  public static void main(String [] args){
    int dado,adivinar,op=1,puntos=0,partidas=0;
    double aux;
    do{
      dado=(int)(Math.random()*6+1);
      do{
        System.out.println("Que numero crees que tiraste?");
        adivinar=scan.nextInt();
        if(adivinar<1||adivinar>6)
          System.out.println("El dado solo tiene 6 caras");
      }while(adivinar<1||adivinar>6);
      if(dado==adivinar){
        puntos++;
        System.out.println("Adivinaste!");
      }
      else
        System.out.println("No adivinaste, el numero que salio fue "+dado);
      System.out.println("Si quieres seguir jugando ingresa un 1 si no teclea otro numero");
      op=scan.nextInt();
      partidas++;
    }while(op==1);
    System.out.println("De "+partidas+" partidas adivinaste "+puntos);
  }
}

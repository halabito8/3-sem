import javax.swing.JOptionPane;
import java.util.Scanner;

public class MensajeSaludo{
  public void saludos(){
    System.out.print("\033[H\033[2J");
    System.out.flush();
    System.out.println("\nElias es gay\n");
    //JOptionPane.showMessageDialog(null,"Ping","Muy bien tu?",JOptionPane.INFORMATION_MESSAGE);
  }
  public void adios(){
    System.out.println("\n\nA nosierto\nEs super gay\n");
  }
}

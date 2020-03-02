import javax.swing.*;

public class Practica2{
  public static void main(String[] args){
    String dialogo,dialogo2;
    int pescadores,peces,persona=0,sobrantes=0;
    dialogo=JOptionPane.showInputDialog("Ingresa el numero de pescadores");
    pescadores=Integer.parseInt(dialogo);
    dialogo2=JOptionPane.showInputDialog("Ingresa el numero de peces");
    peces=Integer.parseInt(dialogo2);
    MetodosP2 obj=new MetodosP2();
    persona=obj.corresponde(pescadores,peces);
    sobrantes=obj.sobrantes(pescadores,peces);
    JOptionPane.showMessageDialog(null,"Peces por persona: "+persona+"\nSobrantes: "+sobrantes,"Pescadores",JOptionPane.INFORMATION_MESSAGE);
  }
}

import javax.swing.*;

public class PruebaObtenerVentana{
  public static void main(String[] args){
    String datoentrada;
    datoentrada=JOptionPane.showInputDialog("Ingresa un numero");
    int k,j=2,rescero,restres;
    double resuno,a=3,b=2,resdos;
    k=Integer.parseInt(datoentrada);
    JOptionPane.showMessageDialog(null,k,"Valor usuario",JOptionPane.INFORMATION_MESSAGE);
    rescero=k/j;
    resuno=k/j;
    resdos=a/b;
    restres=3*2;
    System.out.println(rescero);
    System.out.println(resuno);
    System.out.println(resdos);
    System.out.println(restres);
  }
}

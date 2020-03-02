public class ClaseBienvenida{

  final static int DIAS=7;
  public static String Mensaje1="Asicierto";
  static int x=1,y=6,z=7;
  
  public static void main(String args[]){
    MensajeSaludo Objeto1=new MensajeSaludo();
    Objeto1.saludos();
    Objeto1.adios();
    System.out.println("Varias cosas o whatever "+x+" "+(y+z));
    System.out.println(Mensaje1);
  }
}

public class colores implements Runnable{
  private int time;
  private String colour;
  public colores(int tiempo,String color){
    this.time=tiempo;
    this.colour=color;
  }
  public void run(){
    try{
      Thread.sleep(30000-(time*1000));
    }catch(InterruptedException e){
    }
    System.out.println(colour);
  }
}

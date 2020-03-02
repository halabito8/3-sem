public class Semaforo extends Thread{
  public void run(){
    for(int t=30;t>=0;t--){
      try{
        System.out.println("T menos "+t);
        Thread.sleep(1000);
      }catch(InterruptedException e){
      }
    }
  }
}

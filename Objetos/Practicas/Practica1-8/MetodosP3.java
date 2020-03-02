public class MetodosP3{
  public float setpendiente(float x0,float x1,float y0,float y1){
    return (y1-y0)/(x1-x0);
  }
  public float getpendiente(float m){
    return m;
  }
  public float setordenada(float x0,float y0,float m){
    return y0-x0*m;
  }
  public float getordenada(float b){
    return b;
  }
  public float intersectarx(float m1,float b1,float m2,float b2){
    return (b2-b1)/(m1-m2);
  }
  public float intersectary(float m1,float b1,float x){
    return m1*x+b1;
  }
}

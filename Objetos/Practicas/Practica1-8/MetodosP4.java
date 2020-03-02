public class MetodosP4{
  static double m,h,v,c,p,val1,val2,val3;
  public MetodosP4(double val1,double val2,double val3){
    m=val1;
    h=val2;
    v=val3;
  }
  public void setpotencial(double g){
    p=m*g*h;
  }
  public void setcinetica(){
    c=(m*v*v)/2;
  }
  public double getcinetica(){
    return c;
  }
  public double getpotencial(){
    return p;
  }
}

public class MetodosP5{
  static double a,b,c,disc,temp1,temp2;
  public double raiz(double a,double b,double c){
    return (b*b)-(4*a*c);
  }
  public double xpos(double a,double b,double c){
    disc=(b*b)-(4*a*c);
    disc=Math.sqrt(disc);
    b=b*-1;
    return (b+disc)/(2*a);
  }
  public double xneg(double a,double b,double c){
    disc=(b*b)-(4*a*c);
    disc=Math.sqrt(disc);
    b=b*-1;
    return (b-disc)/(2*a);
  }
  public double xver(double a,double b){
    return -b/(2*a);
  }
  public double yver(double a,double b,double c){
    disc=-b/(2*a);
    temp1=a*(disc*disc);
    temp2=b*disc;
    return temp1+temp2+c;
  }
}

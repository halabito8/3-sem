public class Respuestas{
  public double Integral(double[] arreglo,int liminf,int limsup){
    double suma=0,area=0,i,intervalo=.00001;
    int j;
    for(i=liminf;i<=limsup;i+=intervalo){
      suma=0;
      for(j=arreglo.length-1;j>=0;j--)
        suma+=(arreglo[j]*Math.pow(i,j));
      area+=intervalo*suma;
    }
    return area;
  }
  public double Unpunto(double[] arreglo,int x){
    int j;
    double suma=0;
    for(j=arreglo.length-1;j>=0;j--)
      suma+=(arreglo[j]*Math.pow(x,j));
    return suma;
  }
}

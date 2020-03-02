public class MetodosP7{
  static int maxf=1;
  public double prom(int arreglo[]){
    int i;
    double suma=0;
    for(i=0;i<arreglo.length;i++){
      suma+=arreglo[i];
    }
    return (suma/arreglo.length);
  }
  public int[][] tablafrecuencias(int arreglo[],int max){
    int contador=1,j=0,i;
    int[][] frecuencias=new int[max][2];
    for(i=1;i<arreglo.length;i++){
      if(arreglo[i]==arreglo[i-1])
        contador++;
      else{
        frecuencias[j][0]=arreglo[i-1];
        frecuencias[j][1]=contador;
        j++;
        contador=1;
        maxf++;
      }
    }
    frecuencias[j][0]=arreglo[i-1];
    if(contador>1)
      frecuencias[j][1]=contador;
    else
      frecuencias[j][1]=1;
    for(i=0;i<maxf;i++)
      System.out.println(frecuencias[i][0]+"   "+frecuencias[i][1]);
    return frecuencias;
  }
  public double mediaf(int[][] frecuencias){
    int i;
    double suma=0,sumaf=0;
    for(i=0;i<maxf;i++){
      suma+=frecuencias[i][0]*frecuencias[i][1];
    }
    for(i=0;i<maxf;i++)
      sumaf+=frecuencias[i][1];
    return suma/sumaf;
  }
  public void median(int arreglo[]){
    double mediana,j;
    int i;
    if(arreglo.length%2==1)
      System.out.println("La mediana es: "+arreglo[arreglo.length/2]);
    else{
      i=arreglo.length/2;
      mediana=(double)(arreglo[i]+arreglo[i+1])/2;
      System.out.println("La mediana es: "+mediana);
    }
  }
}

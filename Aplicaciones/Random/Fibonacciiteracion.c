#include<stdio.h>
#include<time.h>

int main(void){
  int iteracion,i;
  double n1=0,n2=1,Fibonacci;
  clock_t empieza=0,acaba=0;
  double diferencia=0;
  FILE *archivo;
  archivo=fopen("iteracion.txt","at");
  empieza=clock();
  printf("%f\n",(double)(empieza));
  for(iteracion=1;iteracion<101;iteracion++){
    Fibonacci=n1+n2;
    n1=n2;
    n2=Fibonacci;
    acaba=clock();
    diferencia=(double)(acaba-empieza)/CLOCKS_PER_SEC;
    fprintf(archivo,"%i %f\n",iteracion,diferencia);
  }
  fclose(archivo);
  return 0;
}

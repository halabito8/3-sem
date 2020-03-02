#include<stdio.h>
#include<time.h>

double Recursivo(int n);

int main(void){
  int iteracion,cuantos=0;
  double Fibonacci;
  clock_t empieza=0,acaba=0;
  double diferencia=0;
  FILE *archivo;
  empieza=clock();
  for(iteracion=1;iteracion<101;iteracion++){
    Fibonacci=Recursivo(iteracion);
    acaba=clock();
    printf("%e\n",Fibonacci);
    diferencia=(double)(acaba-empieza)/CLOCKS_PER_SEC;
    archivo=fopen("recursivo.txt","at");
    fprintf(archivo,"%i %f\n",iteracion,diferencia);
    fclose(archivo);
  }
  return 0;
}

double Recursivo(int n){
  if(n==0)
    return 0;
  else if(n==1)
    return 1;
  else
    return(Recursivo(n-1)+Recursivo(n-2));
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct resultados{//lista dinamica que almacena en tiempo el eje x (tiempo), en final el eje y (f(t))
  float tiempo,final;
  struct resultados *sig;
}resultados;

void Pedirdatos(float *amplitud,float *frecuencia,int *numharmonicos,float *tiempofinal,float *puntos);
void Resolver(float amplitud,float frecuencia,int numharmonicos,float tiempofinal,resultados **inicio,float puntos);
void Escribir(resultados *inicio);
void Borrarlista(resultados *Inicio);
float Sumatoria(float amplitud,float deltaf,float i,float frecuencia,int numharmonicos);
void Plot(int num);

int main(void){
  resultados *inicio;
  float amplitud,frecuencia,tiempofinal,puntos;
  int numharmonicos;
  Pedirdatos(&amplitud,&frecuencia,&numharmonicos,&tiempofinal,&puntos);
  Resolver(amplitud,frecuencia,numharmonicos,tiempofinal,&inicio,puntos);
  Escribir(inicio);
  Plot(numharmonicos);
  Borrarlista(inicio);
}

void Pedirdatos(float *amplitud,float *frecuencia,int *numharmonicos,float *tiempofinal,float *puntos){//recibe los parametros y los manda al main
  printf("De cuanto es la amplitud?\n");
  scanf("%f",amplitud);
  printf("De cuanto es la frecuencia?\n");
  scanf("%f",frecuencia);
  printf("De cuanto es el numero harmonico?\n");
  scanf("%i",numharmonicos);
  printf("De cuanto es el tiempo final?\n");
  scanf("%f",tiempofinal);
  printf("Cuantos puntos vas a querer graficar?\n");
  scanf("%f",puntos);
}

void Resolver(float amplitud,float frecuencia,int numharmonicos,float tiempofinal,resultados **inicio,float puntos){/*recibe los datos para poder graficar,
  recibe el inicio de la lista dininamica de los resultados*/
  float deltaf,i;
  resultados *temp,*temp2;//variables para el manejo de la lista dinamica
  deltaf=tiempofinal/puntos;//define de cuanto es el salto de cada t
  for(i=0;i<=tiempofinal;i+=deltaf){/*ciclo for que va aumentando en deltaf para poder graficar cada punto en el eje x
    se detiene cuando llega al ultimo punto que es el tiempo final*/
    temp=(resultados*)malloc(sizeof(resultados));
    temp->final=(amplitud/2)-Sumatoria(amplitud,deltaf,i,frecuencia,numharmonicos);/*coloca en el eje y la solucion de
    la ecuacion (amplitud/2)-funcion(sumatoria)*/
    temp->tiempo=i;//coloca en el eje x el tiempo en el cual se esta evaluenado la funcion
    temp->sig=NULL;
    if(i==0)//si la lista esta vacia, coloca la primera coordenada como el inicio de la lista
      *inicio=temp;
    else{//si ya la lista tiene algo iserta la siguiente coordenada al final de lista
      temp2=*inicio;
      while(temp2->sig!=NULL)
        temp2=temp2->sig;
      temp2->sig=temp;
    }
  }
}

float Sumatoria(float amplitud,float deltaf,float i,float frecuencia,int numharmonicos){
  float resultado=0;
  int j;
  for(j=1;j<numharmonicos;j++)/*empieza en 1, para evitar dividir entre 0, y
  acaba cuando evalua en el limite del numero harmonico*/
    resultado+=(amplitud/(M_PI*j))*((cos(M_PI*j))-1)*(sin(2*M_PI*j*frecuencia*i));/*formula del archivo, j es el numero harmonico a evaluar,
    i es el teimpo en el cual se esta evaluando*/
  return resultado;
}

void Escribir(resultados *inicio){//escribe en el archivo los resultados de la formula
  resultados *imprime;
  FILE *arch;
  imprime=inicio;
  arch=fopen("senial.txt","wt");
  while(imprime!=NULL){
    fprintf(arch,"%f %f\n",imprime->tiempo,imprime->final);
    imprime=imprime->sig;
  }
  fclose(arch);
}

void Borrarlista(resultados *Inicio){//borra la lista dinamica en el que estan los resultados
  resultados *borra;
  borra=Inicio;
  while(borra!=NULL){
      Inicio=Inicio->sig;
      free(borra);
      borra=Inicio;
    }
}

void Plot(int num){
  char titulo[100];
  int i;
  sprintf(titulo,"set title \"f(t), %i armonicos\"",num);
  char *configGnuplot[]={titulo,
      "set ylabel \"f(t)\"",
      "set xlabel \"tiempo\"",
      "plot \"senial.txt\" with lines",
      "set autoscale",
      "replot"
  };
  FILE *ventana=popen("gnuplot -persist","w");
  for(i=0;i<=4;i++)
    fprintf(ventana,"%s \n",configGnuplot[i]);
}

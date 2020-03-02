#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Neurona{
  double w[2],Bias,Error;
  int X[2];
}NeuPensante;

void Resul(NeuPensante *AND, int Tipo);
int Verif(double Resultado);
void EntreAND_OR(NeuPensante* Neu, double Datos[4][3], char NombreArchivo[]);
void EntreNOT(NeuPensante* Neu, double Datos[2][2], char NombreArchivo[]);
double ForPass(NeuPensante *Neu, double InX[], int Tipo);
void InitNeuAND_OR(NeuPensante *Neu);
void InitNeuNOT(NeuPensante *Neu);

int main(void){
  NeuPensante NueAND,NueOR,NueNOT;
  int op;
  double AND[4][3] = {{-1, -1, -1}, {-1, 1, -1}, {1, -1, -1}, {1, 1, 1}};
  double NOT[2][2] = {{-1, 1}, {1, -1}};
  double OR[4][3] = {{-1, -1, -1}, {-1, 1, 1}, {1, -1, 1}, {1, 1, 1}};
  InitNeuAND_OR(&NueAND);
  InitNeuAND_OR(&NueOR);
  InitNeuNOT(&NueNOT);
  EntreAND_OR(&NueAND,AND,"AND.txt");
  EntreAND_OR(&NueOR,OR,"OR.txt");
  EntreNOT(&NueNOT,NOT,"NOT.txt");
  printf("\nEstas neuronas ya piensan\nApachurra enter o puedes ver esta pantalla eternamente\n");
  __fpurge(stdin);
  getchar();
  do{
  system("clear");
  printf("Menu\n1.-AND\n2.-OR\n3.-NOT\n4.-Salir\n");
  scanf(" %i",&op);
  system("clear");
  switch(op){
  	case 1:
  	  Resul(&NueAND,2);
	  break;
  	case 2:
  	  Resul(&NueOR,2);
	  break;
  	case 3:
  	  Resul(&NueNOT,1);
	  break;
  	case 4:
  	  printf("\n\nFATHER WHY HAVE YOU FORSAKEN ME???\n\n");
  	  exit(0);
	  break;
  	default:
  	  printf("Opción incorrecta, hay que leer el menu (No el de los pancakes) detenidamente.\n");
	  break;
  	}
    printf("\nPresiona enter para continuar.");
    __fpurge(stdin);
    getchar();
  }while(op!=4);
}

void InitNeuAND_OR(NeuPensante *Neu){
  srand48(time(NULL));
  Neu->w[0] = drand48();
  Neu->w[1] = drand48();
  Neu->Bias = drand48();
}
void InitNeuNOT(NeuPensante *Neu){
  srand48(time(NULL));
  Neu->w[0] = drand48();
  Neu->Bias = drand48();
}

void Resul(NeuPensante *Neu, int Tipo){
  double InX[2];
  if(Tipo == 2){
    printf("Ingrese 1 o -1\n");
    scanf(" %lf",&InX[0]);
    printf("Ingrese 1 o -1\n");
    scanf(" %lf",&InX[1]);
    printf("El resultado es: %i", Verif(ForPass(Neu,InX,Tipo)));
  }
  else{
    printf("Ingrese 1 o -1\n");
    scanf(" %lf",&InX[0]);
    printf("El resultado es: %i", Verif(ForPass(Neu,InX,Tipo)));
  }
}

void EntreAND_OR(NeuPensante* Neu, double Datos[4][3], char NombreArchivo[]){
  FILE *Archivo;
  Archivo = fopen(NombreArchivo, "wt");
  double N = 0.001;
  int indice = 0;
  for(int i = 0; i < 1000; i++){
    if(indice == 4)
      indice = 0;
    Neu->Error = Datos[indice][2] - ForPass(Neu,Datos[indice],2);
    for(int j = 0 ; j < 2;j++)
      Neu->w[j] += N * Neu->Error * Datos[indice][j];
    Neu->Bias += Neu->Error * N;
    fprintf(Archivo, "%lf, %lf, %lf\n", Neu->w[0],Neu->w[1],Neu->Error);
    indice++;
  }
  fclose(Archivo);
}

void EntreNOT(NeuPensante* Neu, double Datos[2][2], char NombreArchivo[]){
  FILE *Archivo;
  Archivo=fopen(NombreArchivo, "wt");
  double N=0.01;
  int indice=0,i;
  for(i=0;i<1000;i++){
    if(indice == 2)
      indice = 0;
    Neu->Error = Datos[indice][1] - ForPass(Neu,Datos[indice],1);
    Neu->w[0] += N * Neu->Error * Datos[indice][0];
    Neu->Bias += Neu->Error * N;
    fprintf(Archivo, "%lf, %lf\n", Neu->w[0],Neu->Error);
    indice++;
  }
  fclose(Archivo);
}

double ForPass(NeuPensante *Neu, double InX[], int Tipo){
  double Suma=0;
  for(int i=0; i < Tipo; i++)
    Suma+=InX[i]*Neu->w[i];
  Suma+=Neu->Bias;
  return Suma;
}

int Verif(double Resultado){
  if(Resultado<0)
    return -1;
  else
    return 1;
}

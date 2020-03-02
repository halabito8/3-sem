#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Neurona{
  double *w,b,thresh, res,*x;
}tipo_neurona;

void And(tipo_neurona *neurona);
void Or(tipo_neurona *neurona);
void Not(tipo_neurona *neurona);
void Xor(tipo_neurona *neurona);

int main(void){
  int opc;
  tipo_neurona neurona;

  neurona.thresh=0.5;
  neurona.w = (double *) malloc (sizeof (tipo_neurona)*2);
  neurona.x = (double *) malloc (sizeof (tipo_neurona)*2)
  do{
    system("clear");
    printf("Menú:\n");
    printf("1. And\n");
    printf("2. Or\n");
    printf("3. Not\n");
    printf("4. XOr\n");
    printf("5. Exit\n");
    printf("Elija la opción deseada\n");
    scanf(" %i",&opc);
    system("clear");

    switch(opc){
      case 1:
       And(&neurona);
       break;
      case 2:
       Or(&neurona);
       break;
      case 3:
       Not(&neurona);
       break;
      case 4:
       Xor(&neurona);
       break;
      case 5:
       printf("Saliendo del programa\n");
       exit(0);
       break;
      default:
       printf("Opción inválida\n");
       break;
      }
    printf("\nPresione cualquier tecla para regresar al menú.");
    __fpurge(stdin);
    getchar();
  }while(opc != 5);
}

void And(tipo_neurona *neurona){
  printf("Inserte el valor de A:\n");
  scanf(" %i",&neurona->x[0]);
  printf("Inserte el valor de B:\n");
  scanf(" %i",&neurona->x[1]);

  neurona->w[0] = 1;
  neurona->w[1] = 1;
  neurona->b = -1;

  neurona->res = neurona->w[0]*neurona->x[0] + neurona->w[1]*neurona->x[1]+neurona->b;

  if(neurona->res < neurona->thresh)
    printf("Resultado = 0\n");
  else
    printf("Resultado = 1\n");
}

void Or(tipo_neurona *neurona){
  printf("Inserte el valor de A:\n");
  scanf(" %i",&neurona->x[0]);
  printf("Inserte el valor de B:\n");
  scanf(" %i",&neurona->x[1]);

  neurona->w[0] = 1;
  neurona->w[1] = 1;
  neurona->b = 0;

  neurona->res = neurona->w[0]*neurona->x[0] + neurona->w[1]*neurona->x[1]+neurona->b;

  if(neurona->res < neurona->thresh)
    printf("Resultado = 0\n");
  else
    printf("Resultado = 1\n");
}

void Not(tipo_neurona *neurona){
  printf("Inserte el valor de A:\n");
  scanf(" %i",&neurona->x[0]);

  neurona->w[0] = -1;
  neurona->b = 1;

  neurona->res = neurona->w[0]*neurona->x[0] + neurona->b;

  if(neurona->res < neurona->thresh)
    printf("Resultado = 0\n");
  else
    printf("Resultado = 1\n");
}

void Xor(tipo_neurona *neurona){
  printf("No se puede\n");
}

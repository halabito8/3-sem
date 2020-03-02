#include<stdio.h>
#include<stdlib.h>

void validar(int a);
void Desplegar(unsigned short int numeros);
void Operar(unsigned short int numeros);

int main(int argc,char **argv){
  int a=argc,i;
  unsigned short int n1,numeros=0,op=1;
  validar(a);//evalua si hay demasiados argumentos en la terminal
  for(i=1;i<argc;i++){//separa y almacena en cada numero
    n1=atoi(argv[i]);
    if(n1>15)//Si el valor es mayor a 15 (4 bits) no lo va a almacenar
      printf("No es posible almacenar el valor %i\n",i);
    else{
      n1<<=(i-1)*4;//recorre a la izquierda los cuatro bits necesarios para almacenar la variable
      numeros=numeros|n1;
    }
  }
  do{
    printf("Que deseas hacer?\n");
    printf("1. Desplegar 1 numero\n2. Operar los numeros\n3. Salir\n");
    __fpurge(stdin);
    scanf("%hi",&op);
    switch(op){
      case 1:
        Desplegar(numeros);
      break;
      case 2:
        Operar(numeros);
      break;
      case 3:
        op=3;
      break;
      default:
        printf("Escoje una opcion correcta\n");
      break;
    }
  }while(op!=3);
}

void validar(int a){
  if(a>5){
    printf("Hay demasiados argumentos\n");
    exit(0);
  }
}

void Desplegar(unsigned short int numeros){
  unsigned short int cual,izquierda,derecha,temp=0;
  printf("Que numero quieres imprimir?\n");
  scanf("%hi",&cual);
  if(cual>4)
    printf("No existe ese valor\n");
  else{
    izquierda=cual*-4+16;//calcula cuantos bits tiene que recorrer a la izquieda, para que todo a la izquierda sea cero
    numeros<<=izquierda;
    numeros>>=12;//ya que lo recorrio a la izquierda los recorre a la derecha para que se imprima correctamente
    printf("El numero %hi es: %hi\n",cual,numeros);
  }
}

void Operar(unsigned short int numeros){
  unsigned short int n[4],i,izq,op;
  float temp=0;
  for(i=1;i<5;i++){//separa los numeros y los inserta en un arreglo
    izq=i*-4+16;
    n[i-1]=numeros<<izq;
    n[i-1]>>=12;
  }
  printf("Que operacion quieres hacer?\n1.+\n2.-\n3.*\n4./\n");
  scanf("%hu",&op);
  switch(op){
    case 1:
      for(i=0;i<4;i++)
        temp+=n[i];
    break;
    case 2:
      for(i=0;i<4;i++)
        temp-=n[i];
    break;
    case 3:
      temp=n[0]*n[1]*n[2]*n[3];
    break;
    case 4:
      temp=n[0]/n[1]/n[2]/n[3];
    break;
  }
  printf("El resultado es: %f\n",temp);
}

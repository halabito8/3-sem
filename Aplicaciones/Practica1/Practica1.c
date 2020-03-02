#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void Peuler(float x0,float xn,float y0,float h,float formula[],float xy[2][100],int *max);
void Seuler(float x0,float xn,float y0,float h,float formula[],float xy[2][100],float yp,int *max,float alpha1,float alpha0);
void Teuler(float x0,float xn,float y0,float h,float formula[],float xy[2][100],float yp,int *max,float alpha1,float alpha0,float alpha2,float yp2);
float resolver(float x,float formula[]);
void primer();
void segundo();
void tercer();

int main(void){
  int cuantos;
  do{
    printf("De que grado va a ser la ecuacion (hasta tercer grado)?\n");
    scanf("%i",&cuantos);
    switch(cuantos){
      case 1:
        primer();
      break;
      case 2:
        segundo();
      break;
      case 3:
        tercer();
      break;
      case 4:
        exit(0);
      default:
        printf("Escoje un numero valido\n");
      break;
    }
  }while(cuantos<1&&cuantos>4);
}

void primer(){
  float x0,xn,y0,h,formula[10]={0},xy[2][100];
  int exponente,i,max=0;
  FILE *archivo;
  printf("Introduzca el valor de x0 en t0 (el intervalo inferior donde empieza la grafica en el eje x)\n");
  scanf("%f",&x0);
  printf("Introduzca el valor de y0 en t0 (el intervalo donde empieza la grafica en el eje y)\n");
  scanf("%f",&y0);
  printf("Introduzca el valor de xn (el intervalo superior donde termina la grafica en el eje x)\n");
  scanf("%f",&xn);
  printf("Introduzca el valor de h (tamaño de paso)\n");
  scanf("%f",&h);
  printf("Cual es el exponente mayor de la f(x)?\n");
  scanf("%i",&exponente);
  for(i=exponente;i>=0;i--){
    printf("Introduzco el valor de x con exponente %i\n",i);
    scanf("%f",&formula[i]);
  }
  printf("Calculando euler\n");
  Peuler(x0,xn,y0,h,formula,xy,&max);
  archivo=fopen("EulerPG.txt","wt");
  for(i=0;i<max;i++)
    fprintf(archivo,"%.2f   %.2f\n",xy[0][i],xy[1][i]);
  fclose(archivo);

}

void segundo(){
  float x0,xn,y0,h,formula[10]={0},xy[2][100],yp,alpha1,alpha0;
  int exponente,i,max=0;
  FILE *archivo;
  printf("Introduzca el valor de x0 en t0 (el intervalo inferior donde empieza la grafica en el eje x)\n");
  scanf("%f",&x0);
  printf("Introduzca el valor de y0 en t0 (el intervalo donde empieza la grafica en el eje y)\n");
  scanf("%f",&y0);
  printf("Introduzca el valor de xn (el intervalo superior donde termina la grafica en el eje x)\n");
  scanf("%f",&xn);
  printf("Introduzca el valor de y prima en t0\n");
  scanf("%f",&yp);
  printf("Introduzca el valor de alpha 1 (la que va con y prima)\n");
  scanf("%f",&alpha1);
  printf("Introduzca el valor de alpha 0 (la que va con y)\n");
  scanf("%f",&alpha0);
  printf("Introduzca el valor de h (tamaño de paso)\n");
  scanf("%f",&h);
  printf("Cual es el exponente mayor de la f(x)?\n");
  scanf("%i",&exponente);
  for(i=exponente;i>=0;i--){
    printf("Introduzco el valor de x con exponente %i\n",i);
    scanf("%f",&formula[i]);
  }
  printf("Calculando euler\n");
  Seuler(x0,xn,y0,h,formula,xy,yp,&max,alpha1,alpha0);
  archivo=fopen("EulerSG.txt","wt");
  for(i=0;i<max;i++)
    fprintf(archivo,"%.2f   %.2f\n",xy[0][i],xy[1][i]);
  fclose(archivo);
}

void tercer(){
  float x0,xn,y0,h,formula[10]={0},xy[2][100],yp,yp2,alpha0,alpha1,alpha2;
  int exponente,i,max=0;
  FILE *archivo;
  printf("Introduzca el valor de x0 en t0 (el intervalo inferior donde empieza la grafica en el eje x)\n");
  scanf("%f",&x0);
  printf("Introduzca el valor de y0 en t0 (el intervalo donde empieza la grafica en el eje y)\n");
  scanf("%f",&y0);
  printf("Introduzca el valor de xn (el intervalo superior donde termina la grafica en el eje x)\n");
  scanf("%f",&xn);
  printf("Introduzca el valor de y prima en t0\n");
  scanf("%f",&yp);
  printf("Introduzca el valor de y biprima en t0\n");
  scanf("%f",&yp2);
  printf("Introduzca el valor de alpha 2 (la que va con y biprima)\n");
  scanf("%f",&alpha2);
  printf("Introduzca el valor de alpha 1 (la que va con y prima)\n");
  scanf("%f",&alpha1);
  printf("Introduzca el valor de alpha 0 (la que va con y)\n");
  scanf("%f",&alpha0);
  printf("Introduzca el valor de h (tamaño de paso)\n");
  scanf("%f",&h);
  printf("Cual es el exponente mayor de la f(x)?\n");
  scanf("%i",&exponente);
  for(i=exponente;i>=0;i--){
    printf("Introduzco el valor de x con exponente %i\n",i);
    scanf("%f",&formula[i]);
  }
  printf("Calculando euler\n");
  Teuler(x0,xn,y0,h,formula,xy,yp,&max,alpha1,alpha0,alpha2,yp2);
  archivo=fopen("EulerTG.txt","wt");
  for(i=0;i<max;i++)
    fprintf(archivo,"%.2f   %.2f\n",xy[0][i],xy[1][i]);
  fclose(archivo);
}

/*resuelve euler en primer grado,
recibe como parametros los valores iniciales para poder calcular euler*/
void Peuler(float x0,float xn,float y0,float h,float formula[],float xy[2][100],int *max){
  float x;
  int i=0;
  //coloca en la primeras coordenadas x0 y y0
  xy[0][0]=x0;
  xy[1][0]=y0;
  //calcula los numeros de Euler dentro de los limites con el salto que el usuario indico
  while(x0<=xn){//evalua si todavia estamos dentro de los limites de la formula
    x=xy[0][0]+(double)i*h;//resuleve x para la resolucion de la formula
    xy[0][i+1]=xy[0][i]+h;//aumenta en h la coordenada x
    xy[1][i+1]=xy[1][i]+resolver(x,formula)*h;//calcula la coordenada y
    i++;
    (*max)++;//Para imprimir nada mas los numeros que se resolvieron
    x0+=h;//aumenta x0 en el salto que el usuario indico
  }
}

void Seuler(float x0,float xn,float y0,float h,float formula[],float xy[2][100],float yp,int *max,float alpha1,float alpha0){
  float u1,u2,x;
  int i=0;
  xy[0][0]=x0;
  xy[1][0]=y0;
  u1=y0;
  u2=yp;
  while(x0<=xn){
    x=xy[0][0]+(double)i*h;//resuleve x para la resolucion de la formula
    xy[0][i+1]=x;//aumenta en h la coordenada x
    xy[1][i+1]=((-alpha1*u2-alpha0*u1)+resolver(x,formula))*h;//calcula la coordenada y
    u1=u2;
    u2=xy[1][i+1];
    i++;
    (*max)++;//Para imprimir nada mas los numeros que se resolvieron
    x0+=h;
  }
}

void Teuler(float x0,float xn,float y0,float h,float formula[],float xy[2][100],float yp,int *max,float alpha1,float alpha0,float alpha2,float yp2){
  float u1,u2,u3,x;
  int i=0;
  xy[0][0]=x0;
  xy[1][0]=y0;
  u1=y0;
  u2=yp;
  u3=yp2;
  while(x0<=xn){
    x=xy[0][0]+(double)i*h;//resuleve x para la resolucion de la formula
    xy[0][i+1]=x;//aumenta en h la coordenada x
    xy[1][i+1]=((-alpha2*u1-alpha1*u2-alpha0*u3)+resolver(x,formula))*h;//calcula la coordenada y
    u1=u2;
    u2=u3;
    u3=xy[1][i+1];
    i++;
    (*max)++;//Para imprimir nada mas los numeros que se resolvieron
    x0+=h;
  }
}

float resolver(float x,float formula[]){//resuelve la formula con la x dada
  int i;
  float j=0;
  for(i=9;i>=0;i--)
    j+=formula[i]*pow(x,i);//suma en j el reultado de cada variable (x lo eleva a surespectiva potencia y lo multiplica por la constante)
  return j;
}

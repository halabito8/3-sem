#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
  unsigned char dato;
  int *costo;
  struct nodo *sig;
  struct nodo **vertices;
}nodo;

void nuevonodo(int max,nodo *Inicio, int *cantidad);//crea un nuevo nada en la lista dinamica
void borrarlista(nodo *inicio);//borra la lista dinamica
void nuevaarista(int max,nodo *inicio);//relaciona dos nodos
void desplegar(nodo *inicio,int max);//despliega el grafo
void Dijkstra(nodo *inicio, int cantidad);//inicializa y pide datos
void wazechafa(nodo *inicio,int cantidad,unsigned int SDF[],char ant[],unsigned int *visitados);//evalua un solo nodo no visitado

int main(void){
  int max,i,op, cantidad=1;
  nodo *temp,*inicio;
  printf("Cuando vertices va a haber por nodo?\n");
  scanf("%i",&max);
  temp=(nodo*)malloc(sizeof(nodo));//crea el nodo raiz
  temp->vertices=(nodo**)malloc(sizeof(nodo*)*max);//crea una lista de vertices del tamaño que el usuario requiera
  temp->costo=(int*)malloc(sizeof(int)*max);//crea una lista de costos del tamaño que el usuario requiera (en la posicion del vertice enla lista es la misma que la del costo en su lista)
  for(i=0;i<max;i++)//inicializa todos los vertices en NULL
    temp->vertices[i]=NULL;
  temp->sig=NULL;
  temp->dato='A';
  inicio=temp;
  printf("Nodo \"A\" creado con 0 vertices\n");
  i=0;
  do{
    printf("Que quieres hacer?\n1. Anadir nodo\n2. Anadir vertice\n3. Desplegar grafo\n4. Dijkstra\n5. Salir\n");
    __fpurge(stdin);
    scanf("%i",&op);
    switch(op){
      case 1:
        nuevonodo(max,inicio,&cantidad);
      break;
      case 2:
        nuevaarista(max,inicio);
      break;
      case 3:
        desplegar(inicio,max);
      break;
      case 4:
        Dijkstra(inicio,cantidad);
      break;
      case 5:
        i=1;
        borrarlista(inicio);
        printf("No me mates...\n");
      break;
      default:
        printf("Escoja una opcion valida\n");
      break;
    }
  }while(i==0);
}

/* @param nodo inicio es el principio de la lista dinamica,
@param int cantidad es la cantidad de nodos que hay*/
void Dijkstra(nodo *inicio,int cantidad){
  nodo *temp;
  char direccion[cantidad],salida,llegada,*ant,ruta[20],desde,hola;
  unsigned int i=0,*SDF,j=0,visitados=0;
  printf("De que nodo desea salir:\n");
  __fpurge(stdin);
  scanf("%c", &salida);
  //en la misma posicionque se va a colocar SDF() se va a colocar el nodo anterior que se puede calcular de esta forma dato-65
  SDF=(unsigned int*)malloc(sizeof(unsigned int)*cantidad);//crea el array de SDF() del tamaño de nodos que hay
  ant=(char*)malloc(sizeof(char)*cantidad);//crea una lista de caracteres del tamaño de nodos que hay)
  for(i=0;i<cantidad;i++)//inicilaiza todos los valores en "infinito"-1
    SDF[i]=2147483644;
  temp=inicio;
  i=salida-65;//en la posicion i-65 (la posicion en SDF y ant de la letra) colocar 0 en SDF y NULL en ant
  SDF[i]=0;
  ant[i]='\0';
  for(i=0;i<cantidad;i++)//como wazechafa nada mas evalua un nodo no visitado se tiene que ejecutar la misma cantidad de veces que nodos hay
    wazechafa(inicio,cantidad,SDF,ant,&visitados);
  system("clear");
  hola='A';
  for(i=0;i<cantidad;i++){//despliega la tabla
    printf("%c\t",hola);
    printf("%i\t",SDF[i]);
    if(ant[i]=='\0')
      printf("NULL\n");
    else
      printf("%c\n",ant[i]);
    hola++;
  }
}

/*@param nodo inicio es el principio de la lista dinamica,
@param int cantidad es la cantidad de nodos que hay,
@param unsigned int SDF[] se guarda la lista de SDF de los nodos,
@param char ant[] se guarda en nodo previo para ver el mejor camino
@param unsigned int *visitados es la variable en donde se guaradan los nodos visitados a nivel de bits 1 visitado 0 no visitado
*/
void wazechafa(nodo *inicio,int cantidad,unsigned int SDF[],char ant[],unsigned int *visitados){
  nodo *checar,*llegada;
  int min,sv=1,i,novertice,j,temp;
  min=2147483645;//inicializa el valor en "infinito" para que pueda encontrar el valor mas bajo sin vistar
  for(i=0;i<cantidad;i++){
    if((sv&(*visitados))==0){//sv nada mas tiene un uno en una posicion si el AND da resultado cero es que ese nodo no se ha vsitado
      if(min>SDF[i]){//evalua si hay un nuevo minimo
        min=SDF[i];//coloca un nuevo minimo
        novertice=i;//guardo la posicion de mi dato
      }
    }
    sv<<=1;//recorre el 1 de sv una posicion para cheacr el siguiente nodo sin vistar
  }
  checar=inicio;
  for(i=0;i<novertice;i++)//recorro la lista para obtener los vertices del nodo ha evaluar
    checar=checar->sig;
  printf("Checando vertice %c\n",checar->dato);
  i=0;
  while(checar->vertices[i]!=NULL){//chaca todos los vertices
    sv=1;
    sv<<=checar->vertices[i]->dato-65;//recorre el uno la cantidad de espacios para evaluar si ese nodo ya ha sido visitado
    if((sv&(*visitados))==0){
      temp=SDF[novertice]+checar->costo[i];//coloca en temp un SDF
      j=checar->vertices[i]->dato-65;//posicion del dato a evaluar en la lista de SDF
      if(temp<SDF[j]){//si el nuevo SDF(temp) es menor lo reemplazamos y colocamos la letra anterior
        SDF[j]=temp;
        ant[j]=checar->dato;
      }
    }
    i++;
  }
  temp=1;
  temp<<=checar->dato-65;//recorremos el uno los espacios necesarios para colocar visitado en la lista
  (*visitados)=(*visitados)|temp;
}

/*@param int max numero maximo de vertices que hay por nodo,
@param  nodo *inicio es el principio de la lista dinamica,
@param int *cantidad cantidad de nodos que hay
*/
void nuevonodo(int max,nodo *inicio, int *cantidad){
  int i;
  nodo *nuevo,*temp;
  nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->vertices=(nodo**)malloc(sizeof(nodo*)*max);//crea una lista de vertices del tamaño que el usuario requiera
  nuevo->costo=(int*)malloc(sizeof(int)*max);//crea una lista de costos del tamaño que el usuario requiera (en la posicion del vertice enla lista es la misma que la del costo en su lista)
  for(i=0;i<max;i++)//inicializa todos los vertices en NULL
    nuevo->vertices[i]=NULL;
  nuevo->sig=NULL;
  temp=inicio;
  while(temp->sig!=NULL)//busca el ultimo dato de la lista para colocar el nuevo dato al final
    temp=temp->sig;
  temp->sig=nuevo;
  nuevo->dato=(temp->dato)+1;//agrega en 1 la letra
  system("clear");
  printf("Nodo \"%c\" creado con 0 vertices\n",nuevo->dato);
  printf("\n");
  (*cantidad)++;
}

/*@param int max numero maximo de vertices que hay por nodo,
@param  nodo *inicio es el principio de la lista dinamica
*/
void nuevaarista(int max,nodo *inicio){
  int contador=0,contador2=0,costo;
  unsigned char letra;
  nodo *principio,*fin;
  printf("De que nodo sale la conexion?\n");
  __fpurge(stdin);
  scanf("%c",&letra);
  principio=inicio;
  while(principio->dato!=letra&&principio!=NULL)//checa si existe el nodo
    principio=principio->sig;
  if(principio==NULL){
    printf("Ese nodo no existe\n");
    return;
  }
  while(principio->vertices[contador]!=NULL)//checa si sus conexiones estan llenas
    contador++;
  if(contador==max){
    printf("Ese nodo ya tiene sus conexiones llenas\n");
    return;
  }
  printf("A que nodo lo quieres juntar?\n");
  __fpurge(stdin);
  scanf("%c",&letra);
  fin=inicio;
  while(fin->dato!=letra&&fin!=NULL)//checa si existe el nodo
    fin=fin->sig;
  if(fin==NULL){
    printf("Ese nodo no existe\n");
    return;
  }
  while(fin->vertices[contador2]!=NULL)//checa si sus conexiones estan llenas
    contador2++;
  if(contador2==max){
    printf("Ese nodo ya tiene sus conexiones llenas\n");
    system("clear");
    return;
  }
  printf("Cuanto es el costo?\n");
  scanf("%i",&costo);
  /* en contador lleva la cuenta en donde se va a colocar en el primer nodo recibido
  en contador2 lleva la cuenta en donde se va a colocar en el segundo nodo recibido*/
  principio->costo[contador]=costo;
  principio->vertices[contador]=fin;
  fin->costo[contador2]=costo;
  fin->vertices[contador2]=principio;
  system("clear");
  printf("La conexion del nodo %c al nodo %c establecida con un costo de %i\n",principio->dato,fin->dato,costo);
  printf("\n");
}

/*@param int max numero maximo de vertices que hay por nodo,
@param  nodo *inicio es el principio de la lista dinamica
*/
void desplegar(nodo *inicio,int max){
  nodo *imprimir;
  int i;
  imprimir=inicio;
  system("clear");
  while(imprimir!=NULL){
    printf("El nodo \"%c\" tiene conexiones con:",imprimir->dato);
    i=0;
    for(i=0;i<max;i++){
      if(imprimir->vertices[i]!=NULL)
        printf(" %c",imprimir->vertices[i]->dato);
    }
    printf("\n\n");
    imprimir=imprimir->sig;
  }
}

//@param  nodo *inicio es el principio de la lista dinamica
void borrarlista(nodo *Inicio){
  nodo *temp;
    temp=Inicio;
    while(temp!=NULL){
      Inicio=Inicio->sig;
      free(temp);
      temp=Inicio;
    }
}

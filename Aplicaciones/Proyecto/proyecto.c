/*
 @file formato.c

 @brief Este programa esta disenado para trabajar
 como un sistema de control de versiones. En el
 cual, se pueden dar de alta usuarios, proyectos,
 asignar a usuarios a proyectos, hacer commits, reverts
 pulls, pushs y ver el status de cada archivo modificado
 por cada usuario.

 @autor David Halabe, Gabriela Uribe y Alan Flores
 @date 05/12/2019
 */

/*Inclusion de bibliotecas*/
#include "maquinas_de_estado.h"
#include<stdio.h>
#include<string.h>
#include<time.h>

/*Declaracion de estructuras dinamicas*/
typedef struct def_Usuarios{
  char usuario[20], contra[20];
  struct def_Usuarios *sig;
}tipousuarios;

typedef struct def_UsuProyecto{
  char nproyecto[20], usuario[20];
  struct def_UsuProyecto *sig;
}tipouproyecto;

typedef struct def_MasterBranch{
  char nproyecto[20], ncommit[100];
  struct def_MasterBranch *sig;
}tipomasterb;

typedef struct def_Commit{
  int numcom,pull;
  char ncommit[100], fecha[30], usuario[20], nproyecto[20],lineas[1000];
  struct def_Commit *sig;
}tipocommit;

/* Declaracion de variables globales*/
/* Inicios de las listas dinamicas*/
/* Variables de contral de usuario y proyecto*/
tipousuarios *iniciousr=NULL;
tipocommit *iniciocom=NULL;
tipomasterb *iniciomb=NULL;
tipouproyecto *iniciousrpro=NULL;
char usractual [20];
char proactual[20];

int main(int argc, char *argv[]){
    system("clear");
    States MachineState=LEER_ARCHIVOS;
    /*Maquina de estados con sus respectivas funciones*/
    StateMachine Machine[] = {
        {LEER_ARCHIVOS, LeerArch},
        {LOG_IN, LogIn},
        {MENU_PRINCIPAL, MenuPrincipal},
        {VER_PROYECTOS, VerProyectos},
        {COMMIT, Commit},
        {REVERT, Revert},
        {PULL, Pull},
        {STATUS, Status},
        {CREAR_PROYECTO, CrearProyecto},
        {CREAR_USUARIO, CrearUsuario},
	      {ESCRIBIR, escribir},
        {CREDITOS, Creditos},
        {SALIR, Salir}
    };
    //bucle infinito de la maquina de estados
    for(;;){
      if(MachineState > STATE_NUM){
	puts("Ocurrio un error");
	exit(0);
      }else{
	(*Machine[MachineState].funcion)(&MachineState);
      }
    }
}

void Creditos(States* State){
  char flag;
  puts("\n\n");
  puts("Creadores del sistema:\n");
  puts("David Halabe");
  puts("Maria Gabriela Uribe");
  puts("Alan Flores");
  __fpurge(stdin);
  flag=getchar();
  *State=MENU_PRINCIPAL;
}

/*
@func LeerArch, funcion encargada de leer todos los archivos generados
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void LeerArch(States* State){
  char string[101];
  tipousuarios *temp,*temp2;
  tipouproyecto *temp3, *temp4;
  tipomasterb *temp5, *temp6;
  tipocommit *temp7, *temp8;
  FILE *archivo;
  //Se leen todos los USUARIOS registrados del archivo usuarios.txt
  archivo=fopen("usuarios.txt","rt");
  if(archivo!=NULL){
    while(fgets(string,19,archivo)!=NULL){
       temp=(tipousuarios*)malloc(sizeof(tipousuarios));
      strcpy(temp->usuario,string);
      temp->usuario[strlen(temp->usuario)-1]='\0';
      fgets(string,19,archivo)!=NULL;
      strcpy(temp->contra,string);
      temp->contra[strlen(temp->contra)-1]='\0';
      temp->sig=NULL;
      if(iniciousr!=NULL){
        temp2= iniciousr;
        while(temp2->sig!=NULL)
          temp2=temp2->sig;
        temp2->sig=temp;
      }
      else
        iniciousr=temp;
    }
     fclose(archivo);
  }

  /*Se lee la relacion entre USUARIOS Y PROYECTOS registrados, del archivo proyecto.txt*/
  archivo = fopen("proyecto.txt", "rt");
  if(archivo!=NULL)
    {
      while(fgets(string,19,archivo)!=NULL){
	temp3=(tipouproyecto*)malloc(sizeof(tipouproyecto));
	strcpy(temp3->usuario,string);
	temp3->usuario[strlen(temp3->usuario)-1]='\0';
	fgets(string,19,archivo)!=NULL;
	strcpy(temp3->nproyecto,string);
	temp3->nproyecto[strlen(temp3->nproyecto)-1]='\0';
  temp3->sig=NULL;
	if(iniciousrpro!=NULL){
	  temp4=iniciousrpro;
	  while(temp4->sig!=NULL)
	    temp4=temp4->sig;
	  temp4->sig=temp3;
	}
	else
	  iniciousrpro=temp3;
      }
      fclose(archivo);
    }

   /*Se leen los commits de los MASTER B hechos, del archivo masterbranch.txt*/
  archivo = fopen("masterbranch.txt", "rt");
  if(archivo!=NULL)
    {
      while(fgets(string,99,archivo)!=NULL){
	temp5=(tipomasterb*)malloc(sizeof(tipomasterb));
	strcpy(temp5->ncommit,string);
	temp5->ncommit[strlen(temp5->ncommit)-1]='\0';
	fgets(string,19,archivo)!=NULL;
	strcpy(temp5->nproyecto,string);
	temp5->nproyecto[strlen(temp5->nproyecto)-1]='\0';
  temp5->sig=NULL;
	if(iniciomb!=NULL){
	  temp6=iniciomb;
	  while(temp6->sig!=NULL)
	    temp6=temp6->sig;
	  temp6->sig=temp5;
	}
	else
	  iniciomb=temp5;
      }
      fclose(archivo);
    }

  /*Se leen todos los COMMITS hechos, del archivo commit.txt*/
  archivo = fopen("commit.txt", "rt");
  if(archivo!=NULL)
    {
      while(fgets(string,99,archivo)!=NULL){
	temp7=(tipocommit*)malloc(sizeof(tipocommit));
	strcpy(temp7->ncommit,string);
	temp7->ncommit[strlen(temp7->ncommit)-1]='\0';

	fgets(string,19,archivo);
	strcpy(temp7->nproyecto,string);
	temp7->nproyecto[strlen(temp7->nproyecto)-1]='\0';

	fgets(string,29,archivo);
	strcpy(temp7->fecha,string);
	temp7->fecha[strlen(temp7->fecha)-1]='\0';

	fgets(string,19,archivo);
	strcpy(temp7->usuario,string);
	temp7->usuario[strlen(temp7->usuario)-1]='\0';

  fgets(string,999,archivo);
  strcpy(temp7->lineas,string);
  temp7->lineas[strlen(temp7->lineas)-1]='\0';

  fscanf(archivo, "%i\n", &temp7->pull);

	fscanf(archivo, "%i\n", &temp7->numcom);
  temp7->sig=NULL;

	if(iniciocom!=NULL){
	  temp8=iniciocom;
	  while(temp8->sig!=NULL)
	    temp8=temp8->sig;
	  temp8->sig=temp7;
	}
	else
	  iniciocom=temp7;
      }
      fclose(archivo);
    }
  *State=LOG_IN;
}

/*
@func LogIn, funcion encargada de desplegar el log in al usuario y validar si existe el usuario, valida si la contraseña es correcta
@param Status, parametro que conecta a la funcion con la maquina de estado
*/
void LogIn(States* State){
    char usuario[50],contrasena[50];
    tipousuarios *temp;
    temp=iniciousr;
    system("clear");
    printf("  _    ___   ___ ___ _  _ \n");
    printf(" | |  / _ \\ / __|_ _| \\| |\n");
    printf(" | |_| (_) | (_ || || .` |\n");
    printf(" |____\\___/ \\___|___|_|\\_|\n\n\n");
    puts("Introduzca su nombre de usuario: ");
    scanf("%s", usuario);
    while(temp!=NULL && strcmp(usuario,temp->usuario)!=0)
      temp=temp->sig;
    if(temp!=NULL){
      puts("Introduzca su contraseña: ");
      __fpurge(stdin);
      scanf("%s", contrasena);
      if(strcmp(contrasena,temp->contra)==0){
	strcpy(usractual, usuario);
	*State=MENU_PRINCIPAL;
      }
      else
        *State=LOG_IN;
    }
    else{
      puts("El usuario no existe");
      *State=LOG_IN;
    }
}

/*
@func MenuPrincipal, funcion encargada de desplegar el Menu principal al usuario para que elija que desea hacer
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void MenuPrincipal(States *State){
  int Opcion;
  system("clear");
  printf("\n");
  printf("__   _____ ___ ___ ___ ___  _  _    ___ ___  _  _ _____ ___  ___  _      _____   _____ _____ ___ __  __ \n");
  printf("\\ \\ / | __| _ / __|_ _/ _ \\| \\| |  / __/ _ \\| \\| |_   _| _ \\/ _ \\| |    / __\\ \\ / / __|_   _| __|  \\/  |\n");
  printf(" \\ V /| _||   \\__ \\| | (_) | .` | | (_| (_) | .` | | | |   | (_) | |__  \\__ \\\\ V /\\__ \\ | | | _|| |\\/| | \n");
  printf("  \\_/ |___|_|_|___|___\\___/|_|\\_|  \\___\\___/|_|\\_| |_| |_|_\\\\___/|____| |___/ |_| |___/ |_| |___|_|  |_|\n");
  printf("\n\n");
  puts("1. Ver proyectos");
  puts("2. Crear proyectos");
  puts("3. Crear usuario");
  puts("4. Salir");
  scanf("%d", &Opcion);

    switch(Opcion){
        case 1:
            *State = VER_PROYECTOS;
            break;
        case 2:
            *State = CREAR_PROYECTO;
            break;
        case 3:
            *State = CREAR_USUARIO;
            break;
        case 4:
            *State = ESCRIBIR;
            break;
        case 5:
          *State=CREDITOS;
          break;
        default:
            puts("Opcion invalida");
          break;
    }
}

/*
@func VerProyectos, funcion encargada de desplegar los proyectos del usuario, para que este elija sobre cual hacer commits, revert, pulls y ver el status de sus proyectos
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void VerProyectos(States *State){
  int Opcion,i=0;
  tipouproyecto *busca;
  char proyectos[30][20];
  system("clear");
  printf("  ___ ___  _____   _____ ___ _____ ___  ___ \n");
  printf(" | _ | _ \\/ _ \\ \\ / | __/ __|_   _/ _ \\/ __|\n");
  printf(" |  _|   | (_) \\ V /| _| (__  | || (_) \\__ \\\n");
  printf(" |_| |_|_\\\\___/ |_| |___\\___| |_| \\___/|___/\n");
  printf("\n\n");
  puts("Los proyectos disponibles son los siguientes, seleccione alguno:\n");
  busca=iniciousrpro;
  while(busca!=NULL){
    if(strcmp(busca->usuario,usractual)==0){
      strcpy(proyectos[i],busca->nproyecto);
      i++;
      printf("%i.- ",i);
      puts(busca->nproyecto);
    }
    busca=busca->sig;
  }
  if(i==0){
    system("clear");
    puts("No tienes proyectos disponibles");
    getchar();
    *State=MENU_PRINCIPAL;
  }
  else{
    __fpurge(stdin);
    scanf(" %i",&Opcion);
    if(Opcion>i || Opcion<0){
      puts("\nEse numero/caracter de proyecto no existe");
      __fpurge(stdin);
      getchar();
    }
    else
    {
      strcpy(proactual,proyectos[Opcion-1]);
      puts("\nQue desea hacer en base al proyecto seleccionado?:");
      puts("1. Commit");
      puts("2. Revert");
      puts("3. Pull");
      puts("4. Status");
      puts("5. Regresar menu anterior");
      scanf("%d", &Opcion);

      switch(Opcion){
          case 1:
              *State = COMMIT;
              break;
          case 2:
              *State = REVERT;
              break;
          case 3:
              *State = PULL;
              break;
          case 4:
              *State = STATUS;
              break;
          case 5:
              *State = MENU_PRINCIPAL;
              break;
          default:
              puts("Opcion invalida");
      }
    }
  }
}

/*
@func Commit, funcion encargada de generar el nombre del nuevo commit, y generar el archivo del commit
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void Commit(States *State){
  char string[1000], string2[1000], archcommit[50], archcommit2[100],buffer[200], flag[4],pasado[100];
  tipocommit *busca,*comactual=NULL,*nuevo;
  int numeroc=0, pull, pulleable,linea,push;
  tipomasterb *pushear,*inserta;
  FILE *archivo, *archivo2;
  system("clear");
  printf("\n");
  printf("   ___ ___  __  __ __  __ ___ _____ \n");
  printf("  / __/ _ \\|  \\/  |  \\/  |_ _|_   _| \n");
  printf(" | (_| (_) | |\\/| | |\\/| || |  | |\n");
  printf("  \\___\\___/|_|  |_|_|  |_|___| |_|  \n");
  printf("\n\n");
  //uso de la libreria time.h
  time_t now = time(NULL);
  time(&now);
  struct tm *mytime = localtime(&now);
  //now=time(NULL);

  mytime=localtime(&now);
  sprintf(buffer, "%d:%d-%d-%d-%d_", mytime->tm_hour, mytime->tm_min,mytime->tm_mday, mytime->tm_mon+1, mytime->tm_year+1900);

  busca=iniciocom;
  while(busca!=NULL){
    if(strcmp(busca->usuario, usractual)==0 && strcmp(busca->nproyecto, proactual)==0)
      comactual=busca;
    busca=busca->sig;
  }
  puts("Escriba el nombre de archivo al cual que deseas hacerle commit:");
  __fpurge(stdin);
  gets(archcommit);
  if(comactual!=NULL){
    numeroc=comactual->numcom+1;
    strcpy(pasado,comactual->ncommit);
  }
  else{
    puts("Todavia no tiene ningun commit de este proyecto realizado anteriormente");
    numeroc=1;
  }
  archivo= fopen(archcommit, "rt");
  if(archivo!=NULL){
    strcpy(archcommit2,proactual);
    strcat(archcommit2, usractual);
    strcat(archcommit2, buffer);
    sprintf(flag,"%d", numeroc);
    strcat(archcommit2, flag);
    puts("\nCommit realizado existosamente!");
    puts("\nEl nombre del archivo de su commit es:");
    puts(archcommit2);
    strcat(archcommit2, ".txt");

    archivo2=fopen(archcommit2, "wt");

    while(fgets(string, 999, archivo)!=NULL){
      string[strlen(string)-1]='\0';
      fprintf(archivo2, "%s\n", string);
    }
    fclose(archivo2);
    fclose(archivo);
    puts("Este archivo es para hacer pull?");
    printf("1. Si\n2. No\n");
    __fpurge(stdin);
    scanf("%d", &pulleable);
    if(pulleable==1)
      pull=1;
    else
      pull=0;
    puts("Desea hacer push a este commit?");
    puts("1. Si\n2. No");
    __fpurge(stdin);
    scanf("%d", &push);
    if(push==1){
      pushear=(tipomasterb*)malloc(sizeof(tipomasterb));
      strcpy(pushear->nproyecto,proactual);
      strcpy(pushear->ncommit,archcommit2);
      pushear->sig=NULL;
      inserta=iniciomb;
      if(inserta!=NULL){
        while(inserta->sig!=NULL)
          inserta=inserta->sig;
        inserta->sig=pushear;
      }
      else
        iniciomb=pushear;
    }
    nuevo=(tipocommit*)malloc(sizeof(tipocommit));
    nuevo->numcom=numeroc;
    nuevo->pull=pull;
    strcpy(nuevo->ncommit,archcommit2);
    strcpy(nuevo->fecha,buffer);
    strcpy(nuevo->usuario,usractual);
    strcpy(nuevo->nproyecto,proactual);
    if(numeroc!=1){
      linea=1;
      archivo2=fopen(pasado,"rt");
      archivo=fopen(archcommit, "rt");
      while(fgets(string2,999,archivo2)!=NULL){
        if(fgets(string,999,archivo)!=NULL){
          if(strcmp(string,string2)!=0){
            sprintf(flag,"%i ",linea);
            strcat(nuevo->lineas,flag);
          }
        }
        linea++;
      }
      fclose(archivo);
      fclose(archivo2);
    }
    else
      strcpy(nuevo->lineas,"Primer commit no se cambiaron lineas");
    nuevo->sig=NULL;
    if(iniciocom!=NULL){
    busca=iniciocom;
      while(busca->sig!=NULL)
        busca=busca->sig;
      busca->sig=nuevo;
    }
    else
      iniciocom=nuevo;
    *State=MENU_PRINCIPAL;
  }
  else{
    puts("El archivo insertado no existe\n");
    puts("Presione Enter para continuar");
    getchar();
    system("clear");
    *State=VER_PROYECTOS;
  }
}

/*
@func Revert, funcion encargada de hacer los reverts mostrando los proyectos que ya tienen commits realizados. Pregunta en que archivo se desea hacer el revert
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void Revert(States *State){
  int flag;
  int i=0,opcion;
  tipocommit *busca;
  char proyecto[20],usuario[20],commits[30][100],comactual[100],nombre[30],string[1000];
  FILE *com,*rev;
  system("clear");
  printf("  ___ _____   _____ ___ _____\n");
  printf(" | _ | __\\ \\ / | __| _ |_   _|\n");
  printf(" |   | _| \\ V /| _||   / | | \n");
  printf(" |_|_|___| \\_/ |___|_|_\\ |_|  \n");
  printf("\n");
  strcpy(proyecto,proactual);
  strcpy(usuario,usractual);
  busca=iniciocom;
  if(busca!=NULL){
    while(busca!=NULL){
      if(strcmp(busca->nproyecto,proyecto)==0 && strcmp(busca->usuario,usuario)==0){
        strcpy(commits[i],busca->ncommit);
        printf("%i.- %s\n",i+1,commits[i]);
        i++;
      }
      busca=busca->sig;
    }
    if(i!=0){
      __fpurge(stdin);
      scanf(" %i",&opcion);
      strcpy(comactual,commits[opcion-1]);
      puts("A que archivo lo quieres escribir?");
      __fpurge(stdin);
      gets(nombre);
      rev=fopen(comactual,"rt");
      com=fopen(nombre,"wt");
      while(fgets(string,999,rev)!=NULL){
        string[strlen(string)-1]='\0';
        fputs(string,com);
        fputs("\n",com);
      }
      puts("Revert exitoso\n");
      puts("Presione Enter para continuar");
      getchar();
      fclose(com);
      fclose(rev);
    }
    else
      puts("No hay commits\n");
      puts("Presione Enter para continuar");
      getchar();
  }
  else{
    puts("No hay commits\n");
    puts("Presione Enter para continuar");
    getchar();
  }
  *State = MENU_PRINCIPAL;
}

/*
@func Pull, funcion encargada de realizar los pulls a un nuevo archivo o a archivos anteriores
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void Pull(States *State){
  int i=0,opcion,flag;
  tipocommit *busca;
  char commit[100],commits[30][100],nombre[100],copiar[1000],proyecto[20];
  tipomasterb *temp,*usa=NULL;
  FILE *com,*usuario;
  system("clear");
  printf("  ___ _   _ _    _    \n");
  printf(" | _ | | | | |  | |   \n");
  printf(" |  _| |_| | |__| |__ \n");
  printf(" |_|  \\___/|____|____|\n");
  printf("\n");
  strcpy(proyecto,proactual);
  busca=iniciocom;
  if(busca!=NULL){
    while(busca!=NULL){
      if(strcmp(busca->nproyecto,proyecto)==0 && busca->pull==1){
        strcpy(commits[i],busca->ncommit);
        printf("%i.- %s\n",i+1,busca->ncommit);
        i++;
      }
      busca=busca->sig;
    }
    temp=iniciomb;
    while(temp!=NULL){
      if(strcmp(temp->nproyecto,proactual)==0){
        usa=temp;
      }
      temp=temp->sig;
    }
    if(usa!=NULL){
      puts("El ultimo push a master barnch que se hizo fue este");
      printf("%i.- %s\n",i+1,usa->ncommit);
      strcpy(commits[i],usa->ncommit);
      i++;
    }
    if(i==0){
      puts("No hay commits que se puedan pullear\n");
      puts("Presione Enter para continuar");
      getchar();
    }
    else{
      __fpurge(stdin);
      scanf("%i",&opcion);
      strcpy(commit,commits[opcion-1]);
      puts("A que archivo lo quieres pullear?");
      __fpurge(stdin);
      gets(nombre);
      com=fopen(commit,"rt");
      if(com!=NULL){
        usuario=fopen(nombre,"wt");
        if(usuario!=NULL){
          while(fgets(copiar,999,com)!=NULL){
            copiar[strlen(copiar)-1]='\0';
            fputs(copiar,usuario);
            fputs("\n",usuario);
          }
          fclose(usuario);
        }
        fclose(com);
      }
    }
  }
  *State = MENU_PRINCIPAL;
}

/*
@func Status, funcion encargada de desplegar al usuario en la terminal los cambios que se realizaron en los commits con las lineas cambiadass
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void Status(States *State){
  char flag;
  tipocommit *busca;
  system("clear");
  printf("  ___ _____ _ _____ _   _ ___ \n");
  printf(" / __|_   _/_|_   _| | | / __|\n");
  printf(" \\__ \\ | |/ _ \\| | | |_| \\__ \\\n");
  printf(" |___/ |_/_/ \\_|_|  \\___/|___/\n");
  printf("\n");
  puts("\t\tCommit: \t\t\tLineas que se cambiaron:\n");
  busca=iniciocom;
  while(busca!=NULL){
    if(strcmp(busca->usuario, usractual)==0 && strcmp(busca->nproyecto, proactual)==0)
      printf("%s    %s\n",busca->ncommit,busca->lineas);
    busca=busca->sig;
  }
  __fpurge(stdin);
  flag=getchar();
  *State = MENU_PRINCIPAL;
}

/*
@func CrearProyecto, funcion encargada de dar de alta nuevos proyectos y validar los ya existentes
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void CrearProyecto(States *State){
  tipouproyecto *busca,*busca3, *nuevousuario;
  tipousuarios *busca2;
  char nombre[20], nombreusu[20];
  int Nusuarios, i;
  system("clear");
  printf(" _  _ _   _ _____   _____    ___ ___  _____   _____ ___ _____ ___ \n");
  printf("| \\| | | | | __\\ \\ / / _ \\  | _ | _ \\/ _ \\ \\ / | __/ __|_   _/ _ \\ \n");
  printf("| .` | |_| | _| \\ V | (_) | |  _|   | (_) \\ V /| _| (__  | || (_) |\n");
  printf("|_|\\_|\\___/|___| \\_/ \\___/  |_| |_|_\\\\___/ |_| |___\\___| |_| \\___/\n");
  printf("\n\n");
  puts("Cual es el nombre del proyecto? (max 19 caracteres)");
  __fpurge(stdin);
  gets(nombre);
  busca=iniciousrpro;
  while(busca!=NULL && strcmp(busca->nproyecto,nombre)!=0)
    busca=busca->sig;
  if(busca!=NULL){
    puts("Ese nombre ya esta en uso, inserte un nombre de proyecto diferente");
    __fpurge(stdin);
    getchar();
    *State=CREAR_PROYECTO;
  }
  else{
    puts("Cuantos usuarios van a colaborar en este proyecto?");
    scanf(" %d", &Nusuarios);
    i=0;
    nuevousuario=(tipouproyecto*)malloc(sizeof(tipouproyecto));
    strcpy(nuevousuario->usuario,usractual);
    strcpy(nuevousuario->nproyecto,nombre);
    nuevousuario->sig=NULL;
    if(iniciousrpro!=NULL){
    	busca3=iniciousrpro;
    	while(busca3->sig!=NULL)
    	  busca3=busca3->sig;
    	busca3->sig=nuevousuario;
      }
    else
      iniciousrpro=nuevousuario;
    do{
    	printf("Inserta el nombre del usuario %d:\n", i+1);
    	__fpurge(stdin);
    	gets(nombreusu);
    	busca2=iniciousr;
    	while(busca2!=NULL && strcmp(busca2->usuario,nombreusu)!=0)
    	  busca2=busca2->sig;
    	if(busca2!=NULL){
  	    i++;
  	    nuevousuario=(tipouproyecto*)malloc(sizeof(tipouproyecto));
  	    strcpy(nuevousuario->usuario,nombreusu);
  	    strcpy(nuevousuario->nproyecto,nombre);
  	    nuevousuario->sig=NULL;
  	    if(iniciousrpro!=NULL){
      		busca3=iniciousrpro;
      		while(busca3->sig!=NULL)
      		  busca3=busca3->sig;
      		busca3->sig=nuevousuario;
	      }
  	    else
  	      iniciousrpro=nuevousuario;
  	  }
  	  else
  	  {
  	  puts("Ese usuario no existe, inserte uno que este dado de alta");
      getchar();
  	  }
    }while(i<Nusuarios);

  }
  *State=MENU_PRINCIPAL;

}

/*
@func CrearUsuario, funcion encargada de dar alta a los nuevos usuarios y validar a los existentes
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void CrearUsuario(States *State){
  tipousuarios *nuevo,*busca;
  char nombre[20],passwrd[20];
  system("clear");
  system("clear");
  printf(" _  _ _   _ _____   _____    _   _ ___ _   _  _   ___ ___ ___ \n");
  printf("| \\| | | | | __\\ \\ / / _ \\  | | | / __| | | |/_\\ | _ |_ _/ _ \\ \n");
  printf("| .` | |_| | _| \\ V | (_) | | |_| \\__ | |_| / _ \\|   /| | (_) |\n");
  printf("|_|\\_|\\___/|___| \\_/ \\___/   \\___/|___/\\___/_/ \\_|_|_|___\\___/ \n");
  printf("\n\n");

  printf("Como se va a llamar el nuevo usuario (19 caracteres max)\n");
  __fpurge(stdin);
  gets(nombre);
  busca=iniciousr;
  while(busca!=NULL && strcmp(busca->usuario,nombre)!=0)
    busca=busca->sig;
  if(busca==NULL){
    printf("Cual va a hacer la contrasena(19 caracteres max)\n");
    __fpurge(stdin);
    gets(passwrd);
    nuevo=(tipousuarios*)malloc(sizeof(tipousuarios));
    strcpy(nuevo->usuario,nombre);
    strcpy(nuevo->contra,passwrd);
    nuevo->sig=NULL;
    if(iniciousr!=NULL){
      busca=iniciousr;
      while(busca->sig!=NULL)
	busca=busca->sig;
      busca->sig=nuevo;
    }
    else
      iniciousr=nuevo;
    *State=MENU_PRINCIPAL;
  }
  else{
    puts("Ese usuario ya existe, inserte un nombre de usuario diferente");
    puts("Presione Enter para continuar");
    getchar();
    *State=CREAR_USUARIO;
  }
}

/*
@func escribir, funcion encargada de escribir en todos los archivos de la estructura
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void escribir(States *State){
  FILE* archivo;
  tipousuarios *usuarios;
  tipouproyecto *proyecto;
  tipomasterb *master;
  tipocommit *commit;
  archivo=fopen("usuarios.txt","wt");
  usuarios=iniciousr;
  while(usuarios!=NULL){
    fputs(usuarios->usuario,archivo);
    fputs("\n",archivo);
    fputs(usuarios->contra,archivo);
    fputs("\n",archivo);
    usuarios=usuarios->sig;
  }
  fclose(archivo);

  archivo=fopen("proyecto.txt","wt");
  proyecto=iniciousrpro;
  while(proyecto!=NULL){
    fputs(proyecto->usuario,archivo);
    fputs("\n",archivo);
    fputs(proyecto->nproyecto,archivo);
    fputs("\n",archivo);
    proyecto=proyecto->sig;
  }
  fclose(archivo);

  archivo=fopen("masterbranch.txt","wt");
  master=iniciomb;
  while(master!=NULL){
    fputs(master->ncommit,archivo);
    fputs("\n",archivo);
    fputs(master->nproyecto,archivo);
    fputs("\n",archivo);
    master=master->sig;
  }
  fclose(archivo);

  archivo=fopen("commit.txt","wt");
  commit=iniciocom;
  while(commit!=NULL){
    fputs(commit->ncommit,archivo);
    fputs("\n",archivo);
    fputs(commit->nproyecto,archivo);
    fputs("\n",archivo);
    fputs(commit->fecha,archivo);
    fputs("\n",archivo);
    fputs(commit->usuario,archivo);
    fputs("\n",archivo);
    fputs(commit->lineas,archivo);
    fputs("\n",archivo);
    fprintf(archivo,"%i\n%i",commit->pull, commit->numcom);
    fputs("\n",archivo);
    commit=commit->sig;
  }
  fclose(archivo);

  *State=SALIR;
}

/*
@func Salir, funcion encaergada de liberar la memoria
@param State, parametro que conecta a la funcion con la maquina de estado
*/
void Salir(States *State){
 tipousuarios *borra;
 tipouproyecto *proyecto;
 tipomasterb *master;
 tipocommit *commit;
 borra=iniciousr;
 while(borra!=NULL){
   iniciousr=iniciousr->sig;
   free(borra);
   borra=iniciousr;
 }
 proyecto=iniciousrpro;
 while(proyecto!=NULL){
   iniciousrpro=iniciousrpro->sig;
   free(proyecto);
   proyecto=iniciousrpro;
 }
 master=iniciomb;
 while(master!=NULL){
   iniciomb=iniciomb->sig;
   free(master);
   master=iniciomb;
 }
 commit=iniciocom;
 while(commit!=NULL){
   iniciocom=iniciocom->sig;
   free(commit);
   commit=iniciocom;
 }

 exit(0);
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mysql/mysql.h>

void Apellido(MYSQL *mysql);
void Estado(MYSQL *mysql);

int main(int argc,char *argv[]){
  int i=0,op;
  char *server="localhost";
  char *usr="ic18dhh";
  char *password="209707";
  char *db="ejemplos";
  MYSQL mysql;
  mysql_init(&mysql);
  //Se conecta al servidor
  if(!mysql_real_connect(&mysql,server,usr,password,db,0,NULL,0)){
    printf("Error al conectarse con la base de datos: %s",mysql_error(&mysql));
    exit(1);
  }
  //Se conecta a la BD
  if(mysql_select_db(&mysql,db)){
    printf("Error al seleccionar la base de datos: %s",mysql_error(&mysql));
    exit(1);
  }
  do{
    printf("Que deseas hacer?\n1. Buscar por apellido\n2. Buscar por estado\n3. Salir\n");
    __fpurge(stdin);
    scanf("%i",&op);
    switch(op){
      case 1:
        Apellido(&mysql);
      break;
      case 2:
        Estado(&mysql);
      break;
      case 3:
        i=1;
      break;
      default:
        printf("Opcion no valida\n");
      break;
    }
  }while(i==0);
  mysql_close(&mysql);
}

void Apellido(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  printf("Que apellido buscas?\n");
  __fpurge(stdin);
  gets(buscar);
  sprintf(buffer,"SELECT * FROM presidentes WHERE ap_paterno='%s'",buscar);
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL)
        printf("%s\t",row[i]);
      else
        printf("--\t");
    }
    printf("\n");
  }
  mysql_free_result(res);
}

void Estado(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  printf("Que estado buscas?\n");
  __fpurge(stdin);
  gets(buscar);
  sprintf(buffer,"SELECT * FROM presidentes WHERE estado='%s'",buscar);
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL)
        printf("%s\t",row[i]);
      else
        printf("--\t");
    }
    printf("\n");
  }
  mysql_free_result(res);
}

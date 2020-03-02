#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mysql/mysql.h>

int main(int argc,char *argv[]){
  int i=0;
  char buffer[1024];
  char *server="localhost";
  char *usr="ic18dhh";
  char *password="209707";
  char *db="ejemplos";
  char buscar[100];
  MYSQL mysql;
  MYSQL_RES *res;
  MYSQL_ROW row;
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
  //Ejecuta el query
  strcpy(buscar,"fox");
  sprintf(buffer,"SELECT * FROM presidentes WHERE ap_paterno='%s'",buscar);
  if(mysql_query(&mysql,buffer)){
    printf("Error al ejecutar el query: %s",mysql_error(&mysql));
    exit(1);
  }
  //Obtine el resultset
  if(!(res=mysql_store_result(&mysql))){
    printf("Error al obtener el rs: %s",mysql_error(&mysql));
    exit(0);
  }
  //despliega el resultado
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
  mysql_close(&mysql);
}

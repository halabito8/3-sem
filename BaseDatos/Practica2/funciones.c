#include"tipos.h"
//query1
void MayorAfluencia(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"SELECT nombre FROM p1_reservaciones LEFT JOIN p1_habitaciones USING(idHabitacion) LEFT JOIN p1_hoteles USING(idHotel) GROUP BY idHotel HAVING COUNT(idReservacion) = (SELECT COUNT(idReservacion) FROM p1_reservaciones LEFT JOIN p1_habitaciones USING(idHabitacion) GROUP BY idHotel ORDER BY COUNT(idReservacion) desc LIMIT 1);");
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
      if(row[i]!=NULL){
        printf("Hotel\n------------\n%s\n------------",row[i]);
      }
      else
        printf("--------");
    }
    printf("\n");
  }
  mysql_free_result(res);
}
//query2
void ComisionEmpleados(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"SELECT idEmpleado,CONCAT(nombre, ' ',apellido),COUNT(*) as reservaciones,SUM(precio)*comision as comision FROM p1_reservaciones LEFT JOIN p1_empleados USING(idEmpleado) LEFT JOIN p1_paquetes USING(idPaquete) GROUP BY idEmpleado;");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  printf("idEmpleado\tNombre\t\tReservaciones\t\tComisión\n------------------------------------------------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        printf("%s\t\t",row[i]);
      }
    }
    printf("\n");
  }
  mysql_free_result(res);
}
//query3
void HuespedSCI(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"SELECT CONCAT(h.nombre,' ', h.apellido) FROM p1_huespedes h RIGHT JOIN p1_reservaciones USING(idHuesped) WHERE fechaCheckIn IS NULL;");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  printf("Huéspedes sin Check In\n-------------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
	       printf("%s\t",row[i]);
       }
    }
    printf("\n");
  }
  printf("\n----------------------------------------------");
  mysql_free_result(res);
}
//query4
void HuespedTH(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"SELECT CONCAT(h.nombre, ' ', h.apellido) FROM p1_huespedes h LEFT JOIN p1_reservaciones USING(idHuesped) WHERE fechaCheckIn IS NOT NULL AND fechaCheckOut IS NOT NULL;");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  printf("Huéspedes\n------------------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        printf("%s\t",row[i]);
      }
    }
    printf("\n");
  }
  mysql_free_result(res);
}
//query5
void VentaCI(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"SELECT CONCAT(h.nombre, ' ', h.apellido) AS huesped, CONCAT(e.nombre, ' ', e.apellido) AS empleado, fechaCheckIn FROM p1_huespedes h RIGHT JOIN p1_reservaciones USING(idHuesped) LEFT JOIN p1_empleados e USING(idEmpleado) WHERE fechaCheckIn IS NOT NULL;");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  printf("Huésped\t\t\tEmpleado\t\t\tCheck In\n------------------------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        printf("%s\t\t",row[i]);
      }
    }
    printf("\n");
  }
  printf("\n----------------------------------------------");
  mysql_free_result(res);
}
//query6
void InfoEmpleados(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"set sql_mode='';");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  sprintf(buffer,"SELECT e.apellido, h.nombre as hotel, idTurno, horae as entrada, horas as salida, puesto, COUNT(idAusencia) as ausencias FROM p1_empleados e RIGHT JOIN p1_hoteles h USING(idHotel) LEFT JOIN p1_turnos USING(idTurno) LEFT JOIN p1_tipoEmpleado USING(idTipo) LEFT JOIN p1_ausencias USING(idEmpleado) GROUP BY idEmpleado;");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  printf("Empleado\t\tHotel\t\tID turno\t\tEntrada\t\tSalida\t\tPuesto\t\t# de Ausencias\n-------------------------------------------------------------------------------------------------------------------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        printf("%s\t\t",row[i]);
      }
    }
    printf("\n");
  }
  mysql_free_result(res);
}
//query7
void CuartosHH(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"SELECT CONCAT(hu.nombre,' ',hu.apellido) as nombre,ho.nombre as hotel,numeroHabitacion FROM p1_huespedes hu LEFT JOIN p1_reservaciones USING(idHuesped) LEFT JOIN p1_habitaciones USING(idHabitacion) LEFT JOIN p1_hoteles ho USING(idHotel) WHERE numeroHabitacion IS NOT NULL;");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  printf("Huésped\t\t\tHotel\t\t# de habitación\n-------------------------------------------------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        printf("%s\t\t",row[i]);
      }
    }
    printf("\n");
  }
  printf("----------------------------------------------\n");
  mysql_free_result(res);
}
/*************
/*query8

/*************/
void Temporadas(MYSQL *mysql){
  char buscar[100],buffer[2048];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"select h.nombre,idTemporada from p1_reservaciones left join p1_habitaciones USING(idHabitacion) left join p1_hoteles h USING(idHotel) where idHotel=1 and idTemporada=(select idTemporada from p1_reservaciones	left join p1_habitaciones USING(idHabitacion)  	left join p1_hoteles h USING(idHotel)  	where idHotel=1 and idTemporada is not null  	group by idTemporada  	order by count(*) desc limit 1)  union  select h.nombre,idTemporada from p1_reservaciones   left join p1_habitaciones USING(idHabitacion) left join p1_hoteles h USING(idHotel) where idHotel=2 and idTemporada=(select idTemporada from p1_reservaciones left join p1_habitaciones USING(idHabitacion) left join p1_hoteles h USING(idHotel) 	where idHotel=2 and idTemporada is not null  	group by idTemporada  	order by count(*) desc limit 1)  union  select h.nombre,idTemporada from p1_reservaciones   left join p1_habitaciones USING(idHabitacion)  left join p1_hoteles h USING(idHotel)  where idHotel=3 and idTemporada=(select idTemporada from p1_reservaciones left join p1_habitaciones USING(idHabitacion)	left join p1_hoteles h USING(idHotel)  	where idHotel=3 and idTemporada is not null  	group by idTemporada  	order by count(*) desc limit 1);");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  printf("Hotel\t\tID de temporada\n-------------------------------------------------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        printf("%s\t\t",row[i]);
      }
    }
    printf("\n");
  }
  printf("----------------------------------------------\n");
  mysql_free_result(res);
}

//query9
void Estadistica(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  float x;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"SELECT (COUNT(sp.idReservacion) + COUNT(idCancelacion))/COUNT(r.idReservacion) AS Porcentaje_sp_cancel FROM p1_reservaciones r LEFT JOIN p1_sin_presentar sp USING(idReservacion) LEFT JOIN p1_cancelaciones USING(idReservacion);");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay presidentes con ese apellido\n");
    return;
  }
  printf("%c de cancelaciones y de huéspedes no presentados\n-----------------------------\n",37);
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        strcpy(buscar, row[i]);
       }
    }
  }
  x=atof(buscar);
  x=x*100;
  printf("%3.2f%c\n",x,37);
  printf("---------------------\n");
  mysql_free_result(res);
}
//query10
void Faltas(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i,dia,mes,anio;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  printf("Que dia?\n");
  __fpurge(stdin);
  scanf("%i",&dia);
  printf("Que mes?\n");
  __fpurge(stdin);
  scanf("%i",&mes);
  printf("Que anio?\n");
  __fpurge(stdin);
  scanf("%i",&anio);
  sprintf(buffer,"SELECT CONCAT(nombre,' ',apellido) FROM p1_ausencias LEFT JOIN p1_empleados USING(idEmpleado) WHERE DAY(fecha)=%i AND MONTH(fecha)=%i AND YEAR(fecha)=%i;",dia,mes,anio);
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay faltas en esa fecha\n");
    return;
  }
  printf("Empleados que han faltado\n--------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        printf("%s\t",row[i]);
      }
    }
    printf("\n");
  }
  mysql_free_result(res);
}
//query11
void Cuenta(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  sprintf(buffer,"SELECT idReservacion,CONCAT(nombre,' ',apellido) AS nombre,hn.tipo,fechaCheckIn,fechaCheckOut,COUNT(DISTINCT pro.idProducto) AS productos, COUNT(DISTINCT s.idServicio) AS servicios,paq.idPaquete,noches+paq.precio+COALESCE(puntos_total,0) as Total FROM p1_reservaciones LEFT JOIN p1_habitacion_noches hn USING(idReservacion) LEFT JOIN p1_res_pro pro USING(idReservacion) LEFT JOIN p1_res_ser s USING(idReservacion) LEFT JOIN p1_huespedes USING(idHuesped) LEFT JOIN p1_paquetes paq USING(idPaquete) LEFT JOIN p1_puntos_negativos USING(idReservacion) WHERE fechaCheckIn IS NOT NULL AND fechaCheckOut IS NOT NULL GROUP BY idReservacion;");
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
    }
    printf("\n");
  }
  mysql_free_result(res);
}
/***********************
/*query12
/**********************/
void procedimiento(MYSQL *mysql){
  char buscar[100],buffer[1024];
  int i, mes, idVendedor;
  float porcentaje;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  printf("***Monto total de ventas***\n");
  printf("ID del vendedor: ");
  scanf("%d", &idVendedor);
  printf("Porcentaje de comisión(0.00-1.00): ");
  scanf("%f", &porcentaje);
  printf("Mes: ");
  scanf("%d", &mes);

  sprintf(buffer, "CALL p1_procedimiento(@montoTotal, @montoCom, @mesO, %d, %1.3f, %d);", idVendedor, porcentaje, mes);
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }

  sprintf(buffer, "SELECT @montoTotal, @montoCom, @mesO;");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("Error con el procedimiento\n");
    return;
  }
  printf("Monto total\tMonto de comisión\t\tMes\n-----------------------------------------------------------------------\n");
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        printf("%s\t\t\t",row[i]);
      }//if
    }
    printf("\n");
  }
  mysql_free_result(res);
}

//agregar empleados
void nuevoEmpleado(MYSQL *mysql){
  char buscar[100],buffer[1024],  nombre[25],  apellido[25],  fechaNac[12];
  char cuenta[25];
  float comision;
  int idTurno, idTipo, idHotel, idPV;
  int i, opc;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  printf("1. Vendedor\n2. Empleado\n3.Gerente\nOpción:" );
  scanf("%i", &opc);
  if(opc==1){
    idTipo=3;
    getchar();
    printf("Nombre: ");
    scanf("%s",nombre);
    printf("Apellido: ");
    scanf("%s",apellido);
    printf("fechaNac (aaaa-mm-dd):");
    scanf("%s",fechaNac);
    printf("Cuenta: ");
    scanf("%s", cuenta);
    printf("Turno: ");
    scanf("%d", &idTurno);
    printf("Punto de venta: ");
    scanf("%i", &idPV);
    printf("Comisión(0.00-1.00): ");
    scanf("%f", &comision);
    if(comision>1.00 && comision<0){
      printf("Dato erŕóneo. Comisión(0.00-1.00): ");
      scanf("%f", &comision);
    }
    sprintf(buffer,"INSERT INTO p1_empleados(nombre, apellido, fechaNac, cuenta, comision, idTurno, idTipo, idPV) VALUES('%s', '%s', '%s', '%s', %1.2f, %d, %d, %d)", nombre, apellido, fechaNac, cuenta, comision, idTurno, idTipo, idPV);
  }//if
  else if(opc==2){
    idTipo=1;
    getchar();
    printf("Nombre: ");
    scanf("%s",nombre);
    printf("Apellido: ");
    scanf("%s",apellido);
    printf("fechaNac (aaaa-mm-dd):");
    scanf("%s",fechaNac);
    printf("Cuenta: ");
    scanf("%s", cuenta);
    printf("Turno: ");
    scanf("%d", &idTurno);
    printf("Hotel: ");
    scanf("%d", &idHotel);
    sprintf(buffer,"INSERT INTO p1_empleados(nombre, apellido, fechaNac, cuenta, idTurno, idTipo, idHotel) VALUES('%s', '%s', '%s', '%s', %d, %d, %d)", nombre, apellido, fechaNac, cuenta, idTurno, idTipo, idHotel);
  }//elif
  else if(opc==3){
    idTipo=2;
    getchar();
    printf("Nombre: ");
    scanf("%s",nombre);
    printf("Apellido: ");
    scanf("%s",apellido);
    printf("fechaNac (aaaa-mm-dd):");
    scanf("%s",fechaNac);
    printf("Cuenta: ");
    scanf("%s", cuenta);
    printf("Turno: ");
    scanf("%d", &idTurno);
    printf("Hotel: ");
    scanf("%d", &idHotel);
    sprintf(buffer,"INSERT INTO p1_empleados(nombre, apellido, fechaNac, cuenta, idTurno, idTipo, idHotel) VALUES('%s', '%s', '%s', '%s', %d, %d, %d)", nombre, apellido, fechaNac, cuenta, idTurno, idTipo, idHotel);
  }//elif
  else{
    printf("Esa opción no es válida\n");
  }
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
}

//agregar huespedes
void nuevoHuesped(MYSQL *mysql){
  char buscar[100],buffer[1024],  nombre[25],  apellido[25],  numTarjeta[20], direccion[50];
  char cuenta[20], contrasenia[20];
  int idCategoria;
  int i, opc, opc1;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");
  printf("1. SILVER\n2. GOLD\nOpción: " );
  scanf("%i", &opc);
  if(opc==1){
    idCategoria=1;
  }//if
  else if(opc==2){
    idCategoria=2;
  }//elif
  else{
    printf("Esa opción no es válida\n");
  }
  getchar();
  printf("Nombre: ");
  gets(nombre);
  printf("Apellido: ");
  gets(apellido);
  printf("Dirección: ");
  gets(direccion);
  printf("# de tarjeta: ");
  gets(numTarjeta);
  printf("¿Quieres dar de alta una cuenta?\n1.Sí\n2.No\nOpción: ");
  scanf("%d", &opc1);
  if(opc1==1){
    printf("Cuenta: ");
    scanf("%s", cuenta);
    printf("Contraseña: ");
    scanf("%s", contrasenia);
  }

  //query
  if(opc1==1){
    sprintf(buffer,"INSERT INTO p1_huespedes(direccion, numTarjeta, contrasenia, cuenta, nombre, apellido,idCategoria) VALUES('%s', '%s', '%s', '%s', '%s', '%s',%d)", direccion, numTarjeta, contrasenia, cuenta, nombre, apellido, idCategoria);
  }
  else{
    sprintf(buffer,"INSERT INTO p1_huespedes(direccion, numTarjeta, nombre, apellido,idCategoria) VALUES('%s', '%s', '%s', '%s', %d)", direccion, numTarjeta, nombre, apellido, idCategoria);
  }
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
}
//agregar reservaciones
void nuevaReservacion(MYSQL *mysql){
  char buscar[100],buffer[1024],  nombre[25],  apellido[25],  numTarjeta[20], direccion[50];
  char cuenta[20], contrasenia[20], fechaInicial[12], fechaSalida[12], fechaCheckIn[12], fechaCheckOut[12], fechaVendido[12];
  int idCategoria, idHabitacion;
  int i, opc, opc1, idEmpleado, idPaquete, idHuesped, idTemporada;
  MYSQL_RES *res;
  MYSQL_ROW row;
  system("clear");

  sprintf(buffer, "SELECT CURRENT_DATE();");
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay reservaciones con ese ID.\n");
    return;
  }
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        strcpy(fechaVendido, row[0]);
      }//if
    }//for
  }
  printf("***Nueva reservación***\n");
  printf("Fecha inicial(aaaa-mm-dd): ");
  scanf("%s", fechaInicial);
  while(strcmp(fechaInicial, fechaVendido)<0){
    printf("Esa fecha es errónea. Fecha inicial(aaaa-mm-dd): ");
    scanf("%s", fechaInicial);
  }
  printf("Fecha salida(aaaa-mm-dd): ");
  scanf("%s", fechaSalida);
  while(strcmp(fechaInicial, fechaSalida)>0){
    printf("Esa fecha es errónea. Fecha salida(aaaa-mm-dd): ");
    scanf("%s", fechaSalida);
  }
  printf("ID de empleado: ");
  scanf("%d", &idEmpleado);
  printf("ID de habitación: ");
  scanf("%d", &idHabitacion);
  printf("ID de paquete: ");
  scanf("%d", &idPaquete);
  printf("ID del huésped: ");
  scanf("%d", &idHuesped);

  printf("¿Está en alguna temporada?\n1.Sí\n2.No\nOpción: ");
  scanf("%d", &opc1);
  if(opc1==1){
    printf("ID de la temporada: ");
    scanf("%d", &idTemporada);
    sprintf(buffer, "INSERT INTO p1_reservaciones(fechaRes, fechaSalida,idEmpleado, idHabitacion, idPaquete, idHuesped, idTemporada, fechaVendido) VALUES('%s','%s',%d,%d,%d,%d,%d,'%s')",fechaInicial, fechaSalida, idEmpleado, idHabitacion, idPaquete, idHuesped, idTemporada, fechaVendido);
  }

  sprintf(buffer, "INSERT INTO p1_reservaciones(fechaRes, fechaSalida, idEmpleado, idHabitacion, idPaquete, idHuesped, fechaVendido) VALUES('%s','%s',%d,%d,%d,%d,'%s')", fechaInicial, fechaSalida, idEmpleado, idHabitacion, idPaquete, idHuesped, fechaVendido);
  //query
  if(mysql_query(mysql,buffer)){
    printf("Error con el query\n");
    return;
  }
  mysql_free_result(res);
}
//agregar check in
void checkIn(MYSQL *mysql){
  char buffer[1024], buf[12], fecha[12];
  int opc, i, idReservacion, bandera;
  bandera=0;
  MYSQL_RES *res;
  MYSQL_ROW row;
  printf("***Check IN***\n");
  printf("ID de reservación: ");
  scanf("%d", &opc);
  /***************
  /*OBTENER idReservacion
  /*****************/
  sprintf(buffer, "SELECT idReservacion, CURRENT_DATE() FROM  p1_reservaciones LEFT JOIN p1_cancelaciones USING(idReservacion) WHERE fechaCheckIn IS NULL AND fechaCheckOut IS NULL AND fechaSalida>current_date() AND fechaRes<=CURRENT_DATE() AND idReservacion=%d AND p1_cancelaciones<>%d;", opc, opc);
  if(mysql_query(mysql,buffer)){
    printf("Esa reservación es inexistente.\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay reservaciones con ese ID.\n");
    return;
  }
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        bandera=1;
        strcpy(buf, row[0]);
        strcpy(fecha, row[1]);
      }//if
    }//for
    printf("\n");
  }
  if(bandera==1){
    idReservacion=atoi(buf);
    sprintf(buffer, "UPDATE p1_reservaciones SET fechaCheckIn = '%s' WHERE idReservacion=%d", fecha, opc);
    if(mysql_query(mysql,buffer)){
      printf("Error en el query.\n");
      return;
    }
    printf("Check In completado para la reservación: %d.\n", opc);
  }//if
  else{
    printf("Error con la reservación\n");
  }//else

  mysql_free_result(res);
}

void checkOut(MYSQL *mysql){
  char buffer[1024], buf[12], fecha[12];
  int opc, i, idReservacion, bandera;
  bandera=0;
  MYSQL_RES *res;
  MYSQL_ROW row;
  printf("***Check OUT***\n");
  printf("ID de reservación: ");
  scanf("%d", &opc);
  sprintf(buffer, "select idReservacion, CURRENT_DATE() from p1_reservaciones WHERE fechaCheckIn<=CURRENT_DATE() AND fechaCheckOut IS NULL AND idReservacion = %d;", opc);
  if(mysql_query(mysql,buffer)){
    printf("Esa reservación es inexistente.\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay reservaciones con ese ID.\n");
    return;
  }
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        bandera=1;
        strcpy(buf, row[0]);
        strcpy(fecha, row[1]);
      }//if
    }//for
    printf("\n");
  }
  if(bandera==1){
    idReservacion=atoi(buf);
    sprintf(buffer, "UPDATE p1_reservaciones SET fechaCheckOut = '%s' WHERE idReservacion=%d", fecha, opc);
    if(mysql_query(mysql,buffer)){
      printf("Error en el query.\n");
      return;
    }
    printf("***Check Out completado para la reservación: %d.***\n", opc);
  }//if
  else{
    printf("***Error con la reservación***\n");
  }//else

  mysql_free_result(res);
}
//agregar cancelación
void nuevaCancelacion(MYSQL *mysql){
  char buffer[1024], buf[12], fecha[12];
  int opc, i, idReservacion, bandera;
  bandera=0;
  MYSQL_RES *res;
  MYSQL_ROW row;
  printf("***Cancelaciones***\n");
  printf("ID de reservación: ");
  scanf("%d", &opc);
  sprintf(buffer, "SELECT idReservacion from p1_reservaciones LEFT JOIN p1_cancelaciones USING(idReservacion) WHERE fechaCheckIn IS NULL AND fechaCheckOut IS NULL AND fechaRes>=CURRENT_DATE()  AND idReservacion=%d;", opc);
  if(mysql_query(mysql,buffer)){
    printf("Esa reservación es inexistente.\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay reservaciones con ese ID.\n");
    return;
  }
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        bandera=1;
        strcpy(buf, row[0]);
      }//if
    }//for
  }
  if(bandera==1){
    idReservacion=atoi(buf);
    sprintf(buffer, "INSERT INTO p1_cancelaciones(idReservacion) VALUES(%d);", opc);
    if(mysql_query(mysql,buffer)){
      printf("Error en el query.\n");
      return;
    }
    printf("Cancelación a %d completada\n", opc);
  }
  else{
    printf("Hay un error en la reservación ingresada\n");
  }
  mysql_free_result(res);
}
//agregar ausencia
void nuevaAusencia(MYSQL *mysql){
  char buffer[1024], buf[12], fecha[12];
  int opc, i, idReservacion, bandera;
  bandera=0;
  MYSQL_RES *res;
  MYSQL_ROW row;
  printf("***Ausencias***\n");
  printf("ID de empleado que ha faltado: ");
  scanf("%d", &opc);

  sprintf(buffer, "SELECT idEmpleado FROM p1_empleados LEFT JOIN p1_ausencias UsiNG(idEmpleado) WHERE fecha=CURRENT_DATE() AND idEmpleado=%d;", opc);
  if(mysql_query(mysql,buffer)){
    printf("Ese ID es inexistente.\n");
    return;
  }
  if(!(res=mysql_store_result(mysql))){
    printf("No hay reservaciones con ese ID.\n");
    return;
  }
  while(row=mysql_fetch_row(res)){
    for(i=0;i<mysql_num_fields(res);i++){
      if(row[i]!=NULL){
        bandera=1;
      }//if
    }//for
  }//while
  if(bandera==1){
    printf("*Ese empleado ya tuvo una inasistencia hoy\n");
  }//if
  else{
    sprintf(buffer, "SELECT CURRENT_DATE()");
    if(mysql_query(mysql,buffer)){
      printf("Ese ID es inexistente.\n");
      return;
    }
    if(!(res=mysql_store_result(mysql))){
      printf("No hay reservaciones con ese ID.\n");
      return;
    }
    while(row=mysql_fetch_row(res)){
      for(i=0;i<mysql_num_fields(res);i++){
        if(row[i]!=NULL){
          if(i==0){
            strcpy(buf, row[i]);
          }//
        }//if
      }//for
    }//while
    sprintf(buffer, "INSERT INTO p1_ausencias(fecha, idEmpleado) VALUES('%s', %d);",buf,opc);
    if(mysql_query(mysql,buffer)){
      printf("Ese ID es inexistente.\n");
      return;
    }
    printf("*Ausencia registrada con éxito\n");
  }//else
  mysql_free_result(res);
}


void nuevoProducto(MYSQL *mysql){
  char buffer[1024], nombre[25];
  int idTipoProducto, puntos;
  printf("***Nuevo producto***\n");
  printf("Nombre del producto: ");
  getchar();
  gets(nombre);
  printf("Puntos: ");
  scanf("%d", &puntos);
  printf("ID del tipo de producto: ");
  scanf("%d",&idTipoProducto);
  sprintf(buffer, "INSERT INTO p1_productos(nombre, puntos, idTipoProducto) VALUES('%s', %d, %d);", nombre, puntos, idTipoProducto);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Producto agregado exitosamente\n");
  }
}

void nuevoTipoHabitacion(MYSQL *mysql){
  char buffer[1024], tipo[25];
  int precio;
  printf("***Nuevo tipo de habitación***\nTipo: ");
  getchar();
  gets(tipo);
  printf("Precio: ");
  scanf("%d", &precio);
  sprintf(buffer, "INSERT INTO p1_tipoHabitacion(tipo, precio) VALUES('%s', %d);", tipo, precio);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Tipo de habitación agregado exitosamente\n");
  }
}

void nuevaHabitacion(MYSQL *mysql){
  char buffer[1024];
  int numeroHabitacion, idTipoHabitacion, idHotel;
  printf("***Nueva habitación***\nID de tipo de habitación: ");
  scanf("%d", &idTipoHabitacion);
  printf("ID del hotel: ");
  scanf("%d", &idHotel);
  printf("Número de habitación: ");
  scanf("%d", &numeroHabitacion);
  sprintf(buffer, "INSERT INTO p1_habitaciones(idTipoHabitacion, idHotel, numeroHabitacion) VALUES(%d, %d,%d);", idTipoHabitacion, idHotel, numeroHabitacion);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Habitación agregada exitosamente\n");
  }

}

void nuevoTipoProducto(MYSQL *mysql){
  char buffer[1024], tipo[25];
  printf("***Nuevo tipo de producto***\nTipo: ");
  getchar();
  gets(tipo);
  sprintf(buffer, "INSERT INTO p1_tipoProducto(tipo) VALUES('%s');", tipo);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Nuevo tipo de producto agregado exitosamente\n");
  }
}

void nuevoTurno(MYSQL *mysql){
  char buffer[1024], horae[12], horas[12];
  printf("***Nuevo turno***\n");
  printf("Hora de entrada(hh:mm:ss): ");
  scanf("%s", horae);
  printf("Hora de salida(hh:mm:ss): ");
  scanf("%s", horas);
  sprintf(buffer, "INSERT INTO p1_turnos(horae, horas) VALUES('%s', '%s');", horae, horas);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Turno agregado exitosamente\n");
  }
}

void nuevoServicio(MYSQL *mysql){
  char buffer[1024], tipo[100];
  int puntos;
  printf("***Nuevo servicio***\nTipo: ");
  getchar();
  gets(tipo);
  printf("Puntos: ");
  scanf("%d", &puntos);
  sprintf(buffer, "INSERT INTO p1_servicios(tipo, puntos) VALUES('%s', %d);", tipo, puntos);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Servicio agregado exitosamente\n");
  }

}

void nuevoPV(MYSQL *mysql){
  char ubicacion[25], nombre[25], buffer[1024];
  printf("***Nuevo Punto de venta***\n");
  printf("Ubicación: ");
  getchar();
  gets(ubicacion);
  printf("Nombre: ");
  gets(nombre);
  sprintf(buffer, "INSERT INTO p1_pv(ubicacion, nombre) VALUES('%s', '%s');", ubicacion, nombre);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Punto de venta agregado exitosamente\n");
  }
}

void nuevoHotel(MYSQL *mysql){
  int cuartos;
  char ubicacion[25], nombre[25], buffer[1024];
  printf("***Nuevo hotel***\n");
  printf("Ubicación: ");
  getchar();
  gets(ubicacion);
  printf("Número de cuartos: ");
  scanf("%d",&cuartos);
  __fpurge(stdin);
  printf("Nombre: ");
  gets(nombre);
  sprintf(buffer, "INSERT INTO p1_hoteles(ubicacion, numeroCuartos, nombre) VALUES('%s', %d, '%s');", ubicacion, cuartos, nombre);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Hotel agregado exitosamente\n");
  }
}

void nuevaCategoria(MYSQL *mysql){
  char buffer[1024], tipo[20];
  printf("***Nueva categoría***\nTipo: ");
  getchar();
  gets(tipo);
  sprintf(buffer, "INSERT INTO p1_categorias(tipoCategoria) VALUES('%s');", tipo);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Categoría agregada exitosamente\n");
  }
}

void nuevoTipoEmpleado(MYSQL *mysql){
  char buffer[1024], puesto[25];
  printf("***Nuevo tipo de empleado***\nPuesto: ");
  getchar();
  gets(puesto);
  sprintf(buffer, "INSERT INTO p1_tipoEmpleado(puesto) VALUES('%s');", puesto);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Tipo de empleado agregado exitosamente\n");
  }
}

void nuevoPaquete(MYSQL *mysql){
  char buffer[1024];
  int puntos;
  float precio;
  printf("***Nuevo paquete***\nPuntos: ");
  scanf("%d", &puntos);
  printf("Precio: ");
  scanf("%f", &precio);
  sprintf(buffer, "INSERT INTO p1_paquetes(puntos, precio) VALUES(%d, %.2f);", puntos, precio);
  if(mysql_query(mysql,buffer)){
    printf("Error al ingresar la información.\n");
    return;
  }
  else{
    printf("*Paquete agregado exitosamente\n");
  }
}

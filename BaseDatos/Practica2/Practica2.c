#include"tipos.h"

int main(int argc,char *argv[]){
  int i=0,op;
  char bufer[1024];
  char *server="localhost";
  char *usr="im18crn";
  char *password="211019";
  char *db="im18crn";
  MYSQL mysql;
  mysql_init(&mysql);
  if(!mysql_real_connect(&mysql,server,usr,password,db,0,NULL,0)){
    printf("Error al conectarse con la base de datos: %s",mysql_error(&mysql));
    exit(1);
  }

  do{
    printf("Qué deseas hacer?\n1. Hoteles con mayor afluencia de huéspedes\n2. Comisiones de todos los empleados\n3. Huéspedes que no hicieron Check In\n");
    printf("4. Lista de todos los huéspedes de todos los hoteles\n5. Lista de ventas que han hecho Check In\n6. Información empleados\n");
    printf("7. Lista de cuartos de cada huésped en cada hotel\n8. Temporada del anio más alta por hotel\n9. Estadística de cancelaciones y sin presentar\n");
    printf("10. Empleados que han faltado en una fecha determinada\n11. Cuenta de cada huésped\n12. Calcular comisión de un vendedor de paquetes\n");
    printf("13. Agregar empleado\n");
    printf("14. Agregar huésped\n");
    printf("15. Para hacer una nueva reservación\n16. Para hacer Check In\n17. Para hacer Check Out\n18. Ingresar nueva cancelación.\n19. Agregar ausencia a empleado\n");
    printf("20. Agregar hotel\n21. Agregar punto de venta.\n22. Agregar turno nuevo.\n23. Agregar tipo de producto.\n24. Agregar producto.\n25. Agregar tipo de habitación.\n");
    printf("26. Agregar habitación.\n27. Nueva categoría.\n28. Nuevo servicio.\n29. Nuevo tipo de empleado\n30. Nuevo paquete.\n");
    printf("31. Salir\n");
    __fpurge(stdin);
    scanf("%i",&op);
    system("clear");
    switch(op){
    case 1:
      MayorAfluencia(&mysql);
      break;
    case 2:
      ComisionEmpleados(&mysql);
      break;
    case 3:
      HuespedSCI(&mysql);
      break;
    case 4:
      HuespedTH(&mysql);
      break;
    case 5:
      VentaCI(&mysql);
      break;
    case 6:
      InfoEmpleados(&mysql);
      break;
    case 7:
      CuartosHH(&mysql);
      break;
    case 8:
      Temporadas(&mysql);
      break;
    case 9:
      Estadistica(&mysql);
      break;
    case 10:
      Faltas(&mysql);
      break;
    case 11:
      Cuenta(&mysql);
      break;
    case 12:
      procedimiento(&mysql);
      break;
    case 13:
      nuevoEmpleado(&mysql);
      break;
    case 14:
      nuevoHuesped(&mysql);
      break;
    case 15:
      nuevaReservacion(&mysql);
      break;
    case 16:
      checkIn(&mysql);
      break;
    case 17:
      checkOut(&mysql);
      break;
    case 18:
      nuevaCancelacion(&mysql);
      break;
    case 19:
      nuevaAusencia(&mysql);
      break;
    case 20:
      nuevoHotel(&mysql);
      break;
    case 21:
      nuevoPV(&mysql);
      break;
    case 22:
      nuevoTurno(&mysql);
      break;
    case 23:
      nuevoTipoProducto(&mysql);
      break;
    case 24:
      nuevoProducto(&mysql);
      break;
    case 25:
      nuevoTipoHabitacion(&mysql);
      break;
    case 26:
      nuevaHabitacion(&mysql);
      break;
    case 27:
      nuevaCategoria(&mysql);
      break;
    case 28:
      nuevoServicio(&mysql);
      break;
    case 29:
      nuevoTipoEmpleado(&mysql);
      break;
    case 30:
      nuevoPaquete(&mysql);
      break;
    case 31:
      i=1;
      break;
    default:
      printf("Opcion no valida\n");
      break;
    }
  }while(i==0);
  mysql_close(&mysql);
}

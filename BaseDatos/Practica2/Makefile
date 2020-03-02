practica2.out:Practica2.o funciones.o
	gcc -o practica2.out Practica2.o funciones.o -lnsl -lm -lz -lmysqlclient

Practica2.o:Practica2.c
	gcc -c Practica2.c

funciones.o:funciones.c
	gcc -c funciones.c

clean:
	rm *.o

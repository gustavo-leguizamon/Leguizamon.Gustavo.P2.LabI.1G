#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../inc/LinkedList.h"
#include "../inc/menu.h"
#include "../inc/Controller.h"
#include "../inc/Movie.h"

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	/*
	int min = 1;
	int max = 10;
	int numero;
	float flotante;

	numero = rand() % (max - min + 1) + min;

	flotante = (float)(rand() % (max - min + 1) + min) / 10; //2 DECIMALES
*/





	int option;
	int result;
	int lenPath = 150;
	char path[lenPath];

	LinkedList* listMovies = ll_newLinkedList();
	if (listMovies == NULL){
		puts("No se pudo iniciar la lista");
		exit(EXIT_FAILURE);
	}

	do{
		option = menu();
		switch(option)
		{
			case optMainLoadTextFile:
				controller_loadNameOfFile(path, lenPath);
				result = controller_loadFromText(path, listMovies);
				if (result == 1){
					puts("Se cargaron los datos desde el archivo");
				}
				else if (result == 2){
					puts("Carga de datos cancelada por el usuario");
				}
				else if(result == 3){
					puts("No se pudo leer el archivo, asegurese de que exista");
				}
				else{
					puts("Ocurrio un error al cargar los datos del archivo");
				}
				break;
			case optMainPrintList:
				if (ll_isEmpty(listMovies)){
					puts("NO hay peliculas cargadas en el sistema");
				}
				else{
					result = controller_listMovies(listMovies);
					if (!result){
						puts("Ocurrio un error al mostrar peliculas");
					}
				}
				break;
			case optMainSetRating:
				if (ll_isEmpty(listMovies)){
					puts("NO hay peliculas cargadas en el sistema");
				}
				else{
					result = controller_setRating(listMovies);
					if (result){
						puts("Se asignaron los ratings");
					}
					else{
						puts("Ocurrio un error al asignar ratings");
					}
				}
				break;
			case optMainSetGenre:
				if (ll_isEmpty(listMovies)){
					puts("NO hay peliculas cargadas en el sistema");
				}
				else{
					result = controller_setGenre(listMovies);
					if (result){
						puts("Se asignaron los generos");
					}
					else{
						puts("Ocurrio un error al asignar generos");
					}
				}
				break;
			case optMainFilterByGenre:
				if (ll_isEmpty(listMovies)){
					puts("NO hay peliculas cargadas en el sistema");
				}
				else{
					result = controller_filterByGenre(listMovies);
					if (result){
						controller_loadNameOfFile(path, lenPath);
						result = controller_saveAsText(path, listMovies);
						if (result){
							if (result == 1){
								printf("Peliculas guardadas con exito en el archivo: %s\n", path);
							}
							else if(result == 5){
								puts("Guardado cancelado por el usuario");
							}
							else{
								puts("Ocurrio un error al intentar guardar el archivo");
							}
						}
						else{
							puts("Ocurrio un error, datos no validos para guardar el archivo");
						}
					}
					else{
						puts("Ocurrio un error al filtrar generos");
					}
				}
				break;
			case optMainSort:
				if (ll_isEmpty(listMovies)){
					puts("NO hay peliculas cargadas en el sistema");
				}
				else{
					result = controller_sortMovies(listMovies);
					if (result == 1){
						puts("Peliculas ordenados");
					}
					else if (result == 2){
						puts("No se selecciono metodo de ordenamiento");
					}
					else{
						puts("Ocurrio un error al ordenar las peliculas");
					}
				}
				break;
			case optMainSaveMovies:
				if (!ll_isEmpty(listMovies)){
					controller_loadNameOfFile(path, lenPath);
					result = controller_saveAsText(path, listMovies);
					if (result){
						if (result == 1){
							printf("Peliculas guardadas con exito en el archivo: %s\n", path);
						}
						else if(result == 5){
							puts("Guardado cancelado por el usuario");
						}
						else{
							puts("Ocurrio un error al intentar guardar el archivo");
						}
					}
					else{
						puts("Ocurrio un error, datos no validos para guardar el archivo");
					}
				}
				else{
					puts("No hay peliculas para guardar en el archivo");
				}
				break;
			case optMainExitMenu:
				break;
			default:
				puts("Opcion invalida");
				break;
		}
		puts("\n");
	} while(option != optMainExitMenu);

	ll_deleteLinkedList(listMovies);

	puts("FIN DEL PROGRAMA");

	return EXIT_SUCCESS;
}

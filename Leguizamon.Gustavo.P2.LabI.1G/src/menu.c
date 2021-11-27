#include <stdio.h>
#include <stdlib.h>

#include "../inc/input.h"
#include "../inc/menu.h"


int menu(){
	int selectedOption;

	printf("%d. Cargar archivo .csv (modo texto)\n", optMainLoadTextFile);
	printf("%d. Imprimir lista\n", optMainPrintList);
	printf("%d. Asignar rating\n", optMainSetRating);
	printf("%d. Asignar genero\n", optMainSetGenre);
	printf("%d. Filtrar por genero\n", optMainFilterByGenre);
	printf("%d. Ordenar peliculas\n", optMainSort);
	printf("%d. Guardar peliculas\n", optMainSaveMovies);
	printf("%d. Salir\n", optMainExitMenu);
	printf("\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}


int submenuFilterGenre(){
	int selectedOption;

	puts("**** SELECCIONE GENERO ***");
	printf("%d. Por Drama\n", optFilterGenreDrama);
	printf("%d. Por Comedia\n", optFilterGenreComedy);
	printf("%d. Por Accion\n", optFilterGenreAction);
	printf("%d. Por Terror\n", optFilterGenreTerror);
	printf("\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}

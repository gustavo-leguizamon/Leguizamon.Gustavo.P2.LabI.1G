#include <stdio.h>
#include <stdlib.h>

#include "../inc/input.h"
#include "../inc/menu.h"


int menu(){
	int selectedOption;

	//puts("**** ABM DE EMPLEADOS ****");
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


int submenuOrder(){
	int selectedOption;

	puts("**** TIPO DE ORDENAMIENTO ***");
	printf("%d. Por ID\n", optOrderId);
	printf("%d. Por Nombre\n", optOrderName);
	printf("%d. Salir\n", optOrderExitMenu);
	printf("\n");

	getInt("Ingrese una opcion: ", &selectedOption);
	puts("");

	return selectedOption;
}


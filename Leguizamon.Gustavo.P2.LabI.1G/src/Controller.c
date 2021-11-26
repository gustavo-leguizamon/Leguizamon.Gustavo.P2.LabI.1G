#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Movie.h"
#include "../inc/parser.h"
//#include "output.h"
#include "../inc/menu.h"
#include "../inc/input.h"



int controller_loadNameOfFile(char* fileName, int len){
	int result = 0;

	if (fileName != NULL){
		getString("Indique el path del archivo: ", fileName, len);
		result = 1;
	}

	return result;
}


int controller_loadFromText(char* path, LinkedList* pMovies)
{
	int result = 0;
	char confirmDeleteData = 's';

	if (path != NULL && pMovies != NULL){
		FILE* file = fopen(path, "r");
		if (file != NULL){
			//CONFIRM OVERRIDE DATA IF EXISTS
			if (!ll_isEmpty(pMovies)){
				getChar("Hay datos cargados, si continua se sobreescribiran. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				while (confirmDeleteData != 'n' && confirmDeleteData != 's'){
					getChar("Escriba n o s. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				}
			}

			if (confirmDeleteData == 's'){
				ll_clear(pMovies);
				if (parser_MoviesFromText(file, pMovies)){
					result = 1;
				}
			}
			else{
				result = 2;
			}

			fclose(file);
		}
		else{
			result = 3;
		}
	}

    return result;
}

/*
int controller_loadFromBinary(char* path, LinkedList* pMovies)
{
	int result = 0;
	char confirmDeleteData = 's';

	if (path != NULL && pMovies != NULL){
		FILE* file = fopen(path, "rb");
		if (file != NULL){
			if (!ll_isEmpty(pMovies)){
				getChar("Hay datos cargados, si continua se sobreescribiran. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				while (confirmDeleteData != 'n' && confirmDeleteData != 's'){
					getChar("Escriba n o s. Confirma sobreescritura de datos actuales? n(NO) - s(SI): ", &confirmDeleteData);
				}
			}

			if (confirmDeleteData == 's'){
				ll_clear(pMovies);
				if (parser_MoviesFromBinary(file, pMovies) == 1){
					result = 1;
				}
			}
			else{
				result = 2;
			}

			fclose(file);
		}
		else{
			result = 3;
		}
	}

    return result;
}
*/

int controller_listPets(LinkedList* pMovies)
{
	return movie_showMovies(pMovies);
}

/*
int controller_sortPets(LinkedList* pPets)
{
    int result = 0;
    int option;

    if (pPets != NULL){
    	result = 1;

    	//ll_sort(LinkedList* this, int(*)(void*,void*) pFunc, int order)
    	option = submenuOrder();
    	switch(option){
			case optOrderId:
		    	puts("Ordenando las mascotas por ID...Por favor espere");
		    	ll_sort(pPets, pet_compareById, 1);
				break;
			case optOrderName:
		    	puts("Ordenando las mascotas por nombre...Por favor espere");
		    	ll_sort(pPets, pet_compareByName, 1);
				break;
			case optOrderExitMenu:
				result = 2;
				break;
			default:
				puts("Opcion invalida");
				break;
    	}
		puts("\n");
    }

    return result;
}
*/

int controller_saveAsText(char* path, LinkedList* pMovies)
{
	int result = 0;
	eMovie* auxMovie = NULL;
	char confirm = 's';
	int count;
	int id;
	char title[128];
	char genre[128];
	float rating;

	if (path != NULL && pMovies != NULL){
		FILE* fileR = fopen(path, "r");
		if (fileR != NULL){
			getChar("Existe otro archivo con el mismo nombre. Confirma sobreescribirlo? n(NO) - s(SI): ", &confirm);
			while (confirm != 'n' && confirm != 's'){
				getChar("Escriba n o s. Confirma sobreescribir el archivo? n(NO) - s(SI): ", &confirm);
			}
			fclose(fileR);
		}

		if (confirm == 's'){
			FILE* file = fopen(path, "w");
			if (file != NULL){
				result = 1;
				fprintf(file, "id,titulo,genero,rating\n"); //PRINT HEADER

				for (int i = 0; i < ll_len(pMovies); i++){
					auxMovie = (eMovie*)ll_get(pMovies, i);
					if (auxMovie != NULL &&
						movie_getId(auxMovie, &id) &&
						movie_getTitulo(auxMovie, title) &&
						movie_getGenero(auxMovie, genre) &&
						movie_getRating(auxMovie, &rating)){
						count = fprintf(file, "%d,%s,%s,%f\n", id, title, genre, rating);

						if (count < 4){
							result = 3;
							break;
						}
					}
					else{
						result = 4;
						break;
					}
				}
				fclose(file);
			}
			else{
				result = 2;
			}
		}
		else{
			result = 5;
		}
	}

    return result;
}



int controller_saveAsBinary(char* path, LinkedList* pMovies)
{
	int result = 0;
	eMovie* auxMovie = NULL;
	char confirm = 's';
	int count;

	if (path != NULL && pMovies != NULL){
		FILE* fileR = fopen(path, "r");
		if (fileR != NULL){
			getChar("Existe otro archivo con el mismo nombre. Confirma sobreescribirlo? n(NO) - s(SI): ", &confirm);
			while (confirm != 'n' && confirm != 's'){
				getChar("Escriba n o s. Confirma sobreescribir el archivo? n(NO) - s(SI): ", &confirm);
			}
			fclose(fileR);
		}

		if (confirm == 's'){
			FILE* file = fopen(path, "wb");
			if (file != NULL){
				result = 1;

				for (int i = 0; i < ll_len(pMovies); i++){
					auxMovie = (eMovie*)ll_get(pMovies, i);
					if (auxMovie != NULL){
						count = fwrite(auxMovie, sizeof(eMovie), 1, file);

						if (count < 1){
							result = 3;
							break;
						}
					}
					else{
						result = 4;
						break;
					}
				}

				fclose(file);
			}
			else{
				result = 2;
			}
		}
		else{
			result = 5;
		}
	}

	return result;
}



#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Movie.h"
#include "../inc/parser.h"


int parser_MoviesFromText(FILE* pFile, LinkedList* pMovies)
{
	int success = 0;
	char buffer[4][128];
	int count;
	eMovie* auxMovie = NULL;

	if (pFile != NULL && pMovies != NULL){
		//SALTO CABECERA
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		do{
			count = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if (count < 4){
				break;
			}

			auxMovie = movie_newParametersStr(buffer[0], buffer[1], buffer[2], buffer[3]);
			if  (auxMovie != NULL){
				ll_add(pMovies, auxMovie);
				auxMovie = NULL;
			}
		} while(!feof(pFile));
		success = 1;
	}

    return success;
}

/*
int parser_MoviesFromBinary(FILE* pFile, LinkedList* pPets)
{
	int result = 0;
	eMovie* auxMovie = NULL;
	int count;

	if (pFile != NULL && pPets != NULL){
		result = 1; //"Pelicula cargados correctamente"
		while(!feof(pFile)){
			auxMovie = pet_new();
			if (auxMovie != NULL){
				count = fread(auxMovie, sizeof(eMovie), 1, pFile);
				if (count == 1){
					ll_add(pPets, auxMovie);
					auxMovie = NULL;
				}
				else{
					if (feof(pFile)){
						pet_delete(auxMovie);
						break;
					}
					result = 2; //"Hubo problemas para leer la pelicula"
					break;
				}
			}
			else{
				result = 3; //"Hubo problemas para crear la pelicula"
				break;
			}
		}
	}

	return result;
}
*/

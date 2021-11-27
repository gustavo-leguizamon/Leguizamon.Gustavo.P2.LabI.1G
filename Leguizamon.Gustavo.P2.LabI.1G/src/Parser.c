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

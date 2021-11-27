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

int controller_listMovies(LinkedList* pMovies)
{
	return movie_showMovies(pMovies);
}


int controller_sortMovies(LinkedList* pMovies)
{
    int result = 0;

    if (pMovies != NULL){
    	result = 1;

		puts("\n");
    	puts("Ordenando las peliculas por GENERO y RATING...Por favor espere");
    	ll_sort(pMovies, movie_compareByGenreRating, 1);
    }

    return result;
}


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



int controller_setRating(LinkedList* pMovies){
	int result = 0;
	LinkedList* listOfRatings = NULL;
	int lenRatings;
	eMovie* auxMovie = NULL;


	if (pMovies != NULL){
		listOfRatings = ll_map(pMovies, movie_mapRating);
		if (listOfRatings != NULL){
			ll_clear(pMovies);
			lenRatings = ll_len(listOfRatings);
			for (int i = 0; i < lenRatings; i++){
				auxMovie = (eMovie*)ll_get(listOfRatings, i);
				ll_add(pMovies, auxMovie);
			}
			result = 1;
		}
	}

	return result;
}



int controller_setGenre(LinkedList* pMovies){
	int result = 0;
	LinkedList* listOfGenres = NULL;
	int lenGenres;
	eMovie* auxMovie = NULL;


	if (pMovies != NULL){
		listOfGenres = ll_map(pMovies, movie_mapGenre);
		if (listOfGenres != NULL){
			ll_clear(pMovies);
			lenGenres = ll_len(listOfGenres);
			for (int i = 0; i < lenGenres; i++){
				auxMovie = (eMovie*)ll_get(listOfGenres, i);
				ll_add(pMovies, auxMovie);
			}
			result = 1;
		}
	}

	return result;
}


int controller_filterByGenre(LinkedList* pMovies){
	int result = 0;
	LinkedList* listOfGenres = NULL;
	int lenGenres;
	eMovie* auxMovie = NULL;
	int option;

	if (pMovies != NULL){
		option = submenuFilterGenre();
		switch(option){
			case optFilterGenreDrama:
				listOfGenres = ll_filter(pMovies, movie_filterGenreDrama);
				break;
			case optFilterGenreComedy:
				listOfGenres = ll_filter(pMovies, movie_filterGenreComedy);
				break;
			case optFilterGenreAction:
				listOfGenres = ll_filter(pMovies, movie_filterGenreAction);
				break;
			case optFilterGenreTerror:
				listOfGenres = ll_filter(pMovies, movie_filterGenreTerror);
				break;
			default:
				puts("Opcion invalida");
				break;
		}
		puts("\n");

		if (listOfGenres != NULL){
			ll_clear(pMovies);
			lenGenres = ll_len(listOfGenres);
			for (int i = 0; i < lenGenres; i++){
				auxMovie = (eMovie*)ll_get(listOfGenres, i);
				ll_add(pMovies, auxMovie);
			}
			result = 1;
		}
	}

	return result;
}

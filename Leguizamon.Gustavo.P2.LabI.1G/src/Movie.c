#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
#include "../inc/Movie.h"
#include "../inc/input.h"

eMovie* movie_new(){
	eMovie* newMovie = NULL;

	newMovie = (eMovie*)malloc(sizeof(eMovie)); //calloc(cantidad, sizeof) //inicializa estrustura en vacios
	if (newMovie != NULL){
		newMovie->id_peli = 0;
		strcpy(newMovie->titulo, "");
		strcpy(newMovie->genero, "");
		newMovie->rating = 0;
	}

	return newMovie;
}



eMovie* movie_newParameters(int id, char* titulo, char* genero, float rating){
	eMovie* newMovie;

	newMovie = movie_new();
	if (newMovie != NULL){
		if (!(movie_setId(newMovie, id) &&
			  movie_setTitulo(newMovie, titulo) &&
		      movie_setGenero(newMovie, genero) &&
			  movie_setRating(newMovie, rating))){
			free(newMovie);
			newMovie = NULL;
		}
	}

	return newMovie;
}



eMovie* movie_newParametersStr(char* idStr, char* tituloStr, char* generoStr, char* ratingStr){
	return movie_newParameters(atoi(idStr), tituloStr, generoStr, atof(ratingStr));
}




//GETTERS
int movie_getId(eMovie* this, int* pId){
	int success = 0;

	if (this != NULL && pId != NULL){
		*pId = this->id_peli;
		success = 1;
	}

	return success;
}


int movie_getTitulo(eMovie* this, char* pTitulo){
	int success = 0;

	if (this != NULL && pTitulo != NULL){
		strcpy(pTitulo, this->titulo);
		success = 1;
	}

	return success;
}

int movie_getGenero(eMovie* this, char* pGenero){
	int success = 0;

	if (this != NULL && pGenero != NULL){
		strcpy(pGenero, this->genero);
		success = 1;
	}

	return success;
}

int movie_getRating(eMovie* this, float* pRating){
	int success = 0;

	if (this != NULL && pRating != NULL){
		*pRating = this->rating;
		success = 1;
	}

	return success;
}


//SETTERS
int movie_setId(eMovie* this, int id){
	int success = 0;

	if (this != NULL && id > 0){
		this->id_peli = id;
		success = 1;
	}

	return success;
}


int movie_setTitulo(eMovie* this, char* titulo){
	int success = 0;

	if (this != NULL && titulo != NULL && strlen(titulo) > 0 && strlen(titulo) < 128){
		strcpy(this->titulo, titulo);
		success = 1;
	}

	return success;
}

int movie_setGenero(eMovie* this, char* genero){
	int success = 0;

	if (this != NULL && genero != NULL && strlen(genero) > 0 && strlen(genero) < 128){
		strcpy(this->genero, genero);
		success = 1;
	}

	return success;
}

int movie_setRating(eMovie* this, float rating){
	int success = 0;

	if (this != NULL){
		this->rating = rating;
		success = 1;
	}

	return success;
}






void movie_printHeaderReport(){
	printf("| %4s | %-30s | %-20s | %10s |\n", "ID", "TITULO", "GENERO", "RATING");
}


int movie_showMovie(eMovie* pMovie){
	int result = 0;
	int id;
	char title[128];
	char genre[128];
	float rating;

	if (pMovie != NULL &&
		movie_getId(pMovie, &id) &&
		movie_getTitulo(pMovie, title) &&
		movie_getGenero(pMovie, genre) &&
		movie_getRating(pMovie, &rating)){
		printf("| %4d | %-30s | %-20s | %.1f \n", id, title, genre, rating);
		result = 1;
	}

	return result;
}


int movie_showMovies(LinkedList* pMovies){
	int result = 0;
	eMovie* auxMovie = NULL;

	if (pMovies != NULL){
		//printHeader(columns, lengths, lenColumns);
		movie_printHeaderReport();
		for (int i = 0; i < ll_len(pMovies); i++){
			auxMovie = (eMovie*)ll_get(pMovies, i);
			movie_showMovie(auxMovie);
			//printFooter(lengths, lenColumns);
		}
		result = 1;
	}

    return result;
}

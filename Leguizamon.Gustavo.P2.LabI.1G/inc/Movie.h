#ifndef MOVIE_H_
#define MOVIE_H_

typedef struct {
	int id_peli;
	char titulo[128];
	char genero[128];
	float rating;
} eMovie;

#endif /* MOVIE_H_ */



#include "../inc/LinkedList.h"

eMovie* movie_new();
eMovie* movie_newParameters(int id, char* titulo, char* genero, float rating);
eMovie* movie_newParametersStr(char* idStr, char* tituloStr, char* generoStr, char* ratingStr);



//GETTERS
int movie_getId(eMovie* this, int* pId);
int movie_getTitulo(eMovie* this, char* pTitulo);
int movie_getGenero(eMovie* this, char* pGenero);
int movie_getRating(eMovie* this, float* pRating);


//SETTERS
int movie_setId(eMovie* this, int id);

int movie_setTitulo(eMovie* this, char* titulo);
int movie_setGenero(eMovie* this, char* genero);
int movie_setRating(eMovie* this, float rating);






void movie_printHeaderReport();

int movie_showMovie(eMovie* pMovie);

int movie_showMovies(LinkedList* pMovies);

int movie_compareByGenreRating(void* pMovieA, void* pMovieB);

void* movie_mapRating(void* object);
void* movie_mapGenre(void* object);


int movie_filterGenreDrama(void* object);
int movie_filterGenreComedy(void* object);
int movie_filterGenreAction(void* object);
int movie_filterGenreTerror(void* object);

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_


/**
 * @brief Request path of file to load
 *
 * @param fileName char*
 * @return int 0: Error in parameters - 1: Ok
 */
int controller_loadNameOfFile(char* fileName, int len);

/**
 * @brief Load data of movies from file .csv (text mode).
 *
 * @param path char*
 * @param pMovies LinkedList*
 * @return int 0: Error to load file - 1: Ok - 2: Load cancelled by user - 3: Error to read file
 */
int controller_loadFromText(char* path, LinkedList* pMovies);



/**
 * @brief List movies
 *
 * @param pMovies LinkedList*
 * @return int 0: Error in parameters - 1: Ok
 */
int controller_listMovies(LinkedList* pMovies);


/**
 * @brief Sort movies
 *
 * @param pMovies LinkedList*
 * @return int 0: Error in parameters - 1: Ok
 */
int controller_sortMovies(LinkedList* pMovies);


/**
 * @brief Save data of movies in file .csv (text mode).
 *
 * @param path char*
 * @param pMovies LinkedList*
 * @return int 0: Error in parameters - 1: Ok - 2: Error to open file - 3: Error to save data - 4: Error in data of employee - 5: Cancelled by user
 */
int controller_saveAsText(char* path , LinkedList* pMovies);



int controller_setRating(LinkedList* pMovies);


int controller_setGenre(LinkedList* pMovies);


int controller_filterByGenre(LinkedList* pMovies);

#endif /* INC_CONTROLLER_H_ */

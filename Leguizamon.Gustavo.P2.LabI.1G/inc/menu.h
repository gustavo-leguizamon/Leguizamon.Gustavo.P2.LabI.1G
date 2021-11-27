#ifndef SRC_MENU_H_
#define SRC_MENU_H_

enum enumMainMenu {
	optMainLoadTextFile = 1,
	optMainPrintList,
	optMainSetRating,
	optMainSetGenre,
	optMainFilterByGenre,
	optMainSort,
	optMainSaveMovies,
	optMainExitMenu
};


enum enumFilterGenreMenu {
	optFilterGenreDrama = 1,
	optFilterGenreComedy,
	optFilterGenreAction,
	optFilterGenreTerror
};



#endif /* SRC_MENU_H_ */


/**
 * @brief Displays a menu of options
 *
 * @return Selected option
 */
int menu();


/**
 * @brief Displays a menu of options for order pets
 *
 * @return Selected option
 */
int submenuFilterGenre();

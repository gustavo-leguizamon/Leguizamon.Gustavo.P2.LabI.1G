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
 * @brief Load data of pets from file data.csv (text mode).
 *
 * @param path char*
 * @param pPets LinkedList*
 * @return int 0: Error to load file - 1: Ok - 2: Load cancelled by user - 3: Error to read file
 */
int controller_loadFromText(char* path, LinkedList* pPets);


/**
 * @brief Load data of pets from file data.bin (binary mode).
 *
 * @param path char*
 * @param pPets LinkedList*
 * @return int 0: Error to load file - 1: Ok - 2: Load cancelled by user - 3: Error to read file
 */
int controller_loadFromBinary(char* path, LinkedList* pPets);



/**
 * @brief Add a new pet
 *
 * @param pPets LinkedList*
 * @param pId int*
 * @param pathIdFile char*
 * @return int 0: Error in parameters - 1: Ok - 2: Error in data from user - 3: Error to build employee - 4: Error to add employee in LinkedList
 */
int controller_addPet(LinkedList* pPets, int* pNextId);



/**
 * @brief Remove a pet
 *
 * @param pPets LinkedList*
 * @return int 0: Error in parameters - 1: Ok - 2: Canceled by user
 */
int controller_removePet(LinkedList* pPets);


/**
 * @brief List pets
 *
 * @param pPets LinkedList*
 * @return int 0: Error in parameters - 1: Ok
 */
int controller_listPets(LinkedList* pPets);


/**
 * @brief Sort pets
 *
 * @param pPets LinkedList*
 * @return int 0: Error in parameters - 1: Ok
 */
int controller_sortPets(LinkedList* pPets);


/**
 * @brief Save data of pets in file data.csv (text mode).
 *
 * @param path char*
 * @param pPets LinkedList*
 * @return int 0: Error in parameters - 1: Ok - 2: Error to open file - 3: Error to save data - 4: Error in data of employee - 5: Cancelled by user
 */
int controller_saveAsText(char* path , LinkedList* pPets);


/**
 * @brief Save data of pets in file data.bin (binary mode).
 *
 * @param path char*
 * @param pPets LinkedList*
 * @return int 0: Error in parameters - 1: Ok - 2: Error to open file - 3: Error to save data - 4: Error in data of employee - 5: Cancelled by user
 */
int controller_saveAsBinary(char* path, LinkedList* pPets);


/**
 * @brief Add a new appointment
 *
 * @param pAppointments LinkedList*
 * @param pPets LinkedList*
 * @return 0: Error in parameters - 1: Ok
 */
int controller_addAppointment(LinkedList* pAppointments, LinkedList* pPets);


/**
 * @brief Show number of order
 *
 * @param pAppointments LinkedList*
 * @param pPets LinkedList*
 * @return 0: Error in parameters - 1: ok
 */
int controller_orderOfAppointment(LinkedList* pAppointments, LinkedList* pPets);


/**
 * @brief Attend first pet in list of appointments
 *
 * @param pAppointments LinkedList*
 * @return int 0: Error in parameters - 1: ok
 */
int controller_attendPet(LinkedList* pAppointments);


#endif /* INC_CONTROLLER_H_ */

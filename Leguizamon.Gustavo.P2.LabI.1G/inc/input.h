

#include "fecha.h"

#ifndef INPUT_H_
#define INPUT_H_



#endif /* INPUT_H_ */

int getInt(char* message, int* input);

int getFloat(char* message, float* input);

int getChar(char* message, char* input);

int getString(char* message, char* input, int len);

int getDate(char* message, eFecha* input);

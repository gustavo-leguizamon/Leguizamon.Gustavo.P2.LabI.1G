#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/input.h"

int getInt(char* message, int* input){
	int success = 0;

	if (message != NULL && input != NULL){
		printf("%s", message);

		success = scanf("%d", input);

		while (!success){
			puts("Dato invalido. Debe ingresar un numero.");
			printf("%s", message);
			fflush(stdin);
			success = scanf("%d", input);
		}
	}

	return success;
}

int getFloat(char* message, float* input){
	int success = 0;

	if (message != NULL && input != NULL){
		printf("%s", message);

		success = scanf("%f", input);

		while (!success){
			puts("Dato invalido. Debe ingresar un numero.");
			printf("%s", message);
			fflush(stdin);
			success = scanf("%f", input);
		}
	}

	return success;
}

int getChar(char* message, char* input){
	int success = 0;

	if (message != NULL && input != NULL){
		printf("%s", message);
		fflush(stdin);
		scanf("%c", input);

		success = 1;
	}

	return success;
}

int getString(char* message, char* input, int len){
	int success = 0;

	char auxStr[len];

	if (message != NULL && input != NULL && len > 0){
		printf("%s", message);
		fflush(stdin);
		gets(auxStr);

		while (strlen(auxStr) > len){
			printf("Reingrese un texto mas corto, hasta %d caracteres", len - 1);
			fflush(stdin);
			gets(auxStr);
		}

		strcpy(input, auxStr);

		success = 1;
	}

	return success;
}

int getDate(char* message, eFecha* input){
	int success = 0;

	if (message != NULL && input != NULL){
		printf("%s", message);
		fflush(stdin);
		success = scanf("%d/%d/%d", &input->dia, &input->mes, &input->anio);

		while (success < 3){
			puts("Dato invalido. Debe ingresar una fecha en el formato dd/mm/aaaa.");
			printf("%s", message);
			fflush(stdin);
			success = scanf("%d/%d/%d", &input->dia, &input->mes, &input->anio);
		}

		success = 1;
	}

	return success;
}



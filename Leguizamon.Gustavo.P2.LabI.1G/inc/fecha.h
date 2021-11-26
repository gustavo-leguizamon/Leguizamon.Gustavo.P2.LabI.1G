#ifndef FECHA_H_
#define FECHA_H_

typedef struct{
	int dia;
	int mes;
	int anio;
} eFecha;

#endif /* FECHA_H_ */


int validarFecha(eFecha fecha);

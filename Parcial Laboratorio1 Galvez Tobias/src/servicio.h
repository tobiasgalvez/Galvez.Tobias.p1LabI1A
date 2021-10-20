/*
 * servicio.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int id;
	char descripcion[25];
	float precio;
}eServicio;

int listarServicios(eServicio lista[], int tam);
int cargarServicio(int id, eServicio lista[], int tam,char destino[]);


#endif /* SERVICIO_H_ */

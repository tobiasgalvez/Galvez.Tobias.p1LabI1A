/*
 * trabajo.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */

#include "fecha.h"
#include "mascota.h"
#include "color.h"
#include "tipos.h"
#include "servicio.h"


#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct
{
	int id;
	int idMascota;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

int inicializarTrabajo(eTrabajo lista[], int tam);
int buscarLibreTrabajo(eTrabajo lista[], int tam);
int altaTrabajo(eMascota mascota[], int tam, eColor colores[], int tamCol,eTipo tipos[], int tamTip,  int* pId, eTrabajo lista[], int tamTrabajo, eServicio servicios[], int tamServ);
int buscarMascotaId(eMascota lista[], int tam, int id);
int mostrarTrabajo(eMascota mascotas[],int tam,eServicio servicios[], int tamServ, eTrabajo trabajo);



#endif /* TRABAJO_H_ */

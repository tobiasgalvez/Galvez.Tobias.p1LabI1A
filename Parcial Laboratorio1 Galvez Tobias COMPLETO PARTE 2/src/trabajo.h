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
#include "cliente.h"


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


/**
 * Funcion que inicializa todos los isEmpty de trabajos en "VACIO"
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int inicializarTrabajo(eTrabajo lista[], int tam);
/**
 * Funcion que permite buscar si hay espacio libre para dar de alta un trabajo
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam);
/**
 * Funcion que permite dar de alta un trabajo
 * @param mascota
 * @param tamMascotas
 * @param colores
 * @param tamCol
 * @param tipos
 * @param tamTip
 * @param pId
 * @param lista
 * @param tam
 * @param servicios
 * @param tamServ
 * @return 1 si tuvo exito, y 0 si no.
 */
int altaTrabajo(eMascota mascota[], int tamMascotas, eColor colores[], int tamCol,eTipo tipos[], int tamTip,  int* pId, eTrabajo lista[], int tam, eServicio servicios[], int tamServ, eCliente clientes[], int tamCli);
/**
 * Funcion que permite mostrar un solo trabajo realizado
 * @param trabajo
 * @param mascotas
 * @param tam
 * @param servicios
 * @param tamServ
 * @return 1 si tuvo exito, y 0 si no.
 */
int mostrarTrabajo(eTrabajo trabajo,eMascota mascotas[],int tam,eServicio servicios[], int tamServ);
/**
 * Funcion que permite mostrar una lista de todos los trabajos realizados
 * @param lista
 * @param tam
 * @param mascotas
 * @param tamMascotas
 * @param servicios
 * @param tamServ
 * @return 1 si tuvo exito, y 0 si no.
 */
int mostrarTrabajos( eTrabajo lista[], int tam,eMascota mascotas[], int tamMascotas,eServicio servicios[], int tamServ);



#endif /* TRABAJO_H_ */

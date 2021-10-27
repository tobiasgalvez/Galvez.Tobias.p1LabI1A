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


/**
 * Funcion que permite listar los servicios
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int listarServicios(eServicio lista[], int tam);
/**
 * Funcion que permite cargar la descripcion del servicio elegido por id
 * @param id
 * @param lista
 * @param tam
 * @param destino
 * @return 1 si tuvo exito, y 0 si no.
 */
int cargarServicio(int id, eServicio lista[], int tam,char destino[]);

/**
 * Funcion que permite mostrar un servicio
 * @param trabajo
 * @param mascotas
 * @param tamMascotas
 * @param servicios
 * @param tamServ
 * @return 1 si tuvo exito, y 0 si no.
 */
int mostrarServicio(eTrabajo trabajo,eMascota mascotas[],int tamMascotas,eServicio servicios[], int tamServ);

#endif /* SERVICIO_H_ */

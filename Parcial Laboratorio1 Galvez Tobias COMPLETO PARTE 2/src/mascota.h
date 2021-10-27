/*
 * mascota.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */

#include "UTN.h"
#include "color.h"
#include "tipos.h"
#include "cliente.h"

#ifndef MASCOTA_H_
#define MASCOTA_H_

typedef struct
{
	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int edad;
	char vacunado;
	int idCliente;
	int isEmpty;
}eMascota;

/**
 * Funcion que permite mostrar el menú de mascotas
 * @return opcion ingresada
 */
int menu();
/**
 * Funcion que inicializa todos los isEmpty de mascotas en "VACIO"
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int inicializarMascota(eMascota lista[], int tam);
/**
 * Funcion que permite buscar si hay espacio libre para dar de alta una mascota
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int buscarLibre(eMascota lista[], int tam);
/**
 * Funcion que permite buscar una mascota por id
 * @param lista
 * @param tam
 * @param id
 * @return 1 si tuvo exito, y 0 si no.
 */
int buscarMascotaId(eMascota lista[], int tam, int id);
/**
 * Funcion que permite dar de alta una mascota
 * @param lista
 * @param tam
 * @param colores
 * @param tamCol
 * @param tipos
 * @param tamTip
 * @param pId
 * @return 1 si tuvo exito, y 0 si no.
 */
int altaMascota(eMascota lista[], int tam, eColor colores[], int tamCol,eTipo tipos[], int tamTip,  int* pId, eCliente clientes[], int tamCli);

/**
 * Funcion que permite mostrar el menú de modificación de mascotas
 * @return opcion ingresada
 */
int menuModificacion();
/**
 * Funcion que permite modificar una mascota
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @return 1 si tuvo exito, y 0 si no.
 */
int modificarMascota(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol,eCliente clientes[], int tamCli);
/**
 * Funcion que permite dar de baja una mascota
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @return 1 si tuvo exito, y 0 si no.
 */
int bajaMascota(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli);
/**
 * Funcion que permite mostrar una mascota
 * @param mascota
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @return 1 si tuvo exito, y 0 si no.
 */
int mostrarMascota(eMascota mascota,eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli);
/**
 * Funcion que permite ordenar mascotas por tipo y por nombre
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int ordenarMascotas(eMascota lista[], int tam);
/**
 * Funcion que permite mostrar todas las mascotas
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @return 1 si tuvo exito, y 0 si no.
 */
int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli);
/**
 * Funcion que permite cargar el nombre de la mascota elegida por id
 * @param id
 * @param lista
 * @param tam
 * @param destino
 * @return 1 si tuvo exito, y 0 si no.
 */
int cargarMascota(int id, eMascota lista[], int tam,char destino[]);


/**
 * Funcion que permite mostrar las mascotas del id del color ingresado
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @param clientes
 * @param tamCli
 * @param idColor
 * @return 1 si tuvo exito, y 0 si no.
 */
int mostrarMascotasColorId(eMascota lista[],int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli, int idColor );
/**
 * Funcion que permite mostrar las mascotasd del id del tipo ingresado
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @param clientes
 * @param tamCli
 * @param idTipo
 * @return 1 si tuvo exito, y 0 si no.
 */
int mostrarMascotasTipoId(eMascota lista[],int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli, int idTipo );



#endif /* MASCOTA_H_ */

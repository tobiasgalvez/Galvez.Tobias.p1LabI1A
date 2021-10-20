/*
 * mascota.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */

#include "UTN.h"
#include "color.h"
#include "tipos.h"

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
	int isEmpty;
}eMascota;


int menu();
int inicializarMascota(eMascota lista[], int tam);
int buscarLibre(eMascota lista[], int tam);
int buscarMascotaId(eMascota lista[], int tam, int id);
int altaMascota(eMascota lista[], int tam, eColor colores[], int tamCol,eTipo tipos[], int tamTip,  int* pId);

int menuModificacion();
int modificarMascota(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int bajaMascota(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int mostrarMascota(eMascota mascota,eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int ordenarMascotas(eMascota lista[], int tam);
int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int cargarMascota(int id, eMascota lista[], int tam,char destino[]);



#endif /* MASCOTA_H_ */

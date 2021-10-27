/*
 * informes.h
 *
 *  Created on: 27 oct. 2021
 *      Author: Tobias Galvez
 */

#include "UTN.h"
#include "color.h"
#include "tipos.h"
#include "cliente.h"
#include "mascota.h"
#include "trabajo.h"

#ifndef INFORMES_H_
#define INFORMES_H_


/**
 * Funcion que permite mostrar el menu de informes
 * @return opcion ingresada
 */
int menuInformes();
/**
 * Funcion que permite informar las mascotas del color seleccionado por el usuario
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @param clientes
 * @param tamCli
 * @return 1 si tuvo exito, y 0 si no.
 */
int informeMascotasColor(eMascota lista[],int tam,eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli);
/**
 * Funcion que permite informar el promedio de mascotas vacunadas sobre el total de mascotas
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int informePromedioMascotasVacunadas(eMascota lista[], int tam);
/**
 * Funcion que permite informar la o las mascotas menores de edad
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @param clientes
 * @param tamCli
 * @return 1 si tuvo exito, y 0 si no.
 */
int informeMascotasMenorEdad(eMascota lista[],int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli);
/**
 * Funcion que permite mostrar mascotas separadas por tipo
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @param clientes
 * @param tamCli
 * @return 1 si tuvo exito, y 0 si no.
 */
int informeMascotasPorTipo(eMascota lista[],int tam,eTipo tipos[],int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli);
/**
 * Funcion que permite Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.
 * @param lista
 * @param tam
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @param clientes
 * @param tamCli
 * @return 1 si tuvo exito, y 0 si no.
 */
int informeCantidadMascotasTipoYColor(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli);
/**
 * Funcion que permite Mostrar el o los colores con más cantidad de mascotas
 * @param lista
 * @param tam
 * @param colores
 * @param tamCol
 * @return 1 si tuvo exito, y 0 si no.
 */
int informeColorOColoresConMasMascotas(eMascota lista[], int tam, eColor colores[], int tamCol);
/**
 * Funcion que permite Pedir una mascota y mostrar todos los trabajos que se le hicieron a la misma.
 * @param lista
 * @param tam
 * @param trabajos
 * @param tamTrab
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @param clientes
 * @param tamCli
 * @param servicios
 * @param tamServ
 * @return 1 si tuvo exito, y 0 si no.
 */
int informeMascotaTrabajos(eMascota lista[], int tam, eTrabajo trabajos[], int tamTrab, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli, eServicio servicios[], int tamServ);
/**
 * Funcion que permite Pedir una mascota e informar la suma de los importes de los servicios que se le hicieron a la
misma
 * @param lista
 * @param tam
 * @param trabajos
 * @param tamTrab
 * @param tipos
 * @param tamTip
 * @param colores
 * @param tamCol
 * @param clientes
 * @param tamCli
 * @param servicios
 * @param tamServ
 * @return 1 si tuvo exito, y 0 si no
 */
int informeMascotaImporteServicio(eMascota lista[], int tam, eTrabajo trabajos[], int tamTrab, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli, eServicio servicios[], int tamServ);
/**
 * Funcion que permite Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha.
 *
 * @param lista
 * @param tam
 * @param trabajos
 * @param tamTrab
 * @param servicios
 * @param tamServ
 * @return   1 si tuvo exito, y 0 si no
 */
int informeMascotasServicio(eMascota lista[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ);
/**
 * Funcion que permite Pedir una fecha y mostrar todos los servicios realizados en la misma.
 * @param lista
 * @param tam
 * @param trabajos
 * @param tamTrab
 * @param servicios
 * @param tamServ
 * @return 1 si tuvo exito, y 0 si no
 */
int informeFechaServicios(eMascota lista[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ);

#endif /* INFORMES_H_ */

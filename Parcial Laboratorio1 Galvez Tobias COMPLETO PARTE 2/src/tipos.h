/*
 * tipos.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */

#ifndef TIPOS_H_
#define TIPOS_H_

typedef struct
    {
     int id;
     char descripcion[20];
    }eTipo;

/**
 * Funcion que permite listar los tipos
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int listarTipos(eTipo lista[], int tam);
/**
 * Funcion que permite cargar la descripcion del tipo elegido por id
 * @param id
 * @param lista
 * @param tam
 * @param destino
 * @return 1 si tuvo exito, y 0 si no.
 */
int cargarTipo(int id, eTipo lista[], int tam,char destino[]);




#endif /* TIPOS_H_ */

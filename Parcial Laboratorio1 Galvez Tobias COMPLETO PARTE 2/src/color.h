/*
 * color.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */

#ifndef COLOR_H_
#define COLOR_H_

typedef struct
    {
     int idColor;
     char nombreColor[20];
    }eColor;


/**
 * Funcion que permite listar los colores
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int listarColores(eColor lista[], int tam);
/**
 * Funcion que permite cargar la descripcion del color elegido por id
 * @param id
 * @param lista
 * @param tam
 * @param destino
 * @return 1 si tuvo exito, y 0 si no.
 */
int cargarColor(int id, eColor lista[], int tam,char destino[]);

#endif /* COLOR_H_ */

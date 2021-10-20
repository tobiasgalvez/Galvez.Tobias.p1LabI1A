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

int listarColores(eColor lista[], int tam);
int cargarColor(int id, eColor lista[], int tam,char destino[]);

#endif /* COLOR_H_ */

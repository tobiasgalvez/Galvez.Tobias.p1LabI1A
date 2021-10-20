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

int listarTipos(eTipo lista[], int tam);
int cargarTipo(int id, eTipo lista[], int tam,char destino[]);




#endif /* TIPOS_H_ */

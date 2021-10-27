/*
 * tipos.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipos.h"

int listarTipos(eTipo lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {

            printf("\n--------LISTA DE TIPOS--------\n");
        for(int i=0; i<tam; i++)
        {
            printf("ID: %d \nTIPO: %s", lista[i].id, lista[i].descripcion);
            printf("\n----------------------\n");
        }
        todoOk= 1;
    }
    return todoOk;
}
int cargarTipo(int id, eTipo lista[], int tam,char destino[])
{
    int todoOk=0;
    if(id>=1000 && id<=1004 && lista!=NULL && tam>0 && destino!=NULL)
    {

        for(int i=0; i<tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(destino,lista[i].descripcion) ;
                break;
            }
        }
        todoOk= 1;
    }
    return todoOk;
}

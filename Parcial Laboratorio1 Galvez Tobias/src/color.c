/*
 * color.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"

int listarColores(eColor lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {

            printf("\n---LISTA DE COLORES---\n");
        for(int i=0; i<tam; i++)
        {
            printf("ID: %d \nCOLOR: %s", lista[i].idColor, lista[i].nombreColor);
            printf("\n----------------------\n");
        }
        todoOk= 1;
    }
    return todoOk;
}
int cargarColor(int id, eColor lista[], int tam,char destino[])
{
    int todoOk=0;
    if(id>=5000 && id<=5004 && lista!=NULL && tam>0 && destino!=NULL)
    {

        for(int i=0; i<tam; i++)
        {
            if(id==lista[i].idColor)
            {
                strcpy(destino,lista[i].nombreColor) ;
                break;
            }
        }
        todoOk= 1;
    }
    return todoOk;
}

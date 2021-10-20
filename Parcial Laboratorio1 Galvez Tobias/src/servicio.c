/*
 * servicio.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"

int listarServicios(eServicio lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {

            printf("\n--LISTA DE SERVICIOS--\n");
        for(int i=0; i<tam; i++)
        {
            printf("ID: %d \nSERVICIO: %s \nPRECIO: $%.2f", lista[i].id, lista[i].descripcion,lista[i].precio);
            printf("\n----------------------\n");
        }
        todoOk= 1;
    }
    return todoOk;
}

int cargarServicio(int id, eServicio lista[], int tam,char destino[])
{
    int todoOk=0;
    if(id>= 20000 && id>=20002 && lista!=NULL && tam>0 && destino!=NULL)
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

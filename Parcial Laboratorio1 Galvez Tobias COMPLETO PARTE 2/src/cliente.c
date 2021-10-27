/*
 * cliente.c
 *
 *  Created on: 27 oct. 2021
 *      Author: Tobias Galvez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

int listarClientes(eCliente lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {

            printf("\n--------LISTA DE CLIENTES--------\n");
        for(int i=0; i<tam; i++)
        {
            printf("ID: %d \nCLIENTE: %s", lista[i].id, lista[i].nombre);
            printf("\n----------------------\n");
        }
        todoOk= 1;
    }
    return todoOk;
}

int cargarCliente(int id, eCliente lista[], int tam,char destino[])
{
    int todoOk=0;
    if(id>=100 && id<=104 && lista!=NULL && tam>0 && destino!=NULL)
    {

        for(int i=0; i<tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(destino,lista[i].nombre) ;
                break;
            }
        }
        todoOk= 1;
    }
    return todoOk;
}

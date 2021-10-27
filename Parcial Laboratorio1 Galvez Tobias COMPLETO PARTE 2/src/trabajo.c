/*
 * trabajo.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipos.h"
#include "trabajo.h"
#include "mascota.h"
#include "fecha.h"
#include "servicio.h"
#include "color.h"
#include "UTN.h"
#include "mascota.h"



#define VACIO 1
#define OCUPADO 0

int inicializarTrabajo(eTrabajo lista[], int tam)
{
	int todoOk = 0;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = VACIO;
		}
		todoOk = 1;
	}
	return todoOk;
}


int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == VACIO)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}




int altaTrabajo(eMascota mascotas[], int tamMascotas, eColor colores[], int tamCol,eTipo tipos[], int tamTip,  int* pId, eTrabajo lista[], int tam, eServicio servicios[], int tamServ, eCliente clientes[], int tamCli)
{
	int todoOk = 0;
	int indiceTrabajo;
	int indiceMascota;
	char confirma;
	eTrabajo auxTrabajo;

	if(mascotas != NULL && tamMascotas > 0 && pId != NULL && colores != NULL && tamCol >0 && tipos != NULL && tamTip >0 && lista!= NULL && tam >0)
	{
		system("cls");
	    printf("            *** Alta Trabajo ***              \n");
	    printf("---------------------------------------------\n");

		indiceTrabajo = buscarLibreTrabajo(lista, tam);

		if(indiceTrabajo == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxTrabajo.id = *pId;
			(*pId)++;

			printf("%d", *pId);

			mostrarMascotas(mascotas, tam, tipos, tamTip, colores, tamCol, clientes, tamCli);
			printf("\nElija el ID de la mascota con la cual desea trabajar:");
			scanf("%d", &auxTrabajo.idMascota);

			indiceMascota = buscarMascotaId(mascotas, tam, auxTrabajo.idMascota);

					if(indiceMascota == -1)
					{
						printf("No existe una mascota con id: %d\n", mascotas->id);
					}
					else
					{
						mostrarMascota(mascotas[indiceMascota], tipos, tamTip, colores, tamCol, clientes, tamCli);
					listarServicios(servicios, tamServ);
					utn_getEntero(&auxTrabajo.idServicio, 3, "\nIngrese ID del servicio: \n", "ERROR, eso no es un id válido", 20000, 20002);
					printf("Ingrese fecha de nacimiento:");
					scanf("%d/%d/%d", &auxTrabajo.fecha.dia,
									  &auxTrabajo.fecha.mes,
									  &auxTrabajo.fecha.anio);
						printf("Confirma trabajo? ('s' para confirmar)\n");
						fflush(stdin);
						scanf("%c", &confirma);

						confirma = tolower(confirma);

						if(confirma == 's')
						{
							printf("\nTrabajo adquirido con éxito!!!!");
						}
						else
						{
							printf("Se ha cancelado el trabajo \n");
						}
						todoOk= 1;
					}




			auxTrabajo.isEmpty = OCUPADO;

			lista[indiceTrabajo] = auxTrabajo;

		}
	}
	return todoOk;
}


int mostrarTrabajo(eTrabajo trabajo,eMascota mascotas[],int tamMascotas,eServicio servicios[], int tamServ)
{
    int todoOk = 0;

    if(servicios != NULL && tamServ > 0 && mascotas != NULL && tamMascotas >0)
    {
	char nombreMascota[20];
    char descServicio[20];
    cargarMascota(trabajo.idMascota,mascotas,tamMascotas,nombreMascota);
    cargarServicio(trabajo.idServicio,servicios,tamServ,descServicio);
    printf("%d       %s   \t\t%s     %d/%d/%d \n",
           trabajo.id, nombreMascota, descServicio, trabajo.fecha.dia,trabajo.fecha.mes, trabajo.fecha.anio );

    todoOk = 1;

    }

return todoOk;
}



int mostrarTrabajos( eTrabajo lista[], int tam,eMascota mascotas[], int tamMascotas,eServicio servicios[], int tamServ)
{
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam > 0)
	{
		system("cls");
	    printf("       *** Listado de trabajos ***      \n");
		printf("Id   Nombre de la mascota   Servicio      Fecha\n");
	    printf("-------------------------------------------------------\n");
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				mostrarTrabajo(lista[i],mascotas, tamMascotas, servicios, tamServ);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("   No hay trabajos para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}



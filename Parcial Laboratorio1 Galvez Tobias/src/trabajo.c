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




int altaTrabajo(eMascota mascota[], int tam, eColor colores[], int tamCol,eTipo tipos[], int tamTip,  int* pId, eTrabajo lista[], int tamTrabajo, eServicio servicios[], int tamServ)
{
	int todoOk = 0;
	int indice;
	char confirma;
	eTrabajo auxTrabajo;

	if(mascota != NULL && tam > 0 && pId != NULL && colores != NULL && tamCol >0 && tipos != NULL && tamTip >0 && lista!= NULL && tamTrabajo >0)
	{
		system("cls");
	    printf("            *** Alta Trabajo ***              \n");
	    printf("---------------------------------------------\n");

		indice = buscarLibreTrabajo(lista, tamTrabajo);
		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxTrabajo.id = *pId;
			(*pId)++;

			printf("%d", *pId);

			mostrarMascotas(mascota, tam, tipos, tamTip, colores, tamCol);
			printf("\nElija el ID de la mascota con la cual desea trabajar:");
			scanf("%d", &auxTrabajo.id);

			indice = buscarMascotaId(mascota, tam, auxTrabajo.id);

					if(indice == -1)
					{
						printf("No existe una mascota con id: %d\n", auxTrabajo.id);
					}
					else
					{
						mostrarMascota(mascota[indice], tipos, tamTip, colores, tamCol);
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
					}


					listarServicios(servicios, tamServ);
					utn_getEntero(&auxTrabajo.idServicio, 3, "\nIngrese ID del servicio: \n", "ERROR, eso no es un id válido", 20000, 20002);

					printf("Ingrese fecha de nacimiento:");
					scanf("%d/%d/%d", &auxTrabajo.fecha.dia,
									  &auxTrabajo.fecha.mes,
									  &auxTrabajo.fecha.anio);

			auxTrabajo.isEmpty = OCUPADO;

			lista[indice] = auxTrabajo;

		}
		todoOk = 1;
	}
	return todoOk;
}


int buscarMascotaId(eMascota lista[], int tam, int id)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO && lista[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}



int mostrarTrabajo(eMascota mascotas[],int tam,eServicio servicios[], int tamServ, eTrabajo trabajo)
{
    int todoOk = 0;

    if(servicios != NULL && tamServ > 0 && mascotas != NULL && tam >0)
    {
	char nombreMascota[20];
    char descServicio[20];
    cargarMascota(trabajo.idMascota,mascotas,tam,nombreMascota);
    cargarServicio(trabajo.idServicio,servicios,tamServ,descServicio);
    printf("%d       %s      %s     %d/%d/%d \n",
           trabajo.id, nombreMascota, descServicio, trabajo.fecha.dia,trabajo.fecha.mes, trabajo.fecha.anio );

    todoOk = 1;

    }

return todoOk;
}






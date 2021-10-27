/*
 * mascota.c
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
#include "cliente.h"

#define VACIO 1
#define OCUPADO 0


int menu()
{
    char opcion;

    system("cls");
    printf("            *** ABM Mascotas ***              \n");
    printf("---------------------------------------------\n");
    printf("A- Alta mascota\n");
    printf("B- Modificar mascota\n");
    printf("C- Baja mascota\n");
    printf("D- Listar mascotas\n");
    printf("E- Listar tipos\n");
    printf("F- Listar colores\n");
    printf("G- Listar servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
    printf("J- Informes\n");
    printf("K- Salir\n");


    printf("\nIngresar opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    opcion = toupper(opcion);

    return opcion;
}


int inicializarMascota(eMascota lista[], int tam)
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


int buscarLibre(eMascota lista[], int tam)
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


int altaMascota(eMascota lista[], int tam, eColor colores[], int tamCol,eTipo tipos[], int tamTip,  int* pId, eCliente clientes[], int tamCli)
{
	int todoOk = 0;
	int indice;
	eMascota auxMascota;

	if(lista != NULL && tam > 0 && pId != NULL)
	{
		system("cls");
	    printf("            *** Alta mascota ***              \n");
	    printf("---------------------------------------------\n");

		indice = buscarLibre(lista, tam);
		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxMascota.id = *pId;
			(*pId)++;

			utn_getCadena(auxMascota.nombre, 20, 3, "\nIngrese nombre de la mascota: \n", "ERROR, no es un nombre");
			utn_getEntero(&auxMascota.edad, 3, "\nIngrese edad de la mascota: \n", "ERROR, eso no es una edad válida", 1, 50);

			listarTipos(tipos, tamTip);
			utn_getEntero(&auxMascota.idTipo, 3, "\nIngrese ID del tipo: \n", "ERROR, eso no es un id válido", 1000, 1004);

			listarColores(colores, tamCol);
			utn_getEntero(&auxMascota.idColor, 3, "\nIngrese ID del color: \n", "ERROR, eso no es un id válido", 5000, 5004);

			listarClientes(clientes, tamCli);
			utn_getEntero(&auxMascota.idCliente, 3, "\nIngrese ID del cliente: \n", "ERROR, eso no es un id válido", 100, 104);

			printf("La mascota se encuentra vacunada?('s' / 'n'): \n");
			fflush(stdin);
			scanf("%c", &auxMascota.vacunado);

			auxMascota.isEmpty = OCUPADO;

			lista[indice] = auxMascota;

		}
		todoOk = 1;
	}
	return todoOk;
}



int menuModificacion()
{
    int opcion;

    printf("------MENU MODIFICACION-------\n\n");

    printf("1- Tipo\n");
    printf("2- Vacunado\n");
    printf("3- Salir\n");

    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int modificarMascota(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;
	int auxIdTipo;
	char auxVacunado;


	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("       *** Modificar mascota ***      \n");
		printf("----------------------------------\n");

		mostrarMascotas(lista, tam,tipos, tamTip, colores, tamCol, clientes, tamCli);

		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarMascotaId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una persona con id: %d\n", id);
		}
		else
		{
			mostrarMascota(lista[indice], tipos, tamTip, colores, tamCol, clientes, tamCli);
			printf("Confirma modificacion? ('s' para confirmar)\n");
			fflush(stdin);
			scanf("%c", &confirma);

			confirma = tolower(confirma);

			if(confirma == 's')
			{
				switch(menuModificacion())
				{
				case 1:
					listarTipos(tipos, tamTip);
					utn_getEntero(&auxIdTipo, 3, "Ingrese nuevo ID del tipo: \n", "ERROR, eso no es un id válido", 1000, 1004);
					lista[indice].idTipo = auxIdTipo;
					printf("Tipo modificado exitosamente");
					break;
				case 2:
					printf("\nIngrese nuevo tipo de vacunado('s' / 'n'): ");
					fflush(stdin);
					scanf("%c", &auxVacunado);
					lista[indice].vacunado = auxVacunado;
					printf("Tipo de vacunado modificado exitosamente");
					break;
				}
				todoOk = 1;
			}
			else
			{
				printf("Se ha cancelado la modificacion \n");
			}
		}
	}
	return todoOk;
}

int bajaMascota(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("       *** Baja persona ***      \n");
		printf("----------------------------------\n");

		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarMascotaId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una persona con id: %d\n", id);
		}
		else
		{
			mostrarMascota(lista[indice], tipos, tamTip, colores, tamCol, clientes, tamCli);
			printf("Confirma baja? \n");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				lista[indice].isEmpty = VACIO;
				todoOk = 1;
			}
			else
			{
				printf("Se ha cancelado la baja \n");
			}
		}
	}
	return todoOk;
}


int mostrarMascota(eMascota mascota,eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
    int todoOk = 0;

    if(tipos != NULL && tamTip > 0 && colores != NULL && tamCol >0 && clientes !=NULL && tamCli >0)
    {
	char descTipo[20];
    char descColor[20];
    char nombreCliente[20];
    cargarTipo(mascota.idTipo,tipos,tamTip,descTipo);
    cargarColor(mascota.idColor,colores,tamCol,descColor);
    cargarCliente(mascota.idCliente, clientes, tamCli,nombreCliente);
    printf("%d         %s\t%s\t%s\t%d\t\t%c\t%s \n",
           mascota.id, mascota.nombre, descTipo,descColor,mascota.edad, mascota.vacunado, nombreCliente);

    todoOk = 1;

    }

return todoOk;
}


int ordenarMascotas(eMascota lista[], int tam)
{
	int todoOk = 0;
	eMascota auxMascota;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam - 1; i++)
		{
			for(int j = i + 1; j < tam; j++)
			{
				if(lista[i].idTipo > lista[j].idTipo ||
						(lista[i].idTipo == lista[j].idTipo &&
						strcmp(lista[i].nombre, lista[j].nombre)) > 0)
				{
					auxMascota = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMascota;
				}
			}
		}

		todoOk = 1;
	}
	return todoOk;
}


int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam > 0)
	{
		system("cls");
		ordenarMascotas(lista, tam);
	    printf("       *** Listado de mascotas ***      \n");
		printf("Id        Nombre       Tipo     Color   Edad      Se vacuno?   Nombre del Cliente\n");
	    printf("-------------------------------------------------------------------------------------\n");
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				mostrarMascota(lista[i], tipos, tamTip, colores, tamCol, clientes, tamCli);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("   No hay personas para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}




int cargarMascota(int id, eMascota lista[], int tam,char destino[])
{
    int todoOk=0;
    if( lista!=NULL && tam>0 && destino!=NULL)
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




int mostrarMascotasColorId(eMascota lista[],int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli, int idColor )
{
    int todoOk=0;

    int flag=0;

    if(lista !=NULL&&colores!=NULL&&tam>0&&tamCol>0)
    {
    	printf("Id        Nombre       Tipo     Color   Edad      Se vacuno?   Nombre del Cliente\n");
    	printf("-------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam;i++)
        {
            if(lista[i].isEmpty == OCUPADO && lista[i].idColor==idColor)
            {

                mostrarMascota(lista[i], tipos, tamTip, colores, tamCol, clientes, tamCli);
                printf("\n");
                flag=1;
            }

        }

        if(flag == 0)
        {
            printf("No hay mascotas de ese color");
        }

        todoOk=1;
    }

    return todoOk;
}

int mostrarMascotasTipoId(eMascota lista[],int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli, int idTipo )
{
    int todoOk=0;

    int flag=0;

    if(lista !=NULL&&colores!=NULL&&tam>0&&tamCol>0)
    {
    	printf("Id        Nombre       Tipo     Color   Edad      Se vacuno?   Nombre del Cliente\n");
    	printf("-------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam;i++)
        {
            if(lista[i].isEmpty == OCUPADO && lista[i].idTipo==idTipo)
            {

                mostrarMascota(lista[i], tipos, tamTip, colores, tamCol, clientes, tamCli);
                printf("\n");
                flag=1;
            }

        }

        if(flag == 0)
        {
            printf("No hay mascotas de ese tipo");
        }

        todoOk=1;
    }

    return todoOk;
}



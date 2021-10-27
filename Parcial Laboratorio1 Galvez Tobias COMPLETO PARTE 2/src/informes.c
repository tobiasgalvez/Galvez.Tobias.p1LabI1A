/*
 * informes.c
 *
 *  Created on: 27 oct. 2021
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

int menuInformes()
{
	int opcion;

	    system("cls");
	    printf("            *** INFORMES ***              \n");
	    printf("---------------------------------------------\n");
	    printf("1- Mostrar las mascotas del color seleccionado por el usuario\n");
	    printf("2- Informar promedio de mascotas vacunadas sobre el total de mascotas.\n");
	    printf("3- Informar la o las mascotas de menor edad.\n");
	    printf("4- Listar de las mascotas separadas por tipo.\n");
	    printf("5- Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.\n");
	    printf("6- Mostrar el o los colores con más cantidad de mascotas\n");
	    printf("7- Pedir una mascota y mostrar todos los trabajos que se le hicieron a la misma.\n");
	    printf("8- Pedir una mascota e informar la suma de los importes de los servicios que se le hicieron a la misma.\n");
	    printf("9- Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha.\n");
	    printf("10- Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
	    printf("11- Salir\n");


	    printf("\nIngresar opcion: ");
	    scanf("%d", &opcion);

	    return opcion;
}





int informeMascotasColor(eMascota lista[],int tam,eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
    int todoOk = 0;
    int colorId;
    if(lista !=NULL&&colores!=NULL&&tam>0&&tamCol>0)
    {
        system("cls");
	    printf("  *** Informe de personas de cierto color ***\n");
        printf("-----------------------------------------\n");
        listarColores(colores, tamCol);

        printf("Ingrese el id del color de mascota que desea mostrar: ");
        scanf("%d",&colorId);

       mostrarMascotasColorId(lista,tam, tipos, tamTip, colores, tamCol, clientes, tamCli, colorId);

        todoOk=1;

    }

        return todoOk;

    }



int informePromedioMascotasVacunadas(eMascota lista[], int tam)
{
	int todoOk=0;
	int contMascotasVacunadas;
	float promedioMascotasVacunadas = 0;

	if(lista!=NULL && tam>0)
	{
		for(int i=0; i< tam; i++)
		{
			if(lista[i].vacunado == 's')
			{
				contMascotasVacunadas++;
			}
		}

		todoOk = 1;
	}


	promedioMascotasVacunadas = (float)(contMascotasVacunadas/tam);

	printf("El promedio de mascotas vacunadas sobre el total de mascotas es de %.2f", promedioMascotasVacunadas);

	return todoOk;
}


int informeMascotasMenorEdad(eMascota lista[],int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
	int todoOk = 0;
	int flag = 0;

	if(lista != NULL && tam > 0)
	{
		printf("Id        Nombre       Tipo     Color   Edad      Se vacuno?   Nombre del Cliente\n");
		printf("-------------------------------------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO && lista[i].edad <= 17)
			{
				mostrarMascota(lista[i], tipos, tamTip, colores, tamCol, clientes, tamCli);
				printf("\n");
				flag=1;
			}

		}
		if(flag == 0)
		 {
		   printf("No hay mascotas menores de edad");
		 }

		todoOk=1;
	}

	return todoOk;
}


int informeMascotasPorTipo(eMascota lista[],int tam,eTipo tipos[],int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
    int todoOk= 0;

    if(lista !=NULL&&tipos!=NULL&&tam>0&&tamTip>0)
    {

        printf("  *** Informe de personas de cierto tipo ***\n");
        printf("-----------------------------------------\n");


        for(int i=0;i<tamTip;i++)
        {
            printf("Mascotas de tipo %s: \n\n",tipos[i].descripcion);
            mostrarMascotasTipoId(lista,tam, tipos, tamTip, colores, tamCol, clientes, tamCli, tipos[i].id);
        }
        todoOk=1;
    }


    return todoOk;

}



int informeCantidadMascotasTipoYColor(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli)
{
	int todoOk=0;
	int colorId;
	int tipoId;
	int contMascotasTipoYColor;
	int flag=0;
	char descTipo[25];
	char descColor[25];

	if(lista != NULL && tam >0)
	{
		listarColores(colores, tamCol);
		utn_getEntero(&colorId, 3, "\nIngrese el id del color", "\nERROR, ese no es un id valido", 5000, 5004);
		listarTipos(tipos, tamTip);
		utn_getEntero(&tipoId, 3, "\nIngrese el id del tipo", "\nERROR, ese no es un id valido", 1000, 1004);
		cargarColor(colorId, colores, tamCol, descColor);
		cargarTipo(tipoId, tipos, tamTip, descTipo);



		for(int i=0; i<tam; i++)
		{
			if(lista[i].idColor == colorId && lista[i].idTipo == tipoId)
			{
				contMascotasTipoYColor++;
				flag=1;
			}
		}
		todoOk=1;
	}

	if(flag == 0)
	{
		printf("NO hay mascotas con ese color y ese tipo");
	}
	else
	{
		printf("Las mascotas de tipo: %s y color %s son un total de %d", descTipo, descColor, contMascotasTipoYColor);
	}

	return todoOk;
}

int informeColorOColoresConMasMascotas(eMascota lista[], int tam, eColor colores[], int tamCol)
{
	int todoOk = 0;
	int contNegro;
	int contBlanco;
	int contRojo;
	int contGris;
	int contAzul;
	int colorConMasMascotaId;
	char descColorMasMascotas[25];
	int colorMasMascotas;

	if(lista!=NULL && tam >0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].idColor == 5000)
			{
				contNegro++;
			}
			else if(lista[i].idColor == 5001)
			{
				contBlanco++;
			}
			else if(lista[i].idColor == 5002)
			{
				contRojo++;
			}
			else if(lista[i].idColor == 5003)
			{
				contGris++;
			}
			else if(lista[i].idColor == 5004)
			{
				contAzul++;
			}
		}

		if(contNegro > contBlanco && contNegro > contRojo && contNegro > contGris && contNegro > contAzul)
		{
			colorConMasMascotaId = 5000;
			colorMasMascotas = contNegro;
		}
		else if(contBlanco >= contNegro && contBlanco > contRojo && contBlanco > contGris && contBlanco > contAzul)
		{
			colorConMasMascotaId = 5001;
			colorMasMascotas = contBlanco;
		}
		else if(contRojo >= contNegro && contRojo >= contBlanco && contRojo > contGris && contRojo > contAzul)
		{
			colorConMasMascotaId = 5002;
			colorMasMascotas = contRojo;
		}
		else if(contGris >= contNegro && contGris >= contBlanco && contGris >= contRojo && contGris > contAzul)
		{
			colorConMasMascotaId = 5003;
			colorMasMascotas = contGris;
		}
		else
		{
			colorConMasMascotaId = 5004;
			colorMasMascotas = contAzul;
		}

		cargarColor(colorConMasMascotaId, colores, tamCol, descColorMasMascotas);

		todoOk=1;
	}

	printf("El color %s es el que posee la mayor cantidad de mascotas, con un total de %d mascotas", descColorMasMascotas, colorMasMascotas);

	return todoOk;
}



int informeMascotaTrabajos(eMascota lista[], int tam, eTrabajo trabajos[], int tamTrab, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli, eServicio servicios[], int tamServ)
{
	int todoOk=0;
	int idMascotaIngresado;
	char nombreMascota[25];

	if(lista!=NULL && tam >0 && trabajos !=NULL && tamTrab >0)
	{

		mostrarMascotas(lista, tam, tipos, tamTip, colores, tamCol, clientes, tamCli);
		utn_getEntero(&idMascotaIngresado, 3, "\nIngrese el id de la mascota de la cual desea ver los trabajos", "\nERROR, esa no es un id de mascota valido", 1, 5);
		for(int i=0; i<tam; i++)
		{
			if(lista[i].id == idMascotaIngresado)
			{
				for(int i=0; i<tamTrab; i++)
				{
					if(trabajos[i].idMascota == idMascotaIngresado)
					{
						mostrarTrabajo(trabajos[i], lista, tam, servicios, tamServ);
					}
				}
			}

		}
		todoOk=1;
	}

	return todoOk;
}

int informeMascotaImporteServicio(eMascota lista[], int tam, eTrabajo trabajos[], int tamTrab, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente clientes[], int tamCli, eServicio servicios[], int tamServ)
{
	int todoOk = 0;
	int idMascotaIngresado;
	float acumImporteServicio = 0;

	if(lista!=NULL && tam > 0 && trabajos !=NULL && tamTrab >0)
	{
		mostrarMascotas(lista, tam, tipos, tamTip, colores, tamCol, clientes, tamCli);
		utn_getEntero(&idMascotaIngresado, 3, "\nIngrese el id de la mascota de la cual desea ver los trabajos", "\nERROR, esa no es un id de mascota valido", 1, 5);

		for(int i=0; i<tam; i++)
		{
			if(lista[i].id == idMascotaIngresado)
						{
							for(int i=0; i<tamTrab; i++)
							{
								if(trabajos[i].idMascota == idMascotaIngresado)
								{
									//acumImporteServicio+=;
								}
							}
						}
		}

		todoOk=1;
	}

	return todoOk;
}


int informeMascotasServicio(eMascota lista[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ)
{
	int todoOk = 0;
	int idServicioIngresado;

	if(lista!=NULL && tam > 0 && trabajos !=NULL && tamTrab >0)
	{

		utn_getEntero(&idServicioIngresado, 3, "\nIngrese el id del servicio para mostrar sus mascotas", "\nERROR, esa no es un id de servicio valido", 20000, 20002);
		for(int i=0; i<tamTrab; i++)
		{
			if(trabajos[i].idServicio == idServicioIngresado)
			{
				mostrarTrabajo(trabajos[i], lista, tam, servicios, tamServ);
			}
		}

		todoOk=1;
	}

	return todoOk;
}

int informeFechaServicios(eMascota lista[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ)
{
	int todoOk = 0;
	int fechaIngresada;
	int mesIngresado;
	int anioIngresado;

	if(lista!=NULL && tam > 0 && trabajos !=NULL && tamTrab >0)
	{
		printf("Ingrese fecha de servicio a mostrar:");
		scanf("%d/%d/%d", &fechaIngresada,
						  &mesIngresado,
						  &anioIngresado);

		for(int i=0; i<tamTrab;i++)
		{
			if(trabajos[i].fecha.dia == fechaIngresada && trabajos[i].fecha.mes == mesIngresado && trabajos[i].fecha.anio == anioIngresado)
			{
				mostrarServicio(trabajos[i], lista, tam, servicios, tamServ);
			}
		}
	}

	return todoOk;
}

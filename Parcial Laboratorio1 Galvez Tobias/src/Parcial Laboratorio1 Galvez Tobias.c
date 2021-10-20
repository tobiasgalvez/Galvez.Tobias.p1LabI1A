/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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
#include "UTN.h"

#define TAM 5
#define TAMTIP 5
#define TAMCOL 5
#define TAMSERV 3
#define TAMTRAB 5

int main(void) {
	setbuf(stdout, NULL);
	eMascota mascotas[TAM];
	eTrabajo trabajos[TAMTRAB];
	int nextId=0;
	int nextIdTrabajo=0;
	char seguir = 's';

	eTipo tipos[TAMTIP] =
	    {
	        {1000, "Ave"},
	        {1001, "Perro"},
	        {1002, "Roedor"},
	        {1003, "Gato"},
	        {1004, "Pez"}
	    };
	    eColor colores[TAMCOL] =
	    {
	        {5000, "Negro"},
	        {5001, "Blanco"},
	        {5002, "Rojo"},
	        {5003, "Gris"},
	        {5004, "Azul"}
	    };
	    eServicio servicios[TAMSERV] =
	    {
	        {20000, "Corte",450},
	        {20001, "Desparasitado",800},
	        {20002, "Castrado",600}
	    };


	    if(!inicializarMascota(mascotas, TAM))
	        {
	        	printf("Ocurrio un problema al inicializar personas\n");
	        }

	    if(!inicializarTrabajo(trabajos, TAMTRAB))
	    	        {
	    	        	printf("Ocurrio un problema al inicializar personas\n");
	    	        }

	        do
	        {
	            switch(menu())
	            {
	                case 'A':
	                    if(altaMascota(mascotas, TAM, colores, TAMCOL,tipos, TAMTIP, &nextId))
	                    {
	                    	printf("Alta exitosa\n");
	                    }
	                    else
	                    {
	                    	printf("Hubo un problema al dar de alta\n");
	                    }
	                    break;
	                case 'B':
	                    if(modificarMascota(mascotas, TAM,tipos, TAMTIP, colores, TAMCOL))
	                    {
	                    	printf("Modificacion exitosa\n");
	                    }
	                    else
	                    {
	                    	printf("Hubo un problema al hacer la modificacion\n");
	                    }
	                    break;
	                case 'C':
	                    if(bajaMascota(mascotas, TAM, tipos, TAMTIP, colores, TAMCOL))
	                    {
	                    	printf("Baja exitosa\n");
	                    }
	                    else
	                    {
	                    	printf("Hubo un problema al realizar la baja\n");
	                    }
	                    break;
	               case 'D':
	                    if(mostrarMascotas(mascotas, TAM,tipos, TAMTIP, colores, TAMCOL ))
	                    {
	                    	printf("\nOrdenamiento exitoso\n");
	                    }
	                    else
	                    {
	                    	printf("Hubo un problema al ordenar\n");
	                    }
	                	break;
	               case 'E':
	            	   listarTipos(tipos, TAMTIP);
	            	   break;
	               case 'F':
	            	   listarColores(colores, TAMCOL);
	            	   break;
	               case 'G':
	            	   listarServicios(servicios, TAMSERV);
	            	   break;
	               case 'H':

				if(altaTrabajo(mascotas, TAM, colores, TAMCOL, tipos, TAMTIP, &nextIdTrabajo, trabajos, TAMTRAB, servicios, TAMSERV))
					                    {
					                    	printf("Alta exitosa\n");
					                    }
					                    else
					                    {
					                    	printf("Hubo un problema al dar de alta\n");
					                    }
					                    break;



	               case 'I':
	            	   //mostrarTrabajo(mascotas, TAM, servicios, TAMSERV, trabajos[]);
	            	   //NO LLEGUE A HACER EL MOSTRAR TRABAJOS
	            	   break;

	            }

	                    printf("\nPresione cualquier tecla para continuar...\n");
	                            fflush(stdin);
	                            getchar();
	                        }while(seguir == 's');

}

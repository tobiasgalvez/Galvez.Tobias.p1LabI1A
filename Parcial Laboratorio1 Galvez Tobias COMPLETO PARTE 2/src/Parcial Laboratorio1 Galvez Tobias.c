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
#include "cliente.h"
#include "informes.h"

#define TAMMASCOTA 5
#define TAMTIP 5
#define TAMCOL 5
#define TAMSERV 3
#define TAMTRAB 5
#define TAMCLIENTES 5
#define OCUPADO 0
#define VACIO 1

int main(void) {
	setbuf(stdout, NULL);
	eMascota mascotas[TAMMASCOTA];
	int nextId=1;
	int nextIdTrabajo=1;
	int flagAltaMascota=0;
	int flagAltaTrabajo=0;
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



	    eCliente clientes[TAMCLIENTES] =
	    {
	    	{100, "Tobias",'m'},
	    	{101, "Maria",'f'},
			{102, "Juan",'m'},
	    	{103, "Ricardo",'m'},
			{104, "Juliana",'f'}
	    };


	    eTrabajo trabajos [TAMTRAB] =
	    {
	    	{1, 3,20000, {10,10,2010}, OCUPADO},
	    	{2, 5,20000, {10,10,2015}, OCUPADO},
			{3, 3,20000, {9,8,2021}, OCUPADO},
	    	{4, 1,20000, {14,12,2000}, OCUPADO},
			{5, 2,20000, {5,4,2007}, OCUPADO}
	    };

	    if(!inicializarMascota(mascotas, TAMMASCOTA))
	        {
	        	printf("Ocurrio un problema al inicializar mascotas\n");
	        }

	    if(!inicializarTrabajo(trabajos, TAMTRAB))
	    	        {
	    	        	printf("Ocurrio un problema al inicializar trabajos\n");
	    	        }

	        do
	        {
	            switch(menu())
	            {
	                case 'A':
	                    if(altaMascota(mascotas, TAMMASCOTA, colores, TAMCOL,tipos, TAMTIP, &nextId, clientes, TAMCLIENTES))
	                    {
	                    	printf("Alta exitosa\n");
	                    	flagAltaMascota=1;
	                    }
	                    else
	                    {
	                    	printf("Hubo un problema al dar de alta\n");
	                    }
	                    break;
	                case 'B':
	                	if(flagAltaMascota)
	                	{
	                    if(modificarMascota(mascotas, TAMMASCOTA,tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES))
	                    {
	                    	printf("\nModificacion exitosa\n");
	                    }
	                    else
	                    {
	                    	printf("Hubo un problema al hacer la modificacion\n");
	                    }

	                	}
	                	else
	                	{
	                		printf("\nPrimero debe ingresar al menos una mascota!!!");
	                	}

	                    break;
	                case 'C':
	                	if(flagAltaMascota)
	                	{

	                    if(bajaMascota(mascotas, TAMMASCOTA, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES))
	                    {
	                    	printf("Baja exitosa\n");
	                    }
	                    else
	                    {
	                    	printf("Hubo un problema al realizar la baja\n");
	                    }
	                	}
	                	else
	                	{
	                		printf("\nPrimero debe ingresar al menos una mascota!!!");
	                	}
	                    break;
	               case 'D':
	            	   if(flagAltaMascota)
	            	   {
	                    if(mostrarMascotas(mascotas, TAMMASCOTA,tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES))
	                    {
	                    	printf("\nOrdenamiento exitoso\n");
	                    }
	                    else
	                    {
	                    	printf("Hubo un problema al ordenar\n");
	                    }
	            	   }
	            	   else
	            	   {
	            		   printf("\nPrimero debe ingresar al menos una mascota!!!");
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
	            	   if(flagAltaMascota)
	            	   {
	            		   if(altaTrabajo(mascotas, TAMMASCOTA, colores, TAMCOL, tipos, TAMTIP, &nextIdTrabajo, trabajos, TAMTRAB, servicios, TAMSERV, clientes, TAMCLIENTES))
					                    {
					                    	printf("\nAlta exitosa\n");
					                    	flagAltaTrabajo = 1;
					                    }
					                    else
					                    {
					                    	printf("Hubo un problema al dar de alta\n");
					                    }
	            	   }
	            	   else
	            	   {
	            		   printf("\nPrimero debe ingresar al menos una mascota!!!");
	            	   }

					  break;



	               case 'I':
	            	   if(flagAltaMascota)
	            	   {
	            	   if(flagAltaTrabajo)
	            	   {
	            	   mostrarTrabajos(trabajos, TAMTRAB, mascotas, TAMMASCOTA, servicios, TAMSERV);
	            	   }
	            	   else
	            	   {
	            		   printf("\nPrimero debe ingresar al menos un trabajo!!!");
	            	   }
	            	   }
	            	   else
	            	   {
	            		   printf("\nPrimero debe ingresar al menos una mascota!!!");
	            	   }
	            	   break;

	               case 'J':
	               	    switch(menuInformes())
	               	    {
	               	    case 1:
	               	    	informeMascotasColor(mascotas, TAMMASCOTA, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES);
	               	    	break;
	               	    case 2:
	               	    	informePromedioMascotasVacunadas(mascotas, TAMMASCOTA);
	               	    	break;
	               	    case 3:
	               	    	informeMascotasMenorEdad(mascotas, TAMMASCOTA, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES);
	               	    	break;
	               	    case 4:
	               	    	informeMascotasPorTipo(mascotas, TAMMASCOTA, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES);
	               	    	break;
	               	    case 5:
	               	    	informeCantidadMascotasTipoYColor(mascotas, TAMMASCOTA, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES);
	               	    	break;
	               	    case 6:
	               	    	informeColorOColoresConMasMascotas(mascotas, TAMMASCOTA, colores, TAMCOL);
	               	    	break;
	               	    case 7:
	               	    	informeMascotaTrabajos(mascotas, TAMMASCOTA, trabajos, TAMTRAB, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES, servicios, TAMSERV);
							break;
	               	    case 8:
	               	    	informeMascotaImporteServicio(mascotas, TAMMASCOTA, trabajos, TAMTRAB, tipos, TAMTIP, colores, TAMCOL, clientes, TAMCLIENTES, servicios, TAMSERV);
	               	    	break;
	               	    case 9:
	               	    	informeMascotasServicio(mascotas, TAMMASCOTA, trabajos, TAMTRAB, servicios, TAMSERV);
	               	    	break;
	               	    case 10:
	               	    	informeFechaServicios(mascotas, TAMMASCOTA, trabajos, TAMTRAB, servicios, TAMSERV);
	               	    	break;
	               	    case 11:
	               	    	seguir = 'n';
	               	    	break;
	               	    default:
	               	    	printf("Opcion invalida\n");
	               	    }
	               	    break;

	               case 'K':
	            	   seguir = 'n';
	            	   break;
	               default:
	            	   printf("Opcion invalida\n");
	            }

	                    printf("\nPresione cualquier tecla para continuar...\n");
	                            fflush(stdin);
	                            getchar();
	                        }while(seguir == 's');

}

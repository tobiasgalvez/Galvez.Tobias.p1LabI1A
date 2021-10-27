/*
 * cliente.h
 *
 *  Created on: 27 oct. 2021
 *      Author: Tobias Galvez
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[25];
	char sexo;
}eCliente;

int listarClientes(eCliente lista[], int tam);
int cargarCliente(int id, eCliente lista[], int tam,char destino[]);



#endif /* CLIENTE_H_ */

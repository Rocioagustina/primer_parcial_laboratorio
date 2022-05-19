/*
 * censista.c
 *
 *  Created on: 17 may. 2022
 *      Author: rocio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censista.h"
#include "fecha.h"
#define TAMANIO_ARRAY_CENSISTAS 100
#define DATOS_CENSISTAS "Los datos de los cencistas son: \n"



void inicializarCensista(Censista *listaCensista, int tamanioDelArray)
{
	int i;

	for(i = 0; i < tamanioDelArray; i++)
	{
		listaCensista[i].isEmpty = 1;
		listaCensista[i].estado = 3;
	}
}


void agregarCensista (Censista *isEmpty, Censista censistaCargado)
{
	*isEmpty = censistaCargado;
}

void eliminarCensista (Censista *censista)
{
	censista->estado = 2;
}

int encontrarCensistaPorId(Censista *listaCensista, int tamanioDelArray, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for(i = 0; i < tamanioDelArray; i++)
	{
		if(listaCensista[i].id == id && listaCensista[i].isEmpty == 0)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

void mostrarCensistas(Censista listaCensista [TAMANIO_ARRAY_CENSISTAS])
{
	int i;

	printf(DATOS_CENSISTAS);

	for(i = 0; i < TAMANIO_ARRAY_CENSISTAS; i++)
	{
		if(listaCensista[i].isEmpty == 0)
		{
			mostrarUnCensista(listaCensista[i]);
		}
	}
}

void mostrarUnCensista(Censista censista)
{

	printf("%d\n", censista.id);
	printf("%s\n", censista.nombre);
	printf("%s\n", censista.apellido);
	printf("%d/%d/%d\n", censista.fechaDeNacimiento.dia, censista.fechaDeNacimiento.mes, censista.fechaDeNacimiento.anio);
	printf("%d\n", censista.edad);
	printf("%d\n", censista.direccion);
}

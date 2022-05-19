/*
 * zona.c
 *
 *  Created on: 18 may. 2022
 *      Author: rocio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zona.h"
#define TAM_ZONA 15
#define DATOS_ZONAS "Los datos de las zonas son: \n"


void agregarZona (Zona *isEmpty, Zona zonaCargada)
{
	*isEmpty = zonaCargada;
}

void mostrarZonas(Zona listaZona [TAM_ZONA])
{
	int i;

	printf(DATOS_ZONAS);

	for(i = 0; i < TAM_ZONA; i++)
	{
		if(listaZona[i].isEmpty == 0)
		{
			mostrarUnaZona(listaZona[i]);
		}
	}
}

void mostrarUnaZona(Zona zona)
{

	printf("%d\n", zona.id);
	printf("%s\n", zona.radio);
	printf("%d\n", zona.localidad);
	printf("%d\n", zona.estado);
}

int buscarZonaPorId(Zona *listaZona, int tamanioArrayZona, int idZona)
{
	int retorno;
	int i;

	retorno = 0;


		retorno = -1;

		for(i = 0; i < tamanioArrayZona; i++)
		{
			if(listaZona[i].id == idZona && listaZona[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}

	return retorno;
}

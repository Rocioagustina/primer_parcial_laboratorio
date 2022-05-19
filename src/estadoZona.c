/*
 * estadoZona.c
 *
 *  Created on: 18 may. 2022
 *      Author: rocio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadoZona.h"

#define TAM_ID_ZONAS 2
#define DESCR_PENDIENTE "PENDIENTE"
#define DESCR_FINALIZADO "FINALIZADO"
#define ESTADOS_ZONAS "Los estados de las zonas son: \n\n"


void inicializarEstadoZona(estadoZona *listaEstadoZona)
{
	listaEstadoZona[0].id = 1;
	strcpy(listaEstadoZona[0].descripcion, DESCR_PENDIENTE);

	listaEstadoZona[1].id = 2;
	strcpy(listaEstadoZona[1].descripcion, DESCR_FINALIZADO);

}


void mostrarEstadoZona(estadoZona listaEstadoZona [TAM_ID_ZONAS])
{
	int i;

	printf(ESTADOS_ZONAS);


	for(i = 0; i < 3; i++)
	{
		printf("%d\n", listaEstadoZona[i].id);
		printf("%s \n\n", listaEstadoZona[i].descripcion);
	}
}

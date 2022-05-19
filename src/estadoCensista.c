/*
 * estadoCensista.c
 *
 *  Created on: 18 may. 2022
 *      Author: rocio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadoCensista.h"

#define TAM_ID_CENSISTA 3
#define DESCR_ACTIVO "ACTIVO"
#define DESCR_INACTIVO "INACTIVO"
#define DESCR_LIBERADO "LIBERADO"
#define ESTADOS_CENSISTAS "Los estados de los censistas son: \n\n"


void inicializarEstadoCensista(estadoCensista listaEstadoCensista [TAM_ID_CENSISTA])
{
	listaEstadoCensista[0].id = 1;
	strcpy(listaEstadoCensista[0].descripcion, DESCR_ACTIVO);

	listaEstadoCensista[1].id = 2;
	strcpy(listaEstadoCensista[1].descripcion, DESCR_INACTIVO);

	listaEstadoCensista[2].id = 3;
	strcpy(listaEstadoCensista[2].descripcion, DESCR_LIBERADO);
}


void mostrarEstadoCensista(estadoCensista listaEstadoCensista [TAM_ID])
{
	int i;

	printf(ESTADOS_CENSISTAS);


	for(i = 0; i < 3; i++)
	{
		printf("%d\n", listaEstadoCensista[i].id);
		printf("%s \n\n", listaEstadoCensista[i].descripcion);
	}
}

/*
 * estadoZona.h
 *
 *  Created on: 18 may. 2022
 *      Author: rocio
 */

#ifndef ESTADOZONA_H_
#define ESTADOZONA_H_
#define TAM_STR 512
#define TAM_ID_ZONAS 2

struct
{
 int id;
 char descripcion [TAM_STR];
}typedef estadoZona;

void inicializarEstadoZona(estadoZona *listaEstadoZona);

void mostrarEstadoZona(estadoZona listaEstadoZona [TAM_ID_ZONAS]);

#endif /* ESTADOZONA_H_ */

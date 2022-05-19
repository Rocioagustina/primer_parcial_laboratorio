/*
 * estadoCensista.h
 *
 *  Created on: 18 may. 2022
 *      Author: rocio
 */

#ifndef ESTADOCENSISTA_H_
#define ESTADOCENSISTA_H_
#define TAM_STR 512
#define TAM_ID 3

struct
{
 int id;
 char descripcion [TAM_STR];
}typedef estadoCensista;


void inicializarEstadoCensista(estadoCensista listaEstadoCensista [TAM_ID]);

void mostrarEstadoDelVuelo(estadoCensista listaEstadoCensista [TAM_ID]);

#endif /* ESTADOCENSISTA_H_ */

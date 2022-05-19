/*
 * censista.h
 *
 *  Created on: 17 may. 2022
 *      Author: rocio
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#define TAM_NOMBRE 51
#define TAM_STR 512
#define TAMANIO_ARRAY_CENSISTAS 100
#include "fecha.h"


struct
{
 int id;
 char nombre[TAM_NOMBRE];
 char apellido[TAM_NOMBRE];
 Fecha fechaDeNacimiento;
 int edad;
 int estado;
 int zona;
 char direccion [TAM_STR];
 int isEmpty;
}typedef Censista;

void inicializarCensista(Censista *listaCensista, int tamanioDelArray);

void agregarCensista (Censista *isEmpty, Censista censistaCargado);

void eliminarCensista (Censista *censista);

int encontrarCensistaPorId(Censista *listaCensista, int tamanioDelArray, int id);

void mostrarCensistas(Censista listaCensista [TAMANIO_ARRAY_CENSISTAS]);

void mostrarUnCensista(Censista censista);

int buscarCensistaPorId(Censista *listaCensista, int tamanioArrayCensista, int idCensista);

#endif /* CENSISTA_H_ */

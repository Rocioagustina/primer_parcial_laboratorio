/*
 * rJimenez.h
 *
 *  Created on: 17 may. 2022
 *      Author: rocio
 */

#ifndef RJIMENEZ_H_
#define RJIMENEZ_H_
#define TAM_STR 512
#define TAM_NOMBRE 51
#define TAM_INT 20

#include "censista.h"






int pedirFloat (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], float *pResultado);

int validarFloat (char resultado [TAM_STR]);

int pedirNombre (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], char *pResultadoNombre);

int validarNombre (char nombreSinValidar [TAM_NOMBRE]);

int pedirCodigo (char mensaje [TAM_STR], char *pResultadoCodigo);

int pedirInt(char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], int *pResultadoInt, int minimo, int maximo);

int validarInt(char pResultadoInt [TAM_INT]);

int buscarLibre(Censista *listaCensista, int tamanioDelArray);

int darAltaCensista(Censista *listaCensista, int tamanioDelArray, char mensajeNombre [TAM_NOMBRE], char mensajeErrorNombre [TAM_NOMBRE],
					char mensajeExitoNombre [TAM_NOMBRE], char mensajeErrorEspacio [TAM_NOMBRE], char mensajeApellido [TAM_NOMBRE],
					char mensajeErrorApellido [TAM_NOMBRE], char mensajeExitoApellido [TAM_NOMBRE], char mensajeDia [TAM_STR],
					char mensajeErrorDia[TAM_STR], char mensajeExitoDia [TAM_STR], char mensajeMes [TAM_STR], char mensajeErrorMes [TAM_STR],
					char mensajeExitoMes [TAM_STR], char mensajeAnio [TAM_STR], char mensajeErrorAnio [TAM_STR], char mensajeExitoAnio [TAM_STR],
					char mensajeEdad [TAM_STR], char mensajeErrorEdad [TAM_STR], char mensajeExitoEdad [TAM_STR], char mensajeDireccion [TAM_STR],
					char mensajeErrorDireccion [TAM_STR], char mensajeExitoDireccion [TAM_STR], char mensajeCargaCompleta [TAM_STR], int id,
					int minimo, int maximo);


int modificarCensista(Censista *listaCensista, int tamanioDelArray, char mensajeId [TAM_STR], char mensajeErrorId [TAM_STR], char mensajeExitoId [TAM_STR],
					char mensajeOpcion [TAM_STR], char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR],
					char mensajeModificarNombre [TAM_STR], char mensajeErrorModificarNombre [TAM_STR], char mensajeExitoModificarNombre [TAM_STR],
					char mensajeModificarApellido [TAM_STR], char mensajeErrorModificarApellido [TAM_STR], char mensajeExitoModificarApellido [TAM_STR],
					char mensajeModificarDia [TAM_STR], char mensajeErrorModificarDia [TAM_STR], char mensajeExitoModificarDia [TAM_STR],
					char mensajeModificarMes [TAM_STR], char mensajeErrorModificarMes [TAM_STR], char mensajeExitoModificarMes [TAM_STR],
					char mensajeModificarAnio [TAM_STR], char mensajeErrorModificarAnio [TAM_STR], char mensajeExitoModificarAnio [TAM_STR],
					char mensajeModificarEdad [TAM_STR], char mensajeErrorModificarEdad [TAM_STR], char mensajeExitoModificarEdad [TAM_STR],
					char mensajeModificarDireccion [TAM_STR], char mensajeErrorModificarDireccion [TAM_STR],char mensajeExitoModificarDireccion [TAM_STR]);

int modificarNombre (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR],	char mensajeExitoModificar [TAM_STR], Censista *censista);

int modificarApellido (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista);

int modificarDia (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista);

int modificarMes (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista);

int modificarAnio (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista);

int modificarEdad (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista,
					int minimo, int maximo);

int modificarDireccion(char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista);

int darBajaCensista (Censista *listaCensista, int tamanioDelArray, char mensajeId [TAM_STR], char mensajeErrorId [TAM_STR], char mensajeExitoId [TAM_STR],
					char mensajeErrorBaja [TAM_STR], char mensajeExitoBaja [TAM_STR], char mensajeErrorIdNoEncontrado [TAM_STR]);

#endif /* RJIMENEZ_H_ */

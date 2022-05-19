/*
 * zona.h
 *
 *  Created on: 18 may. 2022
 *      Author: rocio
 */

#ifndef ZONA_H_
#define ZONA_H_
#define TAM_STR 512
#define TAM_ZONA 15


struct
{
 int id;
 char radio [TAM_STR];
 int localidad;
 int estado;
 int isEmpty;
}typedef Zona;

void agregarZona (Zona *isEmpty, Zona zonaCargada);

void mostrarZonas(Zona listaZona [TAM_ZONA]);

void mostrarUnaZona(Zona zona);

int buscarZonaPorId(Zona *listaZona, int tamanioArrayZona, int idZona);

#endif /* ZONA_H_ */

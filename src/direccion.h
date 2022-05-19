/*
 * zona.h
 *
 *  Created on: 18 may. 2022
 *      Author: rocio
 */

#ifndef DIRECCION_H_
#define DIRECCION_H_
#define TAM_STR 512

struct
{
 int id;
 char radio [TAM_STR];
 int localidad;
 int estado;
 int isEmpty;
}typedef Zona;


#endif /* DIRECCION_H_ */

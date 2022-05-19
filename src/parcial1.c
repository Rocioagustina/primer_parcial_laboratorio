/*
 ============================================================================
 Name        : parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rJimenez.h"
#include "censista.h"
#include "estadoCensista.h"
#include "estadoZona.h"

#define MENSAJE_OPCION_UNO "1. ALTA \n"
#define PEDIR_NOMBRE_CENSISTA "Ingrese el nombre del censista: \n"
#define PEDIR_APELLIDO_CENSISTA "Ingrese el apellido del censista: \n"
#define PEDIR_DIA_DE_NACIMIENTO "Ingrese el dia de nacimiento del censista: \n"
#define PEDIR_MES_DE_NACIMIENTO "Ingrese el mes de nacimiento del censista: \n"
#define PEDIR_ANIO_DE_NACIMIENTO "Ingrese el año de nacimiento del censista: \n"
#define PEDIR_EDAD "Ingrese la edad del censista: \n"
#define PEDIR_DIRECCION "Ingrese la direccion del censista: \n"
#define MENSAJE_OPCION_DOS "2. MODIFICACION \n"
#define MENSAJE_OPCION_TRES "3. BAJA \n"
#define MENSAJE_OPCION_CUATRO "4. CARGAR ZONA \n"
#define MENSAJE_OPCION_CINCO "5. ASIGNAR ZONA A CENSAR \n"
#define MENSAJE_OPCION_SEIS "6. CARGA DE DATOS \n"
#define MENSAJE_OPCION_SIETE "7. MOSTRAR CENSISTAS \n"
#define MENSAJE_OPCION_OCHO "8. MOSTRAR ZONAS \n"
#define MENSAJE_OPCION_NUEVE "9. SALIR"
#define TAM_ARRAY_CENSISTAS 100
#define MENSAJE_ERROR_NOMBRE "Error en el ingreso del nombre \n"
#define MENSAJE_EXITO_NOMBRE "El nombre ha sido ingresado exitosamente \n"
#define MENSAJE_ERROR_ESPACIO "No se puede ingresar al censista ya que no hay mas espacio \n"
#define MENSAJE_ERROR_APELLIDO "Error en el ingreso del apellido \n"
#define MENSAJE_EXITO_APELLIDO "El apellido ha sido ingresado exitosamente \n"
#define MENSAJE_ERROR_EDAD "Error en el ingreso de la edad \n"
#define MENSAJE_EXITO_EDAD "La edad ha sido ingresada exitosamente \n"
#define ALTA_COMPLETA "El alta del censista ha sido completada exitosamente \n"
#define MENSAJE_ID "Ingrese el ID del censista: \n"
#define MENSAJE_ERROR_ID "Error en el ingreso del ID \n"
#define MENSAJE_EXITO_ID "El ID fue ingresado correctamente \n"
#define MENSAJE_ERROR_BAJA "Error en la baja, no pudo realizarse \n"
#define MENSAJE_EXITO_BAJA "La baja del censista ha sido completada exitosamente \n"
#define MENSAJE_ID_NO_ENCONTRADO "ID no encontrado \n"
#define MENSAJE_PEDIR_OPCION "Ingrese una opcion: \n"
#define MENSAJE_MODIFICAR "Ingrese el dato que desea modificar: \n"
#define MENSAJE_ERROR_MODIFICAR "Error en la modificacion, no pudo realizarse \n"
#define MENSAJE_EXITO_MODIFICAR "La modificacion ha sido completada exitosamente \n"
#define MENSAJE_MODIFICAR_NOMBRE "Ingrese el nuevo nombre \n"
#define MENSAJE_ERROR_MODIFICAR_NOMBRE "Error en el ingreso del nombre, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_NOMBRE "El nombre ha sido modificado exitosamente \n"
#define MENSAJE_MODIFICAR_APELLIDO "Ingrese el nuevo apellido \n"
#define MENSAJE_ERROR_MODIFICAR_APELLIDO "Error en el ingreso del apellido, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_APELLIDO "El apellido ha sido modificado exitosamente \n"
#define MENSAJE_MODIFICAR_DIA "Ingrese el nuevo dia de nacimiento \n"
#define MENSAJE_ERROR_MODIFICAR_DIA "Error en la modificacion del dia de nacimiento, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_DIA "El dia de nacimiento ha sido modificado exitosamente \n"
#define MENSAJE_MODIFICAR_MES "Ingrese el nuevo mes de nacimiento \n"
#define MENSAJE_ERROR_MODIFICAR_MES "Error en la modificacion del mes de nacimiento, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_MES "El mes de nacimiento ha sido modificado exitosamente \n"
#define MENSAJE_MODIFICAR_ANIO "Ingrese el nuevo año de nacimiento \n"
#define MENSAJE_ERROR_MODIFICAR_ANIO "Error en la modificacion del año de nacimiento, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_ANIO "El año de nacimiento ha sido modificado exitosamente \n"
#define MENSAJE_MODIFICAR_EDAD "Ingrese la nueva edad \n"
#define MENSAJE_ERROR_MODIFICAR_EDAD "Error en el ingreso de la edad, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_EDAD "La edad fue modificada exitosamente \n"
#define MENSAJE_MODIFICAR_DIRECCION "Ingrese la nueva direccion \n"
#define MENSAJE_ERROR_MODIFICAR_DIRECCION "Error en el ingreso de la direccion, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_DIRECCION "La direccion fue modificada exitosamente \n"
#define FIN_DEL_PROCESO "Programa cerrado con exito\n"
#define OPCION_INVALIDA "La opcion ingresada es invalida\n"
#define TAM_ESTADOS_CENSISTAS 3
#define TAM_ESTADOS_ZONAS 2
#define MENSAJE_ERROR_DIA "Error en el ingreso del dia de nacimiento \n"
#define MENSAJE_EXITO_DIA "El dia de nacimiento ha sido ingresado exitosamente \n"
#define MENSAJE_ERROR_MES "Error en el ingreso del mes de nacimiento \n"
#define MENSAJE_EXITO_MES "El mes de nacimiento ha sido ingresado exitosamente \n"
#define MENSAJE_ERROR_ANIO "Error en el ingreso del año de nacimiento \n"
#define MENSAJE_EXITO_ANIO "El año de nacimiento ha sido ingresado exitosamente \n"
#define TAM_ZONA 15
#define MENSAJE_RADIO "Ingrese la cuadra y altura donde comienza el radio \n"
#define MENSAJE_LOCALIDAD "Ingrese el numero de localidad \n"
#define MENSAJE_ERROR_LOCALIDAD "Error en el ingreso del numero de localidad \n"
#define MENSAJE_EXITO_LOCALIDAD "El numero de localidad ha sido ingresado exitosamente \n"
#define MENSAJE_ESTADO "Ingrese el estado de la zona \n"
#define MENSAJE_ERROR_ESTADO "Error en el ingreso del estado de la zona \n"
#define MENSAJE_EXITO_ESTADO "El estado de la zona ha sido ingresado exitosamente \n"
#define MENSAJE_CARGA_COMPLETA "La zona ha sido completada exitosamente \n"
#define MENSAJE_ZONA "Ingrese la zona \n"
#define MENSAJE_ERROR_ZONA "Error en el ingreso de la zona \n"
#define MENSAJE_EXITO_ZONA "La zona ha sido ingresada exitosamente \n"
#define MENSAJE_CENSISTA "Ingrese el censista \n"
#define MENSAJE_ERROR_CENSISTA "Error en el ingreso del censista \n"
#define MENSAJE_EXITO_CENSISTA "El censista ha sido ingresado exitosamente"






int main(void) {

		setbuf(stdout, NULL);
		int opcion;
		int id;
		int idZona;
		Censista arrayCensistas [TAM_ARRAY_CENSISTAS];
		estadoCensista arrayEstadoCensistas [TAM_ESTADOS_CENSISTAS];
		estadoZona arrayEstadoZonas [TAM_ESTADOS_ZONAS];
		Zona arrayZona [TAM_ZONA];

		id = 1;
		idZona = 1;

		inicializarCensista(arrayCensistas, TAM_ARRAY_CENSISTAS);
		inicializarEstadoCensista(arrayEstadoCensistas);
		inicializarEstadoZona(arrayEstadoZonas);


		do
		{
			printf(MENSAJE_OPCION_UNO);
			printf(MENSAJE_OPCION_DOS);
			printf(MENSAJE_OPCION_TRES);
			printf(MENSAJE_OPCION_CUATRO);
			printf(MENSAJE_OPCION_CINCO);
			printf(MENSAJE_OPCION_SEIS);
			printf(MENSAJE_OPCION_SIETE);
			printf(MENSAJE_OPCION_OCHO);
			printf(MENSAJE_OPCION_NUEVE);
			scanf("%d", &opcion);


			switch(opcion)
			{
			case 1:
				if(darAltaCensista(arrayCensistas, TAM_ARRAY_CENSISTAS, PEDIR_NOMBRE_CENSISTA, MENSAJE_ERROR_NOMBRE, MENSAJE_EXITO_NOMBRE,
					MENSAJE_ERROR_ESPACIO, PEDIR_APELLIDO_CENSISTA, MENSAJE_ERROR_APELLIDO, MENSAJE_EXITO_APELLIDO, PEDIR_DIA_DE_NACIMIENTO,
					MENSAJE_ERROR_DIA, MENSAJE_EXITO_DIA, PEDIR_MES_DE_NACIMIENTO, MENSAJE_ERROR_MES, MENSAJE_EXITO_MES, PEDIR_ANIO_DE_NACIMIENTO,
					MENSAJE_ERROR_ANIO, MENSAJE_EXITO_ANIO, PEDIR_EDAD, MENSAJE_ERROR_EDAD, MENSAJE_EXITO_EDAD, PEDIR_DIRECCION, ALTA_COMPLETA, id,
					0, 4) == 0)
				{
					id++;
				}

				break;
			case 2:
				modificarCensista(arrayCensistas, TAMANIO_ARRAY_CENSISTAS, MENSAJE_ID, MENSAJE_ERROR_ID, MENSAJE_EXITO_ID, MENSAJE_PEDIR_OPCION,
					MENSAJE_MODIFICAR, MENSAJE_ERROR_MODIFICAR, MENSAJE_EXITO_MODIFICAR, MENSAJE_MODIFICAR_NOMBRE, MENSAJE_ERROR_MODIFICAR_NOMBRE,
					MENSAJE_EXITO_MODIFICAR_NOMBRE, MENSAJE_MODIFICAR_APELLIDO, MENSAJE_ERROR_MODIFICAR_APELLIDO, MENSAJE_EXITO_MODIFICAR_APELLIDO,
					MENSAJE_MODIFICAR_DIA, MENSAJE_ERROR_MODIFICAR_DIA, MENSAJE_EXITO_MODIFICAR_DIA, MENSAJE_MODIFICAR_MES, MENSAJE_ERROR_MODIFICAR_MES,
					MENSAJE_EXITO_MODIFICAR_MES, MENSAJE_MODIFICAR_ANIO, MENSAJE_ERROR_MODIFICAR_ANIO, MENSAJE_EXITO_MODIFICAR_ANIO, MENSAJE_MODIFICAR_EDAD,
					MENSAJE_ERROR_MODIFICAR_EDAD, MENSAJE_EXITO_MODIFICAR_EDAD, MENSAJE_MODIFICAR_DIRECCION, MENSAJE_ERROR_MODIFICAR_DIRECCION,
					MENSAJE_EXITO_MODIFICAR_DIRECCION);
				break;
			case 3:
				darBajaCensista (arrayCensistas, TAMANIO_ARRAY_CENSISTAS, MENSAJE_ID, MENSAJE_ERROR_ID, MENSAJE_EXITO_ID, MENSAJE_ERROR_BAJA,
						MENSAJE_EXITO_BAJA, MENSAJE_ID_NO_ENCONTRADO);
				break;
			case 4:if(darAltaZona(arrayZona, TAM_ZONA, MENSAJE_RADIO, MENSAJE_LOCALIDAD, MENSAJE_ERROR_LOCALIDAD, MENSAJE_EXITO_LOCALIDAD, MENSAJE_ESTADO,
					MENSAJE_ERROR_ESTADO, MENSAJE_EXITO_ESTADO, MENSAJE_CARGA_COMPLETA, idZona) == 0)
					{
						idZona++;
					}
				break;
			case 5: asignarZona(arrayZona, TAM_ZONA, arrayCensistas, TAMANIO_ARRAY_CENSISTAS, MENSAJE_ZONA, MENSAJE_ERROR_ZONA, MENSAJE_EXITO_ZONA,
					MENSAJE_CENSISTA, MENSAJE_ERROR_CENSISTA, MENSAJE_EXITO_CENSISTA);
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9: printf(FIN_DEL_PROCESO);
				break;
			default:
				printf(OPCION_INVALIDA);
			}
		}while(opcion != 5);




		return EXIT_SUCCESS;
	}


/*
 * rJimenez.c
 *
 *  Created on: 17 may. 2022
 *      Author: rocio
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rJimenez.h"
#include "censista.h"



#define TAM_STR 512
#define TAM_NOMBRE 51
#define TAM_INT 20
#define ELECCION_DE_MODIFICACION "¿Que dato desea modificar? \n\n"
#define MODIFICAR_NOMBRE "1. Nombre \n"
#define MODIFICAR_APELLIDO "2. Apellido \n"
#define MODIFICAR_DIA_NACIMIENTO "4. Dia de nacimiento \n"
#define MODIFICAR_MES_DE_NACIMIENTO "5. Mes de nacimiento \n"
#define MODIFICAR_ANIO_DE_NACIMIENTO "6. Año de nacimiento \n"
#define MODIFICAR_EDAD "7. Edad \n"
#define MODIFICAR_DIRECCION "8. Direccion \n"


/// @fn int pedirFloat(char[], char[], char[], float*)
/// @brief Pide y valida un numero flotante.
///
/// @param mensaje Es el mensaje que pide el numero flotante.
/// @param mensajeError El mensaje que indica que se ingreso un numero incorrecto.
/// @param mensajeExito El mensaje que indica que se ingreso un numero correcto
/// @param pResultado El puntero donde se guarda el numero flotante
/// @return  1 si todo sale bien y 0 si hay algun error.

int pedirFloat (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], float *pResultado)
{
	int retorno;
	char floatSinValidar [TAM_STR];

	retorno = 1;

	printf(mensaje);
	scanf("%s", floatSinValidar);

	if(validarFloat(floatSinValidar) == 0)
	{
		printf(mensajeExito);
		*pResultado = atof(floatSinValidar);
		retorno = 0;
	}
	else
	{
		printf(mensajeError);
	}

	return retorno;
}


/// @fn int validarFloat(char[])
/// @brief Valida un numero flotante.
///
/// @param resultado El numero a validar
/// @return 1 si todo sale bien y 0 si hay algun error.

int validarFloat (char resultado [TAM_STR])
{
	int retorno;
	int banderaFlotante;
	int i;

	retorno = 0;
	banderaFlotante = 0;


	for(i=0 ; i<strlen(resultado) ; i++)
	{
		if(resultado [i] < '0' || resultado [i] > '9')
		{
			if (resultado [i] == '.')
			{
				if (banderaFlotante == 1)
				{
					retorno = 1;
					break;
				}
			banderaFlotante = 1;
			}else
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/// @fn int pedirNombre(char[], char[], char[], char*)
/// @brief Pide una cadena de caracteres
///
/// @param mensaje El mensaje para pedir el nombre
/// @param mensajeError El mensaje que devuelve si se ingreso mal el nombre
/// @param mensajeExito El mensaje que devuelve si se ingreso bien el nombre
/// @param pResultadoNombre El puntero donde se guarda el nombre
/// @return 0 si sale todo bien y 1 si hay algun error

int pedirNombre (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], char *pResultadoNombre)
{
	int retorno;
	char nombreSinValidar[TAM_NOMBRE];

	retorno = 1;

	printf(mensaje);
	scanf("%s", nombreSinValidar);

	if(validarNombre(nombreSinValidar) == 0)
	{
		retorno = 0;
		strcpy(pResultadoNombre, nombreSinValidar);
		printf(mensajeExito);
	}
	else
	{
		printf(mensajeError);
	}

	return retorno;
}

/// @fn int validarNombre(char[])
/// @brief Valida una cadena de caracteres
///
/// @param nombreSinValidar El nombre a validar
/// @return 0 si sale todo bien y 1 si hay algun error

int validarNombre (char nombreSinValidar [TAM_NOMBRE])
{
	int retorno;
	int i;

	retorno = 0;

	for(i = 0; i < strlen (nombreSinValidar); i++)
	{
		if((nombreSinValidar [i] < 'a' || nombreSinValidar [i] > 'z') && (nombreSinValidar [i] < 'A' || nombreSinValidar [i] > 'Z'))
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

/*
/// @fn int pedirCodigo(char[], char[], char[], char*)
/// @brief Pide el codigo del vuelo
///
/// @param mensaje El mensaje para pedir el codigo
/// @param pResultadoCodigo El puntero donde se guarda el codigo
/// @return 0

int pedirCodigo (char mensaje [TAM_STR], char *pResultadoCodigo)
{
	int retorno;

	retorno = 0;

	printf(mensaje);
	scanf("%s", pResultadoCodigo);

	return retorno;
}

*/
/// @fn int pedirInt(char[], char[], char[], int*, int, int)
/// @brief Pide un numero entero
///
/// @param mensaje Es el mensaje que pide un numero entero
/// @param mensajeError El mensaje que devuelve si se ingreso mal el numero entero
/// @param mensajeExito El mensaje que devuelve si se ingreso bien el numero entero
/// @param pResultadoInt El puntero donde se guarda el numero entero
/// @param minimo Es el numero minimo que acepta la funcion
/// @param maximo Es el numero maximo que acepta la funcion
/// @return 0 si sale todo bien y 1 si hay algun error

int pedirInt(char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], int *pResultadoInt, int minimo, int maximo)
{
	int retorno;
	char numeroSinValidar [TAM_INT];
	int numeroNoValidado;

	retorno = 0;

	printf(mensaje);
	scanf("%s", numeroSinValidar);

	if (validarInt(numeroSinValidar) == 0)
	{
		numeroNoValidado = atoi(numeroSinValidar);

		if(numeroNoValidado < maximo && numeroNoValidado > minimo)
		{
			*pResultadoInt = numeroNoValidado;
			printf(mensajeExito);
		}
		else
		{
			retorno = 1;
			printf(mensajeError);
		}
	} else
	{
		retorno = 1;
		printf(mensajeError);
	}

	return retorno;
}

/// @fn int validarInt(char[])
/// @brief Valida que el numero sea un entero
///
/// @param pResultadoInt Es el puntero donde se guarda el entero validado
/// @return 0 si sale todo bien y 1 si hay algun error

int validarInt(char pResultadoInt [TAM_INT])
{
	int retorno;
	int i;

	retorno = 0;

	for(i=0 ; i<strlen(pResultadoInt) ; i++)
	{
		if(pResultadoInt [i] < '0' || pResultadoInt [i] > '9')
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

/// @fn int buscarLibre(Censista*, int)
/// @brief Busca un lugar libre en el array para posicionar el id
///
/// @param listaCensista Es el array de datos de tipo Censista
/// @param tamanioDelArray Es el tamaño del array
/// @return -1 si no hay mas lugar y un numero si encontro un lugar

int buscarLibre(Censista *listaCensista, int tamanioDelArray)
{
	int retorno;
	int i;

	retorno = -1;

	for(i = 0; i < tamanioDelArray; i++)
	{
		if(listaCensista[i].isEmpty != 0)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}



/// @fn int darAltaCensista(Censista*, int, char[], char[], char[], char[], char[], char[], char[], char[], char[], char[], char[], char[], char[], char[], char[], char[], char[], int, int, int)
/// @brief
///
/// @param listaCensista Es el array de datos de tipo Censista
/// @param tamanioDelArray Es el tamaño del array
/// @param mensajeNombre Es el mensaje que pide el nombre
/// @param mensajeErrorNombre Es el mensaje que devuelve si se ingreso mal el nombre
/// @param mensajeExitoNombre Es el mensaje que devuelve si se ingreso bien el nombre
/// @param mensajeErrorEspacio Es el mensaje que devuelve si no hay mas lugar en el array para posicionar el id
/// @param mensajeApellido Es el mensaje que pide el apellido
/// @param mensajeErrorApellido Es el mensaje que devuelve si se ingreso mal el apellido
/// @param mensajeExitoApellido Es el mensaje que devuelve si se ingreso bien el apellido
/// @param mensajeFecha Es el mensaje que pide la fecha de nacimiento
/// @param mensajeErrorFecha Es el mensaje que devuelve si se ingreso mal la fecha de nacimiento
/// @param mensajeExitoFecha Es el mensaje que devuelve si se ingreso bien la fecha de nacimiento
/// @param mensajeEdad Es el mensaje que pide la edad
/// @param mensajeErrorEdad Es el mensaje que devuelve si se ingreso mal la edad
/// @param mensajeExitoEdad Es el mensaje que devuelve si se ingreso bien la edad
/// @param mensajeDireccion Es el mensaje que pide la direccion
/// @param mensajeErrorDireccion Es el mensaje que devuelve si se ingreso mal la direccion
/// @param mensajeExitoDireccion Es el mensaje que devuelve si se ingreso bien la direccion
/// @param mensajeCargaCompleta Es el mensaje que devuelve si se pudo completar la carga con exito
/// @param id Es el numero de id que se le asigno al censista
/// @param minimo Es el numero minimo que acepta la funcion
/// @param maximo Es el numero maximo que acepta la funcion
/// @return -1 si no se pudo completar la carga y 0 si se pudo completar

int darAltaCensista(Censista *listaCensista, int tamanioDelArray, char mensajeNombre [TAM_NOMBRE], char mensajeErrorNombre [TAM_NOMBRE],
					char mensajeExitoNombre [TAM_NOMBRE], char mensajeErrorEspacio [TAM_NOMBRE], char mensajeApellido [TAM_NOMBRE],
					char mensajeErrorApellido [TAM_NOMBRE], char mensajeExitoApellido [TAM_NOMBRE], char mensajeDia [TAM_STR],
					char mensajeErrorDia[TAM_STR], char mensajeExitoDia [TAM_STR], char mensajeMes [TAM_STR], char mensajeErrorMes [TAM_STR],
					char mensajeExitoMes [TAM_STR], char mensajeAnio [TAM_STR], char mensajeErrorAnio [TAM_STR], char mensajeExitoAnio [TAM_STR],
					char mensajeEdad [TAM_STR], char mensajeErrorEdad [TAM_STR], char mensajeExitoEdad [TAM_STR], char mensajeDireccion [TAM_STR],
					char mensajeErrorDireccion [TAM_STR], char mensajeExitoDireccion [TAM_STR], char mensajeCargaCompleta [TAM_STR], int id,
					int minimo, int maximo)
{
	int retorno;
	Censista aux;
	int indice;

	retorno = -1;


	indice = buscarLibre(listaCensista, tamanioDelArray);

	if(indice != -1)
	{
		if(pedirNombre(mensajeNombre, mensajeErrorNombre, mensajeExitoNombre, aux.nombre) == 0)
		{
			if(pedirNombre(mensajeApellido, mensajeErrorApellido, mensajeExitoApellido, aux.apellido) == 0)
			{
				if(pedirInt(mensajeDia, mensajeErrorDia, mensajeExitoDia, &aux.fechaDeNacimiento.dia, 0, 32) == 0)
				{
					if(pedirInt(mensajeMes, mensajeErrorMes, mensajeExitoMes, &aux.fechaDeNacimiento.mes, 0, 13) == 0)
					{
						if(pedirInt(mensajeAnio, mensajeErrorAnio, mensajeExitoAnio, &aux.fechaDeNacimiento.anio, 1966, 2005) == 0)
						{
							if(pedirInt(mensajeEdad, mensajeErrorEdad, mensajeExitoEdad, &aux.edad, 17, 56) == 0)
							{
								if(pedirInt(mensajeDireccion, mensajeErrorDireccion, mensajeExitoDireccion, &aux.direccion, 1 ,100) == 0)
								{
									printf(mensajeCargaCompleta);
									aux.id = id;
									aux.isEmpty = 0;
									agregarCensista(&listaCensista[indice], aux);
									retorno = 0;
								}
							}
						}
					}
				}
			}
		}
	}
	else
	{
		printf(mensajeErrorEspacio);
	}


	return retorno;
}

int darBajaCensista (Censista *listaCensista, int tamanioDelArray, char mensajeId [TAM_STR], char mensajeErrorId [TAM_STR],
					char mensajeExitoId [TAM_STR], char mensajeErrorBaja [TAM_STR], char mensajeExitoBaja [TAM_STR],
					char mensajeErrorIdNoEncontrado [TAM_STR])
{
	int retorno;
	int idBorrar;
	int indice;


	retorno = 1;

	mostrarCensistas(listaCensista);

	 if(pedirInt(mensajeId, mensajeErrorId, mensajeExitoId, &idBorrar, 0, tamanioDelArray) == 0)
	 {
		 indice = encontrarCensistaPorId(listaCensista, tamanioDelArray, idBorrar);
		 if(indice != -1)
		 {
			 eliminarCensista(&listaCensista[indice]);
			 printf(mensajeExitoBaja);
			 retorno = 0;
		 } else
		 {
			 printf(mensajeErrorIdNoEncontrado);
		 }
	 }
	 else
	 {
		 printf(mensajeErrorBaja);
	 }

	return retorno;
}


int modificarCensista(Censista *listaCensista, int tamanioDelArray, char mensajeId [TAM_STR], char mensajeErrorId [TAM_STR], char mensajeExitoId [TAM_STR],
					char mensajeOpcion [TAM_STR], char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR],
					char mensajeModificarNombre [TAM_STR], char mensajeErrorModificarNombre [TAM_STR], char mensajeExitoModificarNombre [TAM_STR],
					char mensajeModificarApellido [TAM_STR], char mensajeErrorModificarApellido [TAM_STR], char mensajeExitoModificarApellido [TAM_STR],
					char mensajeModificarDia [TAM_STR], char mensajeErrorModificarDia [TAM_STR], char mensajeExitoModificarDia [TAM_STR],
					char mensajeModificarMes [TAM_STR], char mensajeErrorModificarMes [TAM_STR], char mensajeExitoModificarMes [TAM_STR],
					char mensajeModificarAnio [TAM_STR], char mensajeErrorModificarAnio [TAM_STR], char mensajeExitoModificarAnio [TAM_STR],
					char mensajeModificarEdad [TAM_STR], char mensajeErrorModificarEdad [TAM_STR], char mensajeExitoModificarEdad [TAM_STR],
					char mensajeModificarDireccion [TAM_STR], char mensajeErrorModificarDireccion [TAM_STR],char mensajeExitoModificarDireccion [TAM_STR])
{
	int retorno;
	int idBorrar;
	int indice;
	int opcion;

	retorno = 1;

	mostrarCensistas(listaCensista);

	if(pedirInt(mensajeId, mensajeErrorId, mensajeExitoId, &idBorrar, 0, tamanioDelArray) == 0)
	{
		 indice = encontrarCensistaPorId(listaCensista, tamanioDelArray, idBorrar);
		 if(indice != -1)
		 {

			 printf(ELECCION_DE_MODIFICACION);
			 printf(MODIFICAR_NOMBRE);
			 printf(MODIFICAR_APELLIDO);
			 printf(MODIFICAR_DIA_NACIMIENTO);
			 printf(MODIFICAR_MES_DE_NACIMIENTO);
			 printf(MODIFICAR_ANIO_DE_NACIMIENTO);
			 printf(MODIFICAR_EDAD);
			 printf(MODIFICAR_DIRECCION);
			 printf(mensajeOpcion);
			 pedirInt(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, &opcion, 0,6);

			 switch(opcion)
			 {
			 case 1: if(modificarNombre (mensajeModificarNombre, mensajeErrorModificarNombre, mensajeExitoModificarNombre, &listaCensista[indice]) != -1)
					 {
						retorno = 0;
					 }
					break;


			 case 2: if(modificarApellido(mensajeModificarApellido, mensajeErrorModificarApellido, mensajeExitoModificarApellido, &listaCensista[indice])
					 != -1)
					 {
						 retorno = 0;
					 }
			 	 	break;

			 case 3: if(modificarDia(mensajeModificarDia, mensajeErrorModificarDia, mensajeExitoModificarDia, &listaCensista[indice]) != -1)
			 	 	 {
				 	 	 retorno = 0;
			 	 	 }
				 break;
			 case 4: if(modificarMes(mensajeModificarMes, mensajeErrorModificarMes, mensajeExitoModificarMes, &listaCensista[indice]) != -1)
					 {
				 	 	 retorno = 0;
					 }
				 break;

			 case 5: if(modificarAnio(mensajeModificarAnio, mensajeErrorModificarAnio, mensajeExitoModificarAnio, &listaCensista[indice]) != -1)
					 {
						 retorno = 0;
					 }
				 break;
			 case 6: if(modificarEdad(mensajeModificarEdad, mensajeErrorModificarEdad, mensajeExitoModificarEdad, &listaCensista[indice], 17, 56) != -1)
			 	 	 {
				 	 	 retorno = 0;
			 	 	 }
				 break;

			 case 7:if(modificarDireccion(mensajeModificarDireccion, mensajeErrorModificarDireccion, mensajeExitoModificarDireccion, &listaCensista[indice])
					 != -1)
			 	 	 {
				 	 	 retorno = 0;
			 	 	 }
				 break;
			 }
		 }
	}


	return retorno;
}


int modificarNombre (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR],	char mensajeExitoModificar [TAM_STR], Censista *censista)
{
	int retorno;
	char nombreModificado[TAM_NOMBRE];

	retorno = -1;


	retorno = pedirNombre(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, nombreModificado);
	if (retorno != -1)
	{
		strcpy(censista->nombre, nombreModificado);
	}

	return retorno;
}


int modificarApellido (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista)
{
	int retorno;
	char apellidoModificado[TAM_NOMBRE];

	retorno = -1;

	retorno = pedirNombre(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar , apellidoModificado);
	if(retorno != -1)
	{
		strcpy(censista->apellido, apellidoModificado);
	}

	return retorno;
}


int modificarDia (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista)
{
	int retorno;
	int diaModificado;

	retorno = -1;

	retorno = pedirInt(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, &diaModificado, 0, 32);
	if(retorno != -1)
	{
		censista->fechaDeNacimiento.dia = diaModificado;
	}

	return retorno;
}

int modificarMes (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista)
{
	int retorno;
	int mesModificado;

	retorno = -1;

	retorno = pedirInt(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, &mesModificado, 0, 13);
	if(retorno != -1)
	{
		censista->fechaDeNacimiento.mes = mesModificado;
	}

	return retorno;
}

int modificarAnio (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista)
{
	int retorno;
	int anioModificado;

	retorno = -1;

	retorno = pedirInt(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, &anioModificado, 1966, 2005);
	if(retorno != -1)
	{
		censista->fechaDeNacimiento.anio = anioModificado;
	}

	return retorno;
}

int modificarEdad (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista,
					int minimo, int maximo)
{
	int retorno;
	int edadModificada;

	retorno = -1;

	retorno = pedirInt(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, &edadModificada, 18, 55);
	if(retorno != -1)
	{
		censista->edad = edadModificada;
	}

	return retorno;
}


int modificarDireccion(char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Censista *censista)
{
	int retorno;
	int direccionModificada;

	retorno = -1;

	retorno = pedirInt(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, &direccionModificada, 1, 100);
	if(retorno != -1)
	{
		censista->direccion = direccionModificada;
	}

	return retorno;
}

/*
 * eDuenio.h
 *
 *  Created on: 3 jul. 2021
 *      Author: maria
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "io_tools.h"

#ifndef EDUENIO_H_
#define EDUENIO_H_

//*** DEFINES
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct{
	int id;
	int idBicicleta;
	char nombre[51];
	char dni[11];
	char telefono[21];
	int isEmpty;
}eDuenio;

/**
 * @fn void hardcodearDuenios(eDuenio*, int)
 * @brief Setea datos predefinidos en la estructura
 *
 * @param listado Array donde escribir
 * @param TAM Tamaño del array
 */
void hardcodearDuenios(eDuenio* listado, int TAM);

/**
 * @fn void eDuenio_Inicializar(eDuenio*, int)
 * @brief Inicializa los indices como disponibles para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 */
void eDuenio_Inicializar(eDuenio* array, int TAM);

/**
 * @fn int eDuenio_ObtenerID(int)
 * @brief Recibe el ID inicial y lo incrementa tras cada entrada de datos
 *
 * @param lastID ID donde leer y escribir
 * @return ID actual
 */
int eDuenio_ObtenerID(int lastID);

/**
 * @fn int eDuenio_ObtenerIndexLibre(eDuenio*, int)
 * @brief Detecta cual es el primer indice disponible para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return El indice libre
 */
int eDuenio_ObtenerIndexLibre(eDuenio* array, int TAM);

/**
 * @fn int eDuenio_BuscarPorID(eDuenio*, int, int)
 * @brief Busca datos de un indice mediante su ID
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return ID Recibe la ID a buscar
 * @return -1 si hubo un error; el indice si la busqueda fue exitosa
 */
int eDuenio_BuscarPorID(eDuenio* array, int TAM, int ID);

/**
 * @fn void eDuenio_MostrarUno(eDuenio)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param listado Array donde leer
 */
void eDuenio_MostrarUno(eDuenio listado);

/**
 * @fn int eDuenio_MostrarTodos(eDuenio*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param array Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eDuenio_MostrarTodos(eDuenio* array, int TAM);

/**
 * @fn int eDuenio_Sort(eDuenio*, int, int)
 * @brief Ordena el array de datos por ascendente y descendente
 *
 * @param array Array que ordenar
 * @param TAM Tamaño del array recibido
 * @param criterio 1 para ascendente, -1 para descendente
 * @return 1 por ordenamiento exitoso, 0 por error
 */
int eDuenio_Sort(eDuenio* arrayS, int TAM, int criterio);

#endif /* EDUENIO_H_ */

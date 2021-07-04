/*
 * servicios.h
 *
 *  Created on: 4 may. 2021
 *      Author: maria
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "io_tools.h"
#ifndef SERVICIOS_H_
#define SERVICIOS_H_

//*** DEFINES
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct{
	int id;
	char descripcion[26];
	int precio;
	int isEmpty;

}eServicio;
//***

/**
 * @fn void hardcodearServicios(eServicio*, int)
 * @brief Setea datos predefinidos en la estructura
 *
 * @param listado Array donde escribir
 * @param TAM Tamaño del array
 */
void hardcodearServicios(eServicio* listado, int TAM);

/**
 * @fn void eServicio_Inicializar(eServicio*, int)
 * @brief Inicializa los indices como disponibles para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 */
void eServicio_Inicializar(eServicio* array, int TAM);

/**
 * @fn int eServicio_ObtenerID(int)
 * @brief Recibe el ID inicial y lo incrementa tras cada entrada de datos
 *
 * @param lastID ID donde leer y escribir
 * @return ID actual
 */
int eServicio_ObtenerID(int lastID);

/**
 * @fn int eServicio_ObtenerIndexLibre(eServicio*, int)
 * @brief Detecta cual es el primer indice disponible para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return El indice libre
 */
int eServicio_ObtenerIndexLibre(eServicio* array, int TAM);

/**
 * @fn int eServicio_BuscarPorID(eServicio*, int, int)
 * @brief Busca datos de un indice mediante su ID
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return ID Recibe la ID a buscar
 * @return -1 si hubo un error; el indice si la busqueda fue exitosa
 */
int eServicio_BuscarPorID(eServicio* array, int TAM, int ID);

/**
 * @fn void eServicio_MostrarUno(eServicio)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param listado Array donde leer
 */
void eServicio_MostrarUno(eServicio listado);

/**
 * @fn int eServicio_MostrarTodos(eServicio*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param array Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eServicio_MostrarTodos(eServicio* array, int TAM);

/**
 * @fn int eServicio_Sort(eServicio*, int, int)
 * @brief Ordena el array de datos por ascendente y descendente
 *
 * @param array Array que ordenar
 * @param TAM Tamaño del array recibido
 * @param criterio 1 para ascendente, -1 para descendente
 * @return 1 por ordenamiento exitoso, 0 por error
 */
int eServicio_Sort(eServicio* arrayS, int TAM, int criterio);
#endif /* SERVICIOS_H_ */

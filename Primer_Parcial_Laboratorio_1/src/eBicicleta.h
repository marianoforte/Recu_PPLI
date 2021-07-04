/*
 * struct3.h
 *
 *  Created on: 11 may. 2021
 *      Author: maria
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "io_tools.h"
#ifndef STRUCT3_H_
#define STRUCT3_H_

//*** DEFINES
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct{
	int id;
	char marca[26];
	int rodado;
	char color[26];
	int isEmpty;

}eBicicleta;

/**
 * @fn void hardcodearStruct(eBicicleta*, int)
 * @brief Setea datos predefinidos en la estructura
 *
 * @param listado Array donde escribir
 * @param TAM Tamaño del array
 */
void hardcodearStruct(eBicicleta* listado, int TAM);

/**
 * @fn void eBicicleta_Inicializar(eBicicleta*, int)
 * @brief Inicializa los indices como disponibles para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 */
void eBicicleta_Inicializar(eBicicleta* array, int TAM);

/**
 * @fn int eBicicleta_ObtenerID(int)
 * @brief Recibe el ID inicial y lo incrementa tras cada entrada de datos
 *
 * @param lastID ID donde leer y escribir
 * @return ID actual
 */
int eBicicleta_ObtenerID(int lastID);

/**
 * @fn int eBicicleta_ObtenerIndexLibre(eBicicleta*, int)
 * @brief Detecta cual es el primer indice disponible para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return El indice libre
 */
int eBicicleta_ObtenerIndexLibre(eBicicleta* array, int TAM);

/**
 * @fn int eBicicleta_BuscarPorID(eBicicleta*, int, int)
 * @brief Busca datos de un indice mediante su ID
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return ID Recibe la ID a buscar
 * @return -1 si hubo un error; el indice si la busqueda fue exitosa
 */
int eBicicleta_BuscarPorID(eBicicleta* array, int TAM, int ID);

/**
 * @fn void eBicicleta_MostrarUno(eBicicleta)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param listado Array donde leer
 */
void eBicicleta_MostrarUno(eBicicleta listado);

/**
 * @fn int eBicicleta_MostrarTodos(eBicicleta*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param array Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eBicicleta_MostrarTodos(eBicicleta* array, int TAM);

#endif /* STRUCT3_H_ */

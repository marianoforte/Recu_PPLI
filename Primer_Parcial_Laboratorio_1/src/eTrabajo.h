#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "io_tools.h"
#include "eDuenio.h"
#ifndef ETRANAJO_H_
#define ETRABAJO_H_

//*** DEFINES
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURAS
typedef struct{
		int dia;
		int mes;
		int anio;
}eFecha;

typedef struct {
	int idTrabajo;
	int idBicicleta;
	int idServicio;
	int idDuenio;
	int isEmpty;
	eFecha fecha;

}eTrabajo;
//***

/** INICIO CABECERAS DE FUNCION*/
/**
 * @fn void hardcodearTrabajos(eTrabajo*, int)
 * @brief Setea datos predefinidos en la estructura
 *
 * @param listado Array donde escribir
 * @param TAM Tamaño del array
 */
void hardcodearTrabajos(eTrabajo* listado, int TAM);

/**
 * @fn void eTrabajo_Inicializar(eTrabajo*, int)
 * @brief Inicializa los indices como disponibles para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 */
void eTrabajo_Inicializar(eTrabajo* array, int TAM);

/**
 * @fn int eTrabajo_ObtenerID(int)
 * @brief Recibe el ID inicial y lo incrementa tras cada entrada de datos
 *
 * @param lastID ID donde leer y escribir
 * @return ID actual
 */
int eTrabajo_ObtenerID(int lastID);

/**
 * @fn int eTrabajo_ObtenerIndexLibre(eTrabajo*, int)
 * @brief Detecta cual es el primer indice disponible para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return El indice libre
 */
int eTrabajo_ObtenerIndexLibre(eTrabajo* array, int TAM);

/**
 * @fn int eTrabajo_BuscarPorID(eTrabajo*, int, int)
 * @brief Busca datos de un indice mediante su ID
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return ID Recibe la ID a buscar
 * @return -1 si hubo un error; el indice si la busqueda fue exitosa
 */
int eTrabajo_BuscarPorID(eTrabajo* array, int TAM, int ID);

/**
 * @fn int eTrabajo_SortByOwnerId(eTrabajo*, int, int, eDuenio*, int)
 * @brief Ordena el array de datos por ascendente y descendente
 *
 * @param arrayT Array que ordenar
 * @param TAM Tamaño del array recibido
 * @param criterio 1 para ascendente, -1 para descendente
 * @param arrayD Array que ordenar
 * @param TAMD Tamaño del array recibido
 * @return 1 por ordenamiento exitoso, 0 por error
 */
int eTrabajo_SortByOwnerId(eTrabajo* arrayT, int TAM, int criterio, eDuenio* arrayD, int TAMD);


/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR


/** FIN CABECERAS DE FUNCION*/
#endif

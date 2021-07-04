/*
 * structRelations.h
 *
 *  Created on: 11 may. 2021
 *      Author: maria
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "eTrabajo.h"
#include "servicios.h"
#include "eBicicleta.h"
#include "eDuenio.h"
#ifndef STRUCTRELATIONS_H_
#define STRUCTRELATIONS_H_

/**
 * @fn int eTrabajo_Alta(eTrabajo*, int, eBicicleta*, int, eServicio*, int, eDuenio*, int, int)
 * @brief Da la alta de un trabajo
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @param lastId Ultima ID en el sistema
 * @return 0 si fue exitoso, 1 si falló
 */
int eTrabajo_Alta(eTrabajo* array, int TAM, eBicicleta* arrayB, int TAMB, eServicio* arrayS, int TAMS, eDuenio* arrayD, int TAMD, int lastID);

/**
 * @fn eTrabajo eTrabajo_CargarDatos(eServicio*, int, eBicicleta*, int, eDuenio*, int)
 * @brief Solicita los datos a agregar en el sistema
 *
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @return El trabajo a dar de alta
 */
eTrabajo eTrabajo_CargarDatos(eServicio* arrayS, int TAMS, eBicicleta* ArrayB, int TAMB, eDuenio* arrayD, int TAMD);

/**
 * @fn int eTrabajo_Modificacion(eTrabajo*, int, eBicicleta*, int, eServicio*, int, eDuenio*, int)
 * @brief Modifica un trabajo
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eTrabajo_Modificacion(eTrabajo* array, int TAM, eBicicleta* bicicleta, int TAMB, eServicio* arrayS, int TAMS, eDuenio* arrayD, int TAMD);

/**
 * @fn eTrabajo eTrabajo_CargarDatos(eTrabajo, eServicio*, int, eBicicleta*, int, eDuenio*, int)
 * @brief Solicita los datos a agregar en el sistema
 *
 * @param trabajo Trabajo al que modificar
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @return El trabajo a modificar
 */
eTrabajo eTrabajo_ModificarUno(eTrabajo trabajo, eServicio* arrayS, int TAMS, eBicicleta* arrayB, int TAMB, eDuenio* arrayD, int TAMD);

/**
 * @fn int eTrabajo_Baja(eTrabajo*, int, eBicicleta*, int, eServicio*, int, eDuenio*, int)
 * @brief Da la baja de un trabajo
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eTrabajo_Baja(eTrabajo* array, int TAM, eBicicleta* bicicleta, int TAMB, eServicio* servicio, int TAMS, eDuenio* arrayD, int TAMD);

/**
 * @fn int indicarMaximoServicios(int*, int)
 * @brief Busca el maximo de los servicios
 *
 * @param array Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int indicarMaximoServicios(int* array, int TAM);

/**
 * @fn int eServicio_ContarServiciosConMasTrabajos(eTrabajo*, int, eServicio*, int)
 * @brief Cuenta los servicios que tienen mas trabajos a realizar
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eServicio_ContarServiciosConMasTrabajos(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS);

/**
 * @fn int eTrabajo_MostrarGananciaTotal(eTrabajo*, int, eServicio*, int)
 * @brief Muestra las ganancias totales de todos los trabajos
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eTrabajo_MostrarGananciaTotal(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS);

/**
 * @fn void eTrabajo_MostrarUno(eTrabajo, eBicicleta, eServicio, eDuenio)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param trabajo Array donde leer
 * @param bicicleta Array donde leer
 * @param servicio Array donde leer
 * @param duenio Array donde leer
 */
void eTrabajo_MostrarUno(eTrabajo trabajo, eBicicleta bicicleta, eServicio servicio, eDuenio duenio);

/**
 * @fn int eTrabajo_MostrarTodos(eTrabajo*, int, eBicicleta*, int, eServicio*, int, eDuenio*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eTrabajo_MostrarTodos(eTrabajo* arrayT, int TAM, eBicicleta* arrayB, int TAMB, eServicio* arrayS, int TAMS, eDuenio* arrayD, int TAMD);

/**
 * @fn void eServicio_MostrarUnoConbicicleta(eServicio, eBicicleta)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param listado Array donde leer
 * @param listadoB Array donde leer
 */
void eServicio_MostrarUnoConBicicleta(eServicio arrayS, eBicicleta arrayB, eDuenio arrayD);

/**
 * @fn int eServicio_MostrarTodosConBicicleta(eTrabajo*, int, eServicio*, int, eBicicleta*, int, eDuenio*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eServicio_MostrarTodosConBicicleta(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS, eBicicleta* arrayB, int TAMB, eDuenio* arrayD, int TAMD);

/**
 * @fn int eTrabajo_CantidadBicicletasRojo(eTrabajo*, int, eBicicleta*, int)
 * @brief Cuenta la cantidad de bicicletas rojas que hay en el sistema
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eTrabajo_CantidadBicicletasRojo(eTrabajo* arrayT, int TAMT, eBicicleta* arrayB, int TAMB);

/**
 * @fn int eTrabajo_MostrarCantidadBicicletasRojas(eTrabajo*, int, eBicicleta*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
void eTrabajo_MostrarCantidadBicicletasRojas(eTrabajo* arrayT, int TAMT, eBicicleta* arrayB, int TAMB);

/**
 * @fn void eDuenio_MostrarUnCargoPorDuenio(eDuenio, eServicio)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param arrayD Array donde leer
 * @param arrayS Array donde leer
 */
void eDuenio_MostrarUnCargoPorDuenio(eDuenio arrayD, eServicio arrayS);

/**
 * @fn int eDuenio_MostrarCargoPorDuenio(eTrabajo*, int, eServicio*, int, eDuenio*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayS Array donde lee los datos
 * @param TAMS Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eDuenio_MostrarCargoPorDuenio(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS, eDuenio* arrayD, int TAMD);

/**
 * @fn void eDuenio_MostrarUnCargoPorDuenio(eDuenio, eBicicleta)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param arrayD Array donde leer
 * @param arrayB Array donde leer
 */
void eDuenio_MostrarUnaBicicletaPorDuenio(eDuenio arrayD, eBicicleta arrayB);

/**
 * @fn int eDuenio_MostrarBicicletasPorDuenio(eTrabajo*, int, eBicicleta*, int, eDuenio*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param arrayT Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param arrayB Array donde lee los datos
 * @param TAMB Tamaño del array recibido
 * @param arrayD Array donde lee los datos
 * @param TAMD Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int eDuenio_MostrarBicicletasPorDuenio(eTrabajo* arrayT, int TAMT, eBicicleta* arrayB, int TAMB, eDuenio* arrayD, int TAMD);

/** SORT **/

/**
 * @fn int eTrabajo_SortByYearAndBrand(eTrabajo*, int, int, eBicicleta*, int)
 * @brief Ordena el array de datos por ascendente y descendente
 *
 * @param arrayT Array que ordenar
 * @param TAM Tamaño del array recibido
 * @param criterio 1 para ascendente, -1 para descendente
 * @param arrayB Array que ordenar
 * @param TAMB Tamaño del array recibido
 * @return 1 por ordenamiento exitoso, 0 por error
 */
int eTrabajo_SortByYearAndBrand(eTrabajo* arrayT, int TAM, int criterio, eBicicleta* arrayB, int TAMB);

/**
 * @fn int eTrabajo_SortByBrand(eTrabajo*, int, int, eBicicleta*, int)
 * @brief Ordena el array de datos por ascendente y descendente
 *
 * @param array Array que ordenar
 * @param TAM Tamaño del array recibido
 * @param criterio 1 para ascendente, -1 para descendente
 * @param arrayB Array que ordenar
 * @param TAMB Tamaño del array recibido
 * @return 1 por ordenamiento exitoso, 0 por error
 */
int eTrabajo_SortByBrand(eTrabajo* arrayT, int TAM, int criterio, eBicicleta* arrayB, int TAMB);

/** CALCULOS **/

/**
 * @fn int eTrabajo_CalcularGananciaTotal(eTrabajo*, int, eServicio*, int)
 * @brief Calcula las ganacias totales
 *
 * @param array Array que ordenar
 * @param TAM Tamaño del array recibido
 * @param arrayS Array que ordenar
 * @param TAMB Tamaño del array recibido
 * @return 1 por ordenamiento exitoso, 0 por error
 */
int eTrabajo_CalcularGananciaTotal(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS);




#endif /* STRUCTRELATIONS_H_ */

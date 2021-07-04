/*
 * servicios.c
 *
 *  Created on: 4 may. 2021
 *      Author: maria
 */


#include "servicios.h"

void hardcodearServicios(eServicio* listado, int TAM){
	int id[4] = {20000, 20001, 20002, 20003};
	char descripcion[4][26] = {"Limpieza", "Parche", "Centrado", "Cadena"};
	int precio[4] = {250, 300, 400, 350};
	int isEmpty[4] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(int i=0;i<TAM;i++){
		listado[i].id=id[i];
		strcpy(listado[i].descripcion, descripcion[i]);
		listado[i].precio=precio[i];
		listado[i].isEmpty=isEmpty[i];
	}
}

void eServicio_Inicializar(eServicio* array, int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eServicio_ObtenerID(int lastID) {
	//INCREMENTA PARAMETRO RECIBIDO CADA VEZ QUE SE LLAMA ESTA FUNCION
	return lastID += 1;
}

int eServicio_ObtenerIndexLibre(eServicio* array, int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eServicio_BuscarPorID(eServicio* array, int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].id == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eServicio_MostrarUno(eServicio listado){
	//PRINTF DE UN SOLO SERVICIO
	printf("%5d %14s %9d\n", listado.id, listado.descripcion, listado.precio);
}

int eServicio_MostrarTodos(eServicio* array, int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO SERVICIOS");
	printf("  ID     DESCRIPCION    PRECIO\n\n"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Trabajo
				eServicio_MostrarUno(array[i]);
				//CONTADOR DE Trabajo
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO SERVICIOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad == 0) {
		puts("\n\t> NO HAY SERVICIOS PARA MOSTRAR");
		rtn = 1;
	}

	return rtn;
}

int eServicio_Sort(eServicio* arrayS, int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eServicio aux;

	/** EJEMPLO DE SORT CON ID DE TRABAJO
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (arrayS != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayS[i].isEmpty == OCUPADO
							&& arrayS[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (arrayS[i].id > arrayS[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = arrayS[i];
							arrayS[i] = arrayS[j];
							arrayS[j] = aux;
						}
						if((arrayS[i].id > arrayS[j].id) && (arrayS[i].descripcion > arrayS[j].descripcion)){
							aux = arrayS[i];
							arrayS[i] = arrayS[j];
							arrayS[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayS[i].isEmpty == OCUPADO
							&& arrayS[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (arrayS[i].id < arrayS[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = arrayS[i];
							arrayS[i] = arrayS[j];
							arrayS[j] = aux;
						}
						if((arrayS[i].id < arrayS[j].id) && (arrayS[i].descripcion < arrayS[j].descripcion)){
						aux = arrayS[i];
						arrayS[i] = arrayS[j];
						arrayS[j] = aux;
					}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			puts("\nCRITERIO DE ORDENAMIENTO MAL INGRESADO");
			rtn = 0;
			break;
		}
	}
	return rtn;
}

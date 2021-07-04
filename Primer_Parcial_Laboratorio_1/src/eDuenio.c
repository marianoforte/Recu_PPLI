/*
 * eDuenio.c
 *
 *  Created on: 3 jul. 2021
 *      Author: maria
 */
#include "eDuenio.h"

void hardcodearDuenios(eDuenio* listado, int TAM){
	int id[5] = {1, 2, 3, 4, 5};
	int idBicicleta[5] = {27, 26, 29, 25, 28};
	char nombre[5][51] = {"Julian Lopez", "Lucia Schneider", "Marcos Diaz", "Paula Lucio", "Martina Ripanti"};
	char dni[5][11] = {"32738094", "24837021", "28146269", "34094325", "18554987"};
	char telefono[5][21] = {"1587624367", "1524187646", "1564832267", "1522758435", "1515760643"};
	int isEmpty[5] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(int i=0;i<TAM;i++){
		listado[i].id = id[i];
		listado[i].idBicicleta = idBicicleta[i];
		strcpy(listado[i].nombre, nombre[i]);
		strcpy(listado[i].dni, dni[i]);
		strcpy(listado[i].telefono, telefono[i]);
		listado[i].isEmpty=isEmpty[i];
	}
}

void eDuenio_Inicializar(eDuenio* array, int TAM) {
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

int eDuenio_ObtenerID(int lastID) {
	//INCREMENTA PARAMETRO RECIBIDO CADA VEZ QUE SE LLAMA ESTA FUNCION
	return lastID += 1;
}

int eDuenio_ObtenerIndexLibre(eDuenio* array, int TAM) {
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

int eDuenio_BuscarPorID(eDuenio* array, int TAM, int ID) {
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

void eDuenio_MostrarUno(eDuenio listado){
	//PRINTF DE UN SOLO DUENIO
	printf("%d %22s %13s %13s\n", listado.id, listado.nombre, listado.dni, listado.telefono);
}

int eDuenio_MostrarTodos(eDuenio* array, int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO SERVICIOS");
	printf("ID             NOMBRE            DNI       TELEFONO\n\n"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		eDuenio_Sort(array, TAM, -1);
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO DUENIO
				eDuenio_MostrarUno(array[i]);
				//CONTADOR DE DUENIOS
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

int eDuenio_Sort(eDuenio* array, int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eDuenio aux;

	/** EJEMPLO DE SORT CON ID DE DUENIO
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].id > array[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
						if(array[i].id > array[j].id){
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
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
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].id < array[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
						if(array[i].id < array[j].id){
						aux = array[i];
						array[i] = array[j];
						array[j] = aux;
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

/*
 * struct3.c
 *
 *  Created on: 11 may. 2021
 *      Author: maria
 */

#include "eBicicleta.h"

void hardcodearStruct(eBicicleta* listado, int TAM){
	int id[5] = {25, 26, 27, 28, 29};
	char marca[5][26] = {"Aurora", "Vairo", "Venzo", "Raleigh", "Olmo"};
	int rodado[5] = {20, 16, 22, 18, 20};
	char color[5][26] = {"Rojo", "Azul", "Negro", "Amarillo", "Verde"};
	int isEmpty[5] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(int i=0;i<TAM;i++){
		listado[i].id=id[i];
		strcpy(listado[i].marca, marca[i]);
		listado[i].rodado=rodado[i];
		strcpy(listado[i].color, color[i]);
		listado[i].isEmpty=isEmpty[i];
	}
}

void eBicicleta_Inicializar(eBicicleta* array, int TAM) {
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

int eBicicleta_ObtenerIndexLibre(eBicicleta* array, int TAM) {
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

int eBicicleta_ObtenerID(int lastID) {
	//INCREMENTA PARAMETRO RECIBIDO CADA VEZ QUE SE LLAMA ESTA FUNCION
	return lastID += 1;
}

int eBicicleta_BuscarPorID(eBicicleta* array, int TAM, int ID){
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			//printf("id bicicleta: %d\n", array[i].id);
			if (array[i].isEmpty == OCUPADO && array[i].id == ID) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eBicicleta_MostrarUno(eBicicleta listado){
	//PRINTF DE UN SOLO SERVICIO
	printf("%1d %11s %7d\n", listado.id, listado.marca, listado.rodado);
}

int eBicicleta_MostrarTodos(eBicicleta* array, int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO SERVICIOS");
	printf("ID       MARCA    RODADO\n\n"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Trabajo
				eBicicleta_MostrarUno(array[i]);
				//CONTADOR DE Trabajo
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO BICICLETAS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad == 0) {
		puts("\n\t> NO HAY BICICLETAS PARA MOSTRAR");
		rtn = 1;
	}

	return rtn;
}

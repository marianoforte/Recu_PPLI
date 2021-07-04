#include "eTrabajo.h"


void hardcodearTrabajos(eTrabajo* listado, int TAM){
	int idTrabajo[5] = {1, 2, 3, 4, 5};
	int idBicicleta[5] = {25, 26, 27, 28, 29};
	int idServicio[5] = {20001, 20003, 20000, 20002, 20001};
	int idDuenio[5] = {4, 2, 1, 5, 3};
	int fechaDia[5] = {3, 21, 14, 27, 6};
	int fechaMes[5] = {5, 10, 1, 6, 8};
	int fechaAnio[5]={2020, 2021, 2019, 2020, 2021};
	int isEmpty[5] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(int i=0;i<TAM;i++){
		listado[i].idTrabajo=idTrabajo[i];
		listado[i].idBicicleta=idBicicleta[i];
		listado[i].idServicio=idServicio[i];
		listado[i].idDuenio=idDuenio[i];
		listado[i].fecha.dia=fechaDia[i];
		listado[i].fecha.mes=fechaMes[i];
		listado[i].fecha.anio=fechaAnio[i];
		listado[i].isEmpty=isEmpty[i];
	}
}

void eTrabajo_Inicializar(eTrabajo* array, int TAM) {
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

int eTrabajo_ObtenerID(int lastID) {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return lastID += 1;
}

int eTrabajo_ObtenerIndexLibre(eTrabajo* array, int TAM) {
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

int eTrabajo_BuscarPorID(eTrabajo* array, int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idTrabajo == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eTrabajo_SortByOwnerId(eTrabajo* arrayT, int TAM, int criterio, eDuenio* arrayD, int TAMD){
	int rtn = 0;
	int i;
	int j;
	eTrabajo aux;

	/** EJEMPLO DE SORT CON ID DE TRABAJO
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (arrayT != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM-1; i++){
				for (j=i+1; j < TAM; j++){
					//printf("Indice A: %d\n", indexBicicletaA);
					//printf("Indice B: %d\n", indexBicicletaB);
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayT[i].isEmpty == OCUPADO && arrayT[j].isEmpty == OCUPADO){
						//CRITERIO DE ORDENAMIENTO
					if (arrayT[i].idDuenio > arrayT[j].idDuenio) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = arrayT[i];
							arrayT[i] = arrayT[j];
							arrayT[j] = aux;
						}
					}
				}
			}

			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = 0 + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayT[i].isEmpty == OCUPADO
							&& arrayT[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (arrayT[i].idDuenio < arrayT[j].idDuenio) {
						aux = arrayT[i];
						arrayT[i] = arrayT[j];
						arrayT[j] = aux;
					}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}




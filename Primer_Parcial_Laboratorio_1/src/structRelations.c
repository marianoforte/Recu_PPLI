/*
 * structRelations.c
 *
 *  Created on: 11 may. 2021
 *      Author: maria
 */
#include "structRelations.h"

#define TAM_SERVICIOS 4

int eTrabajo_Alta(eTrabajo* array, int TAM, eBicicleta* arrayB, int TAMB, eServicio* arrayS, int TAMS, eDuenio* arrayD, int TAMD, int lastID){
	int rtn = 0;
	int confirmacion = 0;
	eTrabajo auxTrabajo;

	//BUSCO ESPACIO EN ARRAY
	int index = eTrabajo_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO TRABAJO AUXILIAR
		auxTrabajo = eTrabajo_CargarDatos(arrayS,TAMS, arrayB, TAMB, arrayD, TAMD);
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxTrabajo.idTrabajo = lastID;
		//CAMBIO SU ESTADO A "OCUPADO"
		auxTrabajo.isEmpty = OCUPADO;

		printf("\nESTA SEGURO QUE DESEA DAR DE ALTA ESTE TRABAJO? (1. SI / 2. NO): ");
		getAndValidateIntAndFloatNumber("%d", &confirmacion);
		while(confirmacion != 1 && confirmacion != 2){
			puts("OPCION INCORRECTA.");
			printf("\nESTA SEGURO QUE DESEA DAR DE ALTA ESTE TRABAJO? (1. SI / 2. NO)");
			getAndValidateIntAndFloatNumber("%d", &confirmacion);
		}
		if(confirmacion == 1){
			//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
			array[index] = auxTrabajo;
			//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
			rtn = 1;
		}
	}

	return rtn;
}

eTrabajo eTrabajo_CargarDatos(eServicio* arrayS, int TAMS, eBicicleta* arrayB, int TAMB, eDuenio* arrayD, int TAMD) {
	eTrabajo auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/

	fflush(stdin);
	printf("\nSeleccione el ID de la bicicleta a ingresar");
	eBicicleta_MostrarTodos(arrayB, TAMB);
	printf("\n Bicicleta elegida: ");
	getAndValidateIntAndFloatNumber("%d",&auxiliar.idBicicleta);
	while(eBicicleta_BuscarPorID(arrayB, TAMS, auxiliar.idBicicleta) == -1){
		printf("\nEl ID de la bicicleta no coincide con el registro. Ingrese nuevamente el ID del servicio: ");
		getAndValidateIntAndFloatNumber("%d",&auxiliar.idBicicleta);
	}

	fflush(stdin);
	printf("\nElija un servicio a realizar");
	eServicio_MostrarTodos(arrayS, TAMS);
	printf("\nServicio a realizar (ID): ");
	getAndValidateIntAndFloatNumber("%d",&auxiliar.idServicio);
	while(eServicio_BuscarPorID(arrayS, TAMS, auxiliar.idServicio) == -1){
		printf("\nEl ID del servicio no coincide con el registro. Ingrese nuevamente el ID del servicio: ");
		getAndValidateIntAndFloatNumber("%d",&auxiliar.idServicio);
	}

	fflush(stdin);
	printf("\nElija el duenio de la bicicleta");
	eDuenio_MostrarTodos(arrayD, TAMD);
	printf("\nDuenio de la bicicleta (ID): ");
	getAndValidateIntAndFloatNumber("%d",&auxiliar.idDuenio);
	while(eDuenio_BuscarPorID(arrayD, TAMD, auxiliar.idDuenio) == -1){
		printf("\nEl ID del duenio no coincide con el registro. Ingrese nuevamente el ID del duenio: ");
		getAndValidateIntAndFloatNumber("%d",&auxiliar.idDuenio);
	}

	fflush(stdin);
	printf("\nIngrese la fecha (DD/MM/AAAA) ");
	printf("\nIngrese el dia: ");
	getAndValidateIntAndFloatNumber("%d",&auxiliar.fecha.dia);
	while(auxiliar.fecha.dia < 1){
			printf("\nEl dia debe ser un numero mayor a cero. Ingrese nuevamente el dia: ");
			getAndValidateIntAndFloatNumber("%d",&auxiliar.fecha.dia);
		}
	printf("\nIngrese el mes: ");
	getAndValidateIntAndFloatNumber("%d",&auxiliar.fecha.mes);
	while(auxiliar.fecha.mes < 1){
				printf("\nEl mes debe ser un numero mayor a cero. Ingrese nuevamente el mes: ");
				getAndValidateIntAndFloatNumber("%d",&auxiliar.fecha.mes);
			}
	printf("\nIngrese el anio: ");
		getAndValidateIntAndFloatNumber("%d",&auxiliar.fecha.anio);
	while(auxiliar.fecha.anio < 1){
		printf("\nEl anio debe ser un numero mayor a cero. Ingrese nuevamente el anio: ");
		getAndValidateIntAndFloatNumber("%d",&auxiliar.fecha.anio);
	}

	return auxiliar;
}

int eTrabajo_Modificacion(eTrabajo* array, int TAM, eBicicleta* bicicleta, int TAMB, eServicio* arrayS, int TAMS, eDuenio* arrayD, int TAMD) {
	int rtn = 0;
	int idTrabajo;
	int index;
	int flag = 0;
	int confirmacion = 0;
	eTrabajo auxiliar;

	//LISTO TODOS LOS TRABAJOS
	if (eTrabajo_MostrarTodos(array, TAM, bicicleta, TAMB, arrayS, TAMS, arrayD, TAMD)){
		//BANDERA EN 1 SI HAY TRABAJOS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY TRABAJOS PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		printf("INGRESE ID A MODIFICAR: ");
		getAndValidateIntAndFloatNumber("%d", &idTrabajo);

		//BUSCO INDEX POR ID EN ARRAY
		while (eTrabajo_BuscarPorID(array, TAM, idTrabajo) == -1) {
			puts("NO EXISTE ID.");

			printf("INGRESE ID A MODIFICAR: ");
			getAndValidateIntAndFloatNumber("%d", &idTrabajo);
		}

		//OBTENGO INDEX DEL ARRAY DE TRABAJO A MODIFICAR
		index = eTrabajo_BuscarPorID(array, TAM, idTrabajo);

		//LLAMO A FUNCION QUE MODIFICA Trabajo
		auxiliar = eTrabajo_ModificarUno(array[index], arrayS, TAMS, bicicleta, TAMB, arrayD, TAMD);

		printf("ESTA SEGURO QUE DESEA MODIFICAR ESTE TRABAJO? (1. SI / 2. NO): ");
		getAndValidateIntAndFloatNumber("%d", &confirmacion);
		while(confirmacion != 1 && confirmacion != 2){
			puts("OPCION INCORRECTA.");
			printf("\nESTA SEGURO QUE DESEA MODIFICAR ESTE TRABAJO? (1. SI / 2. NO): ");
			getAndValidateIntAndFloatNumber("%d", &confirmacion);
		}
		if(confirmacion == 1){
			//MODIFICACION ACEPTADA - ASIGNO CAMBIOS AL ARRAY EN EL INDICE INDICADO ANTERIORMENTE
			array[index] = auxiliar;
			//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
					rtn = 1;
		}
	}

	return rtn;
}

eTrabajo eTrabajo_ModificarUno(eTrabajo trabajo, eServicio* arrayS, int TAMS, eBicicleta* arrayB, int TAMB, eDuenio* arrayD, int TAMD){
	eTrabajo auxiliar = trabajo;
	int opcion;
	printf("Elija que desea modificar (1- Marca de bicicleta, 2- Servicio, 3- Duenio): ");
	getAndValidateIntAndFloatNumber("%d",&opcion);
	switch(opcion){
		case 1:
			fflush(stdin);
			printf("\nSeleccione el ID de la bicicleta a ingresar");
			eBicicleta_MostrarTodos(arrayB, TAMB);
			printf("\n Bicicleta elegida: ");
			getAndValidateIntAndFloatNumber("%d",&auxiliar.idBicicleta);
			while(eBicicleta_BuscarPorID(arrayB, TAMS, auxiliar.idBicicleta) == -1){
				printf("\nEl ID de la bicicleta no coincide con el registro. Ingrese nuevamente el servicio: ");
				getAndValidateIntAndFloatNumber("%d",&auxiliar.idBicicleta);
			}
			break;
		case 2:
			fflush(stdin);
			printf("\nElija un servicio a realizar");
			eServicio_MostrarTodos(arrayS, TAMS);
			printf("\nServicio a realizar (ID): ");
			getAndValidateIntAndFloatNumber("%d",&auxiliar.idServicio);
			while(eServicio_BuscarPorID(arrayS, TAMS, auxiliar.idServicio) == -1){
				printf("\nEl ID del servicio no coincide con el registro. Ingrese nuevamente el servicio: ");
				getAndValidateIntAndFloatNumber("%d",&auxiliar.idServicio);
			}
			break;
		case 3:
			fflush(stdin);
			printf("\nElija el duenio de la bicicleta");
			eDuenio_MostrarTodos(arrayD, TAMD);
			printf("\nDuenio de la bicicleta (ID): ");
			getAndValidateIntAndFloatNumber("%d",&auxiliar.idDuenio);
			while(eDuenio_BuscarPorID(arrayD, TAMD, auxiliar.idDuenio) == -1){
				printf("\nEl ID del duenio no coincide con el registro. Ingrese nuevamente el ID del duenio: ");
				getAndValidateIntAndFloatNumber("%d",&auxiliar.idDuenio);
			}
			break;
		default:
			printf("Opcion incorrecta");
			break;

	}
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eTrabajo_Baja(eTrabajo* array, int TAM, eBicicleta* bicicleta, int TAMB, eServicio* servicio, int TAMS, eDuenio* arrayD, int TAMD) {
	int rtn = 0;
	int idTrabajo;
	int index;
	int flag = 0;
	int confirmacion = 0;

	//LISTO TODOS LOS TRABAJOS
	if (eTrabajo_MostrarTodos(array, TAM, bicicleta, TAMB, servicio, TAMS, arrayD, TAMD)) {
		//BANDERA EN 1 SI HAY TRABAJOS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY TRABAJO PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		printf("INGRESE ID A DAR DE BAJA: ");
		getAndValidateIntAndFloatNumber("%d", &idTrabajo);

		//BUSCO INDEX POR ID EN ARRAY
		while (eTrabajo_BuscarPorID(array, TAM, idTrabajo) == -1) {
			puts("NO EXISTE ID.");
			printf("INGRESE ID A DAR DE BAJA: ");
			getAndValidateIntAndFloatNumber("%d", &idTrabajo);
		}

		//OBTENGO INDEX DEL ARRAY DE TRABAJO A DAR DE BAJA
		index = eTrabajo_BuscarPorID(array, TAM, idTrabajo);

		printf("\nESTA SEGURO QUE DESEA DAR DE BAJA ESTE TRABAJO? (1. SI / 2. NO): ");
		getAndValidateIntAndFloatNumber("%d", &confirmacion);
		while(confirmacion != 1 && confirmacion != 2){
			puts("OPCION INCORRECTA.");
			printf("\nESTA SEGURO QUE DESEA DAR DE BAJA ESTE TRABAJO? (1. SI / 2. NO)");
			getAndValidateIntAndFloatNumber("%d", &confirmacion);
		}
		if(confirmacion == 1){
			//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
			array[index].isEmpty = BAJA;
			//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			rtn = 1;
		}
	}

	return rtn;
}

int eTrabajo_CalcularGananciaTotal(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS){
	int i, j;
	int sumaTotal = 0;
	int cantidad = 0;

	if ((arrayS != NULL && TAMS > 0) && (arrayT != NULL && TAMT > 0)) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAMS; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (arrayS[i].isEmpty == OCUPADO) {
				for(j = 0; j < TAMT; j++){
					if ((arrayT[j].isEmpty == OCUPADO) && (arrayS[i].id == arrayT[j].idServicio)){
							sumaTotal += arrayS[i].precio;
							//CONTADOR DE TRABAJOS
							cantidad++;
					}
				}
			}
		}
	}
	if (cantidad == 0) {
		puts("\n\t> NO HAY PRECIO TOTAL DE SERVICIOS REALIZADOS PARA MOSTRAR");
		sumaTotal = -1;
	}

	return sumaTotal;
}

int eTrabajo_MostrarGananciaTotal(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS) {
	int rtn = 0;
	int totalPrecio;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if ((arrayS != NULL && TAMS > 0) && (arrayT != NULL && TAMT > 0)) {
		//PREGUNTO POR SU ESTADO "OCUPADO"
		totalPrecio = eTrabajo_CalcularGananciaTotal(arrayT, TAMT, arrayS, TAMS);
		if(totalPrecio != -1){
			printf("\nEL PRECIO TOTAL DE LOS SERVICIOS REALIZADOS ES: %d\n", totalPrecio);
			rtn = 1;
		}
	}

	return rtn;
}

void eTrabajo_MostrarUno(eTrabajo trabajo, eBicicleta bicicleta, eServicio servicio, eDuenio duenio) {
	//PRINTF DE UN SOLO Trabajo
	printf("%d %10s %10d %10s %7d/%d/%d %20s %13s %13s\n", trabajo.idTrabajo, bicicleta.marca, bicicleta.rodado, servicio.descripcion, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio, duenio.nombre, duenio.dni, duenio.telefono);
}

int eTrabajo_MostrarTodos(eTrabajo* arrayT, int TAM, eBicicleta* arrayB, int TAMB, eServicio* arrayS, int TAMS, eDuenio* arrayD, int TAMD) {
	int i, indiceServicio, indiceBicicleta, indiceDuenio;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO TRABAJO");
	printf("ID     MARCA     RODADO   SERVICIO        FECHA             NOMBRE            DNI        TELEFONO\n\n"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (arrayT != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			indiceServicio = eServicio_BuscarPorID(arrayS, TAMS, arrayT[i].idServicio);
			indiceBicicleta = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[i].idBicicleta);
			indiceDuenio = eDuenio_BuscarPorID(arrayD, TAMD, arrayT[i].idDuenio);
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (arrayT[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO TRABAJO
				eTrabajo_MostrarUno(arrayT[i], arrayB[indiceBicicleta], arrayS[indiceServicio], arrayD[indiceDuenio]);
				//CONTADOR DE TRABAJO
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO TRABAJOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad == 0) {
		puts("\n\t> NO HAY TRABAJOS PARA MOSTRAR");
		rtn = 1;
	}

	return rtn;
}

void eServicio_MostrarUnoConBicicleta(eServicio arrayS, eBicicleta arrayB, eDuenio arrayD){
	printf("%-8d %-16s %-15d | %-10d %-14s %-10d %-15s | %-5d %-28s\n", arrayS.id, arrayS.descripcion, arrayS.precio, arrayB.id, arrayB.marca, arrayB.rodado, arrayB.color, arrayD.id, arrayD.nombre);
}
int eServicio_MostrarTodosConBicicleta(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS, eBicicleta* arrayB, int TAMB, eDuenio* arrayD, int TAMD){
	int rtn = -1;
	int i, indiceServicio, indiceBicicleta, indiceDuenio;
	int exists = 0;

	printf("\nID       DESCRIPCION      PRECIO      	    ID         MARCA        RODADO       COLOR             ID       NOMBRE\n");

	if(arrayT != NULL && TAMT > 0){
		for(i = 0; i < TAMT; i++){
			indiceServicio = eServicio_BuscarPorID(arrayS, TAMS, arrayT[i].idServicio);
			indiceBicicleta = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[i].idBicicleta);
			indiceDuenio = eDuenio_BuscarPorID(arrayD, TAMD, arrayT[i].idDuenio);
			if(indiceServicio != -1 && indiceBicicleta != -1){
				eServicio_MostrarUnoConBicicleta(arrayS[indiceServicio], arrayB[indiceBicicleta], arrayD[indiceDuenio]);
				exists = 1;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO TRABAJOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (exists == 0){
		puts("\n\t> NO HAY TRABAJOS PARA MOSTRAR");
		rtn = 1;
	}

	return rtn;
}

int eTrabajo_CantidadBicicletasRojo(eTrabajo* arrayT, int TAMT, eBicicleta* arrayB, int TAMB){
	int i, indiceBicicleta;
	int rtn = -1;
	int contador = 0;

	for(i = 0; i < TAMT; i++){
		indiceBicicleta = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[i].idBicicleta);
		if(strcmp(arrayB[indiceBicicleta].color, "Rojo") == 0){
			contador++;
		}
	}
	if(contador != 0){
		rtn = contador;
	}


	return rtn;
}

void eTrabajo_MostrarCantidadBicicletasRojas(eTrabajo* arrayT, int TAMT, eBicicleta* arrayB, int TAMB){
	int cantidad = -1;

	cantidad = eTrabajo_CantidadBicicletasRojo(arrayT, TAMT, arrayB, TAMB);

	if(cantidad != -1){
		printf("\nCANTIDAD DE BICICLETAS ROJAS QUE REALIZARON UN SERVICIO: %d\n", cantidad);
	}
	else{
		puts("\nNO HAY BICICLETAS PARA MOSTRAR");
	}
}

int getPrecioTotal(eTrabajo* trabajo, int TAMT, eDuenio* duenio, int TAMD, eServicio* servicio, int TAMS){

	int indiceServicioA, indiceServicioB, i, j, precioA, precioB;
	int contadorRecurrencias = 0;
	int precioTotal = 0;
	for(i = 0; i < TAMT; i++){
		indiceServicioA = eServicio_BuscarPorID(servicio, TAMS, trabajo[i].idServicio);
		//indiceDuenio = eDuenio_BuscarPorID(duenio, TAMD, trabajo[i].idDuenio);
		for(j=i+1; j<TAMS; j++){
			indiceServicioB = eServicio_BuscarPorID(servicio, TAMS, trabajo[j].idServicio);
			if((indiceServicioA != -1 && indiceServicioB != -1) && (trabajo[i].idDuenio == trabajo[j].idDuenio)){
				contadorRecurrencias++;
				if(contadorRecurrencias > 1){
					precioA = servicio[indiceServicioA].precio;
					precioB = servicio[indiceServicioB].precio;
					precioTotal = precioA+precioB;
				}
			}
		}
	}
	return precioTotal;
}

void eDuenio_MostrarUnCargoPorDuenio(eDuenio arrayD, eServicio arrayS){
	printf("%-6d %-20s %-15s %-15s %-9d %-10s\n", arrayD.id, arrayD.nombre, arrayD.dni, arrayD.telefono, arrayS.precio, arrayS.descripcion);
}

int eDuenio_MostrarCargoPorDuenio(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS, eDuenio* arrayD, int TAMD){
	int rtn = -1;
	int i, indiceServicio, indiceDuenio;
	int exists = 0;

	printf("\nID         NOMBRE             DNI            TELEFONO      COSTO      SERVICIO\n");

	if(arrayT != NULL && TAMT > 0){
		eTrabajo_SortByOwnerId(arrayT, TAMT, -1, arrayD, TAMD);
		for(i = 0; i < TAMT; i++){
			indiceServicio = eServicio_BuscarPorID(arrayS, TAMS, arrayT[i].idServicio);
			indiceDuenio = eDuenio_BuscarPorID(arrayD, TAMD, arrayT[i].idDuenio);
			if(indiceServicio != -1 && indiceDuenio != -1){
				eDuenio_MostrarUnCargoPorDuenio(arrayD[indiceDuenio], arrayS[indiceServicio]);
				exists = 1;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO DUENIOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (exists == 0){
		puts("\n\t> NO HAY DUENIOS PARA MOSTRAR");
		rtn = 1;
	}

	return rtn;
}

void eDuenio_MostrarUnaBicicletaPorDuenio(eDuenio duenio, eBicicleta bicicleta){
	printf("%-6d %-20s %-15s %-15s %-10s %-10d %-10s\n", duenio.id, duenio.nombre, duenio.dni, duenio.telefono, bicicleta.marca, bicicleta.rodado, bicicleta.color);
}

int eDuenio_MostrarBicicletasPorDuenio(eTrabajo* arrayT, int TAMT, eBicicleta* arrayB, int TAMB, eDuenio* arrayD, int TAMD){
	int rtn = -1;
	int i, indiceBicicleta, indiceDuenio;
	int exists = 0;

	printf("\nID         NOMBRE             DNI            TELEFONO       MARCA    RODADO       COLOR\n");

	if(arrayT != NULL && TAMD > 0){
		eTrabajo_SortByOwnerId(arrayT, TAMT, -1, arrayD, TAMD);
		for(i = 0; i < TAMD; i++){
			indiceBicicleta = eBicicleta_BuscarPorID(arrayB, TAMB, arrayD[i].idBicicleta);
			indiceDuenio = eDuenio_BuscarPorID(arrayD, TAMD, arrayD[i].id);
			if(indiceBicicleta != -1 && indiceDuenio != -1){
				eDuenio_MostrarUnaBicicletaPorDuenio(arrayD[indiceDuenio], arrayB[indiceBicicleta]);
				exists = 1;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO DUENIOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (exists == 0){
		puts("\n\t> NO HAY DUENIOS PARA MOSTRAR");
		rtn = 1;
	}

	return rtn;
}

int indicarMaximoServicios(int* array, int TAM){
	int i;
	int max = -1;

	if(array != NULL && TAM > 0){
		for(i=0; i<TAM; i++){
			if(i == 0 || array[i] > max){
				max = array[i];
			}
		}
	}

	return max;
}

int eServicio_ContarServiciosConMasTrabajos(eTrabajo* arrayT, int TAMT, eServicio* arrayS, int TAMS){

	int rtn = -1;
	int i,j, max;
	int contadores[TAMS];

	if(arrayS != NULL && arrayT != NULL && TAMS > 0 && TAMT > 0){
		for(i=0; i<TAMS; i++){
			contadores[i] = 0;
			for(j=0; j<TAMT; j++){
				if(arrayS[i].id == arrayT[j].idServicio){
					contadores[i]++;
				}
			}
		}
		max = indicarMaximoServicios(contadores, TAMS);
		if(max != -1){
			puts("\nSERVICIOS CON MAS TRABAJOS:\n");
			for(i=0; i<TAMS; i++){
				if(contadores[i] == max){
					eServicio_MostrarUno(arrayS[i]);
					rtn = 1;
				}
			}
		}

	}
	return rtn;
}

int eTrabajo_SortByYearAndBrand(eTrabajo* arrayT, int TAM, int criterio, eBicicleta* arrayB, int TAMB){
	int rtn = 0;
	int indexBicicletaA;
	int indexBicicletaB;
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
					indexBicicletaA = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[i].idBicicleta);
					indexBicicletaB = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[j].idBicicleta);
					//printf("Indice A: %d\n", indexBicicletaA);
					//printf("Indice B: %d\n", indexBicicletaB);
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayT[i].isEmpty == OCUPADO && arrayT[j].isEmpty == OCUPADO){
						//CRITERIO DE ORDENAMIENTO
					if ((arrayT[i].fecha.anio > arrayT[j].fecha.anio) || (arrayT[i].fecha.anio == arrayT[j].fecha.anio && strcmp(arrayB[indexBicicletaA].marca, arrayB[indexBicicletaB].marca) > 0)) {
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
				indexBicicletaA = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[i].idBicicleta);
				for (j = 0 + 1; j < TAM; j++) {
					indexBicicletaB = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[j].idBicicleta);
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayT[i].isEmpty == OCUPADO
							&& arrayT[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if((arrayT[i].fecha.anio < arrayT[j].fecha.anio) || (arrayT[i].fecha.anio == arrayT[j].fecha.anio && strcmp(arrayB[indexBicicletaA].marca, arrayB[indexBicicletaB].marca) < 0)){
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

int eTrabajo_SortByBrand(eTrabajo* arrayT, int TAM, int criterio, eBicicleta* arrayB, int TAMB){
	int rtn = 0;
	int indexBicicletaA;
	int indexBicicletaB;
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
					indexBicicletaA = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[i].idBicicleta);
					indexBicicletaB = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[j].idBicicleta);
					//printf("Indice A: %d\n", indexBicicletaA);
					//printf("Indice B: %d\n", indexBicicletaB);
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayT[i].isEmpty == OCUPADO && arrayT[j].isEmpty == OCUPADO){
						//CRITERIO DE ORDENAMIENTO
					if (strcmp(arrayB[indexBicicletaA].marca, arrayB[indexBicicletaB].marca) > 0) {
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
				indexBicicletaA = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[i].idBicicleta);
				for (j = 0 + 1; j < TAM; j++) {
					indexBicicletaB = eBicicleta_BuscarPorID(arrayB, TAMB, arrayT[j].idBicicleta);
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayT[i].isEmpty == OCUPADO
							&& arrayT[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if(strcmp(arrayB[indexBicicletaA].marca, arrayB[indexBicicletaB].marca) < 0){
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

/*
 * Menu.c
 *
 *  Created on: 8 may. 2021
 *      Author: maria
 */

#include "Menu.h"
#define TAM_ESTRUCTURA 10
#define TAM_SERVICIOS 4
#define TAM_BICICLETAS 5
#define TAM_DUENIOS 10
#define TAM_HARDCODE_T 5
#define TAM_HARDCODE_S 4
#define TAM_HARDCODE_BICICLETAS 5
#define TAM_HARDCODE_DUENIOS 5

void Menu(void){
	int mainOpc, opc;
	int lastID;
	lastID = 4;
	int confirmacion = 0;
	int addFlag = 0;

	//CREO ARRAYS DE ESTRUCTURAS
	eTrabajo trabajo[TAM_ESTRUCTURA];
	eBicicleta bicicletas[TAM_BICICLETAS];
	eServicio servicios[TAM_SERVICIOS];
	eDuenio duenios[TAM_DUENIOS];

	//INICIALIAZO ARRAYS DE ESTRUCTURAS
	eTrabajo_Inicializar(trabajo, TAM_ESTRUCTURA);
	eServicio_Inicializar(servicios, TAM_SERVICIOS);
	eBicicleta_Inicializar(bicicletas, TAM_HARDCODE_S);

	//HARDCODEO ARRAYS DE ESTRUCTURAS
	hardcodearTrabajos(trabajo, TAM_HARDCODE_T);
	hardcodearServicios(servicios, TAM_HARDCODE_S);
	hardcodearStruct(bicicletas, TAM_HARDCODE_BICICLETAS);
	hardcodearDuenios(duenios, TAM_HARDCODE_DUENIOS);

	//BUCLE DE MENU
	do{
		//MENU PRINT
		//Menu();
		printf("SELECCIONE OPCION: \n1. ALTA\n2. MODIFICAR\n3. BAJA\n4. LISTAR\n5. SALIR\n\nINGRESE OPCION: ");
		getAndValidateIntAndFloatNumber("%d", &mainOpc);

		//MENU SWITCH
		switch(mainOpc){
		case 1:
			//ALTA
			lastID = eTrabajo_ObtenerID(lastID);
			if (eTrabajo_Alta(trabajo, TAM_ESTRUCTURA, bicicletas, TAM_BICICLETAS, servicios, TAM_SERVICIOS, duenios, TAM_DUENIOS, lastID)) {
				puts(" * TRABAJO DADO DE ALTA EXITOSAMENTE");
				addFlag = 1;
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS TRABAJOS");
			}
			printf("\n");
			system("pause");
			break;
		case 2:
			//BAJA
			if(addFlag == 1){
				if (eTrabajo_Baja(trabajo, TAM_ESTRUCTURA, bicicletas, TAM_BICICLETAS, servicios, TAM_SERVICIOS, duenios, TAM_DUENIOS)) {
					puts("\n * BAJA DE TRABAJO EXITOSA");
					eTrabajo_MostrarTodos(trabajo, TAM_ESTRUCTURA, bicicletas, TAM_BICICLETAS, servicios, TAM_SERVICIOS, duenios, TAM_DUENIOS);
				} else {
					puts("\n * BAJA DE TRABAJO CANCELADA");
				}
			}
			else{
				puts("\n * NO SE HAN REALIZADO ALTAS TODAVIA");
			}

			printf("\n");
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if(addFlag == 1){
				if (eTrabajo_Modificacion(trabajo, TAM_ESTRUCTURA, bicicletas, TAM_BICICLETAS, servicios, TAM_SERVICIOS, duenios, TAM_DUENIOS)) {
					puts("\n * MODIFICACION DE TRABAJO EXITOSA\n");
				} else {
					puts("\n * MODIFICACION DE TRABAJO CANCELADA");
				}
			}
			else{
				puts("\n * NO SE HAN REALIZADO ALTAS TODAVIA");
			}
			printf("\n");
			system("pause");
			break;
		case 4:
			//LISTADO TRABAJOS Y SERVICIOS
			printf("\nSELECCIONE UNA OPCION A MOSTRAR: \n1. TODOS LOS TRABAJOS POR AÑO Y MARCA EN CASO DE SER EL MISMO AÑO\n2. TODOS LOS SERVICIOS\n"
					"3. TODAS LAS BICICLETAS\n4. TOTAL EN PESOS POR SERVICIOS PRESTADOS\n"
					"5. TODOS LOS TRABAJOS ORDENADOS POR MARCA DE BICICLETA\n6. EL O LOS SERVICIOS CON MAS TRABAJOS REALIZADOS\n"
					"7. LISTADO DE SERVICIOS CON LOS DATOS DE LAS BICICLETAS QUE SE LO REALIZARON\n"
					"8. CANTIDAD DE BICICLETAS DE COLOR ROJO QUE REALIZARON DETERMINADO SERVICIO\n9. TODOS LOS DUENIOS\n10. MONTO A PAGAR DEL SERVICIO POR DUENIO\n"
					"11. BICICLETA DE CADA DUENIO\n\nINGRESE OPCION: ");
			getAndValidateIntAndFloatNumber("%d", &opc);
			switch(opc){
			case 1:
				eTrabajo_SortByYearAndBrand(trabajo, TAM_ESTRUCTURA, -1, bicicletas, TAM_BICICLETAS);
				eTrabajo_MostrarTodos(trabajo, TAM_ESTRUCTURA, bicicletas, TAM_BICICLETAS, servicios, TAM_SERVICIOS, duenios, TAM_DUENIOS);
				break;
			case 2:
				eServicio_MostrarTodos(servicios, TAM_SERVICIOS);
				break;
			case 3:
				eBicicleta_MostrarTodos(bicicletas, TAM_BICICLETAS);
				break;
			case 4:
				eTrabajo_MostrarGananciaTotal(trabajo, TAM_ESTRUCTURA, servicios, TAM_SERVICIOS);
				break;
			case 5:
				eTrabajo_SortByBrand(trabajo, TAM_ESTRUCTURA, -1, bicicletas, TAM_BICICLETAS);
				eTrabajo_MostrarTodos(trabajo, TAM_ESTRUCTURA, bicicletas, TAM_BICICLETAS, servicios, TAM_SERVICIOS, duenios, TAM_DUENIOS);
				break;
			case 6:
				eServicio_ContarServiciosConMasTrabajos(trabajo, TAM_ESTRUCTURA, servicios, TAM_SERVICIOS);
				break;
			case 7:
				eServicio_MostrarTodosConBicicleta(trabajo, TAM_ESTRUCTURA, servicios, TAM_SERVICIOS, bicicletas, TAM_BICICLETAS, duenios, TAM_DUENIOS);
				break;
			case 8:
				eTrabajo_MostrarCantidadBicicletasRojas(trabajo, TAM_ESTRUCTURA, bicicletas, TAM_BICICLETAS);
				break;
			case 9:
				eDuenio_MostrarTodos(duenios, TAM_DUENIOS);
				break;
			case 10:
				eDuenio_MostrarCargoPorDuenio(trabajo, TAM_ESTRUCTURA, servicios, TAM_SERVICIOS, duenios, TAM_DUENIOS);
				break;
			case 11:
				eDuenio_MostrarBicicletasPorDuenio(trabajo, TAM_ESTRUCTURA, bicicletas, TAM_BICICLETAS, duenios, TAM_DUENIOS);
				break;
			default:
				puts("OPCION INVALIDA");
				system("pause");
				break;
			}
			printf("\n");
			system("pause");
			break;
		case 5:
			printf("ESTA SEGURO QUE DESEA SALIR DE LA APLICACION? (1. SI / 2. NO): ");
			getAndValidateIntAndFloatNumber("%d", &confirmacion);
			while(confirmacion != 1 && confirmacion != 2){
				puts("OPCION INCORRECTA.");
				printf("\nESTA SEGURO QUE DESEA SALIR DE LA APLICACION? (1. SI / 2. NO): ");
				getAndValidateIntAndFloatNumber("%d", &confirmacion);
			}
			if(confirmacion == 1){
				opc = 0;
				break;
			}
			else{
				break;
			}
		default:
			puts("OPCION INVALIDA");
			system("pause");
			break;
		}
	}while(mainOpc != 5);
}


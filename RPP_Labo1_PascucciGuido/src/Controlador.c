#include <stdio.h>
#include <stdlib.h>
#include "Controlador.h"
#include "Inputs.h"
#include "Producto.h"


int mostrarMenuPrincipal(void) {
	int option;

	getIntInMinMaxRange(&option, "\n========================================================================================================================\n"
								 "MENU\n"
								 "========================================================================================================================\n"
								 "1. CARGAR PRODUCTO\n"
								 "2. MODIFICAR PRODUCTO\n"
								 "3. BORRAR PRODUCTO\n"
								 "4. LISTAR PRODUCTOS\n"
								 "5. LISTAR CATEGORÍAS\n"
								 "6. Promedio de precio de todos los productos\n"
								 "7. Listado de categorías con sus productos\n\n"
								 "8. EXIT\n"
								 "========================================================================================================================\n"
								 "Ingrese una opcion: ",

								 "\n\nERROR ! Por favor ingrese nuevamente una opcion correcta...\n"
								 "\n========================================================================================================================\n"
								 "MENU\n"
								 "========================================================================================================================\n"
								 "1. CARGAR PRODUCTO\n"
								 "2. MODIFICAR PRODUCTO\n"
								 "3. BORRAR PRODUCTO\n"
								 "4. LISTAR PRODUCTOS\n"
								 "5. LISTAR CATEGORÍAS\n"
								 "6. Promedio de precio de todos los productos\n"
								 "7. Listado de categorías con sus productos\n\n"
								 "8. EXIT\n"
								 "========================================================================================================================\n"
								 "Ingrese una opcion: ", 1, 8);

	return option;
}



void controladorPrincipal(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias) {
	int option;
	int flagPrimerID = 0;
	int contadorID = 0;
	int flagHayProductos = 0;
	int contadorProductos = 0;

	if(listaProductos != NULL && sizeProductos > 0 && listaCategorias != NULL && sizeCategorias > 0) {
		inicializarEspaciosDeLista(listaProductos, sizeProductos);

			do {
				option = mostrarMenuPrincipal();

				switch(option)
				{
					case 1:
						controlador_alta(listaProductos, sizeProductos, &flagPrimerID, &contadorID, &flagHayProductos, &contadorProductos);
						break;

					case 2:
						controlador_modificacion(listaProductos, sizeProductos, listaCategorias, sizeCategorias, flagHayProductos, contadorProductos);
						break;

					case 3:
						controlador_baja(listaProductos, sizeProductos, listaCategorias, sizeCategorias, &contadorID, &flagHayProductos, &contadorProductos);
						break;

					case 4:
						controlador_listado(listaProductos, sizeProductos, listaCategorias, sizeCategorias, flagHayProductos, contadorProductos);
						break;

					case 5:
						/// LISTAR CATEGORÍAS
						break;

					case 6:
						controlador_promedioPrecios(listaProductos, sizeProductos, flagHayProductos, contadorProductos);
						break;

					case 7:
						/// Listado de categorías con sus productos
						break;

					case 8:
						mostrarMensajeDeCierre();
						break;
				}

			} while(option != 8);
	}

}


void controlador_alta(eProducto listaProductos[], int size, int *flagPrimerID, int *contadorID, int *flagHayProductos, int *contadorProductos) {

	if(!eProducto_agregarProducto(listaProductos, size, flagPrimerID, contadorID)) {
		printf("\n\nSe ha agregado este producto a la lista!\n");
		*flagHayProductos = 1;
		(*contadorProductos)++;
	} else {
		printf("<<Error al agregar>> Este producto no ha sido agregado a la lista!\n");
	}

	system("pause");
}



void controlador_modificacion(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias, int flagHayProductos, int contadorProductos) {

	if(flagHayProductos && contadorProductos) {

		if(listaProductos != NULL && sizeProductos > 0 && listaCategorias != NULL && sizeCategorias > 0) {
			eProducto_modificarProducto(listaProductos, sizeProductos, listaCategorias, sizeCategorias);
		} else {
			printf("<<Error al mostrar>>\n");
		}

	} else {
		printf("\n\nNo hay productos cargados en el sistema\n");
	}

	system("pause");
}


void controlador_baja(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias, int *contadorID, int *flagHayProductos, int *contadorProductos) {

	if(*flagHayProductos && *contadorProductos) {

		if(listaProductos != NULL && sizeProductos > 0 && listaCategorias != NULL && sizeCategorias > 0) {
			eProducto_removerProducto(listaProductos, sizeProductos, listaCategorias, sizeCategorias, contadorProductos);
		} else {
			printf("<<Error al mostrar>>\n");
		}

	} else {
		printf("\n\nNo hay productos cargados en el sistema\n");
	}

	system("pause");
}



void controlador_listado(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias, int flagHayProductos, int contadorProductos) {

	if(flagHayProductos && contadorProductos) {

		if(listaProductos != NULL && sizeProductos > 0 && listaCategorias != NULL && sizeCategorias > 0) {
			eProducto_ordenarProductosPrecioAscendente(listaProductos, sizeProductos);
			printf("\n\n");
			eProducto_mostrarListaProductos(listaProductos, sizeProductos, listaCategorias, sizeCategorias);
		} else {
			printf("<<Error al mostrar>>\n");
		}

	} else {
		printf("\n\nNo hay productos cargados en el sistema\n");
	}

	system("pause");
}



void controlador_promedioPrecios(eProducto listaProductos[], int sizeProductos, int flagHayProductos, int contadorProductos) {

	if(flagHayProductos && contadorProductos) {

		if(listaProductos != NULL && sizeProductos > 0) {
			eProducto_calcularPromedioDePrecios(listaProductos, sizeProductos);
		} else {
			printf("<<Error al mostrar>>\n");
		}

	} else {
		printf("\n\nNo hay productos cargados en el sistema\n");
	}

	system("pause");
}





void mostrarMensajeDeCierre(void) {
	printf("\n\n========================================================================================================================\n"
			"Programa Finalizado.\n"
			"========================================================================================================================");
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controlador.h"
#include "Inputs.h"
#include "Producto.h"


int inicializarEspaciosDeLista(eProducto listaProductos[], int size) {
	int ret = -1;

	if(listaProductos != NULL && size > 0) {
		for (int i = 0; i < size; ++i) {
			listaProductos[i].espacioLibre = TRUE;
		}
		ret = 0;
	}

	return ret;
}


int buscarEspacioLibre(eProducto listaProductos[], int size) {
	int indexLibre = -1;

	if(listaProductos != NULL && size > 0) {
		for (int i = 0; i < size; ++i) {
			if(listaProductos[i].espacioLibre == TRUE) {
				indexLibre = i;
				break;
			}
		}
	}

	return indexLibre;
}


int buscarProductoPorID(eProducto listaProductos[], int size, int idProducto) {
	int index = -1;

	for (int i = 0; i < size; ++i) {
		 if(idProducto == listaProductos[i].id) {
			 index = i;
			 break;
		 }
	}

	return index;
}


int generarID(int *flagPrimerID, int contadorID) {
	int nuevoID;

	if(!flagPrimerID) {
		nuevoID = ID;
		*flagPrimerID = 1;
	} else {
		nuevoID = ID + contadorID;
	}

	return nuevoID;
}


int eProducto_agregarProducto(eProducto listaProductos[], int size, int *flagPrimerID, int *contadorID) {
	int ret = -1;
	int indexLibre;

	if(listaProductos != NULL && size > 0) {
		indexLibre = buscarEspacioLibre(listaProductos, size);
		if(indexLibre != -1) {
			printf("\n========================================================================================================================\n"
					"ALTA DE PRODUCTO - CARGA DE DATOS\n"
					"Por favor ingrese los siguientes datos...\n"
					"========================================================================================================================\n");
			settearID(listaProductos, indexLibre, flagPrimerID, contadorID);
			settearNombre(listaProductos, indexLibre);
			settearDescripcion(listaProductos, indexLibre);
			settearPrecio(listaProductos, indexLibre);
			settearCategoria(listaProductos, indexLibre);
			listaProductos[indexLibre].espacioLibre = FALSE;
			ret = 0;
		} else {
			printf("\n\nNo hay espacio disponible\n");
		}
	}

	return ret;
}



void settearID(eProducto listaProductos[], int index, int *flagPrimerID, int *contadorID) {
	int id;
	id = generarID(flagPrimerID, *contadorID);
	listaProductos[index].id = id;
	(*contadorID)++;
}


void settearNombre(eProducto listaProductos[], int index) {
	char auxNombre[21];
	getString(auxNombre, "* Nombre: ", "<<Error>> Ingrese nombre nuevamente: ", 21);
	printf("========================================================================================================================\n");
	strcpy(listaProductos[index].nombre, auxNombre);
}


void settearDescripcion(eProducto listaProductos[], int index) {
	char auxDescripcion[31];
	getString(auxDescripcion, "* Descripcion: ", "<<Error>> Ingrese descripcion nuevamente: ", 31);
	printf("========================================================================================================================\n");
	strcpy(listaProductos[index].descripcion, auxDescripcion);
}



void settearPrecio(eProducto listaProductos[], int index) {
	float precio;
	getFloatInMinMaxRange(&precio, "* Precio: ", "<<Error>> Ingrese precio nuevamente: ", 0, 300000);
	printf("========================================================================================================================\n");
	listaProductos[index].precio = precio;
}



void settearCategoria(eProducto listaProductos[], int index) {
	int opcion;
	int idCategoria;

	getIntInMinMaxRange(&opcion, "* Categoria:\n"
								    "Comida   ---> 1\t\t\tJuguetes   ---> 2\t\t\tGolosinas   ---> 3\n",

								    "<<Error>> Opcion invalida - Por favor reingrese una opcion...\n"
								    "* Categoria:\n"
								    "Comida   ---> 1\t\t\tJuguetes   ---> 2\t\t\tGolosinas   ---> 3\n", 1, 3);
	printf("========================================================================================================================\n");

	switch(opcion) {
		case 1:
			idCategoria = 2000;
			break;

		case 2:
			idCategoria = 2001;
			break;

		case 3:
			idCategoria = 2002;
			break;
	}

	listaProductos[index].idCategoria = idCategoria;
}


int eProducto_modificarProducto(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias) {
	int ret = -1;
	int idProducto;
	int index;
	int opcion;
	int categoria;
	float precio;

	if(listaProductos != NULL && sizeProductos > 0 && listaCategorias != NULL && sizeCategorias > 0) {
		printf("\n\n\n========================================================================================================================\n"
				"MODIFICACION DE PRODUCTO\n"
				"Por favor seleccione un ID de la lista y luego ingreselo para comenzar la modificacion...\n"
				"========================================================================================================================\n\n");

		eProducto_mostrarListaProductos(listaProductos, sizeProductos, listaCategorias, sizeCategorias);
		getInteger(&idProducto, "Ingrese el ID del producto a modificar: ");
		index = buscarProductoPorID(listaProductos, sizeProductos, idProducto);

		if(index != -1) {
			opcion = eProducto_submenuModificarProducto(listaProductos, sizeProductos, &categoria, &precio);
			if(confirmarModificacionProducto()) {
				switch(opcion) {
					case 1:
						listaProductos[index].idCategoria = categoria;
						break;
					case 2:
						listaProductos[index].precio = precio;
						break;
				}
				printf("\nHas modificado este producto\n");
				ret = 0;
			} else {
				printf("\nHas cancelado la modificacion\n");
			}
		} else {
			printf("\nNo se ha podido encontrar el ID ingresado...\n");
		}
	}

	return ret;
}

int eProducto_submenuModificarProducto(eProducto listaProductos[], int size, int *idCategoria, float *precio) {
	int opcion;
	int categoriaSeleccionada;

	getIntInMinMaxRange(&opcion, "Que desea modificar?\n"
								 "1. Categoria\n"
								 "2. Precio\n",

								 "<<Error>> La opcion ingresada no es valida. Por favor reingrese una opcion...\n"
								 "Que desea modificar?\n"
								 "1. Categoria\n"
								 "2. Precio\n", 1, 2);

	switch(opcion) {
	case 1:
		getIntInMinMaxRange(&categoriaSeleccionada, "* Nueva Categoria:\n"
													"Comida   ---> 1\t\t\tJuguetes   ---> 2\t\t\tGolosinas   ---> 3\n",

													"<<Error>> Opcion invalida - Por favor reingrese una opcion...\n"
													"* Nueva Categoria:\n"
													"Comida   ---> 1\t\t\tJuguetes   ---> 2\t\t\tGolosinas   ---> 3\n", 1, 3);
		switch(categoriaSeleccionada) {
			case 1:
				*idCategoria = 2000;
				break;

			case 2:
				*idCategoria = 2001;
				break;

			case 3:
				*idCategoria = 2002;
				break;
		}
		break;

	case 2:
		getFloatInMinMaxRange(precio, "* Nuevo Precio: ", "<<Error>> Ingrese precio nuevamente: ", 0, 300000);
		printf("========================================================================================================================\n");
		break;
	}

	return opcion;
}



int confirmarModificacionProducto(void) {
	int option;
	getIntInMinMaxRange(&option, "Esta seguro/a que desea modificar este producto?\n"
								 "1. Si, Aceptar\n"
								 "0. No, Cancelar\n",

								 "<<Error>> La opcion ingresada no es valida. Por favor reingrese una opcion...\n"
								 "Esta seguro/a que desea modificar este producto?\n"
								 "1. Si, Aceptar\n"
								 "0. No, Cancelar\n", 0, 1);

	return option;
}



int eProducto_removerProducto(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias, int *contadorProductos) {
	int ret = -1;
	int idProducto;
	int index;

	if(listaProductos != NULL && sizeProductos > 0 && listaCategorias != NULL && sizeCategorias > 0) {
		printf("\n\n\n========================================================================================================================\n"
			   "BAJA DE PRODUCTO\n"
			   "Por favor seleccione un ID de la lista y luego ingreselo para comenzar la baja...\n"
			   "========================================================================================================================\n\n");

		eProducto_mostrarListaProductos(listaProductos, sizeProductos, listaCategorias, sizeCategorias);
		getInteger(&idProducto, "Ingrese el ID del producto a eliminar: ");
		index = buscarProductoPorID(listaProductos, sizeProductos, idProducto);

		if(index != -1) {
			if(confirmarBajaProducto()) {
				listaProductos[index].espacioLibre = TRUE;
				printf("\nHas eliminado este producto de la lista\n");
				(*contadorProductos)--;
				ret = 0;
			} else {
				printf("\nHas cancelado la baja del producto\n");
			}
		} else {
			printf("\nNo se ha podido encontrar el ID ingresado...\n");
		}
	}

	return ret;
}



int confirmarBajaProducto(void) {
	int option;
	getIntInMinMaxRange(&option, "Esta seguro/a que desea eliminar este producto de la lista?\n"
								 "1. Si, Aceptar\n"
								 "0. No, Cancelar\n",

								 "<<Error>> La opcion ingresada no es valida. Por favor reingrese una opcion...\n"
								 "Esta seguro/a que desea eliminar este producto de la lista?\n"
								 "1. Si, Aceptar\n"
								 "0. No, Cancelar\n", 0, 1);

	return option;
}



int eProducto_mostrarListaProductos(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias) {
	int ret = -1;

	if(listaProductos != NULL && sizeProductos > 0 && listaCategorias != NULL && sizeCategorias > 0) {

		printf("LISTA PRODUCTOS\n"
			   "========================================================================================================================\n"
			   "%-10s %-25s %-35s %-20s %-20s","ID","Nombre","Descripcion","Precio","Categoria\n"
			   "========================================================================================================================\n");

		for (int i = 0; i < sizeProductos; ++i) {
			if(listaProductos[i].espacioLibre == FALSE) {
				for (int j = 0; j < sizeCategorias; ++j) {
					if (listaProductos[i].idCategoria == listaCategorias[j].id) {
						eProducto_mostrarProducto(listaProductos, i, listaCategorias, j);
						break;
					}
				}
			}
		}

		ret = 0;
	}

	printf("\n\n");
	return ret;
}



void eProducto_mostrarProducto(eProducto listaProductos[], int indexProducto, eCategoria listaCategorias[], int indexCategoria) {
	printf("%-10d %-25s %-35s %-20.2f %-20s\n",
			listaProductos[indexProducto].id,
			listaProductos[indexProducto].nombre,
			listaProductos[indexProducto].descripcion,
			listaProductos[indexProducto].precio,
			listaCategorias[indexCategoria].nombre);
}



int hardcodearCategorias(eCategoria listaCategorias[], int size) {
	int ret = -1;

	if(listaCategorias != NULL && size > 0) {
		int auxID[] = {2000, 2001, 2002};
		char auxNombre[][21] = {"Comida", "Juguetes", "Golosinas"};

		for (int i = 0; i < size; ++i) {
			listaCategorias[i].id = auxID[i];
			strcpy(listaCategorias[i].nombre, auxNombre[i]);
		}

		ret = 0;
	}

	return ret;
}



void eProducto_ordenarProductosPrecioAscendente(eProducto listaProductos[], int sizeProductos) {
	int limite = sizeProductos - 1;
	int flagSwap;
	int cmp;
	eProducto listaProductosAux[SIZE_PRO];

	do {
		flagSwap = 0;
		for (int i = 0; i < limite; ++i) {
			if ((listaProductos[i].espacioLibre == FALSE && listaProductos[i+1].espacioLibre == FALSE)) {
				if ((listaProductos[i].precio > listaProductos[i+1].precio)) {
					listaProductosAux[i] = listaProductos[i];
					listaProductos[i] = listaProductos[i+1];
					listaProductos[i+1] = listaProductosAux[i];
					flagSwap = 1;
				}
				else if(listaProductos[i].precio == listaProductos[i+1].precio) {
					cmp = strcmp(listaProductos[i].nombre, listaProductos[i+1].nombre);
					if(cmp == 1) {
						listaProductosAux[i] = listaProductos[i];
						listaProductos[i] = listaProductos[i+1];
						listaProductos[i+1] = listaProductosAux[i];
						flagSwap = 1;
					}
				}
			}
		}

		limite--;
	} while (flagSwap);

}




void eProducto_calcularPromedioDePrecios(eProducto listaProductos[], int sizeProductos) {
	float acumuladorPrecio = 0;
	int contadorProductos = 0;
	float promedio;

	for (int i = 0; i < sizeProductos; ++i) {
		if (listaProductos[i].espacioLibre == FALSE) {
			acumuladorPrecio = acumuladorPrecio + listaProductos[i].precio;
			contadorProductos++;
		}
	}

	promedio = (float)acumuladorPrecio / contadorProductos;
	printf("\nPromedio de Precios: %.2f\n\n", promedio);
}






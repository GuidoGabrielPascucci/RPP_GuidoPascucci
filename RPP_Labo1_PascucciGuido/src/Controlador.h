#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include "Producto.h"
#define SIZE_PRO 10
#define SIZE_CAT 3
#define TRUE 1
#define FALSE 0
#define ID 1000

int mostrarMenuPrincipal(void);
void controladorPrincipal(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias);
void controlador_alta(eProducto listaProductos[], int size, int *flagPrimerID, int *contadorID, int *flagHayProductos, int *contadorProductos);
void controlador_modificacion(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias, int flagHayProductos, int contadorProductos);
void controlador_baja(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias, int *contadorID, int *flagHayProductos, int *contadorProductos);
void controlador_listado(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias, int flagHayProductos, int contadorProductos);
void controlador_promedioPrecios(eProducto listaProductos[], int sizeProductos, int flagHayProductos, int contadorProductos);
void mostrarMensajeDeCierre(void);

#endif

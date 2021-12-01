/*
 ============================================================================
 Name        : RPP_Labo1_PascucciGuido.c
 Author      : Pascucci, Guido - 1D
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

#include "Controlador.h"
#include "Producto.h"

int main(void) {
	setbuf(stdout, NULL);

	eProducto listaProductos[SIZE_PRO];
	eCategoria listaCategorias[SIZE_CAT];

	hardcodearCategorias(listaCategorias, SIZE_CAT);
	controladorPrincipal(listaProductos, SIZE_PRO, listaCategorias, SIZE_CAT);

	return EXIT_SUCCESS;
}






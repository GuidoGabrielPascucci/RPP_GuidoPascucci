#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct {
	int id;
	char nombre[21];
} eCategoria;

typedef struct {
	int id;
	char nombre[21];
	char descripcion[31];
	float precio;
	int idCategoria;
	int espacioLibre;
} eProducto;


int inicializarEspaciosDeLista(eProducto listaProductos[], int size);
int buscarEspacioLibre(eProducto listaProductos[], int size);
int buscarProductoPorID(eProducto listaProductos[], int size, int idProducto);
int generarID(int *flagPrimerID, int contadorID);

/// ALTA
int eProducto_agregarProducto(eProducto listaProductos[], int size, int *flagPrimerID, int *contadorID);
void settearID(eProducto listaProductos[], int index, int* flagPrimerID, int* contadorID);
void settearNombre(eProducto listaProductos[], int index);
void settearDescripcion(eProducto listaProductos[], int index);
void settearPrecio(eProducto listaProductos[], int index);
void settearCategoria(eProducto listaProductos[], int index);

/// MODIFICACION
int eProducto_modificarProducto(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias);
int eProducto_submenuModificarProducto(eProducto listaProductos[], int size, int *categoriaSeleccionada, float *precio);
int confirmarModificacionProducto(void);

/// BAJA
int eProducto_removerProducto(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias, int *contadorProductos);
int confirmarBajaProducto(void);

/// LISTAR
int eProducto_mostrarListaProductos(eProducto listaProductos[], int sizeProductos, eCategoria listaCategorias[], int sizeCategorias);
void eProducto_mostrarProducto(eProducto listaProductos[], int indexProducto, eCategoria listaCategorias[], int indexCategoria);

/// ORDENAR
void eProducto_ordenarProductosPrecioAscendente(eProducto listaProductos[], int sizeProductos);

/// PROMEDIO
void eProducto_calcularPromedioDePrecios(eProducto listaProductos[], int sizeProductos);

/// CATEGORIAS
int hardcodearCategorias(eCategoria listaCategorias[], int size);



#endif

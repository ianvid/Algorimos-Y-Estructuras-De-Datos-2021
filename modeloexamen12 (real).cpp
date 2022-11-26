#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//flotante AyED ian vidmar comision s12, 1er a�o

//cola con dni, apellido_nombre y preguntas correctas.

typedef struct nodocola { //estructura de los nodos de la cola--------------------------------------------------------
	int dni;
	char apellido_nombre[100];
	int cant_preguntas_entregadas_correctas;
	struct nodocola* siguiente;
}nodocola;

typedef struct cola { //estructura de la  cola
	nodocola* ultimo;
	nodocola* primero;
	bool esvacia;
}cola;

cola* cola1;

void iniciarcola() { //inicio de la cola, crea un espacio en memoria para la estructura de la cola que contiene primero y ultimo y lo asigna a la estructura declarada anteriormente
	cola1 = (cola*)malloc(sizeof(cola));
	cola1->primero = NULL;
	cola1->ultimo = NULL;
}

nodocola* crearnodocola() { //funcion para crear un nodo de la cola y asignar sus datos, luego devuelve la direccion en memoria del nodo para ubicarlo en la cola dentro de la funcion void encolar();
	nodocola* temp = (nodocola*)malloc(sizeof(nodocola));
	printf("ingrese dni: "); scanf("%d", &temp->dni);
	printf("ingrese apellido y nombre: "); scanf("%s", temp->apellido_nombre);
	printf("ingrese cantidad de preguntas respondidas correctamente: "); scanf("%d", &temp->cant_preguntas_entregadas_correctas);
	temp->siguiente = NULL;

	return temp;
}

void encolar() { //recibe el nodo de la funcion crearnodocola() y lo ubica en la cola
	nodocola* temp = crearnodocola();
	if (cola1->primero == NULL) {
		cola1->primero = temp;
		cola1->ultimo = temp;
		return;
	}
	cola1->ultimo->siguiente = temp;
	cola1->ultimo = temp;
	temp->siguiente = NULL;
}

bool esvacia() {//funcion para saber si la cola es vacia (devuelve 0 si la cola esta vacia, y de lo contrario devuelve 1
	if (cola1->primero == NULL) { return 0; }
	else { return 1; }

}

nodocola* desencolar() { //remueve al primero en la cola, libera el primero, y devuelve el primero en la cola
	if (esvacia() == 0) { // si la lista se encuentra vacia, volver
		return 0x0;
	}
	nodocola* aux = (nodocola*)malloc(sizeof(nodocola));
	strcpy(aux->apellido_nombre, cola1->primero->apellido_nombre);
	aux->cant_preguntas_entregadas_correctas = cola1->primero->cant_preguntas_entregadas_correctas;
	aux->dni = cola1->primero->dni;


	nodocola* temp = cola1->primero->siguiente;
	free(cola1->primero);
	cola1->primero = temp;

	if (esvacia() == 0) {
		cola1->ultimo = NULL;
	}

	return aux;
}

//lista de control----------------------------------------------------------------------------------------------

typedef struct nodo1 { //nodo de la lista de control
	int dni;
	char apellido_nombre[100];
	int cant_preguntas_entregadas_correctas;
	int situacion_alumno; //cada numero indica la situacion del alumno: 1: desaprobado,  2: recuperatorio,  3: aprobado
	struct nodo1* siguiente;
}nodo1;

int* hola = 0xFFAFSN3298
int a = *hola

typedef struct lista1 { // estructura de la lista de control
	nodo1* cabeza;
	int longitud;
}lista1;

lista1* lista1A; //declaracion del struct de la lista de control

void iniciarlista() { //creacion de la estructura de la lista de control (asigna el espacio en memoria)
	lista1A = (lista1*)malloc(sizeof(lista1));
	lista1A->cabeza = NULL;
}

void cargarlista() {
	nodo1* temp = (nodo1*)malloc(sizeof(nodo1));
	nodocola* aux = desencolar(); //desencola
	if (aux == NULL) { return; }
	temp->dni = aux->dni;
	strcpy(temp->apellido_nombre, aux->apellido_nombre);
	temp->cant_preguntas_entregadas_correctas = aux->cant_preguntas_entregadas_correctas;
	//se calcula el porcentaje de preguntas correctas
	float porcentaje = 0;
	porcentaje = temp->cant_preguntas_entregadas_correctas * 100 / 15; //se calcula el porcentaje con regla de 3 simple
	if (porcentaje > 80) {
		temp->situacion_alumno = 3;//aprobado
	}
	if (79.99 > porcentaje > 60) {
		temp->situacion_alumno = 2;//recuperatorio
	}
	if (porcentaje <= 60) {
		temp->situacion_alumno = 1; //desaprobado
	}

	//ubica el nodo en la lista
	if (lista1A->cabeza == NULL) { // si mi lista esta vacia
		temp->siguiente = NULL; //inicializo con null
		lista1A->cabeza = temp; //ahora mi lista apunta a mi nuevo nodo como head
	}
	else { // si no esta vacia
		temp->siguiente = lista1A->cabeza; //mi nuevo nodo va a apuntar a la cabeza de la lista
		lista1A->cabeza = temp; //mi lista va a apuntar a mi nuevo nodo (convirtiendolo en cabeza)
	}

	cargarlista(); //la funcion se llama a si misma hasta que la cola este vacia, ese checkeo se hace en la 3ra linea de esta misma funcion con un IF (if (aux == NULL) { return; })
	//porque aux es null si la funcion desencolar, a su vez al llamar a la funcion esvacia(), devuelve que esta vacia


}

int cantidad100porciento(nodo1* temp, int cantidad) { //funcion recursiva para obtener cantidad de alumnos con las 15 preguntas correctas (100%)
	if (temp == NULL) { //la funcion se llama por primera vez con el parametro en NULL, se empieza por la cabeza de la lista y la cantidad es 0
		temp = lista1A->cabeza;
		cantidad = 0;
	}
	if (temp->cant_preguntas_entregadas_correctas == 15) { //si la cantidad de preguntas es 15, se suma un numero
		cantidad++;
	}
	if (temp->siguiente == NULL) { return cantidad; } //una vez se llegue al fondo de la lista, devuelve la cantidad recolectada
	cantidad100porciento(temp->siguiente, cantidad); //si todavia no se llega al fondo, avanzar en la lista y llamar recursivamente la funcion
}

int main()
{
	iniciarcola();
	iniciarlista();
	int op = 1;
	while (op != 0) { //encola alumnos hasta que el usuario ingrese 0
		encolar();
		printf("seguir cargando alumnos? 1-0: "); scanf("%d", &op);
	}
	cargarlista();
	printf("cantidad de alumnos con el 100 porciento completado: %d\n", cantidad100porciento(NULL, 0));
}


#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct nodopila {
	int dato;
	struct nodopila* siguiente;
}nodopila;


typedef struct pila {
	nodopila* cima;
}pila;

void apilar(pila* pila) {
	nodopila* temp = (nodopila*)malloc(sizeof(nodopila));
	if (pila->cima == NULL) {
		pila->cima = temp;
		return;
	}
	temp->siguiente = pila->cima;
	pila->cima = temp;
}

void desapilar(pila* pila) {
	nodopila* temp = pila->cima->siguiente;
	free(pila->cima);
	pila->cima = temp;
}

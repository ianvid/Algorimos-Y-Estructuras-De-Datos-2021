#include <stdio.h>
#include <stdlib.h>

typedef struct nodo1 {
    int dato;
    struct nodo1* siguiente;
}nodo1;

typedef struct lista1 { 
    nodo1* cabeza;
    int longitud;
}lista1;

lista1* lista1A;

void iniciarlista() {
    lista1A = (lista1*)malloc(sizeof(lista1));
    lista1A->cabeza = NULL;
}

void cargarlista1() {
    nodo1* temp = (nodo1*)malloc(sizeof(nodo1));

    printf("ingrese dato: "); scanf("%d",&temp->dato);


    if (lista1A->cabeza != NULL) {
        temp->siguiente = lista1A->cabeza;
    }
    else {
        temp->siguiente = NULL;
    }

    lista1A->cabeza = temp;
    lista1A->longitud++;

    

    int eleccion = 0;
    printf("seguir cargando datos? 1-0: "); scanf("%d", &eleccion);
    if (eleccion == 1) {
        cargarlista1();
    }
    else {
        ordenarlista();
    }
    
}

void cargarlista() {
    int a = 1;
    while (a != 0) {
        nodo* temp = (nodo*)malloc(sizeof(nodo));
        printf("ingrese dato (0 cancela): "); scanf("%d", &temp->dato);
        a = temp->dato;
        temp->siguiente = nullptr;

        insertarOrdenado(head, temp);
    }


}


void insertarOrdenado(nodo* inicio, nodo* nuevo) { //inicio es la cabeza y nuevo es el address del nodo que acabo de hacer malloc
    //variables: dato, head.
    if (inicio == nullptr || nuevo->dato < inicio->dato) {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else {
        nodo* aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->dato < nuevo->dato) {
            aux = aux->siguiente;
        }
        if (aux->siguiente != nullptr) {
            nuevo->siguiente = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    head = inicio;
    return;
}


void borrarNodo(nodo* cabeza, int dato)
{

    nodo* temp = cabeza;
    nodo* anterior = NULL;

    if (temp != NULL && temp->dato == dato)
    {
        cabeza = temp->siguiente; 
        delete temp;          
        return;
    }
    else
    {
        while (temp != NULL && temp->dato != dato)
        {
            anterior = temp;
            temp = temp->siguiente;
        }

        if (temp == NULL)
            return;

        anterior->siguiente = temp->siguiente;

        free(temp);
    }
}




void imprimirnodos() {
    nodo1* temp = lista1A->cabeza;
    printf("cabeza percibida por imprimir: %d\n", temp->dato);
    while (1) {
        printf("%d\n", temp->dato);
        if (temp->siguiente == NULL) { break; }
        temp = temp->siguiente;
    }

}
int main()
{
    cargarlista1();
    imprimirnodos();
    
}
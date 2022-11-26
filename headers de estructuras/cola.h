
typedef struct nodocola {
	char patente[10];
	int service;
	struct nodocola* siguiente;
}nodocola;

typedef struct cola {
	nodocola* ultimo;
	nodocola* primero;
}cola;

cola* cola1;
void iniciarcola() {
	cola1 = (cola*)malloc(sizeof(cola));
	cola1->primero = NULL;
	cola1->ultimo = NULL;
}

nodocola* crearnodocola() {
	nodocola* temp = (nodocola*)malloc(sizeof(nodocola));
	printf("ingrese patente: "); scanf("%s", temp->patente);
	printf("ingrese tipo servicio: "); scanf("%d", &temp->service);
	temp->siguiente = NULL;

	return temp;
}

void encolar() {
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

void desencolar() {
	if (cola1->primero == NULL) {
		return;
	}
	nodocola* temp = cola1->primero->siguiente;
	free(cola1->primero);
	cola1->primero = temp;

	if (cola1->primero == NULL) {
		cola1->ultimo = NULL;
	}
}

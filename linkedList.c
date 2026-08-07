#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguienteNodo;
} Nodo;

Nodo* crearNodo(int dato){
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if(nuevoNodo == NULL){
        return NULL;
    }

    nuevoNodo->dato = dato;
    nuevoNodo->siguienteNodo = NULL;

    return nuevoNodo;
}

bool agregarAlInicio(Nodo **cabeza, int dato) {
    Nodo *nuevoNodo = crearNodo(dato);
    if(nuevoNodo == NULL) return false;

    nuevoNodo->siguienteNodo = *cabeza;
    *cabeza = nuevoNodo;
    return true;
}

void agregarAlFinal(Nodo **cabeza, int dato){
    Nodo *nuevoNodo = crearNodo(dato);
    
    // Si la lista esta vacia.
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }

    // Si no esta vacia, se busca el ultimo nodo donde siguienteNodo sea NULL
    Nodo *ultimo = *cabeza;
    while(ultimo->siguienteNodo != NULL){
        ultimo = ultimo->siguienteNodo;
    }
    
    // Conectar el nuevo nodo al final de la lista
    ultimo->siguienteNodo = nuevoNodo;
}

void imprimirLista(Nodo *cabeza){
    Nodo *temporal = cabeza;
    if (cabeza == NULL) printf("No hay elementos por mostrar\n");
    else{
        while(temporal != NULL){
            printf(" -> %d", temporal->dato);
            temporal = temporal->siguienteNodo;
        }
        printf(" -> NULL\n");
    }
}

int buscarPorIndice(Nodo *cabeza, int indice){
    Nodo *tmp = cabeza;
    if(indice < 0) return -1;

    for (int i = 0; i<indice && tmp!=NULL; i++)
        tmp = tmp->siguienteNodo;
    
    if(tmp == NULL) return -1;

    return tmp->dato;
}

//Retorna la primer posicion donde se encuentra el elemento
int buscarPorElemento(Nodo *cabeza, int elemento){
    if(cabeza == NULL) return -1;
    
    int pos=0;
    Nodo *tmp = cabeza;
    while(tmp != NULL && tmp->dato != elemento){
        tmp = tmp->siguienteNodo;
        pos++;
    }

    if(tmp == NULL) return -1;

    return pos;
}

void eliminarLinkedList(Nodo *cabeza){
    Nodo *actual = cabeza;
    Nodo *sigNodo = NULL;
    while(actual != NULL){
        sigNodo = actual->siguienteNodo;
        free(actual);
        actual = sigNodo;
    }
}

int main(){
    Nodo *cabeza = NULL;
    unsigned long long numElementos = 0;

    // Inicializar números aleatorios
    srand(time(NULL));

    printf("Iniciando proceso para llenar la memoria (O(1))...\n");

    long long contador = 0;
    while(contador < 1000000){
        int dato = rand();
        
        // Intentamos agregar al inicio; si falla, la memoria se ha agotado
        if (!agregarAlInicio(&cabeza, dato)) {
            break;
        }
        
        numElementos++;

        // Mensaje de progreso cada 1 millón de nodos
        if (numElementos % 1000000 == 0) {
            printf("Nodos creados hasta ahora: %lld millones...\n", numElementos / 1000000);
        }
        contador++;
    }

    imprimirLista(cabeza);

    printf("\n--- Memoria agotada ---\n");
    printf("Total de nodos creados en la Linked List: %lld\n", numElementos);

    eliminarLinkedList(cabeza);
    return 0;
}
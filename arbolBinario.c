#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int tipoDato;
struct Nodo{
    tipoDato dato;
    struct Nodo *izq, *der;
};
typedef struct Nodo Nodo;

Nodo *crearNodo(tipoDato dato){
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato=dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

void insertarEnArbol(Nodo **raiz, tipoDato dato){
    if(*raiz == NULL){
        *raiz = crearNodo(dato);
    }

    Nodo *tmp = *raiz;
    while (true){
        if(dato < tmp->dato){
            if(tmp->izq == NULL){
                tmp->izq = crearNodo(dato);
                break;
            }
            tmp = tmp->izq;
        }else if(dato > tmp->dato){
            if(tmp->der == NULL){
                tmp->der = crearNodo(dato);
                break;
            }
            tmp = tmp->der;
        }else{
            break;
        }
    }
}

void inorden(Nodo *raiz){
    Nodo *tmp = raiz;
    if(tmp != NULL){
        inorden(tmp->izq);
        printf("%d, ", tmp->dato);
        inorden(tmp->der);    
    }
}

int main(){
    Nodo *raiz = NULL;
    for(long i = 0; i<100000000; i++){
        insertarEnArbol(&raiz, rand());
    }
    printf("se guaradaron todos los elementos\n");
    //inorden(raiz);
    return 0;
}
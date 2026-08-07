#include <stdio.h>

int *busquedaBinaria(int *ini, int *fin, int numBuscar){
    if(ini > fin){
        return NULL;
    }

    int *mitad = ini + (fin - ini) / 2;

    if( numBuscar == *mitad ){
        return mitad;
    }else if(numBuscar > *mitad){
        return busquedaBinaria(mitad + 1, fin, numBuscar);
    }else if(numBuscar < *mitad){
        return busquedaBinaria(ini, mitad - 1, numBuscar);
    }
}

int main(){
    int arr[] = {1,5,6,9,44,67,90,91,92};
    int tam = sizeof(arr) / sizeof(arr[0]);
    int *fin = arr + tam - 1;
    int *pos = busquedaBinaria(arr, fin, 92);
    if(pos != NULL){
        int indice = pos - arr;
        printf("%d\n", indice);
    }else{
        printf("%d\n", -1);
    }
    return 0;
}
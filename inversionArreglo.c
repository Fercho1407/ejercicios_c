#include <stdio.h>

void swap(int *a, int *b);
void invertirArreglo(int *arr, int tam);
void imprimirArreglo(int *arr, int tam);

int main(){
    int tam = 2;
    int arr[tam], num;
    for(int i = 0; i<tam; i++){
        scanf("%d", &num);
        *(arr + i) = num;
    }

    printf("Arreglo original -> ");
    imprimirArreglo(arr, tam);

    invertirArreglo(arr, tam);

    printf("Arreglo invertido -> ");
    imprimirArreglo(arr, tam);

    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void invertirArreglo(int *arr, int tam){
    int inicio = 0;
    int fin = tam - 1;

    while(inicio < fin){
        swap((arr + inicio), (arr + fin));
        inicio++;
        fin--;
    }
}

void imprimirArreglo(int *arr, int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
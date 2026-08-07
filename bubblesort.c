#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int *a, int tam){
    for(int i = 0; i<tam-1; i++){
        for(int j = 0; j<tam-1-i; j++){
            if(*(a + j) > *(a + j + 1)){
                swap((a + j), (a+j+1));
            }
        }
    }
}


void imprimirArreglo(int *a, int tam){
    for(int i = 0; i<tam; i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int main(){
    int arr[] = {6,7,9,1,4,2,5,0};
    int tam = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, tam);
    imprimirArreglo(arr, tam);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void unirArreglos(int *arr1, int *arr2, int tam1, int tam2, int *arr);
void imprimirArreglo(int *arr, int tam);

int main(){
    int arr1[] = {2,5,7};
    int arr2[] = {100,101,109};


    int tam1 = (int) sizeof(arr1)/sizeof(arr1[0]);
    int tam2 = (int) sizeof(arr2)/sizeof(arr2[0]);

    int tamArr = tam1 + tam2;
    int *arr = malloc(tamArr * sizeof(int));

    if (arr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    

    unirArreglos(arr1, arr2, tam1, tam2, arr);

    imprimirArreglo(arr, tamArr);

    free(arr);
    
    return 0;
}

void unirArreglos(int *arr1, int *arr2, int tam1, int tam2, int *arr){
    int idxi = 0, idxj = 0, idxArr = 0;
    while (idxi < tam1 && idxj < tam2){
        if(arr1[idxi] < arr2[idxj]){
            arr[idxArr++] = arr1[idxi++];
        }else if(arr1[idxi] > arr2[idxj]){
            arr[idxArr++] = arr2[idxj++];
        }else{
            arr[idxArr++] = arr1[idxi++];
            arr[idxArr++] = arr2[idxj++];
        }
    }

    while(idxi < tam1) arr[idxArr++] = arr1[idxi++];

    while (idxj < tam2) arr[idxArr++] = arr2[idxj++];
}


void imprimirArreglo(int *arr, int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
void unirArreglos(int *arr1, int *arr2, int tam1, int tam2, int *arr, int tamArr){
    if(tam1 == tam2){
        int j = 0;
        for (int i=0; i < tamArr-1; i+=2){
            if(arr1[j] < arr2[j]){
                arr[i] = arr1[j];
                arr[i+1] = arr2[j];
                j++;
            }else{
                arr[i] = arr2[j];
                arr[i+1] = arr1[j];
                j++;
            }
        }
    }else{ //El arreglo mas chico es el numero 1
        int j = 0;
        int menor = tam1;
        if(tam2 < tam1) menor = tam2;

        for (int i=0; j < menor; i+=2){
            if(arr1[j] < arr2[j]){
                arr[i] = arr1[j];
                arr[i+1] = arr2[j];
                j++;
            }else{
                arr[i] = arr2[j];
                arr[i+1] = arr1[j];
                j++;
            }
        }

        if(tam1 < tam2){
            for(int i = (tam1*2); i < tamArr; i++){
                arr[i] = arr2[j];
                j++;
            }
        }else{
            for(int i = (tam2*2); i < tamArr; i++){
                arr[i] = arr1[j];
                j++;
            }
        }

    }


}
*/

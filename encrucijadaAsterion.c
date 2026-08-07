#include <stdio.h>
#include <stdbool.h>

void imprimirMatriz(int N, const int* matriz){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", *(matriz + (i * N) + j));
        }
        printf("\n");
    }
}

bool esImpar(int n){
    return (n % 2) != 0;
}

void rellenarRegionCeros(int N, int* matriz, char region) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            int desplazamiento = (i * N) + j;
            
            switch (region) {
                case 'A': // Arriba
                    if (i < j && (i + j) < (N - 1)) {
                        *(matriz + desplazamiento) = 0;
                    }
                    if (i > j && (i + j) > (N - 1)) {
                        *(matriz + desplazamiento) = 0;
                    }
                    
                break;
                    
                    
                case 'I': // Izquierda
                    if (i > j && (i + j) < (N - 1)) {
                        *(matriz + desplazamiento) = 0;
                    }
                    if (i < j && (i + j) > (N - 1)) {
                        *(matriz + desplazamiento) = 0;
                    }
                break;
            }
        }
    }
}

int main(){
    int N=0;
    scanf("%d", &N);

    int matrix[N][N], elemento;
    int pares=0, impares=0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &elemento);
            if(i==j || (i+j) == (N-1)){
                if(esImpar(elemento)){
                    matrix[i][j] = 1;
                    impares++;
                }else{
                    matrix[i][j] = elemento;
                    pares++;
                }
            }else{
                matrix[i][j] = elemento;
            }
        }
    }

    if (impares > pares){
        rellenarRegionCeros(N, &matrix[0][0], 'A');
    }else{
        rellenarRegionCeros(N, &matrix[0][0], 'I');
    }

    imprimirMatriz(N, &matrix[0][0]);

    return 0;
}
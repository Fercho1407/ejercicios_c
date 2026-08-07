#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 3; // Tamaño inicial

    // 1. MALLOC: Asignar memoria sin inicializar
    // Reservamos espacio para 3 enteros. La memoria contiene "basura".
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error al asignar memoria con malloc\n");
        return 1;
    }

    // Inicializamos manualmente porque malloc no limpia la memoria
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10; 
    }

    printf("Contenido inicial (malloc): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // 2. REALLOC: Redimensionar el bloque de memoria
    // Ampliamos el arreglo para que quepan 5 enteros.
    // Los valores antiguos se conservan, los nuevos son indeterminados.
    int nuevo_n = 5;
    arr = (int*)realloc(arr, nuevo_n * sizeof(int));
    if (arr == NULL) {
        printf("Error al redimensionar memoria\n");
        return 1;
    }

    // Inicializamos solo los nuevos elementos (índices 3 y 4)
    for (int i = n; i < nuevo_n; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("Contenido tras realloc:   ");
    for (int i = 0; i < nuevo_n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Liberamos la memoria actual para demostrar calloc después
    free(arr);
    arr = NULL;

    // 3. CALLOC: Asignar e inicializar a cero
    // Reservamos espacio para 4 enteros y todos se inicializan automáticamente a 0.
    int n_calloc = 4;
    arr = (int*)calloc(n_calloc, sizeof(int));
    if (arr == NULL) {
        printf("Error al asignar memoria con calloc\n");
        return 1;
    }

    printf("Contenido nuevo (calloc): ");
    for (int i = 0; i < n_calloc; i++) printf("%d ", arr[i]); // Imprime: 0 0 0 0
    printf("\n");

    // 4. FREE: Liberar la memoria al finalizar
    free(arr);
    arr = NULL; // Buena práctica: evitar punteros colgantes

    printf("Memoria liberada correctamente.\n");

    return 0;
}   
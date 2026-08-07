#include <stdio.h>

void imprimirArregloInversa(int *arr, int tam);

int main(){
  int n = 0, numero = 0;
  scanf("%d", &n);
  
  int arr[n];
  
  for(int i = 0; i<n; i++){
    scanf("%d", &numero);
    arr[i] = numero;
  }
  
  imprimirArregloInversa(arr, n);
  
  return 0;
}

void imprimirArregloInversa(int *arr, int tam){
  for(int i = tam-1; i>=0; i--)
    printf("%d ", *(arr + i));
}

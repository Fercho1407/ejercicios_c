#include <stdio.h>

void girarIzquierda(int *arr, int tam);
void girarDerecha(int *arr, int tam);
void imprimirArreglo(int *arr, int tam);

int main(){
    int numeros[] = {1,2,3,4,5};
    
    int izq=0, der=0;
    scanf("%d", &izq);
    scanf("%d", &der);
    
    int totalGiros = (izq - der)%5;
    
    if(totalGiros > 0){
      for(int i = 0; i < totalGiros; i++)
        girarIzquierda(numeros, 5);
    }else{
      totalGiros = totalGiros * -1;
      for(int i = 0; i < totalGiros; i++)
        girarDerecha(numeros, 5);
    }
    
    imprimirArreglo(numeros, 5);
    
    
    return 0;
}

void imprimirArreglo(int *arr, int tam){
  for(int i = 0; i < tam; i++)
        printf("%d ", *(arr + i));
        
    printf("\n");
}

void girarIzquierda(int *arr, int tam){
    int primero = *arr;
    for(int i=0; i<tam-1; i++){
        *(arr + i) = *(arr + i + 1);
    }
    
    *(arr + tam - 1) = primero;
}

void girarDerecha(int *arr, int tam){
  int ultimo = *(arr + tam - 1);
  for(int i = tam-1; i>=0; i--){
    *(arr + i) = *(arr + i - 1);
  }
  
  *arr = ultimo;
}
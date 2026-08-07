#include <stdio.h>

void intercambiar(int *x, int *y){
  int pivote = *x;
  *x = *y;
  *y = pivote;
}

int main(void){
  int x = 10;
  int y = 20;
  
  printf("valor de x: %d\n", x);
  printf("valor de y: %d\n", y);
  
  intercambiar(&x, &y);
  
  printf("valor de x despues: %d\n", x);
  printf("valor de y despues: %d\n", y);
  
  return 0;
}

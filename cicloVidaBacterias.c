#include <stdio.h>

int bacteriasVivas(int n){
  if (n == 0){
    return 1;
  }

  return 1 + 2 * bacteriasVivas(n - 1);
}

int main(){
  printf("%d", bacteriasVivas(5));
  return 0;
}

#include <stdio.h>

long long sumaPrimerosNnumeros(long long n){
  return (n * (n + 1)) / 2;
}

int main(){
  long long n = 0;
  

  scanf("%lld", &n);
    
  printf("%lld\n", sumaPrimerosNnumeros(n));
  
  return 0;
}

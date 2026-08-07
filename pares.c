#include <stdio.h>
#include <stdbool.h>

bool esPar(long long x){
    return (x%2) == 0;
}

int main(){
    int n = 0, pares=0;
    long long x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lld", &x);
        if(esPar(x)){
            printf("[%lld] ", x);
            pares++;
        }
    }
    
    if(pares == 0)
        printf(":(");

    return 0;
}
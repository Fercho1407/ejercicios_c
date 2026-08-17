#include <stdio.h>

//Se declara el apuntador a la funcion
typedef float (*OperacionFuncion)(float, float);

//Un struct donde se asocia un caracter a la funcion a ejecutar
typedef struct {
    char operador;
    OperacionFuncion operacion;
}Operacion;

//Declaracion de las funciones
float division(float a, float b);
float multiplicacion(float a, float b);
float suma(float a, float b);
float resta(float a, float b);

int main(){
    float a, b; //operandos
    char operadorUsr; //caracter de la operacion

    //un arreglo donde se define el caracter operador a la funcion a realizar
    Operacion operaciones[] = {
        {'/', division},
        {'*', multiplicacion},
        {'+', suma},
        {'-', resta}
    };

    //Tamanio del arreglo de funciones
    int totalOperaciones = sizeof(operaciones) / sizeof(operaciones[0]);

    printf("\nIngresa la operacion a realizar: ");
    if(scanf("%f %c %f", &a, &operadorUsr, &b) != 3){
        printf("\nError al leer la operacion\n");
        return 1;
    }

    //Verifica si el operador existe dentro de las opereaciones a realizar
    //Si no esta definido manda error 
    int operacion = -1;
    for(int i = 0; i<totalOperaciones; i++){
        if(operaciones[i].operador == operadorUsr){
            operacion = i;
            break;
        }
    }

    if(operacion == -1){
        printf("Operacion no soportada\n");
        return 1;
    }

    //En caso de existir ejecuta la funcion
    float resultado = operaciones[operacion].operacion(a, b);

    printf("El resultado es: %f\n", resultado);

    return 0;
}

float suma(float a, float b) {return a + b;}
float resta(float a, float b) {return a - b;}
float multiplicacion(float a, float b){return a * b;}
float division(float a, float b){
    if(b == 0){
        printf("\ndivision entre 0 invalida\n");
        return 0.0f;
    }
    return a / b;
}
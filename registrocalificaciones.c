/*
3. Registro de calificaciones con estructuras y asignación dinámica (Nivel: Intermedio)
Objetivo: Combinar estructuras (struct) con memoria dinámica y paso de estructuras a funciones mediante punteros.

El problema: Diseña un sistema para gestionar alumnos.

Crea un struct Estudiante que contenga: char nombre[50], int id y un puntero a float (float *calificaciones) para almacenar un número variable de notas.

En el main, pídele al usuario cuántos estudiantes registrará.

Usa malloc para crear un arreglo dinámico de struct Estudiante.

Para cada estudiante, pídele cuántas calificaciones tiene, reserva memoria dinámica individual para sus calificaciones, y guárdalas.

Finalmente, calcula y muestra el promedio de cada estudiante y libera toda la memoria reservada en cascada (primero las calificaciones de cada uno, luego el arreglo de estudiantes).

Conceptos clave: Estructuras anidadas, punteros a estructuras (->), asignación dinámica de memoria en dos niveles (memoria dentro de memoria).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NOMBRE 51

typedef struct{
    char nombre[SIZE_NOMBRE];
    int matricula;
    float *calificaciones;
}Estudiante;

Estudiante *crearEstudiante(char *nombre, int matricula, int numCalificaciones, float *calificaciones){
    Estudiante *estudiante = (Estudiante*) malloc(sizeof(Estudiante));
    if(estudiante == NULL) return NULL; //siempre preguntar si se reservo la memoria correctamente
    
    strncpy(estudiante->nombre, nombre, sizeof(estudiante->nombre) - 1);
    estudiante->nombre[SIZE_NOMBRE - 1] = '\0';

    estudiante->matricula = matricula;

    estudiante->calificaciones = calificaciones;

    return estudiante;
}

float calcularPromedio(float *calificaciones){
    float sumcalificaciones = 0;
    int numCalificaciones = 0;
    int i = 0;
    while(calificaciones[i] != -1){
        sumcalificaciones += calificaciones[i];
        numCalificaciones++;
        i++;
    }
    
    return sumcalificaciones/numCalificaciones;
}

void imprimirCalificaciones(float *arr) {
    int i = 0;
    while (arr[i] != -1.0f) { // El bucle se detiene al encontrar el centinela
        printf("%.2f ", arr[i]);
        i++;
    }
    printf("\n");
}

void mostraDatosEstudiantes(Estudiante *estudiantes, int numEstudiantes){
    for (int i = 0; i<numEstudiantes; i++){
        printf("\nestudiante %d:\n", i+1);
        printf("nombre: %s\n", estudiantes[i].nombre);
        printf("matricula: %d\n", estudiantes[i].matricula);
        imprimirCalificaciones(estudiantes[i].calificaciones);
        printf("promedio calculado: %f\n", calcularPromedio(estudiantes[i].calificaciones));
    }
}

int main(){
    int numEstudiantes;
    printf("Cuantos estudiantes van a registrar? ");
    scanf("%d", &numEstudiantes);
    printf("\n");

    Estudiante *estudiantes = (Estudiante*)malloc(numEstudiantes * sizeof(Estudiante));
    char nombre[SIZE_NOMBRE];
    int matricula;
    int numCalificaciones;
    float *calificaciones, calificacion;

    for(int i = 0; i<numEstudiantes; i++){
        printf("\nIngresa el numero de matricula ");
        scanf("%d", &matricula);
        
        printf("\ningresa el numero de calificaciones: ");
        scanf("%d", &numCalificaciones);
        calificaciones = (float*) malloc((numCalificaciones+1) * sizeof(float));
        for (int j = 0; j<numCalificaciones; j++){
            printf("\nIngresa la calificacion %d: ", j+1);
            scanf("%f", &calificacion);
            calificaciones[j] = calificacion;
        }
        calificaciones[numCalificaciones] = -1.0f;
        

        printf("\ningresa el nombre del estudiante: ");
        getchar(); // LIMPIEZA: Consume el '\n' que dejó el último scanf
        fgets(nombre, SIZE_NOMBRE, stdin); //Lee la cadena de caracteres desde la entrada estandar
        nombre[strcspn(nombre, "\n")] = '\0'; //En caso de ser menor a 50, limpia el carcter \n y lo remplaza por carcter nulo \0

        estudiantes[i] = *crearEstudiante(nombre, matricula, numCalificaciones, calificaciones);
    }

    mostraDatosEstudiantes(estudiantes, numEstudiantes);

    for (int i = 0; i < numEstudiantes; i++) {
        free(estudiantes[i].calificaciones);
    }

    free(estudiantes);

    return 0;
}
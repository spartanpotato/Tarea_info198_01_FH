#include "../include/opciones.h"
#include "../include/string_utils.h"
#include "../include/utils.h"
#include "../include/math_utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Devuelve respuesta a la interfaz si se escoje opcion 1
char* opcion1(char *sentence){
    char *mensaje = malloc(44);

    if(esPalindromo(sentence) == 1){
        strcpy(mensaje, "La oracion es un palindromo\n");
    }
    else{
        strcpy(mensaje, "La oracion no es un palindromo\n");
    }

    return mensaje;
}

//Devuelve respuesta a la interfaz si se escoje opcion 2
char* opcion2(char *sentence){
    int count = cuentaVocales(sentence);
    char count_str[30];
    sprintf(count_str, "%d", count);

    char *mensaje = malloc(100);
    strcpy(mensaje, "La cantidad de vocales en la oracion es de ");
    strcat(mensaje, count_str);
    strcat(mensaje, "\n");

    return mensaje;
}

//Devuelve respuesta a la interfaz si se escoje opcion 3
char* opcion3(char *sentence){
    int count = cuentaLetras(sentence);
    char count_str[30];
    sprintf(count_str, "%d", count);

    char*mensaje = malloc(100);
    strcpy(mensaje, "La cantidad de letras en la oracion es de ");
    strcat(mensaje, count_str);
    strcat(mensaje, "\n");

    return mensaje;
}

//Devuelve respuesta a la interfaz si se escoje opcion 4
char* opcion4(char *vector_char){
    int length = 0;
    int *array = stringToArray(vector_char, &length);

    int valSumatoria = sumatoria(array, length);
    char sumatoria_str[30];
    sprintf(sumatoria_str, "%d", valSumatoria);
    
    int valPromedio = promedio(array, length);
    char promedio_str[30];
    sprintf(promedio_str, "%d", valPromedio);

    char *mensaje = malloc(100);
    strcpy(mensaje, "La sumatoria de los elementos del array es de ");
    strcat(mensaje, sumatoria_str);
    //strcat(mensaje, "\n");
    strcat(mensaje, " y el promedio es de ");
    strcat(mensaje, promedio_str);
    strcat(mensaje, "\n");

    return mensaje;


}

//Devuelve respuesta a la interfaz si se escoje opcion 5
char* opcion5(char *num_char){
    float num = strtof(num_char, NULL);

    float resultado = func1(num);
    char *resultado_str = malloc(30);
    sprintf(resultado_str, "%.2f", resultado);

    char *mensaje = malloc(100);
    strcpy(mensaje, "el resultado de 5x*x+1/x es ");
    strcat(mensaje, resultado_str);
    strcat(mensaje, "\n");

    return mensaje;
}
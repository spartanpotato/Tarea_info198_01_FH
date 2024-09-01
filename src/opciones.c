#include "opciones.h"
#include "string_utils.h"
#include "utils.h"
#include "math_utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Devuelve respuesta a la interfaz si se escoje opcion 1
char* opcion1(char *sentence){
    char *mensaje = malloc(44);

    if(TienePalindromos(sentence) == 1){
        strcpy(mensaje, "La oracion tiene al menos un palindromo\n");
    }
    else{
        strcpy(mensaje, "La oracion no tiene ni un palindromo\n");
    }

    return mensaje;
}

//Devuelve respuesta a la interfaz si se escoje opcion 2
char* opcion2(char *sentence){
    int count = CuentaVocales(sentence);
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
    int count = CuentaLetras(sentence);
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
    int *array = StringToArray(vector_char, &length);
    int sumatoria = Sumatoria(array, length);
    char sumatoria_str[30];
    sprintf(sumatoria_str, "%d", sumatoria);

    char *mensaje = malloc(100);
    strcpy(mensaje, "La sumatoria de los elementos del array es de ");
    strcat(mensaje, sumatoria_str);
    strcat(mensaje, "\n");

    return mensaje;


}

//Devuelve respuesta a la interfaz si se escoje opcion 5
char* opcion5(char *num_char){
    int num = atoi(num_char);

    float resultado = Func1(num);
    char *resultado_str = malloc(30);
    sprintf(resultado_str, "%.2f", resultado);

    char *mensaje = malloc(100);
    strcpy(mensaje, "el resultado de 5x*x+1/x es ");
    strcat(mensaje, resultado_str);
    strcat(mensaje, "\n");

    return mensaje;
}
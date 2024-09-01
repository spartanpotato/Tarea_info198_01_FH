#include "ui.h"
#include "utils.h"
#include "string_utils.h"
#include "math_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interfaz(char *sentence, char *vector_char, char *num_char){
    system("clear");
    int choice = 0;

    //Mantiene la interfaz
    while (true){

        //Opciones de la interfaz
        actualiza_default();

        scanf("%d", &choice);

        //Acciones para cada input del usuario
        switch (choice){

            case 1 :
                opcion1(sentence, &choice);
                break;

            case 2 :
                opcion2(sentence, &choice);
                break;

            case 3 :
                opcion3(sentence, &choice);
                break;

            case 4 :
                opcion4(vector_char, &choice);
                break;

            case 5 :
                opcion5(num_char, &choice);
                break;
                
            case 6 :
                exit(0);
        }
    }
}

//actualiza la interfaz por defecto
void actualiza_default(){
    printf("-------------------------------------------------------\n");
    printf("1) detectar palindro\n");
    printf("2) contar vocales del texto\n");
    printf("3) contar letras del texto\n");
    printf("4) realizar sumatoria sobre el vector\n");
    printf("5) calcular f(x)=5x*x+1/x\n");
    printf("6) salir\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("-------------------------------------------------------\n");
}

//Actualiza la interfaz 
void actualiza(char *respuesta, int* choice){
    printf("-------------------------------------------------------\n");
    printf("1) detectar palindro\n");
    printf("2) contar vocales del texto\n");
    printf("3) contar letras del texto\n");
    printf("4) realizar sumatoria sobre el vector\n");
    printf("5) calcular f(x)=5x*x+1/x\n");
    printf("6) salir\n");
    printf("\n");
    printf("presionaste: %d\n", *choice);
    printf("respuesta: %s",respuesta);
    printf("presiona 0 para volver\n");
    printf("-------------------------------------------------------\n");
    
}

//Muestra output al elejir opcion 1
void opcion1(char *sentence, int *choice){
    system("clear");
    char *mensaje = malloc(44);

    if(TienePalindromos(sentence) == 1){
        strcpy(mensaje, "La oracion tiene al menos un palindromo\n");
    }
    else{
        strcpy(mensaje, "La oracion no tiene ni un palindromo\n");
    }

    actualiza(mensaje, choice);
    scanf("%d", choice);
    system("clear");
}

//Muestra output al elejir opcion 2
void opcion2(char *sentence, int *choice){
    system("clear");
    int count = CuentaVocales(sentence);
    char count_str[30];
    sprintf(count_str, "%d", count);

    char *mensaje = malloc(100);
    strcpy(mensaje, "La cantidad de vocales en la oracion es de ");
    strcat(mensaje, count_str);
    strcat(mensaje, "\n");

    actualiza(mensaje, choice);
    scanf("%d", choice);
    system("clear");

}

//Muestra output al elejir opcion 3
void opcion3(char *sentence, int *choice){
    system("clear");
    int count = CuentaLetras(sentence);
    char count_str[30];
    sprintf(count_str, "%d", count);

    char*mensaje = malloc(100);
    strcpy(mensaje, "La cantidad de letras en la oracion es de ");
    strcat(mensaje, count_str);
    strcat(mensaje, "\n");

    actualiza(mensaje, choice);
    scanf("%d", choice);
    system("clear");
}

//Muestra output al elejir opcion 4
void opcion4(char *vector_char, int *choice){
    system("clear");
    int length = 0;
    int *array = StringToArray(vector_char, &length);
    int sumatoria = Sumatoria(array, length);
    char sumatoria_str[30];
    sprintf(sumatoria_str, "%d", sumatoria);

    char *mensaje = malloc(100);
    strcpy(mensaje, "La sumatoria de los elementos del array es de ");
    strcat(mensaje, sumatoria_str);
    strcat(mensaje, "\n");

    actualiza(mensaje, choice);
    scanf("%d", choice);
    system("clear");


}

//Muestra output al elejir opcion 5
void opcion5(char *num_char, int *choice){
    system("clear");
    int num = atoi(num_char);

    float resultado = Func1(num);
    char *resultado_str = malloc(30);
    sprintf(resultado_str, "%.2f", resultado);

    char *mensaje = malloc(100);
    strcpy(mensaje, "el resultado de 5x*x+1/x es ");
    strcat(mensaje, resultado_str);
    strcat(mensaje, "\n");

    actualiza(mensaje, choice);
    scanf("%d", choice);
    system("clear");
}
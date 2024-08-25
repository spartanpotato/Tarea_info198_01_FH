#include "ui.h"
#include "utils.h"
#include "string_utils.h"
#include "math_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interfaz(char *sentence, char *vector_char, char *num_char){
    int choice = 0;

    //Mantiene la interfaz
    while (true){

        //Opciones de la interfaz
        printf("1) detectar palindro\n");
        printf("2) contar vocales del texto\n");
        printf("3) contar letras del texto\n");
        printf("4) realizar sumatoria sobre el vector\n");
        printf("5) calcular f(x)=5x*x+1/x\n");
        printf("6) salir\n");
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

//Muestra output al elejir opcion 1
void opcion1(char *sentence, int *choice){
    char* mensaje = malloc(50);

    if(TienePalindromos(sentence) == 1){
        strcpy(mensaje, "La oracion tiene al menos un palindromo\n");
    }
    else{
        strcpy(mensaje, "La oracion no tiene ni un palindromo\n");
    }

    printf("%s",mensaje);
    printf("presiona 0 para volver\n");
    scanf("%d", choice);
}

//Muestra output al elejir opcion 2
void opcion2(char *sentence, int *choice){
    int count = CuentaVocales(sentence);

    printf("La cantidad de vocales en la oracion es de %d\n", count);
    printf("presiona 0 para volver\n");
    scanf("%d", choice);

}

//Muestra output al elejir opcion 3
void opcion3(char *sentence, int *choice){
    int count = CuentaLetras(sentence);

    printf("La cantidad de letras en la oracion es de %d\n", count);
    printf("presiona 0 para volver\n");
    scanf("%d", choice);
}

//Muestra output al elejir opcion 4
void opcion4(char *vector_char, int *choice){
    int length = 0;
    int *array = StringToArray(vector_char, &length);

    int sumatoria = Sumatoria(array, length);

    printf("La sumatoria de los elementos del array es de %d\n", sumatoria);
    printf("presiona 0 para volver\n");
    scanf("%d", choice);


}

//Muestra output al elejir opcion 5
void opcion5(char *num_char, int *choice){
    int num = atoi(num_char);

    float resultado = Func1(num);

    printf("el resultado de 5x*x+1/x es de %f\n", resultado);
    printf("presionta 0 para volver\n");
    scanf("%d", choice);
}
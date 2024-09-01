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
    char *respuesta = NULL;

    //Se definen variables para manejar opciones que haya ingresado el usuario al ejecutar el codigo
    int is_sentence_not_null = (sentence != NULL);
    int is_vector_not_null = (vector_char != NULL);
    int is_num_not_null = (num_char != NULL);

    //Se deben añadir manualmente a un array que se pasara a las funciones en vez 3 o mas variables diferentes
    int array_opciones[] = {is_sentence_not_null,
                            is_vector_not_null,
                            is_num_not_null};


    //Mantiene la interfaz
    while (true){

        //Opciones de la interfaz
        actualiza_default(array_opciones);

        //Se recibe y guarda la opcion
        scanf("%d", &choice);

        //Se libera memoria usada anteriormente
        if (respuesta != NULL) {
            free(respuesta);
            respuesta = NULL;
        }

        //Acciones para cada input del usuario
        switch (choice){

            case 1 :
                if (is_sentence_not_null){
                    respuesta = opcion1(sentence);
                }
                else{
                    respuesta = strdup("Esta opcion no esta disponible\n");
                }
                actualiza(respuesta, &choice, array_opciones);

                scanf("%d", &choice);
                break;


            case 2 :
                if (is_sentence_not_null){
                    respuesta = opcion2(sentence);
                }
                else{
                    respuesta = strdup("Esta opcion no esta disponible\n");
                }
                actualiza(respuesta, &choice, array_opciones);

                scanf("%d", &choice);
                break;


            case 3 :
                if (is_sentence_not_null){
                    respuesta = opcion3(sentence);
                }
                else{
                    respuesta = strdup("Esta opcion no esta disponible\n");
                }
                actualiza(respuesta, &choice, array_opciones);

                scanf("%d", &choice);
                break;


            case 4 :
                if (is_vector_not_null){
                    respuesta = opcion4(vector_char);
                }
                else{
                    respuesta = strdup("Esta opcion no esta disponible\n");
                }
                actualiza(respuesta, &choice, array_opciones);

                scanf("%d", &choice);
                break;


            case 5 :
                if (is_num_not_null){
                   respuesta = opcion5(num_char); 
                }
                else{
                    respuesta = strdup("Esta opcion no esta disponible\n");
                }
                actualiza(respuesta, &choice, array_opciones);
                
                scanf("%d", &choice);
                break;
                
                
            case 6 :
                exit(0);
        }
    }
}

//Actualiza la interfaz dependiendo de las opciones que haya ingresado el usuario
void actualiza_default(int *array_opciones){
    system("clear");

    printf("-------------------------------------------------------\n");

    if(array_opciones[0]){
    printf("1) detectar palindro\n");
    printf("2) contar vocales del texto\n");
    printf("3) contar letras del texto\n");
    }

    if(array_opciones[1]){
    printf("4) realizar sumatoria sobre el vector\n");
    }

    if(array_opciones[2]){
    printf("5) calcular f(x)=5x*x+1/x\n");
    }

    printf("6) salir\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("-------------------------------------------------------\n");

}

//Actualiza la interfaz dependiendo de las opciones que haya ingresado el usuario y una respuesta
void actualiza(char *respuesta, int* choice, int *array_opciones){
    system("clear");

    printf("-------------------------------------------------------\n");

    if(array_opciones[0]){
    printf("1) detectar palindro\n");
    printf("2) contar vocales del texto\n");
    printf("3) contar letras del texto\n");
    }

    if(array_opciones[1]){
    printf("4) realizar sumatoria sobre el vector\n");
    }

    if(array_opciones[2]){
    printf("5) calcular f(x)=5x*x+1/x\n");
    }

    printf("6) salir\n");
    printf("\n");
    printf("presionaste: %d\n", *choice);
    printf("respuesta: %s",respuesta);
    printf("presiona 0 para volver\n");
    printf("-------------------------------------------------------\n");

    
}

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
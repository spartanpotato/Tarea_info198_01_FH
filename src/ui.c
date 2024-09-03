#include "ui.h"
#include "opciones.h"
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
    while (1){

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
    printf("ingresa cualquier tecla para volver\n");
    printf("-------------------------------------------------------\n");

    
}

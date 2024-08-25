#include "ui.h"
#include "string_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interfaz(char *sentence, int *vector, int num){
    int choice = 0;
    char* mensaje = malloc(50);

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
                if(TienePalindromos(sentence) == 1){
                    strcpy(mensaje, "La oracion tiene al menos un palindromo\n");
                }
                else{
                    strcpy(mensaje, "La oracion no tiene ni un palindromo\n");
                }

                printf("%s",mensaje);
                printf("presiona 0 para volver\n");
                scanf("%d", &choice);
                break;
            case 6 :
                exit(0);
        }
    }
}
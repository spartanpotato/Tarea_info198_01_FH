#include "ui.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void interface(char *sentence, int *vector, int num){
    int choice = 0;

    while (true){
        printf("1) detectar palindro\n");
        printf("2) contar vocales del texto\n");
        printf("3) contar letras del texto\n");
        printf("4) realizar sumatoria sobre el vector\n");
        printf("5) calcular f(x)=5x*x+1/x\n");
        printf("6) salir\n");
        scanf("%d", &choice);

        switch (choice){
            case 1 :
                printf("presionaste 1\n");
                printf("presiona 0 para volver\n");
                scanf("%d", &choice);
                break;
            case 6 :
                exit(0);
        }
    }
}
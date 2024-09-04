#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/ui.h"
#include "../include/user_utils.h"

int main(int argc, char **argv) {
    int option;
    char *username = NULL, *password = NULL, *sentence = NULL, *vector_char = NULL, *num_char = NULL;


    // itera las opciones con getopt y guarda los argumentos de cada una en un string
    while ((option = getopt(argc, argv, "u:p:t:v:n:")) != -1) {
        switch (option) {
            case 'u':
                username = malloc(strlen(optarg) + 1);
                strcpy(username,optarg);
                break;

            case 'p':
                password = malloc(strlen(optarg) + 1);
                strcpy(password,optarg);
                break;

            case 't':
                sentence = malloc(strlen(optarg) + 1);
                strcpy(sentence,optarg);
                break;

            case 'v':
                vector_char = malloc(strlen(optarg) + 1);
                strcpy(vector_char,optarg);
                if (vector_char != NULL){
                    if(Cumple_Formato_Vector(vector_char) == 0){
                        fprintf(stderr, "Vector invalido para opcion -v, debe ser de la forma i1,i2,..,in donde i es un entero\n");
                        return 1;
                    }
                }
                break;

            case 'n':
                num_char = malloc(strlen(optarg) + 1);
                strcpy(num_char,optarg);
                if(strcmp(num_char, "0") == 0){
                    fprintf(stderr, "No se le puede entregar '0' a la opcion -n\n");
                    return 1;
                }
                break;

            case '?':
                // Handle unknown option or missing argument
                fprintf(stderr, "Unknown option: -%c\n", optopt);
                return 1;
            default:
                break;
        }
    }

    if(VerificarUsuario(username, password) == 0){
        fprintf(stderr, "Usuario y/o contraseña incorrectos");
        return 1;
    }

    interfaz(sentence, vector_char, num_char);



    // Handle any remaining non-option arguments
    for (int index = optind; index < argc; index++) {
        printf("Non-option argument: %s\n", argv[index]);
    }

    return 0;
}

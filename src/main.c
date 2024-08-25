#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "ui.h"

int main(int argc, char **argv) {
    int option;
    char *username, *password, *sentence, *vector_char, *num_char;

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
                break;
            case 'n':
                num_char = malloc(strlen(optarg) + 1);
                strcpy(num_char,optarg);
                break;
            case '?':
                // Handle unknown option or missing argument
                fprintf(stderr, "Unknown option: -%c\n", optopt);
                return 1;
            default:
                break;
        }
    }

    interfaz(sentence, vector_char, num_char);



    // Handle any remaining non-option arguments
    for (int index = optind; index < argc; index++) {
        printf("Non-option argument: %s\n", argv[index]);
    }

    return 0;
}

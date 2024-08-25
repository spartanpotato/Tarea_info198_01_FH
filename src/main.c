#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(int argc, char **argv) {
    int option;
    char *username, *password, *sentence, *char_vector, *char_num;

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
                char_vector = malloc(strlen(optarg) + 1);
                strcpy(char_vector,optarg);
                break;
            case 'n':
                char_num = malloc(strlen(optarg) + 1);
                strcpy(char_num,optarg);
                break;
            case '?':
                // Handle unknown option or missing argument
                fprintf(stderr, "Unknown option: -%c\n", optopt);
                return 1;
            default:
                break;
        }
    }
    printf("%s\n", username);
    printf("%s\n", password);
    printf("%s\n", sentence);
    printf("%s\n", char_vector);
    printf("%s\n", char_num);

    printf("%s\n", "antes");

    int size = 0;
    int *arr = StringToArray(char_vector, &size);

    printf("%s\n", "despues");

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }   
    printf("\n");

    // Handle any remaining non-option arguments
    for (int index = optind; index < argc; index++) {
        printf("Non-option argument: %s\n", argv[index]);
    }

    return 0;
}

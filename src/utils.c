#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//transforma un string a un array de enteros
int* StringToArray(char *str, int *size) {
    // Create a copy to avoid modifying the original string
    char *copy = strdup(str);
    if (copy == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Count the number of tokens
    char *token = strtok(copy, ",");
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the array
    int *array = malloc(count * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(copy);
        return NULL;
    }

    // Reset the tokenizer
    token = strtok(str, ",");
    for (int i = 0; i < count; i++) {
        if (token != NULL) {
            array[i] = atoi(token);
            token = strtok(NULL, ",");
        }
    }

    // Free the copied string
    free(copy);

    // Set the size of the array
    *size = count;

    // Return the array of integers
    return array;
}
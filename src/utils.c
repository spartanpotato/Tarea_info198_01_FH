#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//transforma un string a un array de enteros
int* StringToArray(char *str, int *size) {
    char *copy = strdup(str);
    if (copy == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    char *token = strtok(copy, ",");
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, ",");
    }

    int *array = malloc(count * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(copy);
        return NULL;
    }

    token = strtok(str, ",");
    for (int i = 0; i < count; i++) {
        if (token != NULL) {
            array[i] = atoi(token);
            token = strtok(NULL, ",");
        }
    }

    free(copy);

    *size = count;

    return array;
}

//Toma un string y devuelve si cumple en formato de vector i,i2,i3,..,in
int Cumple_Formato_Vector(char *str) {
    if (str == NULL){
        return 1;
    }

    while (*str != '\0') {
        if (!isdigit(*str)) {
            return 0;
        }

        while (isdigit(*str)) {
            str++;
        }

        if (*str == '\0') {
            return 1;
        }

        if (*str != ',') {
            return 0;
        }

        str++;

        if (*str == '\0') {
            return 0;
        }
    }

    return 1;
}
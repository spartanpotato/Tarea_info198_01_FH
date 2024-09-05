#include "../include/string_utils.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Compara si los extremos del string son iguales, si lo son itera mas cerca del medio, hasta que se probo todo
//o se encontro una diferencia
int esPalindromo(char *str){
    char *strNoWhitespace = stringSinEspacios(str);
    char *newStr = toLowerCase(strNoWhitespace);
    free(strNoWhitespace);

    int low = 0;
    int high = strlen(newStr) - 1;

    bool esPalindromo = 1;

    while (esPalindromo && low < high){
        if (newStr[low] == newStr[high]){
            low++;
            high--;
        }
        else{
            esPalindromo = 0;
        }
    }

    free(newStr);
    return esPalindromo;
}

//Recorre tood el texto y devuelve la cantidad de vocales
int cuentaVocales(char *str){
    const char vocales[] = "aeiouAEIOU"; 
    int count = 0;
    while(*str){
        for (int i = 0; i < 10; i++){
            if(*str == vocales[i]){
                count++;
                break;
            }
        }
        str++;
    }
    return count;
}

//Recorre todo el texto y devuelve la cantidad de letras
int cuentaLetras(char *str){
    int count = 0;
    while(*str){
        if(isalpha(*str)){
            count++;
        }
        str++;
    }
    return count;
}

//Devuelve copia del string sin espacios en blanco
char* stringSinEspacios(char *str){
    char *str2 = strdup(str);
    int i = 0, j = 0;
    while (str2[i]) {
        if (str2[i] != ' ') {
            str2[j] = str2[i];
            j++;
        }
        i++;
    }
    str2[j] = '\0';
    return str2;
}

//Devuelve copia del string con todos los caracteres en minusculas
char* toLowerCase(char* str) {
    int i = 0;
    char* str2 = malloc(strlen(str) + 1);

    while (str[i]) {
        str2[i] = tolower(str2[i]);
        i++;
    }
    str2[i] = '\0';  // Añade el carácter nulo al final

    return str2;
}


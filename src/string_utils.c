#include "../include/string_utils.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//Compara si los extremos del string son iguales, si lo son itera mas cerca del medio, hasta que se probo todo
//o se encontro una diferencia
int EsPalindromo(char *str){
    int low = 0;
    int high = strlen(str) - 1;

    bool esPalindromo = 1;

    while (esPalindromo && low < high){
        if (str[low] == str[high]){
            low++;
            high--;
        }
        else{
            esPalindromo = 0;
        }
    }

    return esPalindromo;
}

//Usa strtok para dividir el str en tokens delimitados por " " y aplica EsPalindromo sobre estos tokens
//termina al encontrar un palindromo o haber probado todos los token
int TienePalindromos(char *str){
    if(str == NULL){
        return 0;
    }

    char *copy = strdup(str);

    char *token = strtok(copy, " ");

    while(token != NULL){
        if (EsPalindromo(token) == 1){
            return 1;
        }
        token = strtok(NULL, " ");
    }

    return 0;
}

//Recorre tood el texto y devuelve la cantidad de vocales
int CuentaVocales(char *str){
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
int CuentaLetras(char *str){
    int count = 0;
    while(*str){
        if(isalpha(*str)){
            count++;
        }
        str++;
    }
    return count;
}
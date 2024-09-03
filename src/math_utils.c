#include "../include/utils.h"
#include "../include/math_utils.h"


//Devuelve sumatoria de elementos del array
int Sumatoria(int *array, int length){
    int total = 0;
    for (int i = 0; i < length; i++){
        total += array[i];
    }

    return total;
}

//Devuelve promedio de los elementos de un array
int Promedio(int *array, int length){
    int total = 0;
    for (int i = 0; i < length; i++){
        total += array[i];
    }

    return total / length;
}

//Devuelve resultado de la funcion f(x) = 5x*x+1/x
float Func1(int x){
    return (5 * x * x + (1.0/x));
}

#include "utils.h"
#include "math_utils.h"


//Devuelve sumatoria de elementos del array
int Sumatoria(int *array, int length){
    int total = 0;
    for (int i = 0; i < length; i++){
        total += array[i];
    }

    return total;
}

//Devuelve resultado de la funcion f(x) = 5x*x+1/x
float Func1(int x){
    return (5 * x * x + (1.0/x));
}

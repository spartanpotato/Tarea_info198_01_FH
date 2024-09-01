# Interfaz en consola con opciones personalizadas
## Descripcion
 Se busca crear un programa que se pueda ejecutar en consola con diferentes opciones, siendo estas el usuario, su contraseña,
 una oracion, un vector y/o un numero sobre el cual realizar ciertas operaciones,
* Las opciones que se pueden realizar al ejecutar el programa son las siguientes:
    * Detectar si una oracion tiene palindromos, independiente de mayusculas o minusculas
    * Detectar cantidad de vocales en una oracion
    * Detectar cantidad de letras en una oracion
    * Realizar una sumatoria y promedio sobre un vector
    * Realizar la operacion 5 * x^2 + (1/x)

## Requisitos
 El programa no se ha probado en maquinas sin sistema operativo, no se puede asegurar que funcione sin uno
 * Compilador:
    El programa necesita un compilador para c, algunas opciones son
    * GCC para Linux
    * Clang para MacOS
    * MinGW para Windows

## Instrucciones de uso
* Compilacion:
    * El programa tiene un makefile incluido, para compilar solo debe ubicarse con su temrinal o consola en el directorio principal del proyecto y ejecutar el comando make

* Ejecucion:
    * Para ejecutar el programa debe ubicarse con su terminal o consola en el directorio bin del proyecto (o mover el ejecutable de bin a otra ubicacion y ubicarse ahi) y ejecutar el compando ./program segudo de los argumentos que desee usar, estos son:
        * "-u" : Este argumento es obligatorio y tiene que ser uno de los usuarios actualmente soportados por el programa
        * "-p" : Este argumento es obligatorio y es la contraseña asociada al usuario del argumento "-u"
        * "-t" : Este argumento es opcional y es una oracion sobre la cual se pueden realizar las opciones 1, 2 y 3 del programa, debe estar dentro de ""
        * "-v" : Este argumento es opcional y es un vector sobre el cual se puede realizar la opcion 4 del programa, debe tener la forma I1,I2,..,IN donde I es un entero
        * "-n" : Este argumento es opcional y es un numero entero o flotante distinto a 0 sobre el cual se puede realizar la opcion 5 del programa
    * En caso de no incluir uno de los argumentos opcionales las opciones asociadas a este no estaran presente en la interfaz 
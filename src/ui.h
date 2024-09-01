
//Mantiene una interfaz en la consola
void interfaz(char *sentence, char *vector_char, char *num_char);

//Actualiza la interfaz dependiendo de las opciones que haya ingresado el usuario y una respuesta
void actualiza(char *respuesta, int *choice, int *array_opciones);

//Actualiza la interfaz dependiendo de las opciones que haya ingresado el usuario
void actualiza_default(int *array_opciones);

//Devuelve respuesta a la interfaz si se escoje opcion 1
char* opcion1(char *sentence);

//Devuelve respuesta a la interfaz si se escoje opcion 2
char* opcion2(char *sentence);

//Devuelve respuesta a la interfaz si se escoje opcion 3
char* opcion3(char *sentence);

//Devuelve respuesta a la interfaz si se escoje opcion 4
char* opcion4(char* vector_char);

//Devuelve respuesta a la interfaz si se escoje opcion 5
char* opcion5(char* num_char);
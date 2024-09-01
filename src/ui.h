
//Mantiene una interfaz en la consola
void interfaz(char *sentence, char *vector_char, char *num_char);

//Actualiza la interfaz mostrando una respuesta
void actualiza(char *respuesta, int *choice);

//Actializa la interfaz sin respuesta
void actualiza_default();

//Caso de la interfaz si se escoje opcion 1
void opcion1(char *sentence, int *choice);

//caso de la interfaz si se escoje opcion 2
void opcion2(char *sentence, int *choice);

//caso de la interfaz si se escoje opcion 3
void opcion3(char *sentence, int *choice);

//caso de la interfaz si se escoje opcion 4
void opcion4(char* vector_char, int* choice);

//caso de la interfaz si se escoje opcion 5
void opcion5(char* num_char, int* choice);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int VerificarUsuario(char *user, char *password){
    FILE *file = fopen("../data/users.txt", "r");
    if (file == NULL) {
        perror("No se pudo abrir el archivo");
        return 0; 
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *stored_user = strtok(line, ":");
        char *stored_password = strtok(NULL, ":");

        if (strcmp(stored_user, user) == 0){
            if(strcmp(stored_password, password) == 0){
                fclose(file);
                return 1; 
            }
            else{
                return 0;
            }
        }
    }

    fclose(file);
    return 0; 
}

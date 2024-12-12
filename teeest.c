#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    const char *file = "test2.c";

    if (access(file, F_OK) == 0) {
        printf("Le fichier existe.\n");

        if (access(file, R_OK) == 0)
            printf("Le fichier est lisible.\n");
        else
            perror("Erreur de lecture");

        if (access(file, W_OK) == 0)
            printf("Le fichier est modifiable.\n");
        else
            perror("Erreur d'écriture");

        if (access(file, X_OK) == 0)
            printf("Le fichier est exécutable.\n");
        else
            perror("Erreur d'exécution");
    } else {
        perror("Le fichier n'existe pas");
    }

    return 0;
}


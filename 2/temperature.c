// Lecture de la température moyenne
#include <stdio.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    double mean = 0;
    int length = 0;
    char buffer[BUFFER_SIZE];
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Décode la température
        int temp;
        if (sscanf(buffer, "%*d-%*d-%*d,%d", &temp) != 1) {
            printf("Warning: Impossible de lire la température\n");
            continue;
        }
        length++;
        mean += temp;
    }
    if (length == 0) {
        printf("Erreur: Aucune valeurs\n");
        return -1;
    }
    mean /= length;
    printf("La température moyenne est de %g°C sur %d mesures\t", mean, length);
}
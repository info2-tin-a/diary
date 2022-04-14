// Exercice : 

// - Compilation séparée
// - Fichiers
// - Structures

// points 2d (x, y)
// 000000 42 42 04 00 00 00 00 00 00 00 00 00 00 00 
#include "geometry.h"
#include "data.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    {
        Data *data = data_create(10);
        data_display(data);
        printf("Distance: %f\n", data_distance(data));
        data_save(data, "data.bin");
    }

    {
        Data *data = data_load("data.bin");
        if (data == NULL) {
            printf("Error loading file\n");
            return 1;
        }

        data_display(data);
        printf("Distance: %f\n", data_distance(data));
    }
}
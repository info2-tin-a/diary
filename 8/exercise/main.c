// Exercice : 

// - Compilation séparée
// - Fichiers
// - Structures

// points 2d (x, y)
// 000000 42 42 04 00 00 00 00 00 00 00 00 00 00 00 
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

#define MAGIC 0x4242

typedef struct point {
	int32_t x;
	int32_t y;
} Point;

typedef struct data {
   int32_t header; // MAGIC
   int32_t npoints; 
   Point points[];
} Data;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void display_data(Data *data) {
    printf("%d points\n", data->npoints);
    for (int i = 0; i < data->npoints; i++) {
        printf("%d %d\n", data->points[i].x, data->points[i].y);
    }
}



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
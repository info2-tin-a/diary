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
  
Data *data_load(char* filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file\n");
        return NULL;
    }
    Data *data = malloc(sizeof(Data));
    fread(&data->header, sizeof(int32_t), 1, f);
    fread(&data->npoints, sizeof(int32_t), 1, f);

    if (data->header != MAGIC) {
        printf("Invalid header\n");
        return NULL;
    }

    data = realloc(data, sizeof(Data) + sizeof(Point) * data->npoints);    
    fread(data->points, sizeof(Point), data->npoints, f);
    fclose(f);
    return data;
}

void data_save(Data *data, char* filename) {
    FILE *f = fopen(filename, "wb");
    fwrite(&data->header, sizeof(int32_t), 1, f);
    fwrite(&data->npoints, sizeof(int32_t), 1, f);
    fwrite(data->points, sizeof(Point), data->npoints, f);
    fclose(f);
}

Data *data_create(int npoints) {
    Data *data = malloc(sizeof(Data) + sizeof(Point) * npoints);
    data->header = MAGIC;
    data->npoints = npoints;

    for (int i = 0; i < npoints; i++) {
        data->points[i].x = rand() % 100;
        data->points[i].y = rand() % 100;
    }
    return data;
}

double data_distance(Data *data) {
    double sum = 0;
    for (int i = 0; i < data->npoints - 1; i++) {
        sum += distance(data->points[i], data->points[i + 1]);
    }
    return sum;
}

void data_display(Data *data) {
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
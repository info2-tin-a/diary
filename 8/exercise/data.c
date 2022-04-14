#include "geometry.h"
#include "data.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

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
#pragma once

typedef struct vector {
    int capacity;
    int elements;
    int data[];
} Vector;

void vector_init(Vector *vector);

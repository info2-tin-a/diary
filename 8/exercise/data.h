#pragma once 

#define MAGIC 0x4242

typedef struct data {
   int32_t header; // MAGIC
   int32_t npoints; 
   Point points[];
} Data;
  
Data *data_load(char* filename);
void data_save(Data *data, char* filename);
Data *data_create(int npoints);
double data_distance(Data *data);
void data_display(Data *data);

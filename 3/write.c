#include <stdio.h>
#include <string.h>

typedef struct Data {
    int number_of_words;
    int chars; 
    int punct;
    int lines;
    char longest_word[200];
} Data; 

int main() {
    Data data = {0};
    data.chars = 4;
    data.punct = 8;
    data.lines = 15;
    data.number_of_words = 16;
    strcpy(data.longest_word, "anticonstitutionnellement");

    printf("%p\n", &data);
    char u[100];
    printf("%ld\n", sizeof(u));
    FILE * fp = fopen("data.dat", "wb");
    fwrite(&data, sizeof(data), 1, fp);
}
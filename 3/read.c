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

    FILE * fp = fopen("data.dat", "rb");
    fread(&data, sizeof(data), 1, fp);

    printf("%d, %d, %d, %d, %s\n", 
        data.chars, data.lines, data.number_of_words, data.punct, data.longest_word
    );
}
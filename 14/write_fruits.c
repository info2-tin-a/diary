#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct fruit {
    char name[20];
    uint32_t color;
    uint32_t energy;
} Fruit;

int empty() {
    int c;
    ungetc('\n', stdin);
    while ( (c = getchar()) != '\n' && c != EOF ) { }
    return (c == EOF);
}

int main(int argc, char * argv[]) {
    if (argc < 2) abort();
    FILE * fp = fopen(argv[1], "ab");
    while(!feof(stdin)) {
        Fruit fruit = {0};
        printf("Nom : "); 
        if(scanf("%19s", fruit.name)!=1) break;
        if(empty()) break;
        printf("Couleur : "); 
        if(scanf("%x", &fruit.color)!=1) break;;
        if(empty()) break;
        printf("Energy : "); 
        if(scanf("%u", &fruit.energy)!=1) break;
        if(empty()) break;

        if (fruit.energy == 0) break;
        fwrite(&fruit, sizeof(fruit), 1, fp);
        fflush(fp);
    }
}
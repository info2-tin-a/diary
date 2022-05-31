#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct fruit {
    char name[20];
    uint32_t color;
    uint32_t energy;
} Fruit;

int main(int argc, char * argv[]) {
    if (argc < 2) abort();
    FILE * fp = fopen(argv[1], "rb");
    while(!feof(fp)) {
        Fruit fruit;
        if (fread(&fruit, sizeof(fruit), 1, fp) == 1)
            printf("%s\t#%06x\t%d\n", fruit.name, fruit.color, fruit.energy); 
    }
}
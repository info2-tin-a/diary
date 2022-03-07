#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
    int z;
} Point;

int main(int argc, char *argv[]) {
    FILE *fp = argc > 1 ? fopen(argv[1], "wb") : stdout;
    assert(fp != NULL);
    for (int i = 0, x = 0, y = 0; i < 100; i++, x += 1, y -= 10)
        fwrite(&(Point){ .x = x, .y = y, .z = rand() }, 
            sizeof(Point), 1, fp);

    
}
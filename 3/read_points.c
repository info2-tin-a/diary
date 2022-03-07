#include <stdio.h>
#include <assert.h>

typedef struct Point {
    int x;
    int y;
    int z;
} Point;

int main(int argc, char *argv[]) {
    FILE *fp = argc > 1 ? fopen(argv[1], "rb") : stdin;
    assert(fp != NULL);
    for (int i = 0; i < 100; i++) {
        Point p;
        fread(&p, sizeof(Point), 1, fp);
        printf("(%d, %d, %d)\n", p.x, p.y, p.z);
    }

    fseek(fp, sizeof(Point) * 40, SEEK_SET);
    fread(&p, sizeof(Point), 1, fp);
    
}
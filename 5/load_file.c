#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char*argv[]) {
    assert(argc > 1);
    FILE *fp = fopen(argv[1], "r");
    assert(fp != NULL);

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size * sizeof(char));
    assert(data != NULL);

    assert(fread(data, size, sizeof(char), fp) > 0);
    fclose(fp);

    printf("%s", &data[2]);
    
    free(data);
}
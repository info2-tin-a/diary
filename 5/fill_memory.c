#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char*argv[]) {

    int data[100];
    int i = 1;
    int *p = malloc(1);
    printf("Entrez des nombres terminer avec ^D...\n");
    while(!feof(stdin)) {
        int *p = realloc(p, i * sizeof(int));
        assert(p != NULL);
        assert(scanf("%d", p) == 1); 
        i++;
    }

    // char *data = malloc(size * sizeof(char));
    // assert(data != NULL);

    // assert(fread(data, size, sizeof(char), stdin) > 0);


    printf("%s", &data[2]);
    
    free(data);
}
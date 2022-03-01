#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    FILE *fp = fopen("report.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Une erreur s'est produite!\n");
        exit(EXIT_FAILURE);
    }

    int c;
    int sum = 0;
    while((c = fgetc(fp)) != EOF) {
        if (!isdigit(c)) continue;
        printf("J'ai lu : %c (0x%x)\n", c, c);
        sum += c - '0';
    }
    printf("La somme est : %d\n", sum);
}
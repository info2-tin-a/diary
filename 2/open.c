#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() { 
    FILE *fp = fopen("haha.txt", "r");
    fgetc(fp);
    fgetc(fp);
    fprintf(stdout, "%ld\n", ftell(fp));
    // SEEK_SET  Début du fichier
    // SEEK_END  Fin du fichier
    // SEEK_CUR  Position courante du curseur
    fseek(fp, 7, SEEK_SET);
    fprintf(stdout, "%ld\n", ftell(fp));

    fseek(fp, -3, SEEK_CUR);
    fprintf(stdout, "%ld\n", ftell(fp));

    fseek(fp, 0, SEEK_END);
    fprintf(stdout, "%ld\n", ftell(fp));

    fseek(fp, 0, SEEK_SET);

    char buf[128];
    fscanf(fp, "%127s", buf); // BEURK ! 
    printf("str: %s\n", buf);
    printf("%ld\n", strlen(buf));
    int c = fgetc(fp);


    fprintf(stdout, "0x%08x, %c", c, c);
}
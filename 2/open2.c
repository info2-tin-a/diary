#include <stdio.h>

int main() {
    FILE *fp = fopen("haha.txt", "r");

    char buffer[100];
    char *p = fgets(buffer, sizeof(buffer), fp);
    p = fgets(buffer, sizeof(buffer), fp);
    printf("%p\n", p);
    printf("%s\n", buffer);


    FILE *fout = fopen("output.txt", "w");
    fprintf(fout, "biscuits");

}
#include <stdio.h>

int main() {
    char name[64] = {0};

    //scanf("%s", name);
    FILE *fp = fopen("name.txt", "r");
    fscanf(fp, "%s", name);
    printf("hello %s", name);
}

/*
0 STDIN 
1 STDOUT 
2 STDERR 
...
*/
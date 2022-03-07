/**
 * Introduction aux structures...
 */
#include <stdio.h>


int i;
int j[3];

struct Prout {
    int i;
    short s[2];
    char c[4];
    float f;
} s;

struct Prout p;
struct Prout q;

typedef unsigned long int Balls;
typedef unsigned long int size_t; // Déjà défini dans stdlib.h
typedef struct Name { int a; int b; char c[4]} Name;

int main() {
    j[3] = 42;   // j[3] === 3[j]  === *(j + 3)
    printf("%p\n", &i);
    printf("%p\n", &j);

    p.s[1];

    struct Prout toto;
    
    Balls balls = 42;
    Name n;
}
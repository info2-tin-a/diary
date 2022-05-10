#include <stdio.h>


int main() {
    int i = 23;
    {
        int i = 42;
        printf("%d\n", i);
    }
    printf("%d\n", i);
}

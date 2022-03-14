#include <stdio.h>

int find_duplicate(int array[], size_t size) {
    int found = 0;
    for (int i = 0; i < size; i++) {
       found ^= array[i];
       printf("%d\n", found);
    }
    return found;
}

int main() {
    int array[] = {1, 12, 45, 3, 6, 6, 12, 1, 3};
    find_duplicate(array, sizeof(array) / sizeof(array[0]));    
}
#include <stdio.h>

int main() {
#ifdef DEBUG
    fprintf(stderr, "Erreur à la ligne %d, dans le fichier %s", __LINE__, __FILE__);
#else 
    fprintf(stderr, "Unexpected error!\n");
#endif 
}
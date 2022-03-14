#include <stdio.h>
#include <stdbool.h>
/**
 *      ./a.out -d   -v=12 toto "a b"
 *      ------- ---- ----- ----  --- 
 *         0      1    2     3    4
 */

typedef struct options {
    int verbosity; 
    bool d;
    char filename[64];
} Options;

Options process_arguments(int argc, char* argv[]) {
    Options opts;
    for (int i = 0; i < argc; i++) {
       if (!strcmp(argv[i], "-d")) {
           printf("Found -d");
           opts.d = true;
           continue;
       }
       if (sscanf(argv[i], "-v=%d", &opts.verbosity) == 1) {
           printf("Found -v with value %d", opts.verbosity);

           continue;
       }
       strncpy(opts.filename, argv[i], 63);
    }
    return opts;
}

int main(int argc, char argv[]) {
    Options options = process_arguments(argc, argv);

    FILE * fp = fopen(options.filename, "r");

}
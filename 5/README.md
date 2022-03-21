# Semaine 5/16

- [ ] Les Pointeurs !
- [ ] L'allocation dynamique
- [ ] Tableaux dynamiques

## Les pointeurs

Un pointeur est une **variable** qui renseigne une **adresse** et un **type**.


En bleu les variables : 
En vert les pointeurs
En rouge les adresses

```
int a[] = {42, 43, 44};
int *p = &a;
int *q = &p;

int b = *p; 
int c = (*(*q));
int d = *a;        // Segmentation fault
int e = &*&*&*&*&*&*&*&*&*p;

int *c, d; // C est un pointeur sur un entier mais D est un entier

int r = *(p + 1);
int s = p[1];  // 1[p]

int *t[] = {&a, p, q};

char *argv[] 

printf("%s %c", argv[1], argv[1][1])

./a.out un de tr

"./a.out\0un\0de\0tr\0"
 ^        ^   ^   ^
 |        |   |   '-------- argv[3]
 |        |   '------------ argv[2]
 |        '---------------- argv[1]
 '--------------------------argv[0]


typdef struct options {
    char *input_filename;
    char output_filename[64];
} Options;

Options options;
options.input_filename = argv[1];
options.output_filename[0] = argv[2][0];
options.output_filename[1] = argv[2][1];
options.output_filename[2] = argv[2][2];
strcpy(options.output_filename, arv[2]); 

-------------------------------------------------------------------------

void * malloc(size_t size)

free(void *)


int * v = malloc(5 * sizeof(int))
v[0] = 12;
v[1] = 23;

free(&v)









 



```


1. & L'adresse de 
2. * Opérateur unaire de déréférencement 




int32_t *x; 
int32_t  y;

printf("%ld, %ld", sizeof(x), sizeof(y));



int* a;


int *a, b;


(int*)a;






int *a = malloc(10*sizeof(int));
int *b = a; // copie du postit

if (rand()%2)
	a = realloc(20*sizeof(int));

printf("%d\n", b[2]);



- - - -  a
- - - - 
- - - -
- - - -
- - - -

struct { int32_t a; char b[15]; char c; } foo;

struct { char c; int32_t a; char b[15];  } foo;

- x x x
- - - -
- - - -
- - - -
- - - -
- - - X

printf("%ld", sizeof(foo));



char **text = {"a", "dsaasb", "cdd"}

a1  a2  a3  a4 
--- --- --- --- --- 












C'est quoi qui qualifie une variable: 


- Type
- Taille
- Adresse
- Nom 
- Valeur
- Durée de vie
- Classe de stockage

-------

- const
- volatile
- (register)
- static 
- (auto)
- extern  (extern est obligatoire pour les variables et facultatif pour les fonctions)

-------

// math.h
extern double sqrt(double x);

int a(); // Déclaration en amont

int b() {
   a();
}

int a() {
   b();
}


-------

int const a; const int a; // Pour stocker une valeur qui n'est pas destinée à être modifiée plus tard
void display(const int *data, size_t size);   // Information pour dire qu'une variable ne sera pas modifiée

-------

Je dis au compilateur de ne pas optimiser l'exécution du code en lien avec cette variable

volatile int i;

-------

register int i;
for (i = 0; i < 10; i++)

------- 

1. Rendre une variable persistente.
2. Protéger contre l'exportation


// foo.c
static int var = 42;

static int display(int a);

// bar.c
int main() {
   extern int var;
   var++;
}




int foo(int a) {
  int b;
}




#define COUNT_OCCURENCES_INITIALIZER {0, 42}

struct count_occurences_context {
	int count;
      const increment;
};

int count_occurences(count_occurences_context *ctx) {

      return (ctx->count)+=ctx->increment;
}


int bob() {
    count_occurences_context ctx = COUNT_OCCURENCES_INITIALIZER;
    for(...)
       printf("%d\n", count_occurences(&ctx));
}


int alice() {
    for(...)
       printf("%d\n", count_occurences());
}




---------


// array.c

static Array* reallocate_if_needed(Array *);


void push(Array *a, int value);
int pop(Array *a);





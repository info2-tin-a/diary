
#pragma toto aime les biscuits
#define MODE 1


#define PARFUM VANILLA
#define SIZE 2 

PARFUM##SIZE

#ifdef VANILLA_1
VANILLA_2
VANILLA_3

CHOCOLATE_1
CHOCOLATE_2
CHOCOLATE_3 

#define TOTO toto
#define STOTO #TOTO
TOTO
#if MODE > 4 || MODE < 1
#error OOps valid modes are 1 2 3 
#endif 
#define FRENCH
#define TATA 23
int tata = 42;

int main() {
int array[10];
#if TATA > 42
#endif
for (int i = 0; i < 10; i++) {
    array[i] = i;
#ifdef DEBUG
    printf("Valeur de array %d\n", array[i]);
#endif 
}
#if 0 // Parce que...
#ifdef FRENCH
#   ifdef SWISS
    printf("Saluuuut, SA va! %d", tata);
#   else 
    printf("Bonjour bienvenue %d", tata);
#   endif
#else
    printf("Welcome");
#endif 
#endif
}
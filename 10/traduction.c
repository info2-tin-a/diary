

#define LANGUAGE FRENCH

#ifndef LANGUAGE
#error "Please define a language"
#endif 

#if LANGUAGE == FRENCH
#define HELLO "Bonjour"
#define GOODBYE "Aurevoir"
#elif LANGUAGE == SPANICH
#define HELLO "Ola"
...
#else 
#error "Language undefined"
#endif
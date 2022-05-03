# Week 10/16

- [ ] Champs de bits (bitfield)

## Bitfields

De créer des structures dont on maîtrise l'espace mémoire consommé au bit près.

```c
struct S {
    int _2bit : 2;
    int _3bit : 3;
} 

assert(sizeof(S) == 4); // 32-bits -> à cause de l'alignement.
```

Difficutlé majeur : vous devez surveiller l'alignement mémoire. 
Car votre compilateur va s'arranger pour aligner les données à l'optimum (32-bits sur un x86, 16-bits sur un MSP430).

Première chose à faire : grouper par paquets de 8:

```c
struct S {
    int _2bit : 2;
    int _3bit : 3;
    int __ununsed : 3;
} 
```

Deuxième chose à faire : forcer le compilateur à gérer l'alignement souhaité.

```c
#pragma pack(1)
struct S {
    int _2bit : 2;
    int _3bit : 3;
    int __ununsed : 3;
} 

assert(sizeof(S) == 1); 
```

## Unions 

Les unions ont la même syntaxe que les structures mais représentent différentes représentation du même espace mémoire. 

```c
union {
    int64_t int64;
    int32_t int32[2];
    int16_t int16[4];
    int8_t int8[8];
} l64;

union l64 u;
u.int64 = 0x123456789;
u.int8[1];
```

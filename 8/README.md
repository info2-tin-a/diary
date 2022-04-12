# Semaine 8/16

## Préprocesseur

- `#include <>` 1er les fichiers systèmes
- `#include ""` 1er les fichiers locaux
- `#define NAME VALUE` Remplacement de chaîne
- `#define NAME(A, TOTO) VALUE A TOTO`

- `#if`
- `#else`
- `#elif`
- `#endif`

- `#ifdef` == `#if defined`
- `#ifndef` == `#if not defined`
- `#if 0 ... #endif` Pour commenter du code

- `#error` Cause une erreur de préproceseur

- `#pragma`
- `#pragma once` Inclusion une seule fois... (protection contre la réentrence)

Mangling : rajouer un préfixe devant vous vos define pour éviter les collisions de noms.
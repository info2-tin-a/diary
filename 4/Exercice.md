# Doublons

Soit une liste d'entiers dont chaque entier est à double dans la liste sauf un.

Identifier lequel.

Quelle est la complexité de votre programme :

- En espace
- En temps 

Temps 20 minutes.

Exemple:
```c
1 12 45 3 6 6 12 1 3
```

Prototype: 
```c
int find_duplicate(int array[] size_t size);
```

## Algorithmes


1 12 3 45 3 6 6 12  1

tab[12]++;
int tab[k] = {0}; 

1. O(n^2), O(2) : On prend un nombre on parcours la liste et vérifie si on le trouve, sinon on a trouvé le nombre. Puis on recommance avec le nombre suivant.
2. O(n^2/2), O(3) : Pareil mais on swap l'élément trouvé avec le dernier de la liste
3. O(n + k), O(k) : On réserve un espace de k valeur où k est l'occurence la plus élevée (int32), on parcours le tableau et on incrémente la position à l'indice de l'espace réserve de 1. Ensuite on parcours l'espace réservé à la recherche de la valeur 1
4. Variation de 3 mais on identifie k en cherchant la valeur la plus grande. On gagne un peu en espace
5. O(n*log n + n), O(1) On trie le tableau, puis on parcours de deux en deux la liste pour voir si on n'a pas de doublon
6. Variation de 4 mais en utilisant un champ de bits.Fonctionne jusqu'aux valeurs 63
7. O(n), O(1): On parcours une fois le tableau avec une opération XOR sur une variable initialisée à 0.

## ^

  11110000 n 
^ 11001001 m 
------------
  00111001
^ 11001001 
------------
  11110000

q = n ^ 6432643;
q = q ^ 6432643;

```c

int found = 0;
for (int i = 0; i < n; i++) {
  found ^= array[i];
  printf("%d\n", found);
}

```





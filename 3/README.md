# Exercice

On a une liste de points en 3D (100 points).
    - x s'incrémente de 1 à chaque point.
    - y se décrémente de 10 à chaque point.
    - z est aléatoire
On écrit l'intégralité de ces données dans un fichier binaire.
On lit les données et on les affiches à l'écran depuis un autre programme


```
$ ./write data.dat
$ ./read data.dat
(1, -10, 53)
(2, -20, 583)
...

Point p[10];
fwrite(&p, sizeof(p[0]), 10, fp);

union 
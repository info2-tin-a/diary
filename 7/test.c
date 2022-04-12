
#define TEST 42
#include <stdio.h>

#include "delta.h"

double main() {
	double a = -3, b = 2, c = 1;
	printf("Le delta de A, B, C est %f\n", delta(a,b,c));
}


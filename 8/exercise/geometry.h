#pragma once

#include <stdint.h>

typedef struct point {
	int32_t x;
	int32_t y;
} Point;

double distance(Point a, Point b);
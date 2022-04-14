#include "geometry.h"

#include <stdint.h> 
#include <math.h> 

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
#include <stdio.h>

double distance(double x1, double y1, double x2, double y2);

typedef struct Point {
    double x;
    double y;
} Point;

double distance2(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + pow(a.y - b.y, 2) );
}

Point randomPoint() {
    Point p;
    p.x = rand();
    p.y = rand();
    return p;
}

int main() {
    distance2(randomPoint(), randomPoint());
}
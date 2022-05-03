#include <stdbool.h>
#include <stdio.h>

#pragma pack(1)
typedef struct road_light {

    bool red      : 1;
    bool orange   : 1;
    bool green    : 1;
    bool blinking : 1;    
    int __padding : 4;
} RoadLight;

int main() {
    printf("%ld\n", sizeof(RoadLight));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
void circle_zone(float x, float y, float* zone, float num)
{
    zone[0] = x + num;
    zone[1] = y + num;
    zone[2] = x - num;
    zone[3] = y - num;
}

float circle_square(float number) // Count square of sircle figure
{
    return M_PI * number * number;
}
float circle_per(float number) // Count perimetr of sircle figure
{
    return 2 * M_PI * number;
}

int is_it(char* string)
{
    if (!(strcmp(string, "circle"))) {
        return 3;
    }
    if (!(strcmp(string, "triangle"))) {
        return 4;
    }
    if (!(strcmp(string, "polygon"))) {
        return 5;
    }
    return 0;
}

struct figure {
    int number;
    char* head;

    char figure_type[9];
    float point[4];
    float perimetr;
    float area;
    float zone[4];
};
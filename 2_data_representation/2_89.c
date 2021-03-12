#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(void)
{
    srand(time(NULL));
    int x = rand();
    int y = rand();
    int z = rand();
    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;

    assert(((float)x == (float)dx));
    assert(dx - dy == (double)(x - y));
    assert((dx + dy) + dz == dx + (dy + dz));
    assert((dx * dy) * dz == dx * (dy * dz));   // Not always TRUE
    assert(dx / dx == dz / dz);

    return 0;
}
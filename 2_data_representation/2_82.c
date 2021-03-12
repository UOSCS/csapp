#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

// False when x is INT_MIN
// But in Linux(Ubuntu 20.04), It is UB(maybe).
// A() always returns 1 
int A(int x, int y)
{
	return (x < y) == (-x > -y);
}

// True
int B(int x, int y)
{
	return ((x + y) << 4) + y - x == 17 * y + 15 * x;
}

// True
int C(int x, int y)
{
	return ~x + ~y + 1 == ~(x + y);
}

// True
int D(int x, int y) {
  unsigned ux = (unsigned) x;
  unsigned uy = (unsigned) y;

  return (ux - uy) == -(unsigned) (y - x);
}

// True
int E(int x, int y)
{
	return ((x >> 2) << 2) <= x;
}

int main(void)
{
	srand(time(NULL));
	
	int x = rand();
	int y = rand();
	int z = INT_MIN;
	
	printf("%d %d\n", z, -z);
	printf("%d %d\n", (z < 0), (-z > -0));

	assert(A(INT_MIN, 1));
	assert(B(x, y));
	assert(C(x, y));
	assert(D(x, y));
	assert(E(x, y));
	
	return 0;
}

#include <stdio.h>
#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k)
{
	int is_neg = INT_MIN & x;
	
	is_neg && (x = x + (1 << k) - 1);
	
	return x >> k;
}

int main(void)
{
	int x = -10;
	int y = 13;
	
	assert(divide_power2(x, 2) == x / 4);
	assert(divide_power2(x, 3) == x / 8);
	
	assert(divide_power2(y, 2) == y / 4);
	assert(divide_power2(y, 3) == y / 8);

	return 0;
}

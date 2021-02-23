#include <stdio.h>
#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k)
{
	int is_neg = INT_MIN & x;
	
	is_neg && (x = x + (1 << k) - 1);
	
	return x >> k;
}

int mul3div4(int x)
{
	return divide_power2((x << 1) + x, 2);
}

int main(void)
{
	int x = 8;
	int y = INT_MIN;
	
	assert(mul3div4(x) == 3 * x / 4);
	assert(mul3div4(y) == 3 * y / 4);

	return 0;
}

#include <stdio.h>
#include <assert.h>


unsigned rotate_left(unsigned x, int n)
{
	int w = sizeof(int) << 3;
	// If (w - n - 1) >> 1 -> (w - n), UB is occurred (w = (w - 0))
	return (x >> (w - n - 1) >> 1) | (x << n);
}

int main(void)
{
	assert(rotate_left(0x12345678, 0) == 0x12345678);
	assert(rotate_left(0x12345678, 4) == 0x23456781);
	assert(rotate_left(0x12345678, 8) == 0x34567812);
	assert(rotate_left(0x12345678, 20) == 0x67812345);
	
	return 0;
}

#include <stdio.h>
#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y)
{
	int sum = x + y;
	int sign_mask = INT_MIN;
	int pos_over = !(x & sign_mask) && !(y & sign_mask) && (sum & sign_mask);
	int neg_over = (x & sign_mask) && (y & sign_mask) && !(sum & sign_mask);
	
	pos_over && (sum = INT_MAX) || neg_over && (sum = INT_MIN);
	
	return sum;
}

int main(void)
{
	assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
	assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
	assert(0x11 + 0x22 == saturating_add(0x11, 0x22));
	
	return 0;
}

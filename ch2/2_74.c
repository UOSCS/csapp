#include <stdio.h>
#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
	int sub = x + y;
	int sign_mask = INT_MIN;
	int pos_over = !(x & sign_mask) && (y & sign_mask) && (sub & sign_mask);
	int neg_over = (x & sign_mask) && !(y & sign_mask) && !(sub & sign_mask);
		
	return !(pos_over || neg_over);
}

int main(void)
{
	assert(!tsub_ok(0x00, INT_MIN));
	assert(tsub_ok(0x00, 0x00));
	
	return 0;
}

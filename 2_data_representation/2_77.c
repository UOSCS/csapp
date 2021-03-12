#include <stdio.h>
#include <assert.h>

int main(void)
{
	const int K = 1;
	
	assert(17 == (K << 4) + K);
	assert(-7 == -(K << 3) + K);
	assert(60 == (K << 6) - (K << 2));
	assert(-112 == (K << 4) - (K << 7));
	
	return 0;
}

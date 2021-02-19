#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
	return (int)word << (24 - (bytenum << 3)) >> 24;
}

int main(void)
{
	assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
	assert(xbyte(0x00112233, 2) == 0x11);
  
	return 0;
}

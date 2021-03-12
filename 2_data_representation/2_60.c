#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	int tmp1 = b;
	int tmp2 = 0xFF;
	
	tmp1 <<= 8 * i;
	tmp2 <<= 8 * i;
	
	return (x&~tmp2)|tmp1;
}

int main(void)
{
	printf("%#X\n", replace_byte(0x12345678, 0, 0xAB));
	
	return 0;
}

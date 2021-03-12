#include <stdio.h>

int main(void)
{
	int x = 0x89ABCDEF;
	int y = 0x76543210;
	
	printf("%#X\n", (x&0xFF)|(y&~0xFF));
	
	return 0;
}

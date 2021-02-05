#include <stdio.h>

int is_little_endian()
{
	int x = 0x01234567;
	
	if((char)x == 0x67)
		return 1;
	else
		return 0;
}

int main(void)
{
	if(is_little_endian())
		printf("little endian\n");
	else
		printf("big endian\n");
	
	return 0;
}

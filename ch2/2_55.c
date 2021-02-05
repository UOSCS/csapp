#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	for(int i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer)&x, sizeof(void *));
}

void show_short(short x)
{
	show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x)
{
	show_bytes((byte_pointer)&x, sizeof(long));
}

void show_double(double x)
{
	show_bytes((byte_pointer)&x, sizeof(double));
}


int main(void)
{
	int x = 12345;
	
	show_short((short)x);
	show_double((double)x);
	show_long((long)x);
	
	return 0;
}

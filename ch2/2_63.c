#include <stdio.h>

unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int)x >> k;
	
	int w = sizeof(int) << 3;
	int mask = -1 << (w - k);
	
	return xsra & ~mask;
}

int sra(int x, int k)
{
	int xsrl = (unsigned)x >> k;
	
	int w = sizeof(int) << 3;
	int mask = -1 << (w - k);
	int most_important_bit = 1 << (w - 1);
	mask &= !(x & most_important_bit) - 1;
	
	return xsrl | mask;
}

int main(void)
{
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    printf("%d\n", (srl(test_unsigned, 4) == test_unsigned >> 4));
    printf("%d\n", (sra(test_int, 4) == test_int >> 4));
	
	test_unsigned = 0x87654321;
    test_int = 0x87654321;

    printf("%d\n", (srl (test_unsigned, 4) == test_unsigned >> 4));
    printf("%d\n", (sra (test_int, 4) == test_int >> 4));

    return 0;
}

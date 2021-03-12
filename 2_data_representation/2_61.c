#include <stdio.h>

void func_A(int x)
{	
	printf("%d\n", !~x);
}

void func_B(int x)
{	
	printf("%d\n", !x);
}

void func_C(int x)
{	
	printf("%d\n", !~(x | ~0xFF));
}

void func_D(int x)
{	
	printf("%d\n", !(x & (0xFF << (sizeof(int) - 1) << 3)));
}

int main(void)
{
	int x;
	
	scanf("%d", &x);
	
	func_A(x);
	func_B(x);
	func_C(x);
	func_D(x);
	
	return 0;
}

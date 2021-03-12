#include <stdio.h>
#include <assert.h>

int A(int k)
{
  return -1 << k;
}

int B(int k, int j)
{
  return ~(-1 << k) << j;
}

int main(void)
{
  assert(A(8) == 0xFFFFFF00);
  assert(B(16, 8) == 0x00FFFF00);
  
  return 0;
}

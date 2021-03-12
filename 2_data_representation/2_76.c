#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void *my_calloc(size_t nmemb, size_t size)
{
	if(!(nmemb && size))
		return NULL;
		
	size_t buf_size = nmemb * size;
	if(nmemb == (buf_size / size))
	{
		void *arr = malloc(buf_size);
		
		if(arr != NULL)
			memset(arr, 0, buf_size);
		
		return arr;
	}
	else
		return NULL;
}

int main(void)
{
  void* p;
  
  p = my_calloc(sizeof(int), 10);
  assert(p != NULL);
  free(p);

  p = my_calloc(SIZE_MAX, 1);
  assert(p == NULL);
  free(p);
  
  return 0;
}

#include <stdio.h>

int main()
{
	printf("size of int is %d\n", sizeof(int));
	printf("size of void* is %d\n", sizeof(void*));

	int a = 3;
	long b = 32;
	void *p = (void*)a;

	return 0;
}

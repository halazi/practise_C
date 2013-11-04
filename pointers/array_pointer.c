#include <stdio.h>

int main()
{
	int a[3][9];
	int (*p)[9] = a;

	printf("%d\n", sizeof(*p));
	return 0;
}

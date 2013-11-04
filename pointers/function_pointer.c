#include <stdio.h>

int max(int a, int b)
{
	return a >= b ? a : b;
}

int compare(int a, int b, int (*p)())
{
	return (*p)(a, b);
}

int main()
{
	int (*p)() = main;
	int (*q)(int, int) = max;
	printf("%p\n", p);
	printf("%p\n", q);
	int (*pc)() = compare;
	printf("%d\n", (*pc)(1, 2, max));
	char *ps = main;
	printf("%s\n", ps);
	return 0;
}

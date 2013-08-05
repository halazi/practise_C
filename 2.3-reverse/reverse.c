#include <stdio.h>

typedef unsigned long uint64_t;

uint64_t reverse(uint64_t x)
{
	uint64_t ret = 0;
	int i;
	for (i=0; i<64; i++) {
		if (((x>>i) & 1UL) == 1) {
			ret |= 1UL<<(63-i);
			continue;
		}
	}
	return ret;
}

int display(unsigned long x) 
{
	int i;
	for (i=63; i>=0; i--) {
		if (((x >> i) & 1) == 1) break;
	}
	for (; i>=0; i--) {
		printf("%lx", (x>>i) & 1);
	}
	return 0;
}

int main()
{
	int i;
	for (i=0; i<25; i++) {
		display(i);
		printf("-->");
		display(reverse(i));
		printf("\n");
	}
	return 0;
}

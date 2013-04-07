#include <stdio.h>

typedef unsigned long uint64_t;

int parity(uint64_t x) {
	int ret = 0;
	int i;
	for (i=0; i<64; i++) {
		ret += x & 1;
		x = x >> 1;
	}
	return ret % 2;
}

int main() {
	int i;
	for (i=0; i<30; i++) {
		printf("parity of %x is %d\n", i, parity(i));
	}
	return 0;
}

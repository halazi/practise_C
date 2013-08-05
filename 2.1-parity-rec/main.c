#include <stdio.h>

typedef unsigned long uint64_t;

int parity(uint64_t x) {
	if (x == 0) {
		return 0;
	} else {
		if (x & 1 == 1) {
			return 1 - parity(x >> 1);
		} else {
			return parity(x >> 1);
		}
	}
}

int main() {
	int i;
	for (i=0; i<25; i++) {
		printf("parity of %x is %d\n", i, parity(i));
	}
	return 0;
}

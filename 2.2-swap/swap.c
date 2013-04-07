#include <stdio.h>

int swap(unsigned long x, int i, int j) {
	if (((x >> i) & 1) == ((x >> j) & 1)) return x;
	if (((x >> i) & 1) == 1) {
		return x & ~(1 << i) | (1 << j);
	} else {
		return x & ~(1 << j) | (1 << i);
	}
}

int display(unsigned long x) {
	int i;
	for (i=63; i>=0; i--) {
		if (((x >> i) & 1) == 1) break;
	}
	for (; i>=0; i--) {
		printf("%lx", (x>>i) & 1);
	}
	return 0;
}

int main() {
	int x;
	for (x=500; x<525; x++) {
		int i = 0, j = 6;
		printf("swap %dth and %dth bits of %x: ", i, j, x);
		display(x);
		printf("-->");
		display(swap(x, i, j));
		printf("\n");
	}
}

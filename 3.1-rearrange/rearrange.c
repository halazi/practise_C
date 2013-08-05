#include <stdio.h>

int rearrange(const int array[], int length, int index, int *new_array)
{
	int i;
	int tmp = array[index];
	int front = 0;
	int back = length-1;
	for (i=0; i<length; i++) {
		if (array[i] < tmp) {
			new_array[front++] = array[i];
		} else if (array[i] > tmp) {
			new_array[back--] = array[i];
		}
	}
	for (i=front; i<=back; i++) {
		new_array[i] = tmp;
	}

	return 0;
}

int main()
{
	int a[13] = {1, 2, 4, 3, 32, 4, 9, 1, 31, 3, 1, 0, 3};
	int new[13];
	if (!rearrange(a, 13, 5, new)) {
		int i;
		for (i=0; i<13; i++) {
			printf("%d\t%d\n", a[i], new[i]);
		}
	}
	return 0;
}

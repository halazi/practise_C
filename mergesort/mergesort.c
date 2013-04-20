#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 1000000
#define PRE(x,y) (x<=y)

typedef unsigned long TYPE;

void merge(TYPE *arr, int start, int mid, int end)
{
	TYPE *tmp = (TYPE *)calloc(end-start, sizeof(TYPE));
	memcpy(tmp, arr+start, (end-start)*sizeof(TYPE));
	int tmid = mid - start;
	int tend = end - start;
	int p = 0;
	int q = tmid;
	int curr = start;
	while (1) {
		if (p < tmid && q < tend) {
			if PRE(tmp[p], tmp[q]) {
				arr[curr++] = tmp[p];
				p++;
			} else {
				arr[curr++] = tmp[q];
				q++;
			}
		} else {
			if (p == tmid) {
				for (; q<tend; q++) {
					arr[curr++] = tmp[q];
				}
			} else {
				for (; p<tmid; p++) {
					arr[curr++] = tmp[p];
				}
			}
			break;
		}
	}
	free(tmp);
}

void mergesort(TYPE *arr, int start, int end)
{
	int len = end - start;
	if (len <= 1) return;
	if (len == 2) {
		if (!PRE(arr[start], arr[start+1])) {
			TYPE tmp = arr[start];
			arr[start] = arr[start+1];
			arr[start+1] = tmp;
		}
		return;
	}
	int mid = len/2 + start;
	mergesort(arr, start, mid);
	mergesort(arr, mid, end);
	merge(arr, start, mid, end);
}

int check_ok(TYPE *arr, int n)
{
	int i;
	for (i=0; i<n-1; i++) {
		if (!PRE(arr[i], arr[i+1])) break;
	}
	if (i == n-1) return 1;
	else return 0;
}

int main()
{
	TYPE x[N];
	srand(time(NULL));
	int i;
	for (i=0; i<N; i++) {
		x[i] = (TYPE)rand();
	}

	mergesort(x, 0, N);
/*	for (i=0; i<N; i++) {
		printf("%lu ", x[i]);
	}
	printf("\n");
*/
	if (check_ok(x, N)) printf("Good!\n");
	else printf("Bad\n");
	return 0;
}

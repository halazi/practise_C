#include <string.h>
#include "mergesort.h"

static void merge(void *arr, int elt_size, int start, int mid, int end, int (*cmp)(const void *, const void *))
{
	void *tmp = calloc(end-start, elt_size);
	memcpy(tmp, arr+start*elt_size, (end-start)*elt_size);
	int tmid = mid - start;
	int tend = end - start;
	int p = 0;
	int q = tmid;
	int curr = start;
	while (1) {
		if (p < tmid && q < tend) {
			if ((*cmp)(tmp+p*elt_size, tmp+q*elt_size) < 0) {
				memcpy(arr+curr, tmp+p, elt_size);
				p += elt_size;
				curr += elt_size;
			} else {
				memcpy(arr+curr, tmp+q, elt_size);
				q += elt_size;
				curr += elt_size;
			}
		} else {
			if (p == tmid) {
				memcpy(arr+curr, tmp+q, (tend-q)*elt_size);
			} else {
				memcpy(arr+curr, tmp+p, (tmid-p)*elt_size);
			}
			break;
		}
	}
	free(tmp);
}

static void mergesort_helper(void *arr, int elt_size, int start, int end, int (*cmp)(const void *, const void *))
{
	int len = end - start;
	if (len <= 1) return;
	if (len == 2) {
		if ((*cmp)(arr+start*elt_size, arr+(start+1)*elt_size) < 0) {
			void *tmp = malloc(elt_size);
			memcpy(tmp, arr+start*elt_size, elt_size);
			memcpy(arr+start*elt_size, arr+(start+1)*elt_size, elt_size);
			memcpy(arr+(start+1)*elt_size, tmp, elt_size);
			free(tmp);
		}
		return;
	}
	int mid = len/2 + start;
	mergesort_helper(arr, elt_size, start, mid, cmp);
	mergesort_helper(arr, elt_size, mid, end, cmp);
	merge(arr, elt_size, start, mid, end, cmp);
}

void mergesort(void *arr, int len, int elt_size, int (*cmp)(const void *, const void *))
{
	mergesort_helper(arr, elt_size, 0, len, cmp);
}

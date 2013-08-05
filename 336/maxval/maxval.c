#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 10

int main()
{
	int s[N]; 
	int l[N], r[N];
	int i;
	srand(time(NULL));
START:
	for (i=0; i<N; i++) {
		s[i] = rand() % 20000 - 10000;
	}
	l[0] = s[0];
	int lmax[N] = {0};
	r[N-1] = s[N-1];
	int rmax[N] = {0};
	rmax[N-1] = N-1;
	for (i=1; i<N; i++) {
		if (l[i-1]>0) {
			l[i] = l[i-1] + s[i];
			lmax[i] = lmax[i-1];
		}
		else {
			l[i] = s[i];
			lmax[i] = i;
		}
	}
	for (i=N-2; i>=0; i--) {
		if (r[i+1]>0) {
			r[i] = r[i+1] + s[i];
			rmax[i] = rmax[i+1];
		}
		else {
			r[i] = s[i];
			rmax[i] = i;
		}
	}
	int max = -INT_MAX;
	int maxl = -1;
	int maxr = N;
	for (i=0; i<N-1; i++) {
		if (max < l[i]+r[i+1]) {
			max = l[i] + r[i+1];
			maxl = lmax[i];
			maxr = rmax[i+1];
		}
	}
	for (i=0; i<N; i++) {
		if (max < s[i]) {
			max = s[i];
			maxl = i;
			maxr = i;
		}
	}
	//printf("val = %d, left = %d, right =  %d\n", max, maxl, maxr);

	int j, k;
	int vmax = -INT_MAX;
	int vmaxl = -1;
	int vmaxr = N;
	for (i=0; i<N; i++) {
		for (j=i; j<N; j++) {
			int sum = 0;
			for (k=i; k<=j; k++) {
				sum = sum + s[k];
			}
			if (vmax < sum) {
				vmax = sum;
				vmaxl = i;
				vmaxr = j;
			}
		}
	}
	//printf("verified_val = %d, left = %d, right =  %d\n", vmax, vmaxl, vmaxr);
//	for (i=0; i<N; i++) {
//		printf("%d ", s[i]);
//	}
//	printf("\n");
	if (max == vmax && maxl == vmaxl && maxr == vmaxr) {
		//printf("Verify OK!\n");
		goto START;
	} else {
		for (i=0; i<N; i++) {
			printf("%d ", s[i]);
		}
		printf("\n");
		if (max == vmax) {
			printf("Max Value = %d\n", max);
			printf("maxl = %d, maxr = %d\n", maxl, maxr);
			printf("vmaxl = %d, vmaxr = %d\n", vmaxl, vmaxr);
			goto START;
		} else {
			printf("Verify Failed!!!");
			printf("max = %d, maxl = %d, maxr = %d\n", max, maxl, maxr);
			printf("vmax = %d, vmaxl = %d, vmaxr = %d\n", vmax, vmaxl, vmaxr);
		}
	}

	return 0;
}

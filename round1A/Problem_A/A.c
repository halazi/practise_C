#include <stdio.h>
#include <math.h>

typedef unsigned long ulong;

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	int count = 0;
	fscanf(fin, "%d", &count);
	int i;
	ulong r, t;
	ulong x;
	ulong up, down;
	for (i=0; i<count; i++) {
		fscanf(fin, "%lu%lu", &r, &t);
		x = (r<<1) - 1;
		up = (ulong)ceil(t*1.0/x);
		if (x > 1e9) {
		//	if (x > 2*sqrt(2)*t) {
	  	//		down = (ulong)floor(t*1.0/sqrt(2)/x);
		//	} else {
	  	//		down = (ulong)floor(sqrt(t)*4.0);
		//	}
			down = 1;
		} else {
	  		down = (ulong)floor(t*1.0/sqrt(x*x+8*t));
		}
		ulong k = up/2 + down/2;
//		int flag = 0;
		while (1) {
//			printf("down=%lu,up=%lu,k=%lu,#=%d\n", down, up, k, i+1);
			if (down + 1 >= up) break;
			//if (down + 8 > up) break;
			if ((((k+r)<<1)-1) <= (ulong)floor(t*1.0/k + 0.001)) {
				   	if ((((k+r+1)<<1)-1) > (ulong)ceil(t*1.0/(k+1) - 0.001)) {
						//flag = 1;
						break;
					}
					else {
						down = k;
						k = (down + up)/2;
					}
			} else {
				up = k;
				k = (down + up)/2;
			}
		}
		fprintf(fout, "Case #%d: %lu", i+1, k);
/*		else {
			ulong j=down;
			for (; j<=up; j++) {
				if (((((k+r)<<1)-1) <= (ulong)floor(t*1.0/k + 0.001)) && ((((k+r+1)<<1)-1) < (ulong)ceil(t*1.0/(k+1) - 0.001))) {
					fprintf(fout, "Case #%d: %lu", i+1, k);
					break;
				}
			}
		} */
		if (i != count-1) fprintf(fout, "\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

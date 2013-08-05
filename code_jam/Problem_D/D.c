#include <stdio.h>

#define NUM_KEY 400

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	int count;
	fscanf(fin, "%d", &count);
	int i;
	int k, n;
	int start[NUM_KEY];
	for (i=1; i<=count; i++) {
		fscanf(fin, "%d%d", &k, &n);
		int j;
		for (j=0; j<k; j++) fscanf(fin, "%d", start+j);
	}
	return 0;
}

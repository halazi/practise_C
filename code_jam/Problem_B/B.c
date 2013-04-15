#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
	char height;
	char row;
	char col;
}Lawn;

int compare(const void *pa, const void *pb)
{
	char a = ((Lawn *)pa)->height;
	char b = ((Lawn *)pb)->height;
	return b-a;
}

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	int count;
	char tmp;
	fscanf(fin, "%d%c", &count, &tmp);
	int i;
	int n, m;
	Lawn lawn[MAX*MAX];
	char row[MAX], col[MAX];
	for (i=1; i<=count; i++) {
		fscanf(fin, "%d%d", &n, &m);
		int j, k;
		for (j=0; j<n; j++) {
			for (k=0; k<m; k++) {
				int t = j*m + k;
				int height;
				fscanf(fin, "%d", &height);
				lawn[t].height = (char)height;
				lawn[t].row = j;
				lawn[t].col = k;
			}
		}
		qsort(lawn, n*m, sizeof(Lawn), compare);
		for (j=0; j<n*m; j++) {
			row[j] = 0;
			col[j] = 0;
		}	
		for (j=0; j<n*m; j++) {
			int r = lawn[j].row;
			int c = lawn[j].col;
			int h = lawn[j].height;
			if (!row[r] && !col[c]) {
				row[r] = h;
				col[c] = h;
			} else if (!row[r]) {
				row[r] = h;
			} else if (!col[c]) {
				col[c] = h;
			} else if (col[c] != h && row[r] != h) {
				break;
			}
		}
		if (j == n*m) {
			fprintf(fout, "Case #%d: YES", i);
		} else {
			fprintf(fout, "Case #%d: NO", i);
		}
		if (i != count) fprintf(fout, "\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

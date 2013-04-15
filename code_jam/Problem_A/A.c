#include <stdio.h>

typedef unsigned int uint;

int main(int argc, char *argv[])
{
	uint test[10] = {0xf000, 0x0f00, 0x00f0, 0x000f, 0x1111, 0x2222, 0x4444, 0x8888, 0x8421, 0x1248};

	FILE *fin, *fout;
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	int count = 0;
	char tmp;
	fscanf(fin, "%d%c", &count, &tmp);
	int i;
	char c[16], tmp1, tmp2;
	uint x, o;
	for (i=1; i<=count; i++) {
		fscanf(fin, "%c%c%c%c%c", c, c+1, c+2, c+3, &tmp1);
		fscanf(fin, "%c%c%c%c%c", c+4, c+5, c+6, c+7, &tmp1);
		fscanf(fin, "%c%c%c%c%c", c+8, c+9, c+10, c+11, &tmp1);
		fscanf(fin, "%c%c%c%c%c%c", c+12, c+13, c+14, c+15, &tmp1, &tmp2);
		fprintf(fout, "Case #%d: ", i);
		x = 0;
		o = 0;
		int j, full = 1;
		for (j=0; j<16; j++) {
			switch (c[j]) {
				case 'X':
					x |= 1<<j;
					break;
				case 'O':
					o |= 1<<j;
					break;
				case 'T':
					x |= 1<<j;
					o |= 1<<j;
					break;
				case '.':
					full = 0;
					break;
			}
		}
		for (j=0; j<10; j++) {
			if ((x & test[j]) == test[j]) {
				fprintf(fout, "X won");
				break;
			}
			if ((o & test[j]) == test[j]) {
				fprintf(fout, "O won");
				break;
			}
		}
		if (j == 10) {
			if (full) {
				fprintf(fout, "Draw");
			} else {
				fprintf(fout, "Game has not completed");
			}
		}
		if (i<count) fprintf(fout, "\n");
	}
	fclose(fin);
	fclose(fout);
}

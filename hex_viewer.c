#include <stdio.h>

main(char argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	int c;
	int l = 0;
	printf("%d \t", l);
	int i = 0;
	while ((c = fgetc(fp)) != EOF) {
		printf("%02X ", c);
		i++;
		if (i % 16 == 0) {
			l++;
			printf("\n%d \t", l);
		}
	}
}

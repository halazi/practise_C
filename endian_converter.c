#include <stdio.h>
#include <string.h>

int main(char argc, char *argv[])
{
	if (argc == 1) {
		printf("Please specify the file to convert.\n");
		return 1;
	}
	
	char out_file_name[128];
	if (argc == 2) {
		strcat(strcpy(out_file_name, argv[1]), ".new.txt");
	} else {
		strcpy(out_file_name, argv[2]);
	}

	FILE *fin, *fout;
	fin = fopen(argv[1], "r");
	fout = fopen(out_file_name, "w");
	int tc1 = fgetc(fin);
	int tc2 = fgetc(fin);
	char c1, c2;
	while (tc1 != EOF && tc2 != EOF) {
		c1 = (char)tc1;
		c2 = (char)tc2;
		fprintf(fout, "%c%c", c2, c1);
		tc1 = fgetc(fin);
		tc2 = fgetc(fin);
	}
	if (tc1 == EOF && tc2 == EOF) {
		fclose(fout);
		printf("Successful!\n");
		return 0;
	} else {
		fclose(fout);
		printf("Error: odd number of characters.\n");
		return 2;
	}
}

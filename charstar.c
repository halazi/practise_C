#include <stdio.h>
int main()
{
	char *s = "abcde";
	char cs[] = "edcba";
	s = cs;
	printf("%s", s);
}

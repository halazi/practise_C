#include <stdio.h>
#include <limits.h>

int main()
{
	printf("__WORDSIZE \t= %d\n\n", __WORDSIZE);
	printf("SHRT_MAX \t= %u \t(%x)\n", SHRT_MAX, SHRT_MAX);
	printf("USHRT_MAX \t= %u \t(%x)\n\n", USHRT_MAX, USHRT_MAX);
	printf("INT_MAX \t= %u \t(%x)\n", INT_MAX, INT_MAX);
	printf("UINT_MAX \t= %u \t(%x)\n\n", UINT_MAX, UINT_MAX);
	printf("LONG_MAX \t= %lu \t(%lx)\n", LONG_MAX, LONG_MAX);
	printf("ULONG_MAX \t= %lu \t(%lx)\n\n", ULONG_MAX, ULONG_MAX);
	printf("LLONG_MAX \t= %llu \t(%llx)\n", LLONG_MAX, LLONG_MAX);
	printf("ULLONG_MAX \t= %llu \t(%llx)\n", ULLONG_MAX, ULLONG_MAX);
	printf("\"long long\" is the same as \"long\"\n");
	return 0;
}

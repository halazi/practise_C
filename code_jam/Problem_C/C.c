#include <stdio.h>
#include <math.h>

#define MAX 15

typedef unsigned long ulong;

ulong Convert(int *arr, int n)
{
	int i;
	ulong ret = arr[n];
	for (i=n-1; i>=0; i--) {
		ret = ret * 10 + arr[i];
	}
	return ret;
}

ulong FindPrev(ulong s)
{
	int arr[MAX];
	ulong ss = s;
	int i;
	for (i=0; i<MAX; i++) arr[i] = 0;
	for (i=0; i<MAX; i++) {
		arr[i] = ss % 10;
		ss /= 10;
		if (ss == 0) break;
	}
	if (i % 2 == 0) { // odd
		if (i == 0) return s-1;
		int b = i/2 + 1;
		for (; b<=i; b++) {
			if (arr[b] != arr[i-b]) break;
		}
		if (b == i+1) {
			if (arr[i/2] != 0) {
				arr[i/2]--;
				return Convert(arr, i);
			} else {
				int k=1;
				while (arr[i/2+k] == 0) k++;
				arr[i/2+k]--;
				int m = k-1;
				for (; m>=0; m--) arr[i/2+m] = 9;
				for (m=i/2+1; m<=i; m++) arr[i-m] = arr[m];
				if (arr[i/2+k] == 0) return Convert(arr, i-1) + 9;
				else return Convert(arr, i);
			}
		} else {
			int j;
			if (arr[b] < arr[i-b]) {
				for (j=b; j<=i; j++) arr[i-j] = arr[j];
				return Convert(arr, i);
			} else {
				if (arr[i/2] != 0) {
					arr[i/2]--;
					for (j=b; j<=i; j++) arr[i-j] = arr[j];
					return Convert(arr, i);
				} else {
					int k=1;
					while (arr[i/2+k] == 0) k++;
					arr[i/2+k]--;
					k--;
					for (; k>=0; k--) arr[i/2+k] = 9;
					for (k=i/2+1; k<=i; k++) arr[i-k] = arr[k];
					return Convert(arr, i);
				}
			}
		}
	} else { // even
		int b = i/2 + 1;
		for (; b<=i; b++) {
			if (arr[b] != arr[i-b]) break;
		}
		//printf("i=%d, b=%d\n", i, b);
		if (b == i+1) {
			if (arr[i/2] != 0) {
				arr[i/2]--;
				arr[i/2+1]--;
				ulong tmp = Convert(arr, i);
				if (tmp == 0) return 9;
				else return tmp;
			} else {
				int k=1;
				while (arr[i/2+k] == 0) k++;
				arr[i/2+k]--;
				//printf("a[i/2+k]=a[%d/2+%d]=a[%d]=%d\n", i, k, i/2+k, arr[i/2+k]);
				int m = k-1;
				for (; m>0; m--) arr[i/2+m] = 9;
				for (m=i/2+1; m<=i; m++) arr[i-m] = arr[m];
				if (arr[i/2+k] == 0) return Convert(arr, i-1) + 9;
				else return Convert(arr, i);
			}
		} else {
			int j;
			if (arr[b] < arr[i-b]) {
				for (j=b; j<=i; j++) arr[i-j] = arr[j];
				return Convert(arr, i);
			} else {
				if (arr[i/2+1] != 0) {
					arr[i/2+1]--;
					arr[i/2] = arr[i/2+1];
					for (j=b; j<=i; j++) arr[i-j] = arr[j];
					ulong tmp = Convert(arr, i);
					if (tmp == 0) return 9;
					else return tmp;
				} else {
					int k=1;
					while (arr[i/2+k] == 0) k++;
					arr[i/2+k]--;
					k--;
					for (; k>0; k--) arr[i/2+k] = 9;
					for (k=i/2+1; k<=i; k++) arr[i-k] = arr[k];
					return Convert(arr, i);
				}
			}
		}
	}
}

ulong FindNext(ulong s)
{
	int arr[MAX];
	ulong ss = s;
	int i;
	for (i=0; i<MAX; i++) arr[i] = 0;
	for (i=0; i<MAX; i++) {
		arr[i] = ss % 10;
		ss /= 10;
		if (ss == 0) break;
	}
//printf("[](%ld)=", s);
//int t;
//for (t=MAX-1; t>=0; t--) printf("%d", arr[t]);
//printf("\n");
//printf("i=%d\n", i);
	if (i % 2 == 0) { // odd
		if (i == 0) {
			if (s<9) return s+1;
			else return 11;
		}	
		int b = i/2 + 1;
		for (; b<=i; b++) {
			if (arr[b] != arr[i-b]) break;
		}
		if (b == i+1) {
			if (arr[i/2] != 9) {
				arr[i/2]++;
				return Convert(arr, i);
			} else {
				int k=1;
				while (arr[i/2+k] == 9) k++;
				arr[i/2+k]++;
				int m = k-1;
				for (; m>=0; m--) arr[i/2+m] = 0;
				for (m=i/2+1; m<=i; m++) arr[i-m] = arr[m];
				if (arr[i/2+k] == 1) return Convert(arr, i+1) + 1;
				else return Convert(arr, i);
			}
		} else {
			int j;
			if (arr[b] > arr[i-b]) {
				for (j=b; j<=i; j++) arr[i-j] = arr[j];
				return Convert(arr, i);
			} else {
				if (arr[i/2] != 9) {
					arr[i/2]++;
					for (j=b; j<=i; j++) arr[i-j] = arr[j];
					return Convert(arr, i);
				} else {
					int k=1;
					while (arr[i/2+k] == 9) k++;
					arr[i/2+k]++;
					k--;
					for (; k>=0; k--) arr[i/2+k] = 0;
					for (k=i/2+1; k<=i; k++) arr[i-k] = arr[k];
					return Convert(arr, i);
				}
			}
		}
	} else { // even
		int b = i/2 + 1;
		for (; b<=i; b++) {
			if (arr[b] != arr[i-b]) break;
		}
		if (b == i+1) {
			if (arr[i/2] != 9) {
				arr[i/2]++;
				arr[i/2+1]++;
				return Convert(arr, i);
			} else {
				int k=1;
				while (arr[i/2+k] == 9) k++;
				arr[i/2+k]++;
				int m = k-1;
				for (; m>0; m--) arr[i/2+m] = 0;
				for (m=i/2+1; m<=i; m++) arr[i-m] = arr[m];
				if (arr[i/2+k] == 1) return Convert(arr, i+1) + 1;
				else return Convert(arr, i);
			}
		} else {
			int j;
			if (arr[b] > arr[i-b]) {
				for (j=b; j<=i; j++) arr[i-j] = arr[j];
				return Convert(arr, i);
			} else {
				if (arr[i/2+1] != 9) {
					arr[i/2+1]++;
					arr[i/2] = arr[i/2+1];
					for (j=b; j<=i; j++) arr[i-j] = arr[j];
					return Convert(arr, i);
				} else {
					int k=1;
					while (arr[i/2+k] == 9) k++;
					arr[i/2+k]++;
					k--;
					for (; k>0; k--) arr[i/2+k] = 0;
					for (k=i/2+1; k<=i; k++) arr[i-k] = arr[k];
					return Convert(arr, i);
				}
			}
		}
	}
}

int Valid(ulong s)
{
	int arr[MAX];
	int i;
	for (i=0; i<MAX; i++) arr[i] = 0;
	for (i=0; i<MAX; i++) {
		arr[i] = s % 10;
		s /= 10;
		if (s == 0) break;
	}
	int j;
	for (j=0; j<=i/2; j++) {
		if (arr[j] != arr[i-j]) break;
	}
	if (j == i/2 + 1) return 1;
	else return 0;
}

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	int count;
	fscanf(fin, "%d", &count);
	int i;
	ulong s1, s2;
	ulong start, end;
	ulong r1, r2;
	ulong current;
	ulong sum;
	for (i=1; i<=count; i++) {
		fscanf(fin, "%ld%ld", &s1, &s2);
		start = FindNext(s1-1);
		end = FindPrev(s2+1);
		r1 = (ulong)ceil(sqrt(start));
		r2 = (ulong)floor(sqrt(end));
		//printf("s1=%ld, s2=%ld\nstart=%ld, end=%ld\nr1=%ld, r2=%ld\n", s1, s2, start, end, r1, r2);
		current = FindNext(r1-1);
		sum = 0;
		//printf("current=%ld, sum=%ld\n", current, sum);
		while (current <= r2) {
			if (Valid(current * current)) sum++;
			current = FindNext(current);
			//printf("current=%ld, sum=%ld\n", current, sum);
		}
		//printf("\n");
		fprintf(fout, "Case #%d: %ld", i, sum);
		if (i != count) fprintf(fout, "\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

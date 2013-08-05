#include <stdio.h>
#define N 4
int match(int m[N][N], int w[N][N])
{
	int engaged[N][N]; //=0 not engaged, =1 engaged
	int to_propose[N]; //next woman to propose, =5 means finished
	int free_m[N] = {1, 1, 1, 1}; //man and woman are all free initially
	int free_w[N] = {1, 1, 1, 1};
	memset((void *)engaged, 0, N*N*sizeof(int));
	memset(to_propose, 0, N*sizeof(int));
	while (1) {
		int man;
		for (man=0; man<N; man++) {
			if (free_m[man]) break;
		}
		if (man == N) break; //no free man now; alg terminate
		int woman = m[man][to_propose[man]++];
		if (free_w[woman]){
			engaged[man][woman] = 1;
			free_m[man] = 0;
			free_w[woman] = 0;
		} else {
			int engaged_man;
			for (engaged_man=0; engaged_man<N; engaged_man++) {
				if (engaged[engaged_man][woman]) break;
			}
			int i;
			int man_num, engaged_man_num;
			for (i=0; i<N; i++) {
				if (w[woman][i] == man) {
					man_num = i;
				}
				if (w[woman][i] == engaged_man) {
					engaged_man_num = i;
				}
			}
			if (man_num < engaged_man_num) {
				engaged[man][woman] = 1;
				engaged[engaged_man][woman] = 0;
				free_m[man] = 0;
				free_m[engaged_man] = 1;
			}
		}
	}
	printf("Engaged pairs:\n");
	int i;
	for (i=0; i<N; i++) {
		int j;
		for (j=0; j<N; j++) {
			if (engaged[i][j]) {
				printf("%d --> %d\n", i, j);
				break;
			}
		}
	}
	return 0;
}

int main()
{
	// preference list for each man and woman
	int m[N][N] = {	{0,1,2,3},
					{0,1,2,3},
					{0,1,2,3},
					{0,2,1,3}}; 
	int w[N][N] = {	{0,1,2,3},
					{0,3,1,2},
					{2,3,0,1},
					{0,1,2,3}}; 
	int i;
	for (i=0; i<N; i++) {
		printf("man %d:\t\t", i);
		int j;
		for (j=0; j<N; j++) {
			printf(" %d", m[i][j]);
		}
		printf("\n");
	}
	for (i=0; i<N; i++) {
		printf("woman %d:\t", i);
		int j;
		for (j=0; j<N; j++) {
			printf(" %d", w[i][j]);
		}
		printf("\n");
	}
	match(m,w);
	return 0;
}

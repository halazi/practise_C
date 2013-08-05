#include <stdio.h>

#define NUM_T 4 
#define NUM_P 7

typedef struct {
	int pre[NUM_P];
	int post[NUM_P];
} Trans_t;

Trans_t trans[NUM_T] = {
	{{1,0,0,0,0,0,0},{0,1,0,0,0,0,0}},
	{{0,1,1,1,0,0,0},{1,0,0,1,1,0,0}},
	{{0,0,0,1,1,1,0},{0,0,1,1,0,0,1}},
	{{0,0,0,0,0,0,1},{0,0,0,0,0,1,0}}
};

int current[NUM_P] = {1,0,3,1,0,1,0};

int pre_satisfy(int n_trans)
{
	int i;
	for (i=0; i<NUM_P; i++) {
		if (trans[n_trans].pre[i] > current[i]) break;
	}
	if (i == NUM_P) return 1;
	else return 0;
}

void transit(int n_trans)
{
	int i;
	for (i=0; i<NUM_P; i++) {
		current[i] += trans[n_trans].post[i] - trans[n_trans].pre[i];
	}
}

int main()
{
	int i=0, j;
	while (i<20) {
		for (j=0; j<NUM_T; j++) {
			if (pre_satisfy(j)) {
				transit(j);
				break;
			}
		}
		i++;
	}
	for (i=0; i<NUM_P; i++) {
		printf("P%d: %d\n", i+1, current[i]);
	}
	return 0;
}

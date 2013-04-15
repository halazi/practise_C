#include <stdio.h>
#define N 3

int m[N][N], w[N][N], e[N][N];
int e_new[N][N];

int match(int new)
{
	int to_propose[N] = {0, 0, 0}; //next woman to propose, =5 means finished
	int free_m[N] = {1, 1, 1}; //man and woman are all free initially
	int free_w[N] = {1, 1, 1};
	//memset((void *)e, 0, N*N*sizeof(int));
	if (new) {
		int i, j;
		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
				e_new[i][j] = 0;
			}
		}
		while (1) {
			int man;
			for (man=0; man<N; man++) {
				if (free_m[man]) break;
			}
			if (man == N) break; //no free man now; alg terminate
	//		printf("to_propose[%d] = %d\n", man, to_propose[man]);
			int woman = m[man][to_propose[man]++];
			if (free_w[woman]){
				e_new[man][woman] = 1;
				free_m[man] = 0;
				free_w[woman] = 0;
			} else {
				int engaged_man;
				for (engaged_man=0; engaged_man<N; engaged_man++) {
					if (e_new[engaged_man][woman]) break;
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
					e_new[man][woman] = 1;
					e_new[engaged_man][woman] = 0;
					free_m[man] = 0;
					free_m[engaged_man] = 1;
				}
			}
		}
	} else {
		int i, j;
		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
				e[i][j] = 0;
			}
		}
		while (1) {
			int man;
			for (man=0; man<N; man++) {
				if (free_m[man]) break;
			}
			if (man == N) break; //no free man now; alg terminate
	//		printf("to_propose[%d] = %d\n", man, to_propose[man]);
			int woman = m[man][to_propose[man]++];
			if (free_w[woman]){
				e[man][woman] = 1;
				free_m[man] = 0;
				free_w[woman] = 0;
			} else {
				int engaged_man;
				for (engaged_man=0; engaged_man<N; engaged_man++) {
					if (e[engaged_man][woman]) break;
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
					e[man][woman] = 1;
					e[engaged_man][woman] = 0;
					free_m[man] = 0;
					free_m[engaged_man] = 1;
				}
			}
		}
	}
	return 0;
}

int display(int new)
{
	int i;
	for (i=0; i<N; i++) {
		printf("m[%d]:\t", i);
		int j;
		for (j=0; j<N; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i=0; i<N; i++) {
		printf("w[%d]:\t", i);
		int j;
		for (j=0; j<N; j++) {
			printf("%d ", w[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i=0; i<N; i++) {
		printf("e[%d]:\t", i);
		int j;
		for (j=0; j<N; j++) {
			if (new) {
				printf("%d ", e_new[i][j]);
			} else {
				printf("%d ", e[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

int main()
{
	// preference list for each man and woman
	int a, b, a1, b1, a2, b2;
	for (a=0; a<N; a++) {
		m[0][0] = a;
		for (b=0; b<N; b++) {
			if (b == a) continue;
			m[0][1] = b;
			m[0][2] = 3-a-b;
			//printf("man 0: %d %d %d\n", m[0][0], m[0][1], m[0][2]);
			for (a1=0; a1<N; a1++) {
				m[1][0] = a1;
				for (b1=0; b1<N; b1++) {
					if (b1 == a1) continue;
					m[1][1] = b1;
					m[1][2] = 3-a1-b1;
					//printf("man 1: %d %d %d\n", m[1][0], m[1][1], m[1][2]);
					for (a2=0; a2<N; a2++) {
						m[2][0] = a2;
						for (b2=0; b2<N; b2++) {
							if (b2 == a2) continue;
							m[2][1] = b2;
							m[2][2] = 3-a2-b2;
							//printf("man 2: %d %d %d\n", m[2][0], m[2][1], m[2][2]);
							int x,y,x1,y1,x2,y2;
							for (x=0; x<N; x++) {
								w[0][0] = x;
								for (y=0; y<N; y++) {
									if (y == x) continue;
									w[0][1] = y;
									w[0][2] = 3-x-y;
									//printf("woman 0: %d %d %d\n", w[0][0], w[0][1], w[0][2]);
									for (x1=0; x1<N; x1++) {
										w[1][0] = x1;
										for (y1=0; y1<N; y1++) {
											if (y1 == x1) continue;
											w[1][1] = y1;
											w[1][2] = 3-x1-y1;
											//printf("woman 1: %d %d %d\n", w[1][0], w[1][1], w[1][2]);
											for (x2=0; x2<N; x2++) {
												w[2][0] = x2;
												for (y2=0; y2<N; y2++) {
													if (y2 == x2) continue;
													w[2][1] = y2;
													w[2][2] = 3-x2-y2;
													//printf("woman 2: %d %d %d\n", w[2][0], w[2][1], w[2][2]);
													match(0);
													int woman;
													for (woman=0; woman<N; woman++) {
														if (!e[w[woman][0]][woman]) {
															int tmp = w[woman][1];
															w[woman][1] = w[woman][2];
															w[woman][2] = tmp;
															match(1);
															int disp = 0;
															if (e_new[w[woman][0]][woman]) {
																printf("Find it!\n");
																printf("New:\n");
																display(1);
																printf("\n");
																disp = 1;
															} else {
																printf("-");
															}
															w[woman][2] = w[woman][1];
															w[woman][1] = tmp;
															if (disp) {
																match(0);
																printf("Old:\n");
																display(0);
																printf("\n\n");
																//goto end;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
end:	return 0;
}

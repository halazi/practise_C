#include <stdio.h>
#define N 4
int match(int m[N][N], int w[N][N], int engaged[N][N])
{
	int to_propose[N] = {0, 0, 0, 0}; //next woman to propose, =5 means finished
	int free_m[N] = {1, 1, 1, 1}; //man and woman are all free initially
	int free_w[N] = {1, 1, 1, 1};
	memset((void *)engaged, 0, N*N*sizeof(int));
	while (1) {
		int man;
		for (man=0; man<N; man++) {
			if (free_m[man]) break;
		}
		if (man == N) break; //no free man now; alg terminate
//		printf("to_propose[%d] = %d\n", man, to_propose[man]);
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
	return 0;
}

int display(int m[N][N], int w[N][N], int e[N][N])
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
	for (i=0; i<N; i++) {
		printf("w[%d]:\t", i);
		int j;
		for (j=0; j<N; j++) {
			printf("%d ", w[i][j]);
		}
		printf("\n");
	}
	for (i=0; i<N; i++) {
		printf("e[%d]:\t", i);
		int j;
		for (j=0; j<N; j++) {
			printf("%d ", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	// preference list for each man and woman
	int m[N][N];
	int w[N][N];
	int e[N][N];
	int a, b, c, a1, b1, c1, a2, b2, c2, a3, b3, c3;
	for (a=0; a<N; a++) {
		m[0][0] = a;
		for (b=0; b<N; b++) {
			if (b == a) continue;
			m[0][1] = b;
			for (c=0; c<N; c++) {
				if (c == b || c == a) continue;
				m[0][2] = c;
				m[0][3] = 6-a-b-c;
				//printf("man 0: %d %d %d %d\n", m[0][0], m[0][1], m[0][2], m[0][3]);
				for (a1=0; a1<N; a1++) {
					m[1][0] = a1;
					for (b1=0; b1<N; b1++) {
						if (b1 == a1) continue;
						m[1][1] = b1;
						for (c1=0; c1<N; c1++) {
							if (c1 == b1 || c1 == a1) continue;
							m[1][2] = c1;
							m[1][3] = 6-a1-b1-c1;
							//printf("man 1: %d %d %d %d\n", m[1][0], m[1][1], m[1][2], m[1][3]);
							for (a2=0; a2<N; a2++) {
								m[2][0] = a2;
								for (b2=0; b2<N; b2++) {
									if (b2 == a2) continue;
									m[2][1] = b2;
									for (c2=0; c2<N; c2++) {
										if (c2 == b2 || c2 == a2) continue;
										m[2][2] = c2;
										m[2][3] = 6-a2-b2-c2;
										//printf("man 2: %d %d %d %d\n", m[2][0], m[2][1], m[2][2], m[2][3]);
										for (a3=0; a3<N; a3++) {
											m[3][0] = a3;
											for (b3=0; b3<N; b3++) {
												if (b3 == a3) continue;
												m[3][1] = b3;
												for (c3=0; c3<N; c3++) {
													if (c3 == b3 || c3 == a3) continue;
													m[3][2] = c3;
													m[3][3] = 6-a3-b3-c3;
													//printf("man 3: %d %d %d %d\n", m[3][0], m[3][1], m[3][2], m[3][3]);
													int x,y,z,x1,y1,z1,x2,y2,z2,x3,y3,z3;
													for (x=0; x<N; x++) {
														w[0][0] = x;
														for (y=0; y<N; y++) {
															if (y == x) continue;
															w[0][1] = y;
															for (z=0; z<N; z++) {
																if (z == x || z == y) continue;
																w[0][2] = z;
																w[0][3] = 6-x-y-z;
																//printf("woman 0: %d %d %d %d\n", w[0][0], w[0][1], w[0][2], w[0][3]);
																for (x1=0; x1<N; x1++) {
																	w[1][0] = x1;
																	for (y1=0; y1<N; y1++) {
																		if (y1 == x1) continue;
																		w[1][1] = y1;
																		for (z1=0; z1<N; z1++) {
																			if (z1 == x1 || z1 == y1) continue;
																			w[1][2] = z1;
																			w[1][3] = 6-x1-y1-z1;
																			//printf("woman 1: %d %d %d %d\n", w[1][0], w[1][1], w[1][2], w[1][3]);
																			for (x2=0; x2<N; x2++) {
																				w[2][0] = x2;
																				for (y2=0; y2<N; y2++) {
																					if (y2 == x2) continue;
																					w[2][1] = y2;
																					for (z2=0; z2<N; z2++) {
																						if (z2 == x2 || z2 == y2) continue;
																						w[2][2] = z2;
																						w[2][3] = 6-x2-y2-z2;
																						//printf("woman 2: %d %d %d %d\n", w[2][0], w[2][1], w[2][2], w[2][3]);
																						for (x3=0; x3<N; x3++) {
																							w[3][0] = x3;
																							for (y3=0; y3<N; y3++) {
																								if (y3 == x3) continue;
																								w[3][1] = y3;
																								for (z3=0; z3<N; z3++) {
																									if (z3 == x3 || z3 == y3) continue;
																									w[3][2] = z3;
																									w[3][3] = 6-x3-y3-z3;
																									//printf("woman 3: %d %d %d %d\n", w[3][0], w[3][1], w[3][2], w[3][3]);
																									match(m,w,e);
																									int woman;
																									for (woman=0; woman<N; woman++) {
																										if (e[w[woman][1]][woman]) {
																											int tmp = w[woman][2];
																											w[woman][2] = w[woman][3];
																											w[woman][3] = tmp;
																											int e_new[N][N];
																											match(m,w,e_new);
																											int disp = 0;
																											if (e_new[w[woman][0]][woman]) {
																												printf("Find it!\n");
																												printf("New:\n");
																												display(m,w,e_new);
																												disp = 1;
																											}
																											w[woman][3] = w[woman][2];
																											w[woman][2] = tmp;
																											if (disp) {
																												printf("Old:\n");
																												display(m,w,e);
																												goto end;
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ITEMS 6
int main(int argc, char *argv[]) {
	int i,j, m, n;


	printf("enter row til -1-->");
	scanf("%d", &m);
	printf("enter col til -1-->");
	scanf("%d", &n); //
	srand(time(NULL));
	int cnt;
	int *nu = (int*)malloc(m * n * sizeof(int));
	for (i = 0; i < m * n; i++) *(nu + i) = 0;
	while (n != -1 && m != -1) {
		printf("enter nonvals-->");
		scanf("%d", &cnt);
		int i1, j1;
		int *com = (int*)malloc((cnt + 1) * 3 * sizeof(int)), ind = 0;
		for (i = 0; i < (cnt + 1) * 3; i++) *(com + i) = 0;
		*(com + ind) = m;
		ind++;
		*(com + ind) = n;
		ind++;
		*(com + ind) = cnt;
		ind++;
		printf("RANDOM VALS array \n");
		for (i = 0; i < (cnt + 1) * 3; i += 3) printf("%d %d %5d\n", *(com + i), *(com + i + 1), *(com + i + 2));
		for (i = 0; i < cnt; i++) {
			i1 = rand() % m;
			j1 = rand() % n;
			*(nu + i1 * n + j1) = rand() % 20 + 1;
			printf("(%d,%d) produce-->%d\n", i1, j1, *(nu + i1 * n + j1));
		}

		printf("array\n");
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) printf("%5d\t", *(nu + i * n + j));
			printf("\n");
		}

		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++) {
				if (*(nu + i * n + j) != 0) {
					*(com + ind) = i;
					ind++;
					*(com + ind) = j;
					ind++;
					*(com + ind) = *(nu + i * n + j);
					ind++;
				}
			}

		printf("compressed \n");
		for (i = 0; i < (cnt + 1) * 3; i += 3) printf("%d %d %d\n", *(com + i), *(com + i + 1), * (com + i + 2));
		free(nu);
		free (com);
		printf("enter row til -1-->");
		scanf("%d", &m);
		printf("enter col til -1-->");
		scanf("%d", &n);
		nu = (int *)malloc(m * n * sizeof(int));
		for (i = 0; i < m * n; i++) *(nu + i) = 0;
	}
	return 0;
}


/*
enter row til -1-->15
enter col til -1-->15
enter nonvals-->8
RANDOM VALS array
15 15     8
0 0     0
0 0     0
0 0     0
0 0     0
0 0     0
0 0     0
0 0     0
0 0     0
(8,2) produce-->15
(14,14) produce-->18
(5,1) produce-->12
(2,0) produce-->18
(7,3) produce-->4
(2,7) produce-->14
(4,2) produce-->5
(13,3) produce-->15
array
0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
18       0       0       0       0       0       0      14       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
0       0       5       0       0       0       0       0       0       0       0       0       0       0       0
0      12       0       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0       4       0       0       0       0       0       0       0       0       0       0       0
0       0      15       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0      15       0       0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       0       0       0       0      18
compressed
15 15 8
2 0 18
2 7 14
4 2 5
5 1 12
7 3 4
8 2 15
13 3 15
14 14 18
*/

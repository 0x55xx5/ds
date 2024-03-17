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
		printf("compressed array \n");
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

enter row til -1-->3
enter col til -1-->3
enter non-val-->4
array is
2
7
0
6
0
1
0
0
0
compressed
3 3 4
0 0 2
0 1 7
1 0 6
1 2 1

*/

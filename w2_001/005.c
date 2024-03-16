#include <stdio.h>

#include <stdlib.h>


int main(int argc, char *argv[]) {


	int i, n, m, j, s;
	printf("how many stus?(-1 exit):-->");
	scanf("%d", &n);
	printf("enter sub til -1 -->");
	scanf("%d", &m);
	srand(time(NULL));
	int stu[n][m+2]; //int stu[n][m+2];
	while (n != -1 && m != -1) {
		for (i = 0; i < m; i++) {
			printf("SCORE %1d ", i + 1);
			printf("AVG RANK\n");
		}
		for (i = 0; i < n; i++) {
			for (j = 0, s = 0; j < m; j++) {
				s += stu[i][j] = rand() % 101;
				printf("%5d ", stu[i][j]);
			}
			stu[i][m] = (int)s / m;
			stu[i][m + 1] = 1;
			printf("%5d %5d\n", stu[i][m], stu[i][m + 1]);
		}


		for (i = 0; i < n; i++) { //rangking
			for (j = i + 1; j < n; j++) {
				if (stu[i][m] > stu[j][m]) stu[j][m + 1]++;
				else if (stu[i][m] < stu[j][m]) stu[i][m + 1]++;
			}

		}
		for (i = 0; i < m; i++ ) {
			printf("SCORE %1d ", i + 1);
			printf("AVG RANK\n");
		}
		for (i = 0; i < n; i++) {
			for (j = 0, s = 0; j < m + 2; j++) {
				printf("%1d ", stu[i][j]);
				printf("\n");
			}
		}
		
		printf("how many stus?(-1 exit)-->");
		scanf("%d", &n);
		printf("enter sub til -1-->");
		scanf("%d", &m);
	}
	return 0;

}
/*
how many stus?(-1 exit):-->2
enter sub til -1 -->2
SCORE 1 AVG RANK
SCORE 2 AVG RANK
32    77    54     1
64    55    59     1
SCORE 1 AVG RANK
SCORE 2 AVG RANK
32
77
54
2
64
55
59
1
how many stus?(-1 exit)-->



*/

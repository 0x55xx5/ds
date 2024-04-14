#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input Loop */
int main(int argc, char *argv[]) {

	int i, n, m, j, s;

	int k1, k2, pt;
	printf("enter num til -1-->");
	scanf("%d", &n);
	printf("enter subs-1-->");
	scanf("%d", &m);
	int *stu1 = (int *)malloc(sizeof(int) * n * (m + 2)), *ptr;
	ptr = stu1;
	srand(time(NULL));
	while (n != -1 && m != -1) {
		for (i = 0; i < m; i++ ) {
			printf("Score%1d ", i + 1);
			printf("avg 		rank\n");
		}
		for (i = 0; i < n; i++) {
			for (j = 0, s = 0; j < m; j++) {
				k1 = i * (m + 2) + j;
				s += *(stu1 + k1) = rand() % 101;
				printf("%5d ", *(stu1 + k1));
			}
			pt = ++k1;
			*(stu1 + pt) = (int)s / m;
			k1++;
			*(stu1 + k1) = 1;
			printf("%5d %5d\n", *(stu1 + pt), *(stu1 + k1));
		}


		for (i = 0; i < n; i++) { //RANKING
			for (j = i + 1; j < n; j++) {
				k1 = m + (m + 2) * i;
				k2 = m + (m + 2) * j;
				if (*(ptr + k1) > *(ptr + k2)) *(ptr + k2 + 1) = *(ptr + k2 + 1) + 1;
				else if (*(ptr + k1) < * (ptr + k2)) *(ptr + k1 + 1) = *(ptr + k1 + 1) + 1;
			}
		}

		for (i = 0; i < m; i++ ){
			printf("Score%1d ", i + 1);
			printf("avg 		rank\n");
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m + 2; j++) {
				k1 = i * (m + 2) + j;
				printf("%5d ", *(stu1 + k1));
			}
			printf("\n");
		}
		free(stu1);
		printf("enter num til -1-->");
		scanf("%d", &n);
		printf("enter subs-1-->");
		scanf("%d", &m);
		stu1 = (int *)malloc(sizeof(int) * n * (m + 2));
		return 0;
	}
}
/**
  enter num til -1-->10
  enter subs-1-->2
  Score1 avg              rank
  Score2 avg              rank
  40    50    45     1
  1    77    39     1
  53    26    39     1
  42    54    48     1
  35    77    56     1
  70    16    43     1
  28    99    63     1
  25    50    37     1
  49    14    31     1
  25    77    51     1
  Score1 avg              rank
  Score2 avg              rank
  40    50    45     5
  1    77    39     7
  53    26    39     7
  42    54    48     4
  35    77    56     2
  70    16    43     6
  28    99    63     1
  25    50    37     9
  49    14    31    10
  25    77    51     3
  enter num til -1-->

 */
//1/10/11/12/13

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


		for (i = 0; i < n; i++) { //$4ALBER
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
  37    31    34     1
  12    63    37     1
  73    47    60     1
  41    61    51     1
  49    96    72     1
  55    17    36     1
  2    85    43     1
  90    70    80     1
  28     4    16     1
  92     5    48     1
  Score1 avg              rank
  Score2 avg              rank
  37    31    34     9
  12    63    37     7
  73    47    60     3
  41    61    51     4
  49    96    72     2
  55    17    36     8
  2    85    43     6
  90    70    80     1
  28     4    16    10
  92     5    48     5
  enter num til -1--> 
 */

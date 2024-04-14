#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ITEMS 6
int main(int argc, char *argv[]) {


	int A[3][3] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
	int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}}, C[3][3] = {0};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) C[i][j] = A[i][j] + B[i][j];
	printf("A matrix: \n");
	for (int i = 0; i < 3; i++) {
		printf(" | ");
		for (int j = 0; j < 3; j++) printf("%d\t", A[i][j]);
		printf("matrix A\n");
	}

	printf("B matrix: \n");
	for (int i = 0; i < 3; i++) {
		printf(" | ");
		for (int j = 0; j < 3; j++) printf("%d\t", B[i][j]);
		printf("matrix B\n");
	}

	printf("[A matrix+ B matrix]\n");
	for (int i = 0; i < 3; i++) {
		printf(" | ");
		for (int j = 0; j < 3; j++) printf("%d\t", C[i][j]);
		printf("matrix A+B result:\n");
	}

	return 0;
}
/*
A matrix:
| 1    3       5       matrix A
| 7    9       11      matrix A
| 13   15      17      matrix A
B matrix:
| 9    8       7       matrix B
| 6    5       4       matrix B
| 3    2       1       matrix B
[A matrix+ B matrix]
| 10   11      12      matrix A+B result:
| 13   14      15      matrix A+B result:
| 16   17      18      matrix A+B result:

--------------------------------
Process exited after 0.03462 seconds with return value 0 (0 ms cpu time, 3708 KB mem used).

Press ANY key to exit...
*/

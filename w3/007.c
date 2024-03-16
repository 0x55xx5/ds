#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ITEMS 6
/* run this program using the console pauser or add your own getch, system("pause") or input Loop */
void MatrixMultiply (int*, int*, int*, int, int, int);
void PrintPoly(int Poly[], int items);
void PolySum(int Poly1[ITEMS], int Poly2[ITEMS]);
int main(int argc, char *argv[]) {


	int A[3][3] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
	int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}}, C[3][3] = {0};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) C[i][j] = A[i][j] + B[i][j];
	printf("A matrix: \n");
	for (int i = 0; i < 3; i++) {
		printf(" | ");
		for (int j = 0; j < 3; j++) printf("%d\t", A[i][j]);
		printf("|\n");
	}

	printf("B matrix: \n");
	for (int i = 0; i < 3; i++) {
		printf(" | ");
		for (int j = 0; j < 3; j++) printf("%d\t", B[i][j]);
		printf("|\n");
	}

	printf("[A matrix+ B matrix]\n");
	for (int i = 0; i < 3; i++) {
		printf(" | ");
		for (int j = 0; j < 3; j++) printf("%d\t", C[i][j]);
		printf("|\n");
	}

	return 0;
}
/*

A matrix:
| 1    3       5       |
| 7    9       11      |
| 13   15      17      |
B matrix:
| 9    8       7       |
| 6    5       4       |
| 3    2       1       |
[A matrix+ B matrix]
| 10   11      12      |
| 13   14      15      |
| 16   17      18      |

--------------------------------
*/

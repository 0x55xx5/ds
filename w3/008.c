#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ITEMS 6
/* run this program using the console pauser or add your own getch, system("pause") or input Loop */
void MatrixMultiply (int*, int*, int*, int, int, int);
void PrintPoly(int Poly[], int items);
void PolySum(int Poly1[ITEMS], int Poly2[ITEMS]);
int main(int argc, char *argv[]) {
	int *A1, *B1, *C1;
	int M, N, P;
	printf("enter matrix A (M,N): \n");
	printf("M= ");
	scanf("%d", &M);
	printf("N= ");
	scanf("%d", &N);
	A1 = (int*)malloc(M * N * sizeof(int));
	printf("[請輸入矩陣A的各個元素]\n"); //指標二維矩陣
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			printf("a%d %d=", i, j);
			scanf("%d", &A1[i * N + j]);
		}
	printf("enter matrix B (N,P): ");
	printf("\nN= ");
	scanf("%d", &N);
	printf("P= ");
	scanf("%d", &P);
	B1 = (int*)malloc(N * P * sizeof(int));
	printf("[請輸入矩陣B的各個元素]\n"); //指標二維矩陣
	for (int i = 0; i < N; i++)
		for (int j = 0; j < P; j++) {
			printf("b%d %d=", i, j);
			scanf("%d", &B1[i * P + j]);
		}
	printf("A matrix : \n");
	for (int i = 0; i < M; i++) {
		printf(" | ");
		for (int j = 0; j < N; j++) printf("%d\t", A1[i * N + j]);
		printf("|\n");
	}
	printf("B matrix: \n");
	for (int i = 0; i < N; i++)
	{
		printf(" | ");
		for (int j = 0; j < P; j++) printf("%d\t", B1[i * P + j]);
		printf("|\n");
	}
	printf("[A]Multiply*[B]\n");
	C1 = (int*)malloc(M * P * sizeof(int)); //new array
	MatrixMultiply (A1, B1, C1, M, N, P); //result
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < P; j++) printf("%d\t", C1[i * P + j]);
		printf("\n");
	}
	return 0;
}

void PrintPoly(int Poly [], int items) {
	int i, MaxExp;
	MaxExp = Poly[0];
	for (i = 1; i <= Poly[0] + 1; i++) {
		MaxExp--;
		if (Poly[i] != 0) {
			if ((MaxExp + 1) != 0)
				printf("%dX^%d ", Poly[i], MaxExp + 1);
			else
				printf("%d", Poly[i]);
			if (MaxExp >= 0) printf("%c", '+');
		}
	}
	printf("\n");
}

void PolySum (int Poly1[ITEMS], int Poly2[ITEMS]) {
	int i, result[ITEMS];
	result[0] = Poly1[0];
	for (i = 1; i <= Poly1[0] + 1; i++) result[i] = Poly1[i] + Poly2[i]; /*#*#*/ PrintPoly(result, ITEMS);
}

void MatrixMultiply (int* arrA, int* arrB, int* arrC, int M, int N, int P) {
	int i, j, k, Temp;
	if (M <= 0 || N <= 0 || P <= 0) {
		printf("error M,N,P must great than  0\n");
		return;
	}
	for (i = 0; i < M; i++)
		for (j = 0; j < P; j++) {
			Temp = 0;
			for (k = 0; k < N; k++) Temp = Temp + arrA[i * N + k] * arrB[k * P + j];
			arrC[i * P + j] = Temp;
		}
}
/*
enter matrix A (M,N):
M= 3
N= 2
[請輸入矩陣A的各個元素]
a0 0=5
a0 1=4
a1 0=3
a1 1=6
a2 0=7
a2 1=8
enter matrix B (N,P):
N= 3
P= 2
[請輸入矩陣B的各個元素]
b0 0=3
b0 1=4
b1 0=5
b1 1=7
b2 0=3
b2 1=6
A matrix :
| 5    4       3       |
| 6    7       8       |
| -1637926414  134229809       3       |
B matrix:
| 3    4       |
| 5    7       |
| 3    6       |
[A]Multiply*[B]
44      66
77      121
*/

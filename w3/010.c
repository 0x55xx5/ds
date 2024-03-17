#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ITEMS 6
void MatrixMultiply (int*, int*, int*, int, int, int);
void PrintPoly(int Poly[], int items);
void PolySum(int Poly1[ITEMS], int Poly2[ITEMS]);
int main(int argc, char *argv[]) {


	int PolyA[ITEMS] = {4, 3, 7, 0, 6, 2};
	int PolyB[ITEMS] = {4, 1, 5, 2, 0, 9};
	printf("A=> ");
	PrintPoly (PolyA, ITEMS);
	printf("B=> ");
	PrintPoly(PolyB, ITEMS);
	printf("A+B =>");
	PolySum (PolyA, PolyB);
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



*/

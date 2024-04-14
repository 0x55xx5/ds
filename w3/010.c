#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ITEMS 6
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

/*

A=> 3X^4 +7X^3 +6X^1 +2
B=> 1X^4 +5X^3 +2X^2 +9
A+B =>4X^4 +12X^3 +2X^2 +6X^1 +11

*/

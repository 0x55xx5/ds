#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#define ITEMS 6
/* run this program using the console pauser or add your own getch, system("pause") or input Loop */
void MatrixMultiply (int*, int*, int*, int, int, int);
void PrintPoly(int Poly[], int items);
void PolySum(int Poly1[ITEMS], int Poly2[ITEMS]);
int main(int argc, char *argv[]) {
	int is, ie, js, je, ks, ke, ms, me, sta, addc, b, tr2, tc2, tr3, tc3, tr1, tc1, i, j, k, m, n;
	while (1) {
		printf("1D stert-->");
		scanf("%d", &is);
		printf("1D end-->");
		scanf("%d", &ie);
		printf("2d start-->");
		scanf("%d", &js);
		printf("2d end-->");
		scanf("%d", &je);
		printf("3d start-->");
		scanf("%d", &ks);
		printf("3d end-->");
		scanf("%d", &ke);
		printf("unit size-->");
		scanf("%d", &b);
		if (b == 0) break;
		printf("start at-->");
		scanf("%d", &sta);
		tr2 = (je - js + 1) * (ke - ks + 1);
		tc2 = (je - js + 1) * (ie - is + 1);
		printf("cal row-->");
		scanf("%d", &i);
		printf("cal col-->");
		scanf("%d", &j);
		printf("cal 3rd-->");
		scanf("%d", &k);
//row major
		addc = sta + ((i - is) * tr2 + (j - js) * (ke - ks + 1) + k - ks) * b;
		printf("[%d] [%d] [%d]addr  is %d\n", i, j, k, addc); //col major
		addc = sta + ((k - ks) * tc2 + (j - js) * (ie - is + 1) + i - is) * b;
		printf("[%d] [%d] [%d] addr is %d\n", i, j, k, addc);
	}
	
	return 0;
}

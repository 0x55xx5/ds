#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#define ITEMS 6
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
		printf("enter cal row-->");
		scanf("%d", &i);
		printf("enter cal col-->");
		scanf("%d", &j);
		printf("enter cal z-->");
		scanf("%d", &k);
		printf("[%d] [%d] [%d] addr is %d\n", i, j, k, addc);
	}

	return 0;
}

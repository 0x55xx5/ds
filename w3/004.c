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
/*
1D stert-->1
1D end-->3
2d start-->1
2d end-->4
3d start-->1
3d end-->5
unit size-->1
start at-->100
cal row-->1
cal col-->2
cal 3rd-->3
[1] [2] [3]addr  is 107
[1] [2] [3] addr is 127
1D stert-->

*/

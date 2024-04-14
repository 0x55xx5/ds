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
		printf("4d start-->");
		scanf("%d", &ms);
		printf("4d end-->");
		scanf("%d", &me);
		printf("unit size-->");
		scanf("%d", &b);
		if (b == 0) break;
		printf("start at-->");
		scanf("%d", &sta);
	////
		tr3=(je-js+1)*(ke-ks+1)*(me-ms+1); tr2=(me-ms+1)*(ke-ks+1); tc3=(ke-ks+1)*(je-js+1)*(ie-is+1); tc2=(je-js+1)*(ie-is+1); tr1=me-ms+1; tc1=ie-is+1; printf("tr3=%d tr2=%d tr1=%d tc3=%d tc2=%d tcl=%d\n",tr3, tr2, tr1, tc3, tc2, tc1);
		////
		
		printf("cal row-->");
		scanf("%d", &i);
		printf("cal col-->");
		scanf("%d", &j);
		printf("cal 3rd-->");
		scanf("%d", &k);
		printf("cal 4th-->");
		scanf("%d", &m);
//row major
		addc=sta+((i-is)*tr3+(j-js)*tr2+(k-ks)*tr1+m-ms)*b;
		printf("[%d][%d] [%d] [%d][2] at %d\n",i,j,k,m,addc);
//col major
		addc=sta+((m-ms)*tc3+(k-ks)*tc2+(j-js)*tc1+i-is)*b;
		printf("[%d][%d] [%d] [%d] at %d\n",i,j,k,m,addc); 
	}
	
	return 0;
}
/*
1D stert-->1
1D end-->4
2d start-->1
2d end-->6
3d start-->1
3d end-->5
4d start-->1
4d end-->3
unit size-->1
start at-->200
tr3=90 tr2=15 tr1=3 tc3=120 tc2=24 tcl=4
cal row-->3
cal col-->1
cal 3rd-->3
cal 4th-->1
[3][1] [3] [1][2] at 386
[3][1] [3] [1] at 250
1D stert-->
*/

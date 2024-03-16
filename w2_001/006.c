#include <stdio.h>

#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	
	
	int is, ie, js, je, sta, addc, b, tr, tc,i,j;
	printf("row start-->"); scanf("%d",&is);
	printf("row end-->"); scanf("%d",&ie);
	printf("col start end-->"); scanf("%d",&js);
	printf("col end -->"); scanf("%d", &je);
	
		printf("unit size-->"); scanf("%d",&b);
	while (b != 0) {
		printf("start at-->"); scanf("%d",&sta); tr=ie-is+1; tc=je-js+1;
		printf("[?][]-->"); scanf("%d",&i); printf("[][?]-->"); scanf("%d",&j);
//row major
		addc=sta+((i-is)*tc+j-js)*b;
		printf("[%d] [%d]row major addr %d\n",i,j, addc);
//col major
		addc=sta+((j-js)*tr+i-is)*b;
		printf("[%d] [%d]col major addr %d\n",i,j,addc);
	
		
		
		printf("row start-->"); scanf("%d",&is);
		printf("row end-->"); scanf("%d",&ie);
		printf("col start end-->"); scanf("%d",&js);
		printf("col end -->"); scanf("%d", &je);
	}
	return 0;
	
}

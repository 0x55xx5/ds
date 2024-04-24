#include <stdio.h>

#include <stdlib.h>


int main(int argc, char *argv[]) {


	int y = 5, *yp, i;
	yp = &y;
	printf("%d %d %p %p\n", y, *yp, &y, yp); //%p==>ADDRESS
	int a[15] = {5, 6, 7, 8, 9};
	printf("a of address p-->%p", a);
	printf("a[4] of address-->%p\n", &a[4]);
	for (i = 0; i < 5; i++)printf("%d ", a[i]);
	printf("\n");
	yp = a;
	for (i = 0; i < 5; i++)printf("%d ", *(yp + i));
	printf("\n");
	yp = &a[0];
	for (i = 0; i < 5; i++)printf("%d ", *(yp + i));
	printf("\n");

}
/*
5 5 000000a0507ffdbc 000000a0507ffdbc
a of address p-->000000a0507ffd80a[4] of address-->000000a0507ffd90
5 6 7 8 9
5 6 7 8 9
5 6 7 8 9

*/

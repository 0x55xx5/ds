
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input Loop */
int main(int argc, char *argv[]) {
	
	int a[3][5]={15*0}; int *p; p=&a[0][0];
	printf("a[0][0]addr-->%p %p==>",a, p);
	printf("a[2][3]addr-->%p,", (p+13));
	printf("a[2][3]addr-->%p\n",&a[2][3]);
	int arr[2][2], sum;
	printf("|al b1|\n|a2 b2|\n");
	printf("enter al:"); scanf("%d",&arr[0][0]);
	printf("enter b1:"); scanf("%d",&arr[0][1]); 
	printf("a2:"); scanf("%d",&arr[1][0]);
	printf("b2:"); scanf("%d",&arr[1][1]);
	sum = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];/* 求二街行列是*/
	printf("|%d 	%d|\n",arr[0][0],arr[0][1]);
	printf("|%d	%d|\n",arr[1][0],arr[1][1]); 
	printf("sum=%d\n",sum);
	return 0;
}

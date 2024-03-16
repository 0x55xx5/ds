
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float pow1(int x, int y) {
	float p = 1;
	int i;
	for (i = 1; i <= y; i++) p *= x;
	return p;
}

int main(int argc, char *argv[]) {
	int x, y;
	while (1) {
		printf("give me 2 number ?");
		scanf("%d %d", &x, &y);
		if(x == 0) 
			break;
		printf("%d^%d=%f\n", x, y, pow1(x, y));
		printf("%d^%d=%f\n", x, y, pow(x, y));
		return 0;
	}
	
}

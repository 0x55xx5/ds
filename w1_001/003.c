
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prime (int x1) {
	int i;
	for (i = 2; i < x1; i++) if (x1 % i == 0) return 1;
	return 0;
}

int prime1(int x1) {
	int i;
	int qq = (int) sqrt(x1);
	for (i = 2; i <= qq; i++) if (x1 % i == 0) return 1;
	return 0;
}

void all_p(int x1) {
	int i, j, m;
	for (i = 1; i <= x1; i++) {
		if (prime(i) == 0) printf("%d ", i);
	}
	printf("\n");
}
int main(int argc, char *argv[]) {
	int x;
	while (1) {
		printf("give me number ?");
		scanf("%d", &x);
		if (x == 0) break;
		if (prime(x) == 0) printf("%d is prime \n", x);
		else printf("%d not prime\n", x);
		if (prime1(x) == 0) printf("%d\n", x);
		else printf("%d\n", x);
		all_p(x);
	}
}


#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
	int a[10] = {1, 2, 3, 4}, *p, n, *p1;
	p = a;
	printf("%d %d\n", a[0], *p);
	p = a;
	printf("%p %p\n", &a[0], p);
	int i;
	for (i = 0; i < 10; i++) printf("%d ", a[i]);
	printf("\n");
	for (i = 0; i < 10; i++) printf("%d ", *(p + i));
	printf("\n");
	while (1) {
		printf("give me the SIZE-->");
		scanf("%d", &n);
		if (n == 0) break;
		p1 = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i++) {
			printf("index+1 of %d-->", i + 1);
			scanf("%d", p1 + i);
		}
	
		for (i = 0; i < n; i++) printf("%d ", *(p1 + i));
		printf("\n");
	}
	
	return 0;
}
/*
1 1
00000002d6fff9d0 00000002d6fff9d0
1 2 3 4 0 0 0 0 0 0
1 2 3 4 0 0 0 0 0 0
give me the SIZE-->


*/

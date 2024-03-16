
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input Loop */
int main(int argc, char *argv[]) {
	int x, r, n;
	while (1) {
		printf("give me number ?");
		scanf("%d", &x);
		if (x == -1) break;
		int p[x + 1][x + 1];
		for (int i = 0; i <= x; i++) {
			p[i][0] = 1;
			p[i][i] = 1;
			for (int j = 1; j < i; j++) 
			{
				p[i][j] = p[i - 1][j] + p[i - 1][j - 1];
				printf("%d ", p[i][j]);
					printf("\n");
			}

		}
		for (r = 0; r <= x; r++) {
			p[r][0] = 1;
			for (n = 1; n <= r; n++) p[r][n] = p[r][n - 1] * (r - n + 1) / n;
		}

		for (r = 0; r <= x; r++) {
			for (n = 0; n <= r; n++) printf("%d ", p[r][n]);
			printf("\n");
		}

	}
}

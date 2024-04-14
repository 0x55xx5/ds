#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {



	int arrA[4][3] = { {1, 2, 3}, {5, 6, 7}, {9, 10, 11}, {13, 14, 15} }, arrB[3][4] = {0};
	printf("[enter matrix]\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) printf("%d\t", arrA[i][j]);
		printf("\n");
	}

	for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) arrB[i][j] = arrA[j][i];
	printf("[轉置矩陣]\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) printf("%d\t", arrB[i][j]);
		printf("\n");
	}


	return 0;
}
/*

[enter matrix]
1       2       3
5       6       7
9       10      11
13      14      15
[轉置矩陣]
1       5       9       13
2       6       10      14
3       7       11      15

--------------------------------
*/

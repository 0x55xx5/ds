
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[6][6] = {0}, i, j, k, tmpi, tmpj;
    int data[10][2] = {{1, 2}, {2, 1}, {1, 5}, {5, 1}, {2, 3}, {3, 2}, {2, 4}, {4, 2}, {3, 4}, {4, 3}};
    for (i = 0; i < 10; i++)
        for (j = 0; j < 6; j++)
            for (k = 0; k < 6; k++)
            {
                tmpi = data[i][0];
                tmpj = data[i][1];
                arr[tmpi][tmpj] = 1;
            }
    printf("無向圖: \n");
    for (i = 1; i < 6; i++)
    {
        for (j = 1; j < 6; j++)
            printf("[%d]", arr[i][j]);
        printf("\n");
    }

    system("pause");
    return 0;
}
/*

無向圖:
[0][1][0][0][1]
[1][0][1][1][0]
[0][1][0][1][0]
[0][1][1][0][0]
[1][0][0][0][0]
*/

// Prim 演算法又稱P氏法
#define BIG_NO 99999
#include <stdio.h>
#define VERTS 3
int data[60][60];
int total = 0;
int start;
int value[60];
char marked[60] = {0};
int road[60];
void MinSpanTree(int start, int node, int edge)
{
    int smallest, end_point, i, j;
    marked[start] = 1;
    for (i = 0; i < node; i++)
    {
        value[i] = data[start][i];
        road[i] = start;
    }
    for (i = 1; i < node; i++)
    {
        smallest = BIG_NO;
        for (j = 0; j < node; j++)
        {
            if ((marked[j] == 0) && (smallest > value[j]))
            {
                smallest - value[j];
                end_point = j;
            }
        }

        total = total + value[end_point];
        marked[end_point] = 1;
        for (j = 0; j < node; j++)
        {
            if ((marked[j] == 0) && (data[end_point][j] < value[j]))
            {
                value[j] = data[end_point][j];
                road[j] = end_point;
            }
        }
    }
}

int main(void)
{
    int node = 3, edge = 3;
    int x, y, z, i, j;
    for (i = 0; i < node; i++)
        for (j = 0; j < node; j++)
            data[i][j] = BIG_NO;
    printf("圖形頂點個數= %d \n", node);
    printf("圖形總邊數= %d\n", edge);
    for (i = 0; i < edge; i++)
    {
        printf("請輸入第 %d 個邊的起點,終點及邊長,數值之間以空白隔開 \n", i + 1);
        scanf("%d%d%d", &x, &y, &z);
        data[x][y] = z;
        data[y][x] = z;
        printf("第 %d 個邊是從頂點 %d 到頂點 %d,length= %d \n", i + 1, x, y, z);
    }

    printf("輸入最小成本擴張樹起始頂點: ");
    scanf("%d", &start);
    MinSpanTree(start, node, edge);
    printf("最小成本擴張樹路徑為 : \n");
    for (i = 0; i < node; i++)
    {
        if (i != start)
            printf("連結頂點%d--到頂點％d", road[i], i);
    }
    printf("totoal cost= %d\n", total);
    return 0;
}

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#define Ver 6 // Prim's 節點數量
int minKey(int key[], int mstSet[])
{
    int min = 800, min_index, v;
    for (v = 0; v < Ver; v++)
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

void printMST(int parent[], int graph[Ver][Ver])
{
    printf("Edge \tWeight\n");
    int i;
    for (i = 1; i < Ver; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[Ver][Ver])
{
    int parent[Ver];           // 存放最小生成
    int key[Ver], v, i, count; // 放最小聲成樹相鄰的邊的權重
    int mstSet[Ver];           // 標記節點是否已經包含在最小生成樹中

    for (i = 0; i < Ver; i++)
    {
        key[i] = 800;
        mstSet[i] = 0;
    }
    key[0] = 0;     // 使第一個節點成為最小生成树的根
    parent[0] = -1; // 第一個節點沒有父節點
    for (count = 0; count < Ver - 1; count++)
    {
        int u = minKey(key, mstSet); // 從尚未包含在最小生成樹中的節點中選擇一個最小的key值
        mstSet[u] = 1;               // 將選定的節點標記為已處理
        for (v = 0; v < Ver; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v]; // 更新key&parent array
            }
    }
    printMST(parent, graph); // print the constructed MST
}

int main()
{
    int graph[Ver][Ver] = {{0, 18, 0, 0, 12, 15}, {18, 0, 8, 10, 0, 26}, {0, 8, 0, 6, 0, 0}, {0, 10, 6, 0, 15, 23}, {12, 0, 0, 15, 0, 12}, {15, 26, 0, 23, 12, 0}};
    primMST(graph);
    return 0;
}
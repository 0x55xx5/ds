
// 146. Dijkstra演算法
#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
#define NUMBER 6
#define max 9999
int Graph_Matrix[SIZE][SIZE]; // 圖形陣列
int distance[SIZE];           // 路徑長度陣列
void BuildGraph_Matrix(int *Path_Cost);
void shortestPath(int vertex1, int vertex_total);
void BuildGraph_Matrix(int *Path_Cost)
{
    int Start_Point, End_Point, i, j;
    for (i = 1; i < SIZE; i++)
    {
        for (j = 1; j < SIZE; j++)
        {
            if (i == j)
                Graph_Matrix[i][j] = 0;
            else
                Graph_Matrix[i][j] = max;
        }
    }
    i = 0;
    while (i < SIZE)
    {
        Start_Point = Path_Cost[i * 3];
        End_Point = Path_Cost[i * 3 + 1];
        Graph_Matrix[Start_Point][End_Point] = Path_Cost[i * 3 + 2];
        i++;
    }
}

void shortestPath(int vertex1, int vertex_total)
{
    int shortest_vertex = 1;
    int shortest_distance;
    int goal[SIZE];
    int i, j;
    for (i = 1; i <= vertex_total; i++)
    {
        goal[i] = 0;
        distance[i] = Graph_Matrix[vertex1][i];
    }
    goal[vertex1] = 1;
    distance[vertex1] = 0;
    printf("\n");
    for (i = 1; i <= vertex_total - 1; i++)
    {
        shortest_distance = max;
        for (j = 1; j <= vertex_total; j++)
            if (goal[j] == 0 && shortest_distance > distance[j])
            {
                shortest_distance = distance[j];
                shortest_vertex = j;
            }

        goal[shortest_vertex] = 1;
        for (j = 1; j <= vertex_total; j++)
        {
            if (goal[j] == 0 &&
                distance[shortest_vertex] + Graph_Matrix[shortest_vertex][j] < distance[j])
            {
                distance[j] = distance[shortest_vertex] + Graph_Matrix[shortest_vertex][j];
            }
        }
    }
}

int main()
{
    int Path_Cost[8][3] = {{1, 2, 29}, {2, 3, 30}, {2, 4, 35}, {3, 5, 28}, {3, 6, 87}, {4, 5, 42}, {4, 6, 75}, {5, 6, 97}};
    int j; // 1,D[2]=29, D[3]=1-2-3=29+30=59 D[4]=1-2-4=29+35=64 D[5]=min{1-3-5=59+28=87, 1-2-4-5 =29+35+42=106},
    // D[6]=min{1-2-4-6=29+35+75=139,1-3-5-659+28+97=184}=139
    BuildGraph_Matrix(&Path_Cost[0][0]);
    shortestPath(1, NUMBER);
    printf("頂點1到各頂點的最短距離\n");
    for (j = 1; j < SIZE; j++)
        printf("頂點1到頂點%2d最短距離%3d\n", j, distance[j]);
    printf("\n");
    system("pause");
    return 0;
}
/*

頂點1到各頂點的最短距離
頂點1到頂點 1最短距離  0
頂點1到頂點 2最短距離 29
頂點1到頂點 3最短距離 59
頂點1到頂點 4最短距離 64
頂點1到頂點 5最短距離 87
頂點1到頂點 6最短距離139
*/
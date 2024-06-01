
#include <stdio.h>
#include <stdlib.h>
struct list
{
    int val;
    struct list *next;
};
typedef struct list node;
typedef node *link;
link head[9];
int run[9];
void dfs(int cur)
{
    link ptr;
    run[cur] = 1;
    printf("[%d]", cur);
    ptr = head[cur]->next;
    while (ptr != NULL)
    {
        if (run[ptr->val] == 0)
            dfs(ptr->val); /**call recursive*/
        ptr = ptr->next;
    }
}

void print(link h)
{
    while (h != NULL)
    {
        printf("[%d] ", h->val);
        h = h->next;
    }
    printf("\n");
}

int main()
{
    link ptr, newnode;
    int data[20][2] = {{1, 2}, {2, 1}, {1, 3}, {3, 1}, {2, 4}, {4, 2}, {2, 5}, {5, 2}, {3, 6}, {6, 3}, {3, 7}, {7, 3}, {4, 8}, {8, 4}, {5, 8}, {8, 5}, {6, 8}, {8, 6}, {8, 7}, {7, 8}};
    int i, j;

    for (i = 1; i <= 8; i++)
    {
        run[i] = 0;
        head[i] = (link)malloc(sizeof(node));
        head[i]->val = i;
        head[i]->next = NULL;
        ptr = head[i];
        for (j = 0; j < 20; j++)
        {
            if (data[j][0] == i)
            {
                newnode = (link)malloc(sizeof(node));
                newnode->val = data[j][1];
                newnode->next = NULL;
                do
                {
                    ptr->next = newnode;
                    ptr = ptr->next;
                } while (ptr->next != NULL);
            }
        }
        printf("process the point %d-->", i);
        print(head[i]);
    }
    printf("圖形的相鄰串列內容: \n");
    for (i = 1; i <= 8; i++)
    {
        ptr = head[i];
        printf("%d=> ", i);
        ptr = ptr->next;
        while (ptr != NULL)
        {
            printf("[%d]", ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }

    printf("dfs : \n");
    dfs(1);
    printf("\n");
    int data1[14][2] = {{1, 2}, {2, 1}, {1, 5}, {5, 1}, {2, 4}, {4, 2}, {2, 3}, {3, 2}, {3, 4}, {4, 3}, {5, 3}, {3, 5}, {4, 5}, {5, 4}};
    for (i = 1; i <= 5; i++)
    {
        run[i] = 0;
        head[i] = (link)malloc(sizeof(node));
        head[i]->val = i;
        head[i]->next = NULL;
        ptr = head[i];
        for (j = 0; j < 14; j++)
        {
            if (data1[j][0] == i)
            {
                newnode = (link)malloc(sizeof(node));
                newnode->val = data1[j][1];
                newnode->next = NULL;
                do
                {
                    ptr->next = newnode;
                    ptr = ptr->next;
                } while (ptr->next != NULL);
            }
        }
        printf("process the point %d-->", i);
        print(head[i]);
    }
    printf("圖形的相鄰串列內容: \n");

    for (i = 1; i <= 5; i++)
    {
        ptr = head[i];
        printf("%d=> ", i);
        ptr = ptr->next;
        while (ptr != NULL)
        {
            printf("[%d]", ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }
    printf("dfs\n");
    dfs(1);
    printf("\n");
    system("pause");
    return 0;
}

/*
process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
4=> [2][8]
5=> [2][8]
6=> [3][8]
7=> [3][8]
8=> [4][5][6][7]
dfs : 
[1][2][4][8][5][6][3][7]
process the point 1-->[1] [2] [5] 
process the point 2-->[2] [1] [4] [3] 
process the point 3-->[3] [2] [4] [5] 
process the point 4-->[4] [2] [3] [5] 
process the point 5-->[5] [1] [3] [4] 
圖形的相鄰串列內容: 
1=> [2][5]
process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
4=> [2][8]
5=> [2][8]
6=> [3][8]
7=> [3][8]
8=> [4][5][6][7]
dfs : 
[1][2][4][8][5][6][3][7]
process the point 1-->[1] [2] [5] 
process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
4=> [2][8]
5=> [2][8]
6=> [3][8]
7=> [3][8]
8=> [4][5][6][7]
dfs : 
[1][2][4][8][5][6][3][7]
process the point 1-->[1] [2] [5] 
process the point 2-->[2] [1] [4] [3] 
process the point 3-->[3] [2] [4] [5] 
process the point 4-->[4] [2] [3] [5] 
process the point 5-->[5] [1] [3] [4] 
圖形的相鄰串列內容: 
1=> [2][5]
2=> [1][4][3]
3=> [2][4][5]
4=> [2][3][5]
5=> [1][3][4]
dfs
[1][2][4][3][5]
sh: pause: command not found
*/
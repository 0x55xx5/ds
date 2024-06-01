
#include <stdio.h>
#include <stdlib.h>
struct list
{
    int val;
    struct list *next;
};
typedef struct list node;
typedef node *link;
struct list head[6];
/*宣告一個節點型態陣列*/
int main()
{
    link ptr, newnode;
    char data[14][2] = {{1, 2}, {2, 1}, {2, 5}, {5, 2}, {2, 3}, {3, 2}, {2, 4}, {4, 2}, {3, 4}, {4, 3}, {3, 5}, {5, 3}, {4, 5}, {5, 4}};
    int i, j;
    printf("content: \n");
    printf("--\n");
    for (i = 1; i < 6; i++)
    {
        head[i].val = i;
        head[i].next = NULL;
        printf("頂點 %d =>", i);
        ptr = &(head[i]);
        for (j = 0; j < 14; j++)
        {
            if (data[j][0] == i)
            {
                newnode = (link)malloc(sizeof(node));
                newnode->val = data[j][1];
                newnode->next = NULL;
                while (ptr != NULL)
                    ptr = ptr->next;
                ptr = newnode;
                printf("[%d]", newnode->val);
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
/*

content: 
--
頂點 1 =>[2]
頂點 2 =>[1][5][3][4]
頂點 3 =>[2][4][5]
頂點 4 =>[2][3][5]
頂點 5 =>[2][3][4]
sh: pause: command not found
*/

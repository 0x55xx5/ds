
#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left, *right;
};
typedef struct tree node;
typedef node *btree;

btree creat_tree(btree root, int val)
{
    btree newnode, current, backup;
    newnode = (btree)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    else
    {
        for (current = root; current != NULL;)
        {
            backup = current;
            if (current->data > val)
                current = current->left;
            else
                current = current->right;
        }

        if (backup->data > val)
            backup->left = newnode;
        else
            backup->right = newnode;
    }
    return root;
}

btree search(btree ptr, int val)
{
    int i = 1;
    while (1)
    {
        if (ptr == NULL)
            return NULL;
        if (ptr->data == val)
        {
            printf("ser %d times\n", i);
            return ptr;
        }
        else if (ptr->data > val)
            ptr = ptr->left;
        else
            ptr = ptr->right;
        i++;
    }
}
int main()
{
    int i, data, arr[] = {7, 1, 4, 2, 8, 13, 12, 11, 15, 9, 5};
    btree ptr = NULL;
    printf("original \n");
    for (i = 0; i < 11; i++)
    {
        ptr = creat_tree(ptr, arr[i]);
        printf("[%2d] ", arr[i]);
    }
    printf("\n");
    do
    {
        printf("find key?: \n");
        scanf("%d", &data);
        if (data == -1)
            break;
        if ((search(ptr, data)) != NULL)
            printf("found val: [%3d] \n", data);
        else
            printf("NOT FOUND!!\n");
    } while (1);
    system("pause");
    return 0;
}
/*
original
[ 7] [ 1] [ 4] [ 2] [ 8] [13] [12] [11] [15] [ 9] [ 5]
find key?:
2
ser 4 times
found val: [  2]
find key?:
6
NOT FOUND!!
find key?:
9
ser 6 times
found val: [  9]
find key?:

*/
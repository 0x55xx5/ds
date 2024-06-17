
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
btree findMin(btree r)
{
    while (r->left != NULL)
        r = r->left;
    return r;
}
btree findMax(btree r)
{
    while (r->right != NULL)
        r = r->right;
    return r;
}

btree delete_n(btree r, int key)
{
    if (r == NULL)
        return r;
    else if (key < r->data)
        r->left = delete_n(r->left, key);
    else if (key > r->data)
        r->right = delete_n(r->right, key);
    else
    {
        // 節點只有一個或沒有子節點的情況
        if (r->left == NULL)
        {
            btree temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == NULL)
        {
            btree temp = r->left;
            free(r);
            return temp;
        }
        // 節點有兩個子節點的情況
        btree temp = findMin(r->right);            // 找到右子樹中最小的節點
        r->data = temp->data;                      // 把右子樹中最小節點的值複製到當前節點
        r->right = delete_n(r->right, temp->data); // 刪除右子樹中最小的節點

        // case 2:
        //  節點有兩個子節點的情況
        btree temp = findMax(r->left);           // 找到左子樹中最大的節點
        r->data = temp->data;                    // 把左子樹中最大節點的值複製到當前節點
        r->left = delete_n(r->left, temp->data); // 刪除左子樹中最大的節點
    }
    return r;
}
void inorder(btree ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("[%2d] ", ptr->data);
        inorder(ptr->right);
    }
}
int main()
{
    int i, data, arr[] = {7, 1, 4, 2, 8, 13, 12, 11, 15, 9, 5};
    btree ptr = NULL;
    printf("orig \n");
    for (i = 0; i < 11; i++)
    {
        ptr = creat_tree(ptr, arr[i]);
        printf("[%2d] ", arr[i]);
    }
    printf("\n");
    do
    {
        printf("enter new node:");
        scanf("%d", &data);
        if (data == -1)
            break;
        if ((search(ptr, data)) != NULL)
            printf("exist %d!\n", data);
        else
        {
            ptr = creat_tree(ptr, data);
            inorder(ptr);
        }
    } while (1);

    do
    {
        printf("enter del val:");
        scanf("%d", &data);
        if (data == -1)
            break;
        if ((search(ptr, data)) != NULL)
        {
            ptr = delete_n(ptr, data);
            inorder(ptr);
        }
        else
            printf("not founded %d!\n", data);
    } while (1);

    system("pause");
    return 0;
}
/*
[ 7] [ 1] [ 4] [ 2] [ 8] [13] [12] [11] [15] [ 9] [ 5]
enter new node::999
[ 1] [ 2] [ 4] [ 5] [ 7] [ 8] [ 9] [11] [12] [13] [15] [999] enter new node::-1
enter del val:999
ser 5 times
[ 1] [ 2] [ 4] [ 5] [ 7] [ 8] [ 9] [11] [12] [13] [15] enter del val:
*/
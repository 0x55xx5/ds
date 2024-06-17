
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *left, *right;
};
typedef struct Node TreeNode;
typedef TreeNode *btree; // btree is a pointer to TreeNode
btree root, root2;
btree create(char seq[100], int index, int size)
{
    btree temp;
    if (seq[index] == 0 || index >= size)
        return NULL;
    else
    {
        temp = (btree)malloc(sizeof(TreeNode));
        temp->value = (int)seq[index];
        temp->left = NULL;
        temp->right = NULL;
        temp->left = create(seq, 2 * index, size);
        temp->right = create(seq, 2 * index + 1, size);
        return temp;
    }
}

void preorder(btree node)
{
    if (node != NULL)
    {
        printf("%c", (char)node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(btree node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%c", (char)node->value);
        inorder(node->right);
    }
}

void postorder(btree node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%c", (char)node->value);
    }
}

int cond(char opr, int num1, int num2)
{
    switch (opr)
    {
    case '*':
        return (num1 * num2);
        break;
    case '/':
        return (num1 / num2);
        break;
    case '+':
        return (num1 + num2);
        break;
    case '-':
        return (num1 - num2);
        break;
    case '%':
        return (num1 % num2);
        break;
    }
    return -1;
}

int answer(btree node)
{
    int first = 0, sec = 0;
    if (node->left == NULL && node->right == NULL)
        return node->value - 48;
    else
    {
        first = answer(node->left);
        sec = answer(node->right);
        return cond((char)node->value, first, sec);
    }
}

int main(void)
{
    char inf1[] = {' ', '+', '*', '%', '6', '3', '9', '5'};
    char inf2[] = {' ', '+', '+', '+', '*', '%', '/', '*', '1', '2', '3', '2', '6', '3', '2', '2'};

    root = (btree)malloc(sizeof(TreeNode));
    root2 = (btree)malloc(sizeof(TreeNode));
    root = create(inf1, 1, 8);
    printf("====example ====\n");
    printf("=================================\n");
    printf("===to inoder===\n ");
    inorder(root);
    printf(" ===to preorder===\n");
    preorder(root);
    printf("\n===to postOrder===\n ");
    postorder(root);
    printf("\n result: ");
    printf("%d", answer(root));
    printf("\n");
    root2 = create(inf2, 1, 16);
    printf("\n\n");
    printf("====example ====\n");
    printf("=================================\n");
    printf("===to inoder===\n");
    inorder(root2);
    printf(" ===to preorder===\n");
    preorder(root2);
    printf("\n===to postorder===\n ");
    postorder(root2);
    printf("\nresult: ");
    printf("%d", answer(root2));
    printf("\n");
    system("pause");
    return 0;
}
/*

====example ====
=================================
===to inoder===
 6*3+9%5 ===to preorder===
+*63%95
===to postOrder===
 63*95%+
 result: 22


====example ====
=================================
===to inoder===
1*2+3%2+6/3+2*2 ===to preorder===
++*12%32+/63*22
===to postorder===
 12*32%+63/22*++
result: 9
*/
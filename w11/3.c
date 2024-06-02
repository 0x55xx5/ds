// binary search tree
//knuth's algorithm
//k is depth  node number is 2^k-1
//階度i 最大2^(i-1)個節點
#include <stdio.h>
#include <stdlib.h>
void Btree_create(int *btree, int *data, int length)
{
    int i, level;
    /*如果子樹節點的值不為0,則再與陣列內的值比較一次*/
    for (i = 1; i < length; i++)
    {
        for (level = 1; btree[level] != 0;)
        {
            if (data[i] > btree[level])
                level = level * 2 + 1;
            else
                level = level * 2;
        }
        btree[level] = data[i]; /**/
    }
}
int main()
{
    int i, length = 9;//最差狀況
    //int data[] = {0, 6, 3, 5, 4, 7, 8, 9, 2}; 
     int data[] = {0, 9, 6, 3, 7, 1, 2, 8,4}; 
    int btree[16] = {0};          
    printf("array : \n");
    for (i = 0; i < length; i++)
        printf("[%2d] ", data[i]);
    printf("to tree \n");
    Btree_create(btree, data, 9);
    printf("\n");
    for (i = 0; i < 16; i++)
        printf("[%2d] ", btree[i]);
    printf("\n");
    system("pause");
    return 0;
}
/*
   array : 
[ 0] [ 6] [ 3] [ 5] [ 4] [ 7] [ 8] [ 9] [ 2] to tree 

[ 0] [ 6] [ 3] [ 7] [ 2] [ 5] [ 0] [ 8] [ 0] [ 0] [ 4] [ 0] [ 0] [ 0] [ 0] [ 9] 

*/
// quiz 2:
//  96371284
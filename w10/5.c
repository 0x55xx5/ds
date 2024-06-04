
#include <stdio.h>
#include <stdlib.h>

// #include <conio.h>//windows sdk
#define MAX 10
/*定義佇列的大小*/
int main()
{
    int front, rear, val, queue[MAX] = {0};
    char c;
    front = rear = -1;
    while (rear < MAX - 1 && c != 'e')
    {
        printf("[a]表示存入一個數值[d]表示取出一個數值[e]表示跳出此程式: ");
        // c=getche();
        //system("stty -icanon");
        c = getchar();
        switch (c)
        {
        case 'a':
            printf("\n[]: ");
            scanf("%d", &val);
            rear++;
            queue[rear] = val;
            break;
        case 'd':
            if (rear > front)
            {
                front++;
                printf("\n[H]: [%d]\n", queue[front]);
                queue[front] = 0;
            }
            else
            {
                printf("\n[f]\n");
                exit(0);
            }
            break;
        default:
            printf("\n");
            break;
        }
    }
    printf("\n-----\n");
    printf("all queue elements:");
    if (rear == MAX - 1)
        printf("[X]\n");

    else if (front >= rear)
    {
        printf("\n");
        printf("[f]\n");
    }
    else
    {
        while (rear > front)
        {
            front++;
            printf("[%d]", queue[front]);
        }
        printf("\n-------\n");
    }
    printf("\n");
    system("pause");
    return 0;
}
/*
 [a]表示存入一個數值[d]表示取出一個數值[e]表示��出此程式: a

[]: 11
[a]表示存入一個數值[d]�示取出一個數值[e]表示跳出此程式: 
[a]表示存入一個數值[d]表示取出一��數值[e]表示跳出此程式: a

[]: 12
[a]表示存入一個數值[d]�示取出一個數值[e]表示跳出此程式: 
[a]表示存入一個數值[d]表示取出一��數值[e]表示跳出此程式: d

[H]: [11]
*/
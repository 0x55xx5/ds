// 環狀queue
#include <stdio.h>
#include <stdlib.h>
#define max 5
int main(void)
{
    int front, rear, val, queue[max] = {0};
    front = rear = -1;
    while (rear < max && val != -1)
    {
        printf("請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):");
        scanf("%d", &val);
        if (val == 0)
        {
            if (front == rear)
            {
                printf("empty\n");
                break;
            }
            front = (front + 1) % max;
            printf("withdraw data [%d]\n", queue[front]);
            queue[front] = 0;
        }

        else if (val != -1 && rear < max)
        {
            if (rear + 1 == front || (rear == max - 1 && front <= 0))
            {
                printf("FULL\n");
                break;
            }
            rear = (rear + 1) % max;
            queue[rear] = val;
        }
    }

    printf("\nremaining data  : \n");
    if (front == rear)
        printf("empty!!\n");
    else
    {
        while (front != rear)
        {
            front = (front + 1) % max;
            printf("[%d]", queue[front]);
            queue[front] = 0;
        }
        printf("\n");
        return 0;
    }
}

/*

請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):12
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):23
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):36
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):0
withdraw data [12]
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):48
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):0
withdraw data [23]
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):54
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):0
withdraw data [36]
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):64
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):48
請輸入一個值以存入佇列,欲取出值請輸入0。(結束輸入-1):-1

remaining data  :
[48][54][64][48]
*/

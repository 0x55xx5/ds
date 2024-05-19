
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node que;
typedef que *que_list;
que_list front = NULL, rear = NULL;
void enqueue(int value)
{
    que_list node = (que_list)malloc(sizeof(que));
    node->data = value;
    node->next = NULL;
    if (rear == NULL)
        front = node;
    else
        rear->next = node;
    rear = node;
}

int dequeue(int ac)
{
    int value;
    que_list tmp, start,pre;
    if (!(front == NULL) && ac == 1)
    {
        if (front == rear)
            rear = NULL;
        value = front->data;
        front = front->next;
        return value;
    }
    else if (!(rear == NULL) && ac == 2)
    {
        start = front;
        value = rear->data; 
        // 找尋最尾端節點的前一個節點
        tmp  = front;
        while (tmp != rear )
        {
            pre = tmp;
            tmp = tmp->next;
        }
        free(tmp);
        rear = pre; 
        rear->next = NULL;
        return value;
    }
    else
        return -1;
}

void print_q()
{
    que_list t = front;
    printf("remaining-->");
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int temp, item, ch;
    printf("double queue by linkedin list \n");
    printf("====================================\n");
    printf("add 1,get  2,end -1:");
    scanf("%d", &ch);
    while (ch != -1)
    {
        if (ch == 1)
        {
            printf("add data is :");
            scanf("%d", &item);
            enqueue(item);
        }
        else if (ch == 2)
        {
            temp = dequeue(1);
            printf("data from front: %d\n", temp);
            temp = dequeue(2);
            printf("data from rear: %d\n", temp);
        }
        else
            break;
        print_q();
        printf("add 1,get  2,end -1:");
        scanf("%d", &ch);
    }
    print_q();
    system("pause");
    return 0;
}

/*

double queue by linkedin list
====================================
add 1,get  2,end -1:1
add data is :12
remaining-->12 
add 1,get  2,end -1:1
add data is :24
remaining-->12 24 
add 1,get  2,end -1:1
add data is :36
remaining-->12 24 36 
add 1,get  2,end -1:2
data from front: 12
data from rear: 36
remaining-->24 
add 1,get  2,end -1:-1
remaining-->24 
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 4 /*N queen */
struct ss
{
    int row, col;
    struct ss *next;
};
typedef struct ss s_node;
typedef s_node *link;
link stack = NULL;
char put[MAX][MAX] = {MAX * MAX * 0};
char dir[3][2] = {-1, -1, -1, 0, -1, 1};
void push(int k, int l)
{
    link kk = (link)malloc(sizeof(s_node));
    kk->next = stack;
    kk->row = k;
    kk->col = l;
    stack = kk;
}

void pop(int *rr, int *cc)
{
    link top;
    if (stack != NULL)
    {
        *rr = stack->row;
        *cc = stack->col;
        top  =stack;
        stack = stack->next;
        free(top);
    }
}

int legal(int r, int c)
{
    if ((r >= 0) && (r <= (MAX - 1)) && (c >= 0) && (c <= (MAX - 1)))
        return 1;
    return 0;
}

int check(int r, int c)
{
    int i, nr, nc;
    for (i = 0; i <= 2; i++)
    {
        nr = r + dir[i][0];
        nc = c + dir[i][1];
        if (legal(nr, nc))
        {
            switch (i)
            {
            case 0: /* left upper x-1,y-1 */
                while ((nr >= 0) && (nc >= 0))
                    if (put[nr--][nc--] != '0')
                        return 0;
                break;
            case 1: /* upper x-1,y */
                while (nr >= 0)
                    if (put[nr--][nc] != '0')
                        return 0;
                break;
            case 2: /* right upper x-1,y+1 */
                while ((nr >= 0) && (nc < MAX))
                    if (put[nr--][nc++] != '0')
                        return 0;
                break;
            } /* switch */
        }     /* check position legal */
    }         /* for 3 direction */
    return 1;
}

void print()
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            printf("%c", put[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int i, j, r, c, cc, nr, nc, ok, fin = 0;
    link kk;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            put[i][j] = '0';
    system("cls");
    r = c = cc = 0;
    push(r, c);
    put[r][c] = 'Q';
    nr = r + 1;
    printf("%d queen solution: \n", MAX);
    while (1)
    {
        ok = 0;
        for (i = c; i < MAX; i++)
        {
            if (check(nr, i) == 1)
            {
                push(nr, i);
                put[nr][i] = 'Q';
                r = nr++;
                c = i;
                ok = 1;
                break;
            }
        } /* end for Loop */
        if (ok == 1)
        {
            c = 0;
            if (r == (MAX - 1))
            {
                printf("%d\n", cc + 1);
                print();
                cc++;
            }
        }
        else
        {
            do
            {
                pop(&r, &c);
                put[r][c] = '0';
                c++;
                if (c <= (MAX - 1))
                {
                    nr = r;
                    break;
                }
                if ((c > (MAX - 1)) && (r == 0))
                {
                    fin = 1;
                    break;
                }
            } while (1);
        } /* else ok == 0 */
        if (fin == 1)
            break;
    } /* while 1 */
    printf("total have %d solution\n", cc);
    getchar();
    system("pause");
    return 0;
}
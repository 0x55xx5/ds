

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
char posfix[MAX];
int p1[MAX];
int top = -1;
void push(int value) { p1[++top] = value; }
int pop()
{
    if (top != -1)
        return p1[top--];
    else
        return -1;
}
int empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int isoperator(char op)
{
    switch (op)
    {
    case '+':
    case '-':
    case '*':
    case '^':
    case '/':
        return 1;
    default:
        return 0;
    }
}
int eval(char op, int op1, int op2)
{
    int s = 1, i = 1;
    switch (op)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    case '^':
        for (i = 1; i <= op2; i++)
            s *= op1;
        return s;
    }
}
int main()
{
    int n, aa, opl, i;
    char c, fg;
    posfix[0] = 0;
    while (1)
    {
        char exp[100];
        int pos = 0, op1, op2, s1 = 0, fir = 0;
        printf("postfix statement--> ");
        gets(exp);
        if (exp[0] == '\0')
            break;
        while (exp[pos] != '\0' && exp[pos] != '\n')
        {
            if (isoperator(exp[pos]))
            { /* '+ - * /' */
                op2 = pop();
                op1 = pop();
                push(eval(exp[pos], op1, op2));
            }
            else if (exp[pos] == ' ')
            {
                if ((fir == 0) && (s1 != 0))
                {
                    push(s1);
                    s1 = 0;
                    fir = 1;
                }
            }
            else
            {
                s1 = s1 * 10 + exp[pos] - '0';
                fir = 0;
            }
            pos++;
        }

        printf("postfix statement %s result:--->%d\n", exp, pop());
    }

    system("pause");
    return 0;
}
/*
postfix statement 2 3 * result:--->6
*/
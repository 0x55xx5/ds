
#include <stdio.h> 
#include <stdlib.h>
#define MAX 50
char infix_q[MAX];
int compare(char stack_o, char infix_o);
void infix_to_postfix();
void input() {
    printf("-------\n");
    printf("中轉後\n"); printf("用:^,*,+,-,/,(,)$ \n");
    printf("put ur statement: ");
}
int main () {
    int i; for (i=0; i<MAX; i++) infix_q[i]='\0'; infix_to_postfix(); system("pause"); return 0;
}

int compare(char stack_o, char infix_o) {
    char infix_priority[9] ;
    char stack_priority [8] ;
    int index_s=0, index_i=0;
    infix_priority[0]='q';infix_priority[1]=')';
    infix_priority[2]='+';infix_priority[3]='-';
    infix_priority[4]='*';infix_priority[5]='/';
    infix_priority[6]='^';infix_priority[7]=' ';
    infix_priority[8]='(';
    stack_priority[0]='q';stack_priority[1]='('; 
    stack_priority[2]='+';stack_priority[3]='-'; 
    stack_priority[4]='*';stack_priority[5]='/';
    stack_priority [6]='^';stack_priority[7]=' ';
    while (stack_priority[index_s] != stack_o) index_s++; 
    while (infix_priority[index_i] != infix_o) index_i++; 
    return ((int)(index_s/2) >= (int)(index_i/2) ? 1 : 0);
}


void infix_to_postfix() {
char stack_t[MAX];
while (1) {
int rear=0, top=0, flag=0,i=0;
for (i=0; i<MAX; i++) stack_t[i]='\0';
input(); gets(infix_q); if (infix_q[0]=='\0') break;
printf("infix -->%s",infix_q); i=0;
while(infix_q[i]!='\0') { i++; rear++; }
infix_q[rear] = 'q'; printf("postfix statement : ");
stack_t[top] = 'q';
for (flag = 0; flag <= rear; flag++) {
            switch (infix_q[flag]) {
            case ')':
                printf(" "); while(stack_t[top]!='(') printf("%c",stack_t[top--]); top--; break; 
            case 'q':
                while(stack_t[top]!='q') printf("%c",stack_t[top--]); break;
            case '(':
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
            printf(" "); while (compare(stack_t[top], infix_q[flag])==1) printf("%c",stack_t[top--]); 
            stack_t[++top] = infix_q[flag]; break;
            default:
                printf("%c",infix_q[flag]); break;
        }
    }

    printf("\n====================\n");
}
}
/*
-------
中轉後
用:^,*,+,-,/,(,)$ 
put ur statement: 2+9+8-6*3+6
infix -->2+9+8-6*3+6postfix statement : 2 9 +8 +6 3 *-6+
====================
*/
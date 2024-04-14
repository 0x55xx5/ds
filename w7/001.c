
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define MAX 100

struct node{ int data; struct node *next; };
typedef struct node stn;
typedef stn *ln_s;
ln_s top_l=NULL;
int isemp_l() { if(top_l==NULL) return 1; else return 0; }
void push_l(int data) {
	ln_s newnode=(ln_s)malloc(sizeof(stn)); newnode->data=data;
	newnode->next=top_l; top_l=newnode;
}

int pop_l() {
	ln_s ptr; int tmp;
	if(isemp_l()) { printf("empty\n"); return -1; }
	else { ptr=top_l; top_l=top_l->next; tmp=ptr->data; free(ptr); return tmp; }
}

int fact(int i) {
	int sum; if(i==0) return(1); else sum = i* fact(i-1); return sum;
}
int fib(int n) {
	if (n==0) return 0; else if (n==1 || n==2) return 1; else return (fib(n-1)+fib (n-2));
}

void hanoi(int n, int p1, int p2, int p3) {
	if (n==1) printf("circle %d to %d to  %d\n", n, p1, p3);
	else hanoi(n-1, p1, p3, p2); printf("%d %d %d\n", n, p1, p3); hanoi(n-1, p2, p1, p3); 
}

int stack[MAX];
int top=-1;
int isemp1() { if(top==-1) return 1; else return 0; }
int push1(int data) {
	if(top>=MAX) { printf("FULL\n"); return 0; }
	else { stack[++top]=data; return 1; }
}
	int pop1() { if(isemp1()) { printf("empty\n"); return -1; } else return stack[top--]; }
void Swap(int* a,int* b) { int temp=*a; *a=*b; *b=temp; }
void push_al(int sk[], int ca_max, int val) {
	if(top>=ca_max-1) printf("FULL\n"); else { top++; sk[top]=val; }
}
	
int main(int argc, char *argv[]) {
	int val, i;
	do {
		printf("push 1 pop 0 stop -1: "); scanf("%d",&i);
		if(i==-1) break;
		else if (i==1) { printf("enter number:"); scanf("%d",&val); push1(val); }
		else if(i==0) printf("pop val is %d\n",pop1());
	} while(i!= -1); 
	
	while(!isemp1()) printf("seq :%d\n",pop1()); 
	return 0;
}
/*
push 1 pop 0 stop -1: 1
enter number:5
push 1 pop 0 stop -1: 1
enter number:4
push 1 pop 0 stop -1: 1
enter number:3
push 1 pop 0 stop -1: 0
pop val is 3
push 1 pop 0 stop -1: -1
seq :4
seq :5

--------------------------------
Process exited after 16.95 seconds with return value 0 (0 ms cpu time, 3524 KB mem used).

Press ANY key to exit...



*/

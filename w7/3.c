
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
	
	do {
		printf("enter n:\n"); int i, n, j, n1, n2, sum; scanf("%d", &n); if (n == -1) break; 
		for(i=0;i<=n;i++) {
				for(j=i;j>0;j--) sum *=j; printf("%d!=%3d\n", i, sum); sum = 1;
		}
	
		for (i=0;i<=n;i++) printf("%d !%3d\n", i, fact (i));
		for(i=0;i<=n;i++) {
				if (i==0) sum=0; else if (i==1 || i == 2) n1=n2=sum=1; else { sum=n1+n2; n1=n2; n2=sum; } 
			printf("fib(%d) = %d\n", i, sum);
		}
	
		for(i=0;i<=n;i++) printf("fib(%d) = %d\n", i, fib(i));
	
	} while (1);
	return 0;
}
/*


*/

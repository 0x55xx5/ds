
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
	int val,i;
	int card[52], stack [52]={0}, j,k=0, st ;
	char ascVal;
	srand((unsigned) time (NULL)); for (i=0;i<52;i++) card[i]=i+1;//1-52 
	printf("waiting...!]\n");
	while(k<30) { for(i=0; i<51;i++) for(j=i+1;j<52;j++) if (rand()%52==2) Swap (&card[i],&card[j]); k++; } i=0; top=-1;
	while(i!=52) {push_al(stack, 52, card[i]); i++; }
	printf("unclockwise\n"); 
	printf("顯示四家\n \t \t");

	while(top >=0) {
		st =stack[top]/13; 
		switch(st) {
		case 0: 
			ascVal='S'; break; 
		case 1:
			ascVal='H'; break;
		case 2: 
			ascVal='D'; break; 
		case 3:
			ascVal='C'; break;
		}
		printf("[%c%3d]\t", ascVal, stack[top]%13+1); if(top %4==0) printf("\n"); top--;
	}

	return 0;
}
/*

waiting...!]
unclockwise
顯示四家
[H  3]  [D  9]  [C 11]  [H 12]
[H  7]  [H  5]  [H  1]  [C  6]
[C  9]  [H  9]  [S  4]  [C 12]
[D 13]  [D  4]  [S 12]  [S  2]
[H  4]  [S 11]  [H  6]  [D  2]
[S 13]  [D  5]  [D  1]  [D 12]
[D  7]  [C  5]  [D  6]  [C  8]
[C  2]  [C  4]  [D 11]  [C 13]
[C  7]  [S  5]  [S  7]  [S 10]
[S  9]  [D  3]  [S  6]  [H 11]
[C  3]  [C 10]  [D  8]  [D  1]
[S  8]  [C  1]  [H  8]  [H 10]
[H  2]  [H 13]  [S  3]  [D 10]

--------------------------------
Process exited after 0.01999 seconds with return value 0 (15.62 ms cpu time, 3508 KB mem used).

Press ANY key to exit...
*/

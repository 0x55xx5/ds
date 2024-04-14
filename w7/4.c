
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
	if (n==1) printf("circle %d from %d to  %d\n", n, p1, p3);
	else {hanoi(n-1, p1, p3, p2); printf("circle %d from %d to %d\n", n, p1, p3); hanoi(n-1, p2, p1, p3); }
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
int gcd(int n1,int n2){
	int s;
	while( (s=n1%n2)!=0){
		n1=n2;
		n2=s;
	}
	return n2;
}
int gcd2(int n1,int n2){

	if(n1%n2==0){
		return n2;
	}
	else{return gcd2(n2,n1%n2);}

}
int sum1(int i,int j){
	if(j==1)return i;
	else return i+sum1(i,j-1);
}
int sum2(){}
int main(int argc, char *argv[]) {
	//河內塔
	//	hanoi(3,1, 2, 3);
	
	
	int n1;
	printf("enter n1=");scanf("%d",&n1);
	int n2;
	printf("enter n2=");scanf("%d",&n2);
	int r1=gcd2(n1,n2);
	int r2=gcd(n1,n2);
	printf("%d %d",r1,r2);
	return 0;
}
/*


*/

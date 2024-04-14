#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct emp { int num, sal; char name[10]; struct emp *next; };
typedef struct emp node_emp;
typedef node_emp *link1;

int getlen(link1 cir_h) {
	int n = 0;
	if (cir_h != NULL) {
		link1 p = cir_h;
		do {
			n++;
			p = p->next;
			printf("total %d", n);
		} while (p != cir_h);
		return n;
	}
	
	
}
void print_emp(link1 h) {
	printf("\n\tEMPno    NAME \tSAL\n");
	printf("\t=================\n");
			link1 ptr1=h;
			
	do { 
		printf("\t[%d]\t[ %-10s]\t[%3d]\n", ptr1->num, ptr1->name, ptr1->sal);
		ptr1=ptr1->next; } 
	while (ptr1!= h); printf("---total %d ---\n",getlen(h));
}
link1 findnode (link1 head, int num) {
	link1 ptr=head;
	do { if(ptr->num==num) return ptr; ptr=ptr->next; }
	while(ptr!=head); return NULL;
}

link1 insert(link1 head1, link1 ptr1, int num, int sal, char name[10]) { //ADD TO CIRCLE LINK
	link1 newnode1=(link1)malloc(sizeof (node_emp));
	newnode1->num=num; newnode1->sal=sal; strcpy (newnode1->name, name);
	if (head1== NULL) { newnode1->next=head1; return newnode1; } //ADD
	else {
		if(ptr1==head1) 
		{//ADD TO HEAD
		newnode1->next=head1; link1 p=head1; 
			do { p=p->next; } 
			while (p->next != head1); 
			p->next=newnode1; head1=newnode1;
			
		}
		else 
		{ newnode1->next=ptr1->next; ptr1->next=newnode1; }
		
	}
	return head1;
}

link1 concat(link1 ptr1, link1 ptr2) { //
	link1 h=ptr1; while (h->next != ptr1) h=h->next; h->next=ptr2;
	h=ptr2; while (h->next != ptr2) h=h->next; h->next=ptr1; 
	return ptr1;
}

link1 delete1(link1 head,link1 del) { //DEL CIRCLE LINK
	if(head==NULL) { printf("EMPTY"); return NULL; }// IS EMPTY
	if (del==NULL) { printf("NOT IN THE CIRCLE LINK\n"); return NULL; }
	if(del==head){
		link1 p=head; //DEL HEAD
		do { p=p->next; } 
		while (p->next != head); p->next=head->next; head=head->next; 
	} //
	else {
		link1 p=head, pre; 
		do { pre=p; p=p->next; } while (p != del); pre->next=del->next; //del tail or mid
	
	}
	printf("del  no %d name  %s:sal %d\n", del->num, del->name, del->sal); free (del); return head;
	

}

int main(){
	
	
	link1 head1, ptr1, newnode1;
	int new_num, new_sal; char new_name [10]; int pos=0, find, i;
	int data[12][2]={ 1001, 32367,1002, 24388,1003, 27556, 1007, 31299,
		1012,42660, 1014, 25676, 1018, 44145,1043,52182, 1031, 32769, 1037,21100, 1041, 32196, 1046, 25776}; char namedata[12][10]={{"Allen"}, {"Scott"},{"Marry"},{"John"},
			{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	head1=(link1)malloc(sizeof(node_emp));
	if (head1== NULL) { printf("Error!! meme error!!\n"); exit(1); }
	else {
		strcpy(head1->name, namedata[0]); head1->num=data[0][0]; head1->sal=data[0][1]; head1->next=head1; ptr1=head1; 
		for(i=1;i<12;i++) {
			newnode1=(link1)malloc(sizeof (node_emp)); memset(newnode1, 0, sizeof(node_emp));
			newnode1->num=data[i][0]; strcpy(newnode1->name, namedata[i]); newnode1->sal=data[i][1]; ptr1->next=newnode1; newnode1->next=head1; ptr1=newnode1;
			
		}
		print_emp(head1);
	}
	
	
	
	///add
	
	while(1) {
		printf("請輸入要插入其後的員工編號,如輸入的編號不在此串列中,"); 
		printf("to end enter -1:\n"); scanf("%d", &pos);
			if (pos==-1) break;
			else {
		
				ptr1=findnode(head1, pos); 
				if (ptr1 == NULL) 
					printf("not found!!");
				else {
					printf("enrwe no:"); scanf("%d", &new_num); 
					printf("enter sal : "); scanf("%d", &new_sal);
					printf("enter name:"); scanf("%s", new_name); 
					head1=insert(head1, ptr1, new_num, new_sal, new_name);
				}
			}
			print_emp (head1);
	}
	
	
	while(1) {
		printf("enter to del no-1: \n"); scanf("%d",&pos);
		if(pos==-1) break;
		else {
			ptr1=findnode(head1, pos);
			if(ptr1==NULL) printf("not founded!!");
			else head1=delete1(head1, ptr1);
			print_emp(head1);
		}
	}
	print_emp(head1);
	char namedata2[12][10]={{"May"},{"John"},{"Michael"}, {"Andy"},{"Tom"},{"Jane"},{"Yoko"},{"Axel"},{"Alex"},{"Judy"},{"Kelly"},{"Lucy"}};
	srand((unsigned)time(NULL));
	for (i=0;i<12; i++) { data[i][0]=i+13; data[i][1]-rand()%40+41; }
	link1 head2=(link1)malloc(sizeof(node_emp));; //create 2nd link head
	if(!head2) {printf("Error meme error\n"); exit(1); }
	else {
	strcpy(head2->name, namedata2[0]); 
		head2->num=data[0][0];
		head2->sal=data[0][1]; 
		head2->next=head2;
		ptr1=head2; 
		for(i=1;i<12;i++) {
			newnode1=(link1)malloc(sizeof(node_emp)); 
			newnode1->num=data[i][0]; 
			newnode1->sal=data[i][1];
			strcpy(newnode1->name, namedata2[i]); 
			ptr1->next=newnode1; newnode1->next=head2; ptr1=newnode1;
			
		}
		print_emp (head2);
	}

	ptr1=head1= concat(head1, head2); int cnt=0; printf("result: \n");
do { //列印串列資料
	if (ptr1->next!= head1) printf("[%d %s %3d] -> ", ptr1->num, ptr1->name, ptr1->sal);
	else printf("[%2d %6s %3d] \n", ptr1->num, ptr1->name, ptr1->sal);
	cnt++; if(cnt>=3) { printf("\n"); cnt=0; } //every 3 unit
	ptr1=ptr1->next;
} while(ptr1 != head1);
	return 0;
	
}

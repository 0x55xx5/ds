#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct employee {
	int num, salary;
	char name[10];
	struct employee *next;
};
typedef struct employee node;
typedef node *link;



link findnode(link head, int num) {
	link ptr;
	ptr = head;
	while (ptr != NULL) {
		if (ptr->num == num) return ptr;
		ptr = ptr->next;
	}
	return ptr;
}

link insertnode (link head, link ptr, int num, int salary, char name[10]) {
	link InsertNode;
	InsertNode = (link)malloc(sizeof(node));
	if (!InsertNode) return NULL;
	InsertNode->num = num;
	InsertNode->salary = salary;
	strcpy(InsertNode->name, name);
	InsertNode->next = NULL;
	if (ptr == head) {
		InsertNode->next = head;	   //插入第一個節點
		head = InsertNode;
	} else {
		if (ptr->next == NULL) ptr->next = InsertNode; //插入最後
		else {
			InsertNode->next = ptr->next;
			ptr->next = InsertNode;
		} //中間
	}
	return head;
}


link del_ptr(link head, link ptr) {
	link top;
	top = head;
	if (ptr->num == head->num) {
		head = head->next;    //del first
		printf("已刪除 %d %s %d \n", ptr->num, ptr->name, ptr->salary);
	} else {
		while (top->next != ptr) top = top->next; //找到刪除的點前第一個位置
		if (ptr->next == NULL) { //已刪除last
			top->next = NULL;
			printf("已刪除 %d %s %d \n", ptr->num, ptr->name, ptr->salary);
		} else { //刪除在中間節點
			top->next = ptr->next;
			printf("已刪除 %d %s %d \n", ptr->num, ptr->name, ptr->salary);
		}
		
	}
	free(ptr);
	return head;
}
link concatlist (link ptr1, link ptr2) {
	link ptr;
	ptr = ptr1;
	while (ptr->next != NULL) ptr = ptr->next;
	ptr->next = ptr2;
	return ptr1;
}

/* run this program using the console pauser or add your own getch, system("pause") or input Loop */
int main(int argc, char *argv[]) {
	
	
	link head1, ptr1, newnode, head2;
	int new_num, new_salary, i, j;
	char new_name [10];
	int position = 0, find;
	int data[12][2] = { 1001, 32367, 1002, 24388, 1003, 27556, 1007, 31299, 1012, 42660, 1014, 25676, 1018, 44145, 1043, 52182, 1031, 32769, 1037, 21100, 1041, 32196, 1046, 25776};
	char namedata[12][10] = {{"Allen"}, {"Scott"}, {"Marry"}, {"John"},
		{"Mark"}, {"Ricky"}, {"Lisa"}, {"Jasica"}, {"Hanson"}, {"Amy"}, {"Bob"}, {"Jack"}
	};
	head1 = (link)malloc(sizeof (node));
	if (!head1) {
		printf("Error!! MEM FAILED!!\n");
		exit(1);
	}
	head1->num = data[0][0];
	strcpy(head1->name, namedata[0]);
	head1->salary = data[0][1];
	head1->next = NULL;
	ptr1 = head1;
	for (i = 1; i < 12; i++) {
		newnode = (link)malloc(sizeof(node));
		newnode->num = data[i][0];
		strcpy(newnode->name, namedata[i]);
		newnode->salary = data[i][1];
		newnode->next = NULL;
		ptr1->next = newnode;
		ptr1 = ptr1->next;
		
	}
	printf("NUM    NAME   SALARY    \n");
	printf("\t============\n");
	link h = head1;
	while (h != NULL) {
		printf("\t[%4d]\t[ %-7s]\t[%6d]\n", h->num, h->name, h->salary);
		h = h->next;
	}
	
	///
	
	link p, q, x, r; x=head1; p=x; q=NULL; printf("reverse: \n");
	while(p!=NULL) { 
		r=q; q=p; p=p->next; q->next=r;
	}
	x=q;
	head1=ptr1=q; i=0;
	while(ptr1!=NULL) {
		if (ptr1->next != NULL) printf("[%2d %6s %3d] -> ",ptr1->num,ptr1->name,ptr1->salary);
		else printf("[%2d_%6s_%3d]\n",ptr1->num,ptr1->name,ptr1->salary);
		i++; if(i>=3) { printf("\n"); i=0; } //
		ptr1=ptr1->next;
		///
	}
	
	
	char namedata2[12][10]={{"May"},{"John"},{"Michael"}, {"Andy"},{"Tom"},{"Jane"},{"Yoko"},{"Axel"},{"Alex"},{"Judy"},{"Kelly"},{"Lucy"}};
	srand((unsigned)time(NULL));
	for (i=0;i<12;i++) { data[i][0]=i+13; data[i][1]=rand()%40+41; }
	head2=(link)malloc(sizeof(node)); //####
	if(!head2) { printf("Error!!BERAK!!\n"); exit(1); }
		head2->num=data[0][0]; head2->salary=data[0][1]; head2->next=NULL;
		strcpy(head2->name, namedata2[0]);
		ptr1=head2;
		for(i=1;i<12;i++) { //build second linklist
			newnode=(link)malloc(sizeof(node));
			newnode->num=data[i][0];
			strcpy(newnode->name,namedata2[i]); 
			newnode->salary=data[i][1];
			newnode->next=NULL;
			ptr1->next=newnode;
				ptr1=ptr1->next;
		}
	
		i=0; ptr1=concatlist (head1, head2); //link
		printf("result : \n");
		while (ptr1!=NULL) { //print
			if (ptr1->next != NULL) printf("[%2d %6s %3d] -> ",ptr1->num,ptr1->name,ptr1->salary);
			else printf("[%2d %6s %3d]\n",ptr1->num,ptr1->name,ptr1->salary);
			i++; if(i>=3) { printf("\n"); i=0; } //every 3)
			ptr1=ptr1->next;}
	return 0;
}

/*
NUM    NAME   SALARY
============
[1001]  [ Allen  ]      [ 32367]
[1002]  [ Scott  ]      [ 24388]
[1003]  [ Marry  ]      [ 27556]
[1007]  [ John   ]      [ 31299]
[1012]  [ Mark   ]      [ 42660]
[1014]  [ Ricky  ]      [ 25676]
[1018]  [ Lisa   ]      [ 44145]
[1043]  [ Jasica ]      [ 52182]
[1031]  [ Hanson ]      [ 32769]
[1037]  [ Amy    ]      [ 21100]
[1041]  [ Bob    ]      [ 32196]
[1046]  [ Jack   ]      [ 25776]
reverse:
[1046   Jack 25776] -> [1041    Bob 32196] -> [1037    Amy 21100] ->
[1031 Hanson 32769] -> [1043 Jasica 52182] -> [1018   Lisa 44145] ->
[1014  Ricky 25676] -> [1012   Mark 42660] -> [1007   John 31299] ->
[1003  Marry 27556] -> [1002  Scott 24388] -> [1001_ Allen_32367]

result :
[1046   Jack 25776] -> [1041    Bob 32196] -> [1037    Amy 21100] ->
[1031 Hanson 32769] -> [1043 Jasica 52182] -> [1018   Lisa 44145] ->
[1014  Ricky 25676] -> [1012   Mark 42660] -> [1007   John 31299] ->
[1003  Marry 27556] -> [1002  Scott 24388] -> [1001  Allen 32367] ->
[13    May  63] -> [14   John  41] -> [15 Michael  77] ->
[16   Andy  50] -> [17    Tom  52] -> [18   Jane  68] ->
[19   Yoko  72] -> [20   Axel  66] -> [21   Alex  47] ->
[22   Judy  60] -> [23  Kelly  56] -> [24   Lucy  73]


--------------------------------
Process exited after 0.4369 seconds with return value 0 (46.88 ms cpu time, 2784 KB mem used).

Press ANY key to exit...

*/

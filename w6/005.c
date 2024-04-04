
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



struct stu {
	char name[20], no[10];
	int Math, Eng;
	struct stu *rlink, *llink;
};

typedef struct stu s_data;
s_data *ptr, *head, *new_data;

struct emp { int num,sal; char name[10]; struct emp *llink,*rlink; };
typedef struct emp node_emp;
typedef node_emp *link1;

void print_link(s_data *head) { //雙向
	s_data *ptr = head, *pre;
	printf("向右\n");
	do {
		printf("name %s\tno:%s\t MATH:%d\t ENG :%d\n", ptr->name, ptr->no, ptr->Math, ptr->Eng);
		pre = ptr;
		ptr = ptr->rlink;
	} while (ptr != NULL);
	printf("向左\n");
	ptr = pre;
	do {
		printf("name %s\tno:%s\t MATH:%d\t ENG :%d\n", ptr->name, ptr->no, ptr->Math, ptr->Eng);
		ptr = ptr->llink;
	} while (ptr != NULL);
}
void print_DDlink(node_emp *head) { //雙向
	node_emp *ptr = head, *pre;
	printf("向右\n");
	do {
		printf("name %s\tsal:%d\t\n", ptr->name, ptr->sal);
		pre = ptr;
		ptr = ptr->rlink;
	} while (ptr != NULL);
	printf("向左\n");
	ptr = pre;
	do {
		printf("name %s\tsal:%d\t\n", ptr->name, ptr->sal);
		ptr = ptr->llink;
	} while (ptr != NULL);
}




link1 findnode(link1 head, int num) {
	link1 ptr=head; 
	while(ptr!=NULL) {
		if(ptr->num==num) 
			return ptr; 
		ptr=ptr->rlink; 
	} 
	return NULL;
}
link1 insert(link1 head1, link1 ptr1,int num,int sal,char name[10]) {
	link1 newnode1=(link1)malloc(sizeof(node_emp)); newnode1->llink=newnode1->rlink=NULL; newnode1->num=num; newnode1->sal=sal; strcpy(newnode1->name,name);
	if (head1==NULL) {
		return newnode1; 
	} //new 
	else {
		if(ptr1==head1) { 
			head1->llink=newnode1; newnode1->rlink=head1; head1=newnode1;
		} //add to head loc
		else{
			if(ptr1->rlink==NULL) { 
				ptr1->rlink=newnode1; newnode1->llink=ptr1;
			}
			else { //插入中間節點的位置
				newnode1->rlink=ptr1->rlink; ptr1->rlink->llink=newnode1;
				ptr1->rlink=newnode1; newnode1->llink=ptr1;
			}
		}
	}
	return head1;
}


link1 delete1(link1 head,link1 del) { //###G1
	if(head==NULL) { printf("empty\n"); return NULL; }//###EZ
	if(del==NULL) { printf("error \n"); return NULL; } 
	if(del==head) {head=head->rlink; head->llink=NULL;}  //del head
	else {
		if(del->rlink==NULL) { del->llink->rlink=NULL; }//del mid
		else { del->llink->rlink=del->rlink; del->rlink->llink=del->llink;
		}
		
	}
	free(del); return head;
}	

link1 concatlist(link1 ptr1,link1 ptr2) {
	link1 ptr=ptr1;
	while(ptr->rlink!=NULL)
		ptr=ptr->rlink;
	ptr->rlink=ptr2;

	
	return ptr1;
}

int main() {
	link1 head1, ptr1,newnode1, left;
	int pos=0, find, i; 
	int data[12][2]={1001,32367,1002,24388,1003,27556,1007,31299,1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	char namedata2[12][10]={{"May"},{"John"},{"Michael"}, {"Andy"},{"Tom"},{"Jane"},{"Yoko"},{"Axel"},{"Alex"},{"Judy"},{"Kelly"},{"Lucy"}};
	char namedata[12][10] = {{"Allen"}, {"Scott"}, {"Marry"}, {"John"}, {"Mark"}, {"Ricky"}, {"Lisa"}, {"Jasica"}, {"Hanson"}, {"Amy"}, {"Bob"}, {"Jack"}};
	head1 = (link1)malloc(sizeof(node_emp));
	if (head1 == NULL) {
		printf("Error!! ram alloc failed!!\n");
		exit(1);
	} else {
		memset(head1, 0, sizeof(node_emp));
		strcpy(head1->name, namedata[0]);
		head1->num = data[0][0];
		head1->sal = data[0][1];
		left = head1;
		for (i = 1; i < 12; i++) {
			newnode1 = (link1)malloc(sizeof(node_emp));
			memset(newnode1, 0, sizeof(node_emp));
			newnode1->num = data[i][0];
			strcpy(newnode1->name, namedata[i]);
			newnode1->sal = data[i][1];
			left->rlink = newnode1;
			newnode1->llink = left;
			left = newnode1;
		}
		
		printf("\n\t emNo   name\t   sal\n");
		printf("\t==============================\n");
		ptr1 = head1;
		
		while (ptr1 != NULL) {
			printf("\t[%2d]\t[ %-10s]\t[%3d]\n", ptr1->num, ptr1->name, ptr1->sal);
			ptr1 = ptr1->rlink;
		}
	}
	
	srand((unsigned)time(NULL));
	for (i=0;i<12;i++) { data[i][0]=i+13; data[i][1]=rand()%40+41; } 
	link1 head2=(link1)malloc(sizeof(node_emp));; //建立第2組串列首
	if(!head2) { printf("Error!! meme failed!!\n"); exit(1); }
	else {
		memset(head2,0,sizeof(node_emp)); strcpy(head2->name, namedata2[0]);
		head2->num=data[0][0]; head2->sal=data[0][1]; left=head2;
		for(i=1;i<12;i++) {
			newnode1=(link1)malloc(sizeof(node_emp)); memset(newnode1,0,sizeof(node_emp));
			newnode1->num=data[i][0]; strcpy(newnode1->name, namedata2[i]); newnode1->sal=data[i][1];
			left->rlink=newnode1; newnode1->llink=left; left=newnode1;
		}
		
		printf("\n\tno name\tsal\n"); printf("\t==============================\n");
		ptr1=head2;
		
		while(ptr1!=NULL) { printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr1->num,ptr1->name,ptr1->sal); ptr1=ptr1->rlink; }
		
	}

	i=0;
	ptr1=concatlist(head1, head2); //#50
		link1  start=ptr1;
	printf("result : \n");
	while (ptr1!=NULL) { //
		if (ptr1->rlink != NULL) printf("[%2d %6s %3d] -> ",ptr1->num,ptr1->name,ptr1->sal);
		else printf("[%2d %6s %3d]\n",ptr1->num,ptr1->name,ptr1->sal);
		i++;
		if(i>=3) { printf("\n"); i=0; } //every 3 
		ptr1=ptr1->rlink;
	}
	printf("\n");
	print_DDlink(ptr1);
}
/*


*/

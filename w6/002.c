
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//CIRCLE LINKEDLIST DEMO

struct student { char name[20]; char no[10]; struct student *next; };
typedef struct student s_data;
s_data *ptr1, *ptr, *head, *new_data;

void print_stu(s_data *h) {
	s_data *ptr1=h;
	do { 
		printf("name : %s\tstoNo:%s\n", ptr1->name,ptr1->no); 
		ptr1=ptr1->next; } 
	while(ptr1!= h); printf("------------------------\n");
}
int main() {
	
	int select, student_no=0, i=0; float Msum=0,Esum=0; char na[20]; char n1[10];
	do {
		printf("(1)add (2)exit =>"); scanf("%d", &select);
		if (select != 2) {
			printf("name 	 stuno:"); scanf("%s %s",na,n1);
			if (i==0){
				//CTRATE
				ptr=head=(s_data*) malloc(sizeof(s_data)); head->next=ptr;
				strcpy(head->no,n1); strcpy(head->name,na); i=1;
				
			}
			else {
				//CREATE CIRCLE LINKEDLIST
				new_data=(s_data*) malloc(sizeof(s_data));
				ptr->next = new_data; strcpy(new_data->no,n1); strcpy(new_data->name,na); new_data->next = head; ptr = new_data;
			}
		}
		print_stu(head);
} while (select != 2);
print_stu(head);
}
/*
//CIRCLE LINKEDLIST DEMO

(1)add (2)exit =>1
name     stuno:wwqwq 0001
name : wwqwq    stoNo:0001
------------------------
(1add (2)exit =>1 wqdfd 002
name     stuno:name : wwqwq     stoNo:0001
name : wqdfd    stoNo:002
------------------------
(1add (2)exit =>1
name     stuno:dddd 0003
name : wwqwq    stoNo:0001
name : wqdfd    stoNo:002
name : dddd     stoNo:0003
------------------------
(1add (2)exit =>2
name : wwqwq    stoNo:0001
name : wqdfd    stoNo:002
name : dddd     stoNo:0003
------------------------
name : wwqwq    stoNo:0001
name : wqdfd    stoNo:002
name : dddd     stoNo:0003
------------------------

*/

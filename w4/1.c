
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
	char name[20];
	int Math, Eng;
	char no[10];
	struct student *next;
};

typedef struct student s_data;
s_data *ptr;/* 存取指標 */
s_data *head;/* 串列開頭指標 */
s_data *new1; /* 新增元素所在位置指標*/

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
int main(int argc, char *argv[]) {

	head = (s_data*) malloc(sizeof(s_data));
	head->next = NULL;
	ptr = head;
	int sel, num, Msum, Esum;
	do {
		printf("(1)add (2)exit==>");
		scanf("%d", &sel);
		if (sel != 2) {
			printf("姓名 學號 數學成績 英文成績:");
			new1 = (s_data*) malloc(sizeof(s_data));
			scanf("%s %s %d %d", new1->name, new1->no, &new1->Math, &new1->Eng);
			ptr->next = new1;
			new1->next = NULL;
			ptr = ptr->next;
		}
	}	while (sel != 2);
	ptr = head->next;
	putchar('\n');
	num = Msum = Esum = 0;
	while (ptr != NULL) {
		printf("name:%s\tstu no:%s\tmath %d\teng :%d\n", ptr->name, ptr ->no, ptr->Math, ptr->Eng);
		Msum += ptr->Math;
		Esum += ptr->Eng;
		num++;
		ptr = ptr ->next;
	}

	printf("================================--%d %d %d\n", num, Esum, Msum);
	printf("linklist math  avg is %.2f  eng avh%.2f\n", Msum * 1.0 / num, Esum * 1.0 / num);
	return 0;
}
/*
(1)add (2)exit==>1
姓名 學號 數學成績 英文成績:name 123 12 55
(1)add (2)exit==>1
姓名 學號 數學成績 英文成績:rrr 3222 44 70
(1)add (2)exit==>2

name:name       stu no:123      math 12 eng :55
name:rrr        stu no:3222     math 44 eng :70
================================--2 125 56
linklist math  avg is 28.00  eng avh62.50

*/

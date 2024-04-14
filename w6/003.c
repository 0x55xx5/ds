
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


int main() {

	int i = 0, sel;
	char na[20], n[10];
	int m, e;
	do {
		printf("(1)add (2)exit =>");
		scanf("%d", &sel);
		if (sel != 2) {
			printf("name   no  math    eng :");
			scanf("%s %s %d %d", na, n, &m, &e);
			if (i == 0) {
				head = (s_data *)malloc(sizeof(s_data));
				strcpy(head->name, na);
				strcpy(head->no, n);
				head->Math = m;
				head->Eng = e;
				head->llink = NULL;
				head->rlink = NULL;
				ptr = head;
				i = 1;

			} else {
				new_data = (s_data *)malloc(sizeof(s_data));
				strcpy(new_data->name, na);
				strcpy(new_data->no, n);
				new_data->Math = m;
				new_data->Eng = e;
				ptr->rlink = new_data;
				new_data->rlink = NULL;
				new_data->llink = ptr;
				ptr = new_data;
			}

		}
		print_link(head);
	} while (sel != 2);
	print_link(head);
}
/*
(1)add (2)exit =>1
name   no  math    eng :wa  0001 12 55
向右
name wa no:0001  MATH:12         ENG :55
向左
name wa no:0001  MATH:12         ENG :55
(1)add (2)exit =>1
name   no  math    eng :kkkkk 0002 99 100
向右
name wa no:0001  MATH:12         ENG :55
name kkkkk      no:0002  MATH:99         ENG :100
向左
name kkkkk      no:0002  MATH:99         ENG :100
name wa no:0001  MATH:12         ENG :55
(1)add (2)exit =>


*/

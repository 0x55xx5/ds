
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//雙向 add del find 
struct emp {
	int num, sal;
	char name[10];
	struct emp *llink, *rlink;

};
typedef struct emp node_emp;
typedef node_emp *link1;
link1 findnode(link1 head, int num) {
	link1 ptr = head;
	while (ptr != NULL) {
		if (ptr->num == num)
			return ptr;
		ptr = ptr->rlink;
	}
	return NULL;
}
int getlen(link1 cir_h) {
	int n = 0;
	if (cir_h != NULL) {
		link1 p = cir_h;
		do {
			n++;
			p = p->rlink;
			printf("total %d", n);
		} while (p != cir_h);
		return n;
	}
	

}

void print_emp(link1 h) {
	link1 ptr1 = h;

	do{
		printf("---\t[%2d]\t[ %-10s]\t[%3d]\n", ptr1->num, ptr1->name, ptr1->sal);
		ptr1 = ptr1->rlink;
			
	}while(ptr1 != h);
		printf("-1--");
	printf("%d",getlen(h));
}


link1 insert(link1 head1, link1 ptr1, int num, int sal, char name[10]) {
	link1 newnode1 = (link1)malloc(sizeof(node_emp));//init new
	newnode1->llink = newnode1->rlink = NULL;//init
	newnode1->num = num;
	newnode1->sal = sal;
	strcpy(newnode1->name, name);
	if (head1 == NULL) {
		return newnode1;
	} 
	else {
		if (ptr1 == head1) {//add to head loc
			head1->llink = newnode1;
			newnode1->rlink = head1;
			head1 = newnode1;
		} 
		else {
			if (ptr1->rlink == NULL) {//add to tail
				ptr1->rlink = newnode1;
				newnode1->llink = ptr1;
			} else { //插入中間節點的位置
				newnode1->rlink = ptr1->rlink;
				ptr1->rlink->llink = newnode1;
				ptr1->rlink = newnode1;
				newnode1->llink = ptr1;
			}
		}
	}
	return head1;
}


link1 delete1(link1 head, link1 del) { 
	if (head == NULL) {
		printf("empty\n");    //###EZ
		return NULL;
	}
	if (del == NULL) {
		printf("error \n");
		return NULL;
	}
	if (del == head) {
		head = head->rlink;    //del head
		head->llink = NULL;
	} else {
		if (del->rlink == NULL) {
			del->llink->rlink = NULL;    //del tail
		} else {
			del->llink->rlink = del->rlink;
			del->rlink->llink = del->llink;//del mid
		}

	}
	free(del);
	return head;
}
int main() {

	link1 head1, ptr1, newnode1, left;
	int new_num, new_sal;
	char new_name[10];
	int pos = 0, find, i;
	int data[12][2] = {1001, 32367, 1002, 24388, 1003, 27556, 1007, 31299, 1012, 42660, 1014, 25676, 1018, 44145, 1043, 52182, 1031, 32769, 1037, 21100, 1041, 32196, 1046, 25776};
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
				printf("-\t[%2d]\t[ %-10s]\t[%3d]\n", ptr1->num, ptr1->name, ptr1->sal);
				ptr1 = ptr1->rlink;
		}
	}


	//CRUD

	while (1) {
		printf("請輸入要插入其後的員工編號,如輸入的編號不在此串列中,\n");
		printf("新輸入的員工節點將視為此串列的第一個節點,要結束插入過程,enter -1: ");
		scanf("%d", &pos);
		if (pos == -1) break;
		else {
			ptr1 = findnode(head1, pos);
			if (ptr1 == NULL)
				printf("not founded");
			else {
				printf("insert  no:");
				scanf("%d", &new_num);
				printf("insert  sal:");
				scanf("%d", &new_sal);
				printf("insert  name:");
				scanf("%s", new_name);
				head1 = insert(head1, ptr1, new_num, new_sal, new_name);
			}
		}
		printf("\n\t no    name \t sa\n");
		printf("=============================================\n");
		ptr1 = head1;
		while (ptr1 != NULL) {
			printf("\t[%2d]\t[ %-10s]\t[%3d]\n", ptr1->num, ptr1->name, ptr1->sal);
			ptr1 = ptr1->rlink;
		}
	}
	//del


	while (1) {
		printf("enter no to del ");
		scanf("%d", &pos);
		if (pos == -1) break;
		else {
			ptr1 = findnode(head1, pos);

			if (ptr1 == NULL) printf("not founded");
			else {
				head1 = delete1(head1, ptr1);
				printf("del %d employee name: %s sal:%d\n", ptr1->num, ptr1->name, ptr1->sal);
			}
		}
		printf("\no   name  	\tsal\n");
		printf("\t===============================\n");
		ptr1 = head1;
		while (ptr1 != NULL) {
			printf("\t[%2d]\t[ %-10s]\t[%3d]\n", ptr1->num, ptr1->name, ptr1->sal);
			ptr1 = ptr1->rlink;
		}

	}
	printf("\no   name  	\tsal\n");
	printf("\t===============================\n");
	ptr1 = head1;
	while (ptr1 != NULL) {
		printf("\t[%2d]\t[ %-10s]\t[%3d]\n", ptr1->num, ptr1->name, ptr1->sal);
		ptr1 = ptr1->rlink;
	}
}
/*

emNo   name       sal
==============================
[1001]  [ Allen     ]   [32367]
[1002]  [ Scott     ]   [24388]
[1003]  [ Marry     ]   [27556]
[1007]  [ John      ]   [31299]
[1012]  [ Mark      ]   [42660]
[1014]  [ Ricky     ]   [25676]
[1018]  [ Lisa      ]   [44145]
[1043]  [ Jasica    ]   [52182]
[1031]  [ Hanson    ]   [32769]
[1037]  [ Amy       ]   [21100]
[1041]  [ Bob       ]   [32196]
[1046]  [ Jack      ]   [25776]
請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的第一個節點,要結束插入過程,enter -1: 1001
insert  no:1022
insert  sal:33342
insert  name:kkk

no    name      sa
=============================================
[1022]  [ kkk       ]   [33342]
[1001]  [ Allen     ]   [32367]
[1002]  [ Scott     ]   [24388]
[1003]  [ Marry     ]   [27556]
[1007]  [ John      ]   [31299]
[1012]  [ Mark      ]   [42660]
[1014]  [ Ricky     ]   [25676]
[1018]  [ Lisa      ]   [44145]
[1043]  [ Jasica    ]   [52182]
[1031]  [ Hanson    ]   [32769]
[1037]  [ Amy       ]   [21100]
[1041]  [ Bob       ]   [32196]
[1046]  [ Jack      ]   [25776]
請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的第一個節點,要結束插入過程,enter -1: 1046
insert  no:1047
insert  sal:54564
insert  name:kkk

no    name      sa
=============================================
[1022]  [ kkk       ]   [33342]
[1001]  [ Allen     ]   [32367]
[1002]  [ Scott     ]   [24388]
[1003]  [ Marry     ]   [27556]
[1007]  [ John      ]   [31299]
[1012]  [ Mark      ]   [42660]
[1014]  [ Ricky     ]   [25676]
[1018]  [ Lisa      ]   [44145]
[1043]  [ Jasica    ]   [52182]
[1031]  [ Hanson    ]   [32769]
[1037]  [ Amy       ]   [21100]
[1041]  [ Bob       ]   [32196]
[1046]  [ Jack      ]   [25776]
[1047]  [ kkk       ]   [54564]
請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的第一個節點,要結束插入過程,enter -1: 1006
not founded !!
no    name      sa
=============================================
[1022]  [ kkk       ]   [33342]
[1001]  [ Allen     ]   [32367]
[1002]  [ Scott     ]   [24388]
[1003]  [ Marry     ]   [27556]
[1007]  [ John      ]   [31299]
[1012]  [ Mark      ]   [42660]
[1014]  [ Ricky     ]   [25676]
[1018]  [ Lisa      ]   [44145]
[1043]  [ Jasica    ]   [52182]
[1031]  [ Hanson    ]   [32769]
[1037]  [ Amy       ]   [21100]
[1041]  [ Bob       ]   [32196]
[1046]  [ Jack      ]   [25776]
[1047]  [ kkk       ]   [54564]
請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的第一個節點,要結束插入過程,enter -1:

enter no to del 1043
del 1043 employee name: Jasica sal:52182

o   name                sal
===============================
[1031]  [ Hanson    ]   [32769]
[1037]  [ Amy       ]   [21100]
[1041]  [ Bob       ]   [32196]
enter no to del 1031
del 1031 employee name: Hanson sal:32769

o   name                sal
===============================
[1037]  [ Amy       ]   [21100]
[1041]  [ Bob       ]   [32196]
enter no to del 1037
del 1037 employee name: Amy sal:21100

o   name                sal
===============================
[1041]  [ Bob       ]   [32196]
enter no to del 1041

--------------------------------

*/

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
		else {//INSERT中間
			InsertNode->next = ptr->next;
			ptr->next = InsertNode;
		} 
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
		free(ptr);
		return head;
	}
}
link concatlist (link ptr1, link ptr2) {
	link ptr;
	ptr = ptr1;
	while (ptr->next != NULL) ptr = ptr->next;
	ptr->next = ptr2;
	return ptr1;
}

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
	printf("NUM.    NAME   SALARY    \n");
	printf("\t====================\n");
	link h = head1;
	while (h != NULL) {//SHOW DATA
		printf("\t[%4d]\t[ %-7s]\t[%6d]\n", h->num, h->name, h->salary);
		h = h->next;
	}
	while (1) {
		printf("\n請輸入要插入其後的員工編號,如輸入的編號不在此串列中,\n");
		printf("新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:");
		scanf("%d", &position);
		if (position == -1) break;
		else {
			ptr1 = findnode(head1, position);
			printf("enter num:");
			scanf("%d", &new_num);
			printf("enter sal:");
			scanf("%d", &new_salary);
			printf("enter name:");
			scanf("%s", new_name);
			head1 = insertnode(head1, ptr1, new_num, new_salary, new_name);

		}
		printf("NUM.    NAME   SALARY    \n");
		printf("\t=============================\n");
		link h = head1;//PRINT
		while (h != NULL) {
			printf("\t[%4d]\t[ %-7s]\t[%6d]\n", h->num, h->name, h->salary);
			h = h->next;
		}

	}

	ptr1 = head1;
	printf("NUM    NAME   SALARY    \n");
	printf("\t=============================\n");
	while (ptr1 != NULL) {//PRINT
		printf("\t[%4d]\t[ %-7s]\t[%6d]\n", ptr1->num, ptr1->name, ptr1->salary);
		ptr1 = ptr1->next;
	}

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

請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:1001
enter num:1000
enter sal:40000
enter name:kkkk
NUM    NAME   SALARY
================ =============
[1000]  [ kkkk   ]      [ 40000]
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

請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:1046
enter num:1048
enter sal:45777
enter name:namamm
NUM    NAME   SALARY
================ =============
[1000]  [ kkkk   ]      [ 40000]
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
[1048]  [ namamm ]      [ 45777]

請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:-1
NUM    NAME   SALARY
================ =============
[1000]  [ kkkk   ]      [ 40000]
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
[1048]  [ namamm ]      [ 45777]

 */

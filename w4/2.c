
#include <stdio.h>
#include <stdlib.h>
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
int main(int argc, char *argv[]) {
	link head,ptr,newnode;
	int new_num,new_salary;
	char new_name[10];
	int i,j,position=0,find;
	int data[12][2]={1001,31244,1002,68900,1003,91234,1007,85000,1012,56000,1014,28000,1018,23000,1043,31200,1031,31500,1037,45462,1041,56244,1046,21344};
char  namedata[12][10]={{"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},{"H"},{"I"},{"J"},{"K"},{"L"}};
	printf("no salary no salary no salary no salary\n ");
		printf("===================================\n ");
	
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			printf("[%4d] $NTD%5d",data[j*3+i][0],data[j*3+i][1]);
			printf("\n");
			//TODO
		}
		//TODO
	}
printf("===================================\n ");
	head = (link)malloc(sizeof(node));
	if (!head) {
		printf("Error!! memory failed!!\n");
		exit(1);
	}
	head->num = data[0][0];
	for (j = 0; j < 10; j++) head->name [j] = namedata[0][j];
	head->salary = data[0][1];
	head->next = NULL;
	ptr = head;
	for (i = 1; i < 12; i++) {
		newnode = (link)malloc(sizeof(node));
		newnode->num = data[i][0];
		for (j = 0; j < 10; j++) newnode->name [j] = namedata[i][j];
		newnode->salary = data[i][1];
		newnode->next = NULL;
		ptr->next = newnode;
		ptr = ptr->next;
	}

	while (1) {
		printf("\n請輸入要插入其後的員工編號,如輸入的編號不在此串列中,\n");
		printf("新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:");
		scanf("%d", &position);
		
		if (position == -1) break;
		else {
			ptr = findnode (head, position);
			printf("enter employee no:");
			scanf("%d", &new_num);
			printf("enter salary:");
			scanf("%d", &new_salary);
			printf("enter name:");
			scanf("%s", new_name);
			head = insertnode (head, ptr, new_num, new_salary, new_name);
		}
	}


	ptr = head;
	printf("\n\temployee no		name\t salary\n");
	printf("\t==============================\n");
	while (ptr != NULL) {
		printf("\t[%2d]\t[ %-7s]\t[%3d]\n", ptr->num, ptr->name, ptr->salary);
		ptr = ptr->next;
	}
	return 0;
}



/*
no salary no salary no salary no salary
===================================
[1001] $NTD31244
[1007] $NTD85000
[1018] $NTD23000
[1037] $NTD45462
[1002] $NTD68900
[1012] $NTD56000
[1043] $NTD31200
[1041] $NTD56244
[1003] $NTD91234
[1014] $NTD28000
[1031] $NTD31500
[1046] $NTD21344
===================================

請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:1001
enter employee no:1000
enter salary:21650
enter name:yy

請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:1046
enter employee no:1048
enter salary:45000
enter name:mmm

請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:1014
enter employee no:1016
enter salary:42000
enter name:lolo

請輸入要插入其後的員工編號,如輸入的編號不在此串列中,
新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1:-1

employee no             name     salary
==============================
[1000]  [ yy     ]      [21650]
[1001]  [ A      ]      [31244]
[1002]  [ B      ]      [68900]
[1003]  [ C      ]      [91234]
[1007]  [ D      ]      [85000]
[1012]  [ E      ]      [56000]
[1014]  [ F      ]      [28000]
[1016]  [ lolo   ]      [42000]
[1018]  [ G      ]      [23000]
[1043]  [ H      ]      [31200]
[1031]  [ I      ]      [31500]
[1037]  [ J      ]      [45462]
[1041]  [ K      ]      [56244]
[1046]  [ L      ]      [21344]
[1048]  [ mmm    ]      [45000]

--------------------------------

*/

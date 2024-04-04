
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct list {
	int coef, exp;
	struct list *next;
};
typedef struct list node;
typedef node *link;
link creat_link(int data[4]) {
	int i;
	link head, newnode, ptr;
	for (i = 0; i < 4; i++) {
		newnode = (link)malloc(sizeof(node));
		if (!newnode) {
			printf("Error!!ram alloc failed!!\n");
			exit(i);
		}
		if (i == 0) {
			newnode->coef = data[i];
			newnode->exp = 3 - i;
			newnode->next = NULL;
			head = newnode;
			ptr = head;
		}

		else if (data[i] != 0) {
			newnode->coef = data[i];
			newnode->exp = 3 - i;
			newnode->next = NULL;
			ptr->next = newnode;
			ptr = newnode;
		}


	}
	return head;
}
void print_link(link head) {
	while (head != NULL) {
		if (head->exp == 1 && head->coef != 0) /*X^1不顯示指數*/
			printf("%dX + ", head->coef);
		else if (head->exp != 0 && head->coef != 0)
			printf("%dX^%d + ", head->coef, head->exp);
		else if (head->coef != 0) /*X^0不顯示指*/
			printf("%d", head->coef);
		head = head->next;

	}
	printf("\n");
}

link sum_link(link a, link b) {
	int sum[4], i = 0;
	link ptr = b;
	while (a != NULL) {
		b = ptr;
		/*重複比較A及B的指數*/
		while (b != NULL) {
			if (a->exp == b->exp) {
				sum[i] = a->coef + b->coef;
				a = a->next;
				b = b->next;
				i++;
			} else if (b->exp > a->exp) {
				sum[i] = b->coef;
				b = b->next;
				i++;
			} else if (a->exp > b->exp) {
				sum[i] = a->coef;
				a = a->next;
				i++;
			}
		}
	}
	return creat_link(sum);
}
int main() {
	link a, b, c;
	int data1[4] = {3, 0, 4, 2};
	int data2[4] = {6, 8, 6, 9};
	a = creat_link(data1);
	b = creat_link(data2);
	printf("original A=");
	print_link(a);
	printf(" original B=");
	print_link(b);
	printf("### : \nC=");
	c = sum_link(a, b);
	print_link(c);
}
/*

original A=3X^3 + 4X + 2
original B=6X^3 + 8X^2 + 6X + 9
### :
C=9X^3 + 8X^2 + 10X + 11

--------------------------------
Process exited after 0.1427 seconds with return value 0 (0 ms cpu time, 2772 KB mem used).

Press ANY key to exit...

*/

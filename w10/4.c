
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
struct stu{ char name[20]; int score; struct stu *next; };
typedef struct stu s_data;
s_data *front =NULL;
s_data *rear = NULL;
int enqueue(char* name, int score) {
    s_data *new_data= (s_data*) malloc(sizeof(s_data));
    strcpy(new_data->name, name);
    new_data->score = score;
    if (rear == NULL) front = new_data; else rear->next = new_data;
    rear =new_data; new_data->next = NULL;
}

int dequeue() {
    s_data *freeme;
    if (front == NULL) puts("AEE!");
    else {
        printf("%s\t%d....\n", front->name, front->score);
        freeme= front; front= front->next; free(freeme);
    }
}

int show() {
    s_data *ptr = front;
    if (ptr == NULL) puts("EE!");
    else {
        printf("front -> rear\n"); while (ptr != NULL) { printf("%s\t%d\n", ptr->name, ptr->score); ptr = ptr->next; }
    }
}

int main() {
    int sel, sc;
    char name[20];
    do {
    printf("(1) (2) (3) (4)FH => "); scanf("%d", &sel);
    switch (sel) {
    case 1: printf("Z :"); scanf("%s %d", name, &sc); enqueue(name, sc); break;
    case 2: dequeue(); break;
    case 3: show(); break;
    }
    } while (sel != 4);
    show(); system("pause"); return 0;
}
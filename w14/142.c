
#include <stdio.h> #include <stdlib.h>
#define MAXSIZE 10
int front=-1;
int rear=-1;
struct list { int val; struct list *next; };
typedef struct list node;
typedef node *link;
struct GraphLink { link first, last; };
int run[9];
int queue[MAXSIZE];
struct GraphLink head[9];
void insert(struct GraphLink *temp, int x) {
    link newNode;
newNode=(link)malloc(sizeof(node)); newNode->val=x; newNode->next=NULL;
 if(temp->first==NULL) { temp->first=temp->last=newNode; }
else { temp->last->next=newNode; temp->last=newNode; }
}

void enqueue(int value) { if(rear>=MAXSIZE) return; rear++; queue[rear]=value; }
int dequeue() { if(front==rear) return -1; front++; return queue[front]; }
void bfs(int cur) {
    link temp; enqueue(cur); run[cur]=1; printf("[%d]",cur);
        while(front!=rear) {
            cur=dequeue(); temp=head[cur].first;
            while(temp!=NULL) {
                if(run [temp->val]==0) { enqueue(temp->val); run[temp->val]=1; printf("[%d]",temp->val); }
                temp-temp->next;
            }
        }
    }
void print(struct GraphLink temp) {
    link cur=temp.first; while(cur!=NULL) { printf("[%d]",cur->val); cur=cur->next; } printf("\n");
}

int main() {
int data[14][2] = { {1,2},{2,1},{1,5},{5,1},{2,4},{4,2},{2,3},{3,2},{3,4},{4,3},{5,3},{3,5},{4,5},{5,4}};
int i,j; printf("圓形的鄰接串列內容: \n");
for(i=1; i<6; i++) {
    run[i]=0; printf("v %d=>",i);head[i].first=NULL; head[i].last=NULL;
    for(j=0; j<14 ;j++) if(data[j][0]==i) insert(&head[i],data[j][1]); print(head[i]);
}

printf("bfs \n"); bfs(1); printf("\n");
int data2[20][2]={{1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},{3,7},{7,3},{4,8},{8,4},{5,8},{8,5},{6,8},{8,6},{8,7},{7,8}};
printf("圓形的鄰接串列內容: \n");
for(i=1; i<9; i++) {
run[i]=0; printf("v %d=>",i);head[i].first=NULL; head[i].last=NULL;
for(j=0; j<20 ;j++) if(data2[j][0]==i) insert(&head[i],data2[j][1]); print(head[i]);
}
printf("bfs : \n"); bfs(1); printf("\n");
system("pause"); return 0;
}
/**
 process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
4=> [2][8]
5=> [2][8]
6=> [3][8]
7=> [3][8]
8=> [4][5][6][7]
dfs : 
[1][2][4][8][5][6][3][7]
process the point 1-->[1] [2] [5] 
process the point 2-->[2] [1] [4] [3] 
process the point 3-->[3] [2] [4] [5] 
process the point 4-->[4] [2] [3] [5] 
process the point 5-->[5] [1] [3] [4] 
圖形的相鄰串列內容: 
1=> [2][5]
process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
4=> [2][8]
5=> [2][8]
6=> [3][8]
7=> [3][8]
8=> [4][5][6][7]
dfs : 
[1][2][4][8][5][6][3][7]
process the point 1-->[1] [2] [5] 
process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
4=> [2][8]
5=> [2][8]
6=> [3][8]
7=> [3][8]
8=> [4][5][6][7]
dfs : 
[1][2][4][8][5][6][3][7]
process the point 1-->[1] [2] [5] 
process the point 2-->[2] [1] [4] [3] 
process the point 3-->[3] [2] [4] [5] 
process the point 4-->[4] [2] [3] [5] 
process the point 5-->[5] [1] [3] [4] 
圖形的相鄰串列內容: 
1=> [2][5]
2=> [1][4][3]
3=> [2][4][5]
4=> [2][3][5]
5=> [1][3][4]
dfs
[1][2][4][3][5]
process the point 1-->[1] [2] [3] 
process the point 2-->[2] [1] [4] [5] 
process the point 3-->[3] [1] [6] [7] 
process the point 4-->[4] [2] [8] 
process the point 5-->[5] [2] [8] 
process the point 6-->[6] [3] [8] 
process the point 7-->[7] [3] [8] 
process the point 8-->[8] [4] [5] [6] [7] 
圖形的相鄰串列內容: 
1=> [2][3]
2=> [1][4][5]
3=> [1][6][7]
4=> [2][8]
5=> [2][8]
6=> [3][8]
7=> [3][8]
8=> [4][5][6][7]
dfs : 
[1][2][4][8][5][6][3][7]
process the point 1-->[1] [2] [5] 
process the point 2-->[2] [1] [4] [3] 
process the point 3-->[3] [2] [4] [5] 
process the point 4-->[4] [2] [3] [5] 
process the point 5-->[5] [1] [3] [4] 
圖形的相鄰串列內容: 
1=> [2][5]
2=> [1][4][3]
3=> [2][4][5]
4=> [2][3][5]
5=> [1][3][4]
dfs
[1][2][4][3][5]
sh: pause: command not found
 
 * /
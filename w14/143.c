
// Kruskal's algorithm

#include <stdio.h>
#include <stdlib.h>
#define VERTS 6
struct edge { int from,to,find,val; struct edge* next; };
typedef struct edge node;
typedef node* mst;
int v[VERTS+1];
mst findmincost(mst h) {
int minval=100;
mst ptr=h,retptr;
while(ptr!=NULL) {
    if(ptr->val<minval&&ptr->find==0) { minval=ptr->val; retptr=ptr; } ptr=ptr->next;
}
retptr->find=1; return retptr;
}

void mintree(mst head) {
mst ptr=head,mceptr;
int i,result=0;
for(i=0;i<=VERTS;i++) v[i]=0;
while(ptr!=NULL) {
    mceptr=findmincost(head); printf("find value%d\n",mceptr->val);
    v[mceptr->from]++; v[mceptr->to]++; printf("%d, %d, v[%d]->v[%d]\n",mceptr->from, mceptr->to,v[mceptr->from],v[mceptr->to]); 
    if(v[mceptr->from]>1&&v[mceptr->to]>1) { v[mceptr->from]--; v[mceptr->to]--; result=1; } 
    else result=0;
    if(result==0) printf("start at [%d] -> end at [%d] -> len [%d]\n",mceptr->from,mceptr->to,mceptr->val); 
    ptr=ptr->next;
    }
}
void print(mst h) { while (h!=NULL) { printf("from:%d › to:%d › cost=%d\n",h->from,h->to,h->val); h=h->next; } }


int main() {
int data[10][3]={{1,2,6},{1,6,12},{1,5,10},{2,3,3}, {2,4,5},{2,6,8},{3,4,7},{4,6,11}, {4,5,9},{5,6,16}}; int i,j;
mst head,ptr, newnode;
head=NULL;
for(i=0;i<10;i++) {
for(j=1;j<=VERTS;j++) {
if(data[i][0]==j) {
    newnode=(mst)malloc(sizeof(node)); newnode->from=data[i][0]; newnode->to=data[i][1]; 
    newnode->val=data[i][2]; newnode->find=0; newnode->next=NULL; 
    if(head==NULL) { head=newnode; head->next=NULL; ptr=head; }
    else { ptr->next=newnode; ptr=ptr->next; }
}
}

} print (head);
printf("min cost tree:\n"); 
printf("\n"); mintree(head);
 return 0;
}

/*
from:1 › to:2 › cost=6
from:1 › to:6 › cost=12
from:1 › to:5 › cost=10
from:2 › to:3 › cost=3
from:2 › to:4 › cost=5
from:2 › to:6 › cost=8
from:3 › to:4 › cost=7
from:4 › to:6 › cost=11
from:4 › to:5 › cost=9
from:5 › to:6 › cost=16
min cost tree:

find value3
2, 3, v[1]->v[1]
start at [2] -> end at [3] -> len [3]
find value5
2, 4, v[2]->v[1]
start at [2] -> end at [4] -> len [5]
find value6
1, 2, v[1]->v[3]
start at [1] -> end at [2] -> len [6]
find value7
3, 4, v[2]->v[2]
find value8
2, 6, v[4]->v[1]
start at [2] -> end at [6] -> len [8]
find value9
4, 5, v[2]->v[1]
start at [4] -> end at [5] -> len [9]
find value10
1, 5, v[2]->v[2]
find value11
4, 6, v[3]->v[2]
find value12
1, 6, v[2]->v[2]
find value16
5, 6, v[2]->v[2]
*/

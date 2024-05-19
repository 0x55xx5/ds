
#include <stdio.h>
#include <stdlib.h>
struct tree{ int data; struct tree *left, *right; };
typedef struct tree node;
typedef node *btree;
btree creat_tree(btree root, int val){
    btree newnode, current, backup;
    newnode=(btree)malloc(sizeof(node));
    newnode->data=val; newnode->left=NULL; newnode->right=NULL; 
    if(root==NULL) { root=newnode; return root; }
    else {
        for (current=root; current!= NULL;) {
            backup=current;
        if(current->data > val) current=current->left; else current=current->right;
    }
     if(backup->data >val) backup->left=newnode; else backup->right=newnode;
    
}
return root;
}


int main() {
int i,data[]={5,6,24,8,12,3,17,1,9};
btree ptr=NULL, root=NULL;
for(i=0;i<9;i++) ptr=creat_tree(ptr,data[i]);
printf("left tree:\n"); root=ptr->left;
while(root!= NULL) { printf("%d\n", root->data); root=root->left; }
printf("--\n");
printf("right tree:\n"); root=ptr->right;

while(root!=NULL) { printf("%d\n",root->data); root=root->right; } printf("\n"); 
system("pause"); return 0;
}
/*
left tree:
3
1
--
right tree:
6
24


*/
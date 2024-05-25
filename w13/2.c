
#include <stdio.h>
#include <stdlib.h>
int main() {
int arr[6][6]={0},i,j,k,tmpi, tmpj;
int data[7][2]={{1,2},{2,1},{2,3}, {2,4}, {4,3},{4,1}};
for (i=0;i<6;i++)
    for (j=0;j<6;j++) {
         tmpi=data[i][0]; tmpj=data[i][1]; arr[tmpi][tmpj]=1; } 
printf("有向 : \n");
for (i=1;i<6;i++) {
    for (j=1;j<6;j++) printf("[%d]", arr[i][j]); printf("\n");
}
return 0;
}
/*
有向 : 
[0][1][0][0][0]
[1][0][1][1][0]
[0][0][0][0][0]
[1][0][1][0][0]
[0][0][0][0][0]
*/
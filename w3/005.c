#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#define ITEMS 6
/* run this program using the console pauser or add your own getch, system("pause") or input Loop */
void MatrixMultiply (int*, int*, int*, int, int, int);
void PrintPoly(int Poly[], int items);
void PolySum(int Poly1[ITEMS], int Poly2[ITEMS]);
int main(int argc, char *argv[]) {
	
	int num[2][3][3]={{{33,45,67}, {23,71,56}, {55,38,66}},  {{21,9,15 }, {38,69,18}, {90,101,89}}};
	int min=num[0][0][0], *p=&num[0][0][0];
	printf("stud class as  num:\n");
	for(int i=0;i<2;i++) {
		printf("| \n");
		for(int j=0;j<3;j++) {
			printf(" | ");
			for(int k=0;k<3;k++) printf("%d\t",num[i][j][k]); printf(" | \n");
		} printf("| \n");
	}
	
	printf("use pointer to  travse : \n");
	for(int i=0;i<2;i++) {
		printf("| \n");
		for(int j=0;j<3;j++) {
			printf(" | ");
			for (int k=0;k<3; k++) printf("%d\t",*(p++)); printf(" | \n");
		} printf(" | \n");
	}
	
	for(int i=0;i<2;i++)
		for(int j=0;j<3;j++)
			for (int k=0;k<3;k++)
				if(min>=num[i][j][k]) min=num[i][j][k];
	printf("min val is  %d\n",min);
	
	return 0;
}

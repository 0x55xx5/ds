#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#define ITEMS 6
int main(int argc, char *argv[]) {
	
	int num[2][3][3]={{{33,45,67}, {23,71,56}, {55,38,66}},  {{21,9,15 }, {38,69,18}, {90,101,89}}};
	int min=num[0][0][0], *p=&num[0][0][0];
	printf("stud class as  num:\n");
	for(int i=0;i<2;i++) {
		for(int j=0;j<3;j++) {
			printf(" | ");
			for(int k=0;k<3;k++) printf("%d\t",num[i][j][k]); printf(" | \n");
		} printf("common method \n");
	}
	
	printf("use pointer to  travse : \n");
	for(int i=0;i<2;i++) {

		for(int j=0;j<3;j++) {
			printf(" | ");
			for (int k=0;k<3; k++) printf("%d\t",*(p++)); printf(" | \n");
		} printf(" ptr method \n");
	}
	
	for(int i=0;i<2;i++)
		for(int j=0;j<3;j++)
			for (int k=0;k<3;k++)
				if(min>=num[i][j][k]) min=num[i][j][k];
	printf("min val is  %d\n",min);
	
	return 0;
}//find min in array
/*
stud class as  num:
| 33   45      67       |
| 23   71      56       |
| 55   38      66       |
common method
| 21   9       15       |
| 38   69      18       |
| 90   101     89       |
common method
use pointer to  travse :
| 33   45      67       |
| 23   71      56       |
| 55   38      66       |
ptr method
| 21   9       15       |
| 38   69      18       |
| 90   101     89       |
ptr method
min val is  9


*/

#include <stdio.h>

#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	
	int n,s,st,loc, addr;
	while (1) {
		printf("location of array-->"); scanf("%d",&n);//500
		if (n==0) break;
		printf("SIZE-->"); scanf("%d",&s);//
		printf("BASE-Hexadecimal-->"); scanf("%x",&st);//16(1000)
		printf("CALCULATE POS-->"); scanf("%d",&loc);//1000 
		addr=st+(loc-n)*s; printf("index +1=%d ADDR IS %d\n",loc,addr);
		return 0;
	}

}/*
location of array-->500
SIZE-->4
BASE(Hexadecimal 16)-->1000
CALCULATE POS-->1000
index +1=1000 ADDR IS 6096

1000+(1000-500)*4
--------------------------------
Process exited after 18.48 seconds with return value 0 (0 ms cpu time, 2864 KB mem used).*/


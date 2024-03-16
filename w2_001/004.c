#include <stdio.h>

#include <stdlib.h>


int main(int argc, char *argv[]) {


	char s1[] = "my day is a sunny day", *s2 = "this is a book", s3[30], s4[40];
	strcpy(s3, s1);
	strcpy(s4, s2);
	printf("%s %s|%s|%s\n", s1, s2, s3, s4);
	printf("%d %d\n", strlen(s1), strlen(s2));
	char s5[] = {'h', 'e','l', 'l', 'o', '\0'}, s6[] = "hello";

	printf("%s %s| %d| %d\n", s5, s6, strlen(s5), strlen(s6));
	/*my day is a sunny day this is a book|my day is a sunny day|this is a book
	21 14
	hello hello| 5| 5
	
	--------------------------------
	*/

}


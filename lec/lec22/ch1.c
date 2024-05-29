#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char ch = 'A';
	char* p = &ch;

	printf("ch = %c\n", ch);
	printf("*p = %c\n", *p);

	char* q = (char*) malloc(sizeof(char) * 6);
	strcpy(q, "hello");
	printf("q: %s\n", q);
	
	char* r = (char*) calloc(sizeof(char)*10, sizeof(char));
	printf("r: %s\n", r);
	
	return 0;
}

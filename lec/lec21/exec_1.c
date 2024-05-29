#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	char* const list[] = {"date", NULL};
	printf("Before: Hello\n");

	execv("/usr/bin", list);
	
	printf("After: Bye");
	return 0;
}

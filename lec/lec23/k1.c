#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	while(1) {
		printf("I am running, my pid is: %d\n", getpid());
		sleep(2);
	}
	return 0;
}

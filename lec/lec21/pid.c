#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	printf("Before the fork, pid: %d\n", getpid());
	
	pid_t p;
	p = fork();
	
	if (p > 0) {
		printf("Parent, pid: %d\n", getpid());
		exit(0);
		printf("Parent, ppid: %d\n", getppid());
		return 0;
	} else {
		printf("Child, pid: %d\n", getpid());
		printf("Child, ppid: %d\n", getppid());
	}
	
	return 0;
}

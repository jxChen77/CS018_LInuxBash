#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo){
	printf("I got signal %d\n", signo);
}

int main() {
	signal(SIGINT, handler);
	while(1) {
		printf("I am running, my pid is: %d\n", getpid());
		sleep(10);
		printf("*********************: %d\n", getpid());
	}
	return 0;
}

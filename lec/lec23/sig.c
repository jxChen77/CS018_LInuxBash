#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	while(1) {
		printf("pid: %d\n", getpid());
		sleep(1);
	}
	return 0;
}

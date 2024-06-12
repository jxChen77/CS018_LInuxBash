#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd[2];
	char buf[1024];
	
	if (pipe(fd) < 0) {
		exit(EXIT_FAILURE);
	}

	if (fork() == 0) {	
		char* mes="Hello world";
		write(fd[1], mes, strlen(mes));
	}else{
		while(1){
			if(read(fd[0], buf, 1024) > 0) {
				printf("%s\n",buf);
				exit(0);
			}
		}

	}
	return 0;
}

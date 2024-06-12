#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd[2];
	
	if (pipe(fd) < 0) {
		exit(EXIT_FAILURE);
	}

	if (fork() == 0) {	
		int ch[2];
		if (pipe(ch) < 0) {
			exit(EXIT_FAILURE);
		}
		if(fork() == 0) {
			char mes[1024] = {0};
			printf("Please enter a message: ");
			fgets(mes, 1024, stdin);
			write(ch[1], mes, strlen(mes));
		}
		else {
			char bufCh[1024] = {0};
			while(1) {
				if(read(ch[0], bufCh, 1024) > 0){
					write(fd[1], bufCh, strlen(bufCh));
					close(ch[0]);
					close(ch[1]);
					wait(NULL);
					exit(0);
				}
			}
		
		}
	}else{
		char buf[1024];
		while(1){
			if(read(fd[0], buf, 1024) > 0) {
				printf("%s",buf);
				close(fd[0]);
				close(fd[1]);
				wait(NULL);
				exit(0);
			}
		}

	}
	return 0;
}

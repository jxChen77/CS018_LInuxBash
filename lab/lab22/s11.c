#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc, char* argv[]) {
	if (fork() == 0) {
		int fd = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0646);
		if(fd == -1) {
			exit(1);
		}
		for(int i = 1; i < argc-1; i++){
			write(fd, argv[i], strlen(argv[i]));	
			write(fd, "\n", 2);
		}
		close(fd);
	}
	else {
		wait(NULL);
		execlp("cat", "cat", argv[argc-1], NULL);
	}
	return 0;
}

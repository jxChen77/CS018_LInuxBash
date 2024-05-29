#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	char* argv[] = {"pwd", NULL};
	int pid = fork();
	if( pid == 0) {
		execvp("pwd", argv);
		printf("Finish Child Process\n");
	}
	printf("Finish Process\n");
	return 0;
}

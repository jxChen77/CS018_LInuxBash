#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int child1 = 0;
void upperOutput(){
	for(int i = 0; i < 26; i++){
		printf("%c",'A'+i);
	}
	kill(child1, SIGQUIT);
	for(int i = 0; i<5; i++){
		printf("\ngood bye");
	}
	printf("\n");
	raise(SIGQUIT);
}

void lowerOutput(){
	for(int i = 0; i < 26; i++){
		printf("%c",'a'+i);
	}
	printf("\n");
	for(int i =0; i<5; i++) {
		printf("See you\n");
	}
	raise(SIGQUIT);
}

int main(){
	int fd[2];
	if(pipe(fd) < 0)
	       	exit(EXIT_FAILURE);
       	child1 = fork();
	if(child1 > 0){
		int p2 = fork();
		if(p2 > 0){
			write(fd[1], &p2, sizeof(int));
			wait(NULL);
			printf("I go home\n");
			raise(SIGKILL);
		} else{
			signal(SIGINT, upperOutput);
			while(1){
				printf("Hello world\n");
				sleep(1);
			}
		}
	}else{
		sleep(5);
		int child2;
		char ch2[10] = {0};
		if(read(fd[0], &child2, sizeof(int)) != 0)
			printf("child2: %d\n", child2);
		kill(child2, SIGINT);
		signal(SIGQUIT, lowerOutput);
		while(1){
			printf("Hi there\n");
			sleep(1);
		}
	}
}

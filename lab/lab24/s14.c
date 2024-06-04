#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void upperOutput(){
	for(int i = 0; i < 26; i++){
		printf("%c",'A'+i);
	}
	kill(getppid(),SIGQUIT);
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
	wait(NULL);
	printf("Bye Bye");

	raise(SIGKILL);
}

int main(){
	int p = fork();
	if(p > 0){
		sleep(5);
		kill(p, SIGINT);
		signal(SIGQUIT,lowerOutput);
		while(1){
			printf("Hi there\n");
			sleep(1);
		}
	
	}

	else{
		signal(SIGINT,upperOutput);
		while(1){
			printf("Hello world\n");
			sleep(1);
		}
	}
}

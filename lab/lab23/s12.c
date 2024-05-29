#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int status;
	int chPid;
	if (fork() == 0) {
		for(int j =0; j < 3; j++) {
			for(int i = 0; i < 26; i++){
				printf("%c", 'a'+i);
			}
			printf("\n");
		}
		exit(10);
	}else {
		//chPid = wait(&status);
		//printf("Pid: %d\nStatus: %d\n",chPid,WEXITSTATUS(status));
		if(fork() == 0) {
			for(int i = 0; i < 78; i++){
                        	printf("*");
			}
			printf("\n");
			exit(20);
		}else {
		//	chPid = wait(&status);
                //	printf("Pid: %d\nStatus: %d\n",chPid, WEXITSTATUS(status));
		       	if(fork() == 0) {
				for(int i = 0; i < 78; i++){
                        		printf("?");
				}
				printf("\n");
				exit(30);
			} else {
		//		chPid = wait(&status);
                //		printf("Pid: %d\nStatus: %d\n",chPid, WEXITSTATUS(status));
				if(fork() == 0) {
					for(int j =0; j < 3; j++) {
						for(int i = 0; i < 26; i++){
							printf("%c", 'A'+i);
						}
						printf("\n");
					}
					exit(40);
				}else {
					while ((chPid = wait(&status)) > 0)
						printf("Pid: %d\nStatus: %d\n",chPid, WEXITSTATUS(status));
					for(int i = 0; i<10; i++) {
						printf("%d", i);
					}
					printf("\n");
					return 0;
				}
			}
		}
	}
}


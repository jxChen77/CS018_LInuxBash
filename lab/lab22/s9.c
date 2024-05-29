#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	char* argv_p[] = {"echo", "0 1 2 3 4 5 6 7 8 9", NULL};
	if (fork()==0) {
		char* argv_1[] = {"echo", "??????????", NULL};
		if(fork() == 0) {		
			char* argv_2[] = {"date", NULL};
			if(fork() == 0){
				char* argv_3[] = {"echo", "linux system programming", NULL};
				if(fork() == 0) {
					char* argv_4[] = {"echo", "**********", NULL};
					execvp("echo", argv_4);
				}
				else{
					wait(NULL);
					execvp("echo", argv_3);
				}
			}else {
				wait(NULL);
				execvp("date", argv_2);
			}
		}
		else{
			wait(NULL);
			execvp("echo", argv_1);
		}
	}else{
		wait(NULL);
		execvp("echo", argv_p);
	}	
	return 0;
}

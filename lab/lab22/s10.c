#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	if (fork() == 0) {
		execl("/usr/bin/echo", "/usr/bin/echo", "**********", NULL);
	}else if(fork() == 0) {
	
		execl("/usr/bin/ls", "/usr/bin/ls", "-i", "-s", NULL);
	}
	else if (fork() == 0) {
		execl("/usr/bin/echo", "/usr/bin/echo", "??????????", NULL);	
	}
	else if (fork() == 0) {
		execl("/usr/bin/pwd", "/usr/bin/pwd", NULL);
	}
	else{	
               system("ps");
		wait(NULL);
		execl("/usr/bin/echo", "/usr/bin/echo", "0 1 2 3 4 5 6 7 8 9", NULL);
	}	
	return 0;
}

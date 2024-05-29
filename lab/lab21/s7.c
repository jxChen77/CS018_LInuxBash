#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	//pid_t p = fork();
	if( fork() > 0) {
		for(int i = 0; i < 26; i++) {
                        printf(" %d", i + 1);
                }
		//p = fork();
		if(fork() == 0) {
			for(int i = 0; i < 26; i++) {
                        	printf("%c", 'a'+i);
                	}
		}

	}
	else{
		for(int i = 0; i < 26; i++) {
			printf("%c", 'A'+i);
		}
	}
}

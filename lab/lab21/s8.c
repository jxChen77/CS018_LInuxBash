#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t p = fork();
	if( p > 0) {
		printf("I am a parent - numbers\n");
		for(int i = 0; i < 26; i++) {
                        printf(" %d", i + 1);
                }
		return 0;

	}
	else{
		p = fork();
		if (p > 0) {
		       printf("\nI am a child - uppercase letters\n");
               		for(int i = 0; i < 26; i++) {
                        	printf("%c", 'A'+i);
                	}
		}else {

			printf("\nI am a grandchild - lowercase letters\n");
                	for(int i = 0; i < 26; i++) {
                        	printf("%c", 'a'+i);
                	}
		}
	}
}

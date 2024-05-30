#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	printf("Sending signal...\n");
	kill(atoi(argv[1]), 9);
	return 0;
}

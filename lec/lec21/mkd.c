#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
	int check;
	check = mkdir(argv[1], 0777);

	if (!check)
		printf("Directory %s created\n", argv[1]);
	else 
		exit(1);
	exit(0);

} 

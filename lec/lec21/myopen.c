#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	int fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);

	if (fd == -1) {
		fprintf(stderr, "Error number: %d\n", errno);
		exit(1);
	}
	
	close(fd);
	exit(0);
}

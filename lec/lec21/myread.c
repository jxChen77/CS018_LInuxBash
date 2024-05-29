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

	char* buffer = (char*) calloc(20, sizeof(char));
	int size;
	size = read(fd, buffer, 20);

	printf("%d bytes were read \n", size);
	printf("Contents : %s \n", buffer);
	
	close(fd);
	exit(0);
}

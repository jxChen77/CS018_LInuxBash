#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	int fd = open(argv[1], O_RDONLY);

	char* buffer = (char*) calloc(20, sizeof(char));
	int size;
	size = read(fd, buffer, 5);
	printf("%d bytes were read \n", size);
	
	size = read(fd, buffer, 6);
	printf("%d bytes were read \n", size);

	size = read(fd, buffer, 4);
	printf("%d bytes were read \n", size);

	close(fd);
	exit(0);
}

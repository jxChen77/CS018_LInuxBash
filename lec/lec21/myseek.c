#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {
	int fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);

	if (fd == -1) {
		fprintf(stderr, "Error number: %d\n", errno);
		exit(1);
	}

	char* buffer = (char*) calloc(100, sizeof(char));
	read(fd, buffer, 80);

	printf("buf : %s\n", buffer);

	memset(buffer, 0, 100);
	read(fd, buffer, 60);

	printf("buf : %s\n", buffer);
	memset(buffer, 0, 100);
	
	off_t offset = lseek(fd, 0, SEEK_CUR);
	printf("%ld\n", offset);
	if(offset != -1) {
		printf("Move 100 from top\n");
		read(fd, buffer, 10);
	
		printf("buf : %s\n", buffer);
	}
	close(fd);
	exit(0);
}

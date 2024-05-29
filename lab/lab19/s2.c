#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 512

int main(int argc, char* argv[]) {
	int fd = open(argv[2], O_RDONLY);
	int max_line = atoi(argv[1]);
	if (fd == -1) {
		fprintf(stderr, "File %s open error\n", argv[2]);
		exit(1);
	}

	char* buffer = (char*) calloc(BUFSIZE, sizeof(char));
	int size, count = 0;
	size = read(fd, buffer, BUFSIZE);
	
	while (size > 0) {
		for(int i = 0; i < size; i++) {
			if (buffer[i] == '\n') 
				count++;
			if (count < max_line)	
			printf("%c",buffer[i]);
		}
		size = read(fd, buffer, BUFSIZE);
	}
	printf("\n");

	
	close(fd);
	exit(0);
}

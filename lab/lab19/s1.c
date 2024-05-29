#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#define BUFSIZE 512

int main(int argc, char* argv[]) {
        int fd_c = open(argv[1], O_RDONLY);
        int fd_p = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0646);
        if (fd_c == -1) {
                fprintf(stderr, "File %s open error\n", argv[1]);
                exit(1);
        }
	
	time_t st1 = clock();
        char* buffer = (char*) calloc(BUFSIZE, sizeof(char));
        int size;
	time_t st2 = clock();
        size = read(fd_c, buffer, BUFSIZE);
	

        while (size > 0) {
                write(fd_p, buffer, size);
                size = read(fd_c, buffer, BUFSIZE);
        }

	time_t end = clock();
	printf("Read and Write : %ld\n", end-st2);
	printf("All : %ld\n", end-st1);


        close(fd_c);
        close(fd_p);
        exit(0);
}

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

	time_t start = clock();
	char buf;
        while( read(fd_c, &buf, 1)> 0) {
                write(fd_p,&buf, 1);
        }

	time_t end = clock();

	printf("Time: %ld\n", end-start);


        close(fd_c);
        close(fd_p);
        exit(0);
}

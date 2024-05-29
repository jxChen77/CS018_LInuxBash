#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define MAX_SIZE 512
int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_RDONLY);
	int lines = 0;
	if (fd == -1) {
		printf("File: %s open error.\n", argv[1]);
		exit(1);
	}
	
	char* buf = (char*) malloc(1*sizeof(char));
	int* endPos=(int*) malloc(MAX_SIZE*sizeof(int));
	while(read(fd, buf, 1) > 0) {
		if(buf[0] == '\n') 
			endPos[lines++] = lseek(fd,0,SEEK_CUR)-1;
	}
	if (endPos[lines-1] != lseek(fd, 0, SEEK_END)-1) {
		endPos[lines++] = lseek(fd, 0, SEEK_END);
	}
	int length = 0;
	char** context = malloc(lines*sizeof(char*));
	for(int i = 0; i < lines; i++) {
		if (i == 0)
			length = endPos[i];
		else
			length = endPos[i]-endPos[i-1]-1;
		context[i] = malloc((length+1)*sizeof(char));
		memset(context[i],'\0',length+1);
		buf = malloc(length*sizeof(char));
		if (i==0)
			lseek(fd, 0 , SEEK_SET);
		else
			lseek(fd, 1, SEEK_CUR);
		read(fd,buf,length);
		memcpy(context[i], buf, length);
		free(buf);
	}
	
	for (int i = 0; i < lines; i+=2) {
		if (i < lines - 1) {
			char* temp = context[i];
			context[i] = context[i+1];
			context[i+1] = temp;
		}
	}

	for ( int i = 0; i < lines; i++) {
		printf("%s\n", context[i]);
	}
	close(fd);
	exit(0);

}

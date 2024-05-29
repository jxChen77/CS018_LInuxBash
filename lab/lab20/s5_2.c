#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define RED          "\033[0;32;31m"
#define GREEN        "\033[0;32;32m"
#define NONE         "\033[m"
int main(int argc, char* argv[]) {
	int fd = open(argv[2], O_RDONLY);
	int newlinePos = 0;
	int lineNum = 1;
	int wordLength = strlen(argv[1]);
	int wordPos=0;
	if (fd == -1) {
		fprintf(stderr,"File %s open error.", argv[2]);
		exit(1);
	}
	
	char* buf = calloc(1, sizeof(char));
	int end;
	int count=0;
	while (read(fd, buf, 1) > 0) {
		if(buf[0] == '\n') {
			newlinePos= lseek(fd, 0, SEEK_CUR);
			lineNum++;
		}
		else if(buf[0] == argv[1][0]) {
			int find=1;
			wordPos=lseek(fd, 0, SEEK_CUR);
			while (buf[0]!='\n') {
				for (int i = 1; i < wordLength; i++) {
                                	read(fd, buf, 1);
                                	if (buf[0] != argv[1][i]) {
                                        	if(buf[0] == '\n') {
                                                	newlinePos= lseek(fd, 0, SEEK_CUR);
                                                	lineNum++;
                                        	}
                                       		find=0;
						break;
                                	}
                        	}
			}
			for (int i = 1; i < wordLength; i++) {
				read(fd, buf, 1);
				if (buf[0] != argv[1][i]) {
					if(buf[0] == '\n') {
                       				newlinePos= lseek(fd, 0, SEEK_CUR);
                        			lineNum++;
                			}
					find=0;
					break;
				}
			}
			if (find==1) {
				char* temp = (char*) calloc(wordPos-newlinePos, sizeof(char));
				printf(GREEN"%d:"NONE, lineNum);	
				lseek(fd, newlinePos, SEEK_SET);
				read(fd, temp, wordPos-newlinePos-1);
				printf("%s", temp);
				for (int i = 0; i < wordLength; i++) {
				 	read(fd, buf, 1);
					printf(RED"%c"NONE, buf[0]);
				}
				end = read(fd, buf, 1);
				while(buf[0] != '\n' && end != 0) {
					printf("%c", buf[0]);
					read(fd, buf, 1);
				}
				if (buf[0] == '\n') {
					printf("%c", buf[0]);
					newlinePos= lseek(fd, 0, SEEK_CUR);
					lineNum++;
				} else {
					exit(0);
				}
				free(temp);
			}
		}
	}


	exit(0);
}	


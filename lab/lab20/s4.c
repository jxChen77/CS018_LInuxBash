#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#define BLUE         "\033[0;32;34m"
#define GREEN        "\033[0;32;32m"
#define NONE         "\033[m"
int main(int argc, char* argv[]) {
	struct stat buf;
	printf("Filename: %s\n", argv[1]);
	if(stat(argv[1], &buf) < 0) {
		perror("stat error.\n");
		exit(1);
	}
	char code[10];
	if (S_ISDIR(buf.st_mode)) 
		code[0]='d';
	else if (S_ISREG(buf.st_mode)) 
		code[0]='-';
	if (buf.st_mode & S_IRUSR) 
		code[1] = 'r';
	else code[1] = '-';
	if (buf.st_mode & S_IWUSR) 
		code[2] = 'w';
	else code[2] = '-';
	if (buf.st_mode & S_IXUSR) 
		code[3] = 'x';
	else code[3] = '-';
	if (buf.st_mode & S_IRGRP) 
		code[4] = 'r';
	else code[4] = '-';
	if (buf.st_mode & S_IWGRP) 
		code[5] = 'w';
	else code[5] = '-';
	if (buf.st_mode & S_IXGRP) 
		code[6] = 'x';
	else code[6] = '-';
	if (buf.st_mode & S_IROTH) 
		code[7] = 'r';
	else code[7] = '-';
	if (buf.st_mode & S_IWOTH) 
		code[8] = 'w';
	else code[8] = '-';
	if (buf.st_mode & S_IXOTH) 
		code[9] = 'x';
	else code[9] = '-';
	
	printf("%ld %s %6d %8ld ", buf.st_ino, code, buf.st_uid,buf.st_size);
	if (code[0] == 'd') 
		printf(BLUE"%s\n"NONE,argv[1]);
	else if (code[3] == 'x' || code[6] == 'x' || code[9] == 'x') 
		printf(GREEN"%s\n"NONE,argv[1]);
	else 
		printf("%s\n"NONE,argv[1]);
	exit(0);
}	


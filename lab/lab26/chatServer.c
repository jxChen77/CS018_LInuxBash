#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

const int pow_public = 3;
const int pow_private = 7;
const int divide = 33;
struct INFO{
	int key;
	char mes[200];
} INFO;

int getRandom(){
	srand(time(NULL));
	int result = rand() % 9 + 1;
	return result;
}

int getModule(int base, int power, int divide){
	int last = 1;
	while(power > 0) {
		last = last * base % divide;
		power--;	
	}
	return last;
}

char encryptChar(int key, char m) {
	char result = m;
	if(isupper(m)) {
		if (m + key > 'Z') 
			result = 'A' + m + key - 'Z' - 1;
		else result = m + key;
	}else if (islower(m)) {
		if (m + key > 'z')
                        result = 'a' + m + key - 'z' - 1;
		else result = m + key;
	}
	return result;
}

void encrypt(struct INFO* in) {
	for(int i = 0; i < strlen(in->mes); i++) {
		in->mes[i] = encryptChar(in->key, in->mes[i]);
	}
	in->key = getModule(in->key, pow_public, divide);
}

char decryptChar(int key, char m) {
	char result = m;
	if(isupper(m)) {
		if (m - key < 'A') 
			result = 'Z' - ('A' - (m - key) - 1);
		else result = m - key;
	}else if (islower(m)) {
		if (m - key < 'a')
                        result = 'z' - ('a' - (m - key) - 1);
		else result = m - key;
	}
	return result;
}

void decrypt(struct INFO* in) {
	in->key = getModule(in->key, pow_private, divide);
	for(int i = 0; i < strlen(in->mes); i++) {
		in->mes[i] =decryptChar(in->key, in->mes[i]);
	}
}

struct fdss {
	int fd1;
	int fd2;
} fdss;

void *Send_function(void* arg) { 
	struct fdss* fds = (struct fdss*)arg;
	int fd = fds->fd2;
	struct INFO in;
	char buf[200] = {0};
	do {
		memset(buf, '\0', 200);
		in.key = getRandom();
		printf("This is key: %d\n", in.key);
		printf("[To Client]: ");
		fgets(buf, 200, stdin);
		strcpy(in.mes, buf);
		encrypt(&in);
		printf("After encrypt: %s\n", in.mes);
		write(fd, &in, sizeof(in));
	}while(strcmp(buf, "exit\n") != 0);
	printf("Chatting ends se\n");
	close(fds->fd1);
	close(fds->fd2);
	exit(0);
}
void *Receive_function(void* arg) {
	struct fdss* fds = (struct fdss*)arg;
	int fd = fds->fd2;
        char buf[200] = {0};
	struct INFO in;
        do {
		memset(in.mes, '\0', 200);
               	if(read(fd, &in, 204) > 0) {
			decrypt(&in);
			printf("\n[From Client]: %s", in.mes);
		}
	}while(strcmp(in.mes, "exit\n") != 0 );
	printf("Chatting ends re\n");	
	close(fds->fd1);
	close(fds->fd2);
	exit(0);
}
int main(int argc, char* argv[])
{
	int PORT = atoi(argv[1]);
	int server_fd, socket_fd, status; 
	ssize_t size;
	struct sockaddr_in address;
	socklen_t addrlen = sizeof(address);
	pthread_t pthread[2];
	int success = 1;
	struct fdss fds;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	fds.fd1 = server_fd;
	if (server_fd == -1) {
		perror("opening stream socket failed");
		exit(1);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		success = 0;
		perror("bind failed");
		exit(-1);
	}
	if (listen(server_fd, 3) < 0) {
		success = 0;
		perror("listen");
		exit(-1);
	}
	printf("I am waiting at port %d...\n", PORT);

	if ((socket_fd = accept(server_fd, (struct sockaddr*)&address, &addrlen)) <0) {
		success = 0;
		perror("accept");
		exit(-1);
	}
	fds.fd2 = socket_fd;

	printf("accept!\n");
	printf("chatting starts...\n\n\n");

	pthread_create(&pthread[0], NULL, Send_function, &fds);
	pthread_create(&pthread[1], NULL, Receive_function, &fds);	
	if((pthread_join(pthread[0], (void**) &status) == 0) ||(pthread_join(pthread[1], (void**) &status) == 0)) {
			printf("Chatting ends\n");
        		close(socket_fd);
        		close(server_fd);		
                	return 0;
	}
}

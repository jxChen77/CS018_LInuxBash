#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct fdss {
	int fd1;
	int fd2;
} fdss;

void *Send_function(void* arg) {
	struct fdss* fds = (struct fdss*)arg;
	int fd = fds->fd2;
	char buf[200] = {0};
	do {
		memset(buf, '\0', 200);
		printf("Server sending to Client: ");
		fgets(buf, 200, stdin);
		write(fd, buf, strlen(buf));
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
        do {
		memset(buf, '\0', 200);
               	if(read(fd, buf, 200) > 0) {
			printf("\n[From Client]: %s\n", buf);
		}
	}while(strcmp(buf, "exit\n") != 0 );
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

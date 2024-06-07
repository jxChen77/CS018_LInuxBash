#include <pthread.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

void *Send_function(void* arg) {  
	int* fd = (int*) arg;
	char buf[200] = {0};
	do {
		memset(buf, '\0', 200);
		printf("Client sending to Server: ");
		fgets(buf, 200, stdin);
		write(*fd, buf, strlen(buf));
	}while(strcmp(buf, "exit\n") != 0 );  
	printf("Chatting ends se\n");
	close(*fd);
	exit(0);
}
void *Receive_function(void* arg) {  
	int* fd = (int*) arg;
	char buf[200] = {0};
	do {
               	memset(buf, '\0', 200);
		if(read(*fd, buf, 200) > 0) {
  			printf("\n[From Server]: %s\n", buf);
              
		}
	}while(strcmp(buf, "exit\n") != 0);  
	printf("Chatting ends re\n");
	close(*fd);
	exit(0);
}

int main(int argc, char const* argv[])
{
	int PORT = atoi(argv[2]);
	int status, client_fd;
	size_t size;
	struct sockaddr_in serv_addr;
	char buf[1024] = {0};
	pthread_t pthread[2];

	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr, "\n Socket creation error\n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
		fprintf(stderr, "\n Invalid address / Address not supported \n");
		return -1;
	}

	if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
		fprintf(stderr, "\n Connection failed \n");
		return -1;
	}
	
	pthread_create(&pthread[0], NULL, Send_function, &client_fd);
        pthread_create(&pthread[1], NULL, Receive_function, &client_fd);

	
	if(pthread_join(pthread[0], (void**) &status) == 0 ||
		pthread_join(pthread[1], (void**) &status) == 0) {
		printf("Chatting ends\n");
		close(client_fd);
		return 0;
	}
}


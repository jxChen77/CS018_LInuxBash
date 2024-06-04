
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define PORT 9000
int main(int argc, char* argv[])
{
	int server_fd, new_socket;
	ssize_t size;
	struct sockaddr_in address;
	socklen_t addrlen = sizeof(address);
	char buf[1024] = {0};

	char* hello = "~~~ I am server. Hello!!!";
	char hello2[100] = {0};
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		perror("opening stream socket failed");
		exit(1);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		perror("bind failed");
		exit(-1);
	}
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(-1);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) <0) {
		perror("accept");
		exit(-1);
	}
	size = read(new_socket, buf, 1024-1);
	printf("Message from client : %s\n", buf);
	sleep(1);
	printf("Server sends message to the client\n");
	while(strcmp(hello2, "exit") != 0) {
		printf("what you want to send?\n");
		scanf("%s", hello2);
		write(new_socket, hello2, strlen(hello2));
	}
	printf("message sent to the client\n");
	close(new_socket);
	close(server_fd);
	return 0;
}

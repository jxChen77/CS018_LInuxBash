#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 9000 

int main(int argc, char const* argv[])
{
	int status, client_fd;
	size_t size;
	struct sockaddr_in serv_addr;
	char* hello = "*** Hello from client ***";
	char buf[1024] = {0};
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr, "\n Socket creation error\n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, "172.17.121.198", &serv_addr.sin_addr) <= 0) {
		fprintf(stderr, "\n Invalid address / Address not supported \n");
		return -1;
	}

	if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
		fprintf(stderr, "\n Connection failed \n");
		return -1;
	}

	printf("Client sends message to the server\n");
	write(client_fd, hello, strlen(hello));
	printf("message sent to the server.....\n\n");
	sleep(1);
	printf("Client reads message from the server\n");
	while(strncmp(buf,"exit", 4) != 0 ){
		memset(buf,'\0', 1024);
		size = read(client_fd, buf, 1024-1);
		printf("%s\n", buf);
	}
	close(client_fd);
	return 0;
}


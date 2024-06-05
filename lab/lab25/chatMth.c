#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void *p_function(void* data) {
	pid_t pid = getpid();
	pthread_t tid = pthread_self();
	char* msg = (char*) data;
	printf("msg : %s, tid : %x, pid %u\n", msg, (unsigned int) tid, pid);
}
int main() {
	pthread_t pthread[2];
	int thr_id;
	int status;
	char p1[] = "thread 1 is created";
	char p2[] = "thread 2 is created";
	sleep(1);
	thr_id = pthread_create(&pthread[0], NULL, p_function, (void*) p1);
	if (thr_id < 0) {
		perror("pthread0 create error");
		exit(EXIT_FAILURE);
	}
	thr_id = pthread_create(&pthread[1], NULL, p_function, (void*) p2);
	if (thr_id < 0) {
		perror("pthread0 create error");
		exit(EXIT_FAILURE);
	}
	p_function("*** Hello I am the main process");
	pthread_join(pthread[0], (void**)&status);
	pthread_join(pthread[1], (void**)&status);
	printf("Good bye\n");
	return 0;
}	


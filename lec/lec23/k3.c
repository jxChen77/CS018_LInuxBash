#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	int count = 0;
	while(1) {
		printf("Hello\n");
		count++;
		if(count == 5)
			raise(2);
		sleep(2);
	}
}

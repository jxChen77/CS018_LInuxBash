# include <stdio.h>

int main() {
	int count = 0;
	for (int i = 0; i < 10; i++){
		printf("%d\n", i*i);
		count++;
	}
	printf("count:%d\n", count);
	return 0;
}

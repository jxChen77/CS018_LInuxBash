#include <stdio.h>

int main() {
	int a;
	printf("Enter integer a: ");
	scanf("%d", &a);
	printf("You entered %d\n", a);
	
	float b;
	printf("Enter float b: ");
	scanf("%f", &b);
	printf("You entered %5.2f\n", b);

	double c;
	printf("Enter double c: ");
	scanf("%lf", &c);
	printf("You entered %5.2lf\n", c);
	
	return 0;
}

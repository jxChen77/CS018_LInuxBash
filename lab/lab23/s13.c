#include <stdio.h>

int addition(int, int);
int subtraction(int, int);
int multiplication(int, int);
int division(int, int);
int rem(int, int);
int display();

int main(){
	int choice = 0;
	char* functions[] = {"addition", "subtraction", "multiplication", "division", "rem"};
	char isContinue = 'y';
	int (*f) (int, int);
	int a, b;
	do{
		choice = display();
		if(choice > 0 && choice < 6) {
			switch (choice){
				case 1: 
					f = addition;
					break;
				case 2:
					f =subtraction;
				      	break;
				case 3:
				 	f = multiplication;
					break;
				case 4: 
					f = division;
					break;
				case 5: f = rem;
					break;
			} 
			printf("Enter two numbers: ");
			scanf("%d %d", &a, &b);	
			printf("result: %d\n", f(a,b));
			printf("More(y/n): ");
			scanf("%s", &isContinue);
			printf("\n");
		}else{
			printf("wrong choice\n");
		}

	}while (isContinue == 'y');
}

int addition(int x, int y){return x+y;}
int subtraction(int x, int y){return x-y;}
int multiplication(int x, int y){return x*y;}
int division(int x, int y){return x/y;}
int rem(int x, int y){return x%y;}
int display(){
	int cho;
	printf("=========================\n");
	printf("        MENU\n");
	printf("=========================\n");
	printf("  1. addition\n");
	printf("  2. subtraction\n");
	printf("  3. multiplication\n");
	printf("  4. division\n");
	printf("  5. remainder\n");
	printf("Choose one: ");
	scanf("%d", &cho);
	printf("\n");
	return cho;

}

	

# include <stdio.h>
# include <string.h>

int main() {
	char str[50] = "hel bnaabak biubiaue";
	printf ("before str: %s\n", str);

	memset(str, 56, 10);
	printf("after str: %s\n", str);
	
	return 0;
}

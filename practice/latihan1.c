#include <stdio.h>
#include <string.h>

int main()
{
	char a, b, c;
	scanf(" %c %c %c", &a, &b, &c);
	char str[10];
	str[0] = a;
	str[1] = b;
	str[2] = c;
	printf("%s", str);
	return 0;
}
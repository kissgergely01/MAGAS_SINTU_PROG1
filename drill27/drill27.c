#include <stdio.h>

void myfunction(char p[], int x)
{
	printf("p is %s and x is %d\n",p,x);	
}


int main()
{
	printf("Hello, World!\n");

	char hll[] = "hello";
	char wrld[] = "world";
	printf("%s %s\n", hll, wrld);
	
	myfunction("foo",7);
	return 0;
}

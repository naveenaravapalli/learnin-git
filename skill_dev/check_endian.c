#include<stdio.h>

int main()
{
	char *p;
	int i =1;
	p = &i;
	if(*p)
		printf("machine iLittle endian\n");
	else
		printf("machine is Big endian\n");

}

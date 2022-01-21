#include<stdio.h>

int main()
{
	int i,j = 0x12345678;
	printf("before conversion  = %x\n",j);
	i = (((0x000000ff)&j)<<24) | (((0x0000ff00)&j)<<8) | (((0x00ff0000)&j)>>8) | (((0xff000000)&j)>>24);
	printf("after conversion = %x\n",i);
}

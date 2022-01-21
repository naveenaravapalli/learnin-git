#include<stdio.h>
int main()
{
	int *a,c;
	int b ;
	a= &b;
	printf(" a = %d  b = %d",a,b);
	c = &b;
	printf(" c = %d  b = %d",c,b);

}

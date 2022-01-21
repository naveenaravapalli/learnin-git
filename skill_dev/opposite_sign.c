#include<stdio.h>

int check_opposite(int n1,int n2)
{
	return((n1 ^ n2)<0);
}

int main()
{
	int n1 = 8,n2 = -3;
	if(check_opposite(n1,n2))
		printf ("Signs are opposite\n");
	else
		printf ("Signs are same\n");
}

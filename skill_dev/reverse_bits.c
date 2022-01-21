#include<stdio.h>

int main()
{
	int num,reverse_bit = 0;
	printf("enter the number : ");
	scanf("%d",&num);

	while(num>0)
	{
		reverse_bit = reverse_bit << 1;
	       if(num & 1 == 1)
	       reverse_bit = reverse_bit ^ 1;
num = num >> 1;
	}
	printf("reverse bits number : %d\n",reverse_bit);
}

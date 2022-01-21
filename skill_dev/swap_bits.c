#include<stdio.h>

int main()
{
	int num,p1,p2,bit1,bit2,val;
	printf("enter the nunmber :");
	scanf("%d",&num);
	printf("enter the swaping  positions :");
	scanf("%d %d",&p1,&p2);

	//num = num ^ (1<<p1);
	//num = num ^ (1<<p2);
	bit1 = ((num>>p1) & 1);
	bit2 = ((num>>p2) & 1);
	val = bit1 ^ bit2;
	val = (val<<p1) | (val<<p2);
	num = num ^ val;
	printf("number after swaping : %d",num);
}

#include<stdio.h>

int copy_bits(int x,int y,int n,int p)

{

    int u1,u2,u3,u4,x1,y1,yf;
    u1 = ~0; 
    //printf("%d\n",u1);
    u2 = (u1<<n);
    //printf("%d\n",u2);
    u3 = ~(u2);
    //printf("%d\n",u3);
    u4 = u3<<p;
    //printf("%d\n",u4);
    x1 = (x & u4);
    //printf("%d\n",x1);
    y1 = (y | u4);
    //printf("%d\n",y1);
    yf = (x1 | y1);
    return yf;

}

int main()
{
	int x;
	x = copy_bits(19,23,2,3);
	printf("%d\n",x);
}

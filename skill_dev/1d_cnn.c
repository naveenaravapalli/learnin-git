#include<stdio.h>

int main()
{
	unsigned int arr[16] = {1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1}, sarr[4] = {1,1,0,0} ,temp[8],i,j,k,l,m,n,sum = 0;
	printf("enter the arr data :");
	/*for(i=0;i<16;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the sarr data :");
	for(i=0;i<4;i++)
	{
		scanf("%d",&sarr[i]);
	}*/
printf("\n>>>>>>>>>>>>>>>>>>..\n");
	for(n=0;n<9;n=n+4)
	{
		for(m=n;m<(n+3);m++)
		{
			for(k=0,l=m;k<4;l=l+4)
			{
				for(j=l;j<(l+2);j++,k++)
				{
					sum = sum + (arr[j]*sarr[k]);
					if(k==3)
					{
						printf("%d ",sum);
					}
				}
			}
			sum = 0;
		}
	}
}

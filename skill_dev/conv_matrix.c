#include<stdio.h>

int main()
{
	unsigned int arr[4][4],sarr[2][2],farr[3][3],temp[2][2]= {0,0},i,j,k,l,m,n;
	printf("enter the arr data :");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}
	printf("enter the sarr data :");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&sarr[i][j]);
		}
		printf("\n");
	}

	for(n=0;n<3;n++)
	{
		printf("\n");
		for(m=0;m<3;m++)
		{
			temp[n][m]=0;
			for(l=0,i=n;l<2;i++,l++)
			{
				for(k=0,j=m;k<2;j++,k++)
				{
					temp[n][m]=temp[n][m]+(arr[i][j]*sarr[l][k]);
				}
			}
					printf("%d ",temp[n][m]);
		}
	}

}

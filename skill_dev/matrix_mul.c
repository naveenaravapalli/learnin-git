#include<stdio.h>

int main()
{
	int arr[32][32],sarr[5][5],farr[28][28],temp[5][5];
	printf("enter the arr data :");
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("enter the sarr data :");
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&sarr[i][j]);
		}
	}

	for(i=0;i<32;i++)
	{
		for(j=0;j<5;j++)
		{
			temp[i][j]=0;

			for(int k=0;k<5;k++)
				temp[i][j]=temp[i][j]+arr[i][k]*sarr[j][k];
		}
	}
}

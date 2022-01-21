#include<stdio.h>

void selection_sort(int *,int );
void insertion_sort(int *,int );

void main()
{
	int size,i;
	printf("enter the array size : ");
	scanf("%d",&size);
	int arr[size];
	printf("enter %d array elements ",size);
	for(i = 0; i<size; i++)
	{
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,size);
	//insertion_sort(arr,size);
	printf("sort array : ");
	for(i = 0; i<size; i++)
	{
		printf("%d",arr[i]);
	}
}

void selection_sort(int *ptr,int size)
{
	int i,j,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(ptr[i]>ptr[j])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
return ;
}

void insertion_sort(int *ptr,int size)
{
	int i,j,temp;
	for(i=1;i<size;i++)
	{
		j=i-1;
		temp=ptr[i];
		while(j>=0&&temp<ptr[j])
		{
			ptr[j+1] = ptr[j] ;
			j--;
		}
		ptr[j+1]=temp;
	}
return ;
}

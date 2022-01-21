#include<stdio.h>
#include<stdlib.h>

int binary_search(int *, int, int, int);

int main()
{
	int num,val,i,ret;
	printf("enter the array size\n");
	scanf("%d",&num);
	int arr[num];
	printf("enter %d array elements : ",num);
	for(i = 0; i<num; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the element to search in array : ");
	scanf("%d",&val);
	ret = binary_search(arr,0,num,val);
	(ret == 0)?printf("element not present in an array\n"):printf("elemnet present in %dth position in an array\n",ret);
}

int binary_search(int *arr, int l, int r, int val)
{
	int mid;
	if(r>=l)
	{
		mid = (l + r) / 2;
		if(arr[mid] == val)
			return mid;

		if(arr[mid] > val)
			binary_search(arr,l,mid-1,val);

		if(arr[mid] < val)
			binary_search(arr,mid+1,r,val);
	}
	return 0;
}

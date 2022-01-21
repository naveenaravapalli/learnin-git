#include<stdio.h>
void sort(int *,int);
void swap(int *,int *);
 int main()
{
	int a[]={0,1,1,0,0,0,2,2,1,0,1,2,0,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,2,1};
	int size = sizeof(a)/sizeof(a[0]);
	sort(a,size);
}

void sort(int *a,int n)
{
	int mid = 0,low = 0,hi = n-1;
	while(mid<=hi)
	{
		switch(a[mid])
		{
			case 0: swap(&a[low++],&a[mid++]);
				break;
			case 1: mid++;
				break;
			case 2: swap(&a[mid],&a[hi--]);
				break;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return;
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

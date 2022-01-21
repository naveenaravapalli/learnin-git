#include<stdio.h>
#include<stdlib.h>
/*
   void get_maxnumber(char *data)
   {
   char temp;
   int max =data[0],length;
   length= length_data(data);
   for (int i = 1; i < length/2; i++)
   if (data[i] > max)
   max = data[i];

   printf(" max number is %d:\n",atoi(max));

   }

   int length_data(char * data)
   {
   int i=0, count=0;
   for (i=0;data[i];i++)
   {
   count++;
   }
   printf(" lenght is %d\n",atoi(count));
   return count;
   }
   */

int isprime(int n);
int main()
{
	int *ptr=NULL;
	int i,len=0,k=0;

	printf("ENTER THE SIZE OF ARRAY:\n");
	scanf("%d",&len);
	ptr=(int*)malloc(len*sizeof(int));
	printf("ENTER THE ELEMENTS:\n");
	for(i=0;i<len;++i){
		scanf("%d", &ptr[i]);
	}
	printf("Array elements are \n");
	for(i=0;i<len;++i)
	{
		printf("%d\n", ptr[i]);
	}


	for(i=0;ptr[i];i++)
	{
		if(isprime(ptr[i]))
		{
			//	printf("%d is prime number \n",ptr[i]);

			ptr[k++]=ptr[i];

		}

	}

	int temp;

	for(int i = 1; i<k;i++)
	{
		for(int j = 0; j<k-1;j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				temp = ptr[j];
				ptr[j] = ptr[j+1];
				ptr[j+1] = temp;
			}
		}
	}


int min,max;
min = ptr[0];
max = ptr[k-1];

	for(i=0;i<k;i++)
	{
		printf("sortedn %d\n",ptr[i]);
	}
	printf("min = %d max = %d",min,max);
	for(i=min;i<=max;i++)
	{
		
	}
}



int isprime(int n)
{
	int flag=1,i;
	if(n==1)
	{
		return 0;
	}
	for (i = 2; i <= n / 2; ++i)
	{
		// condition for non-prime
		if (n % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

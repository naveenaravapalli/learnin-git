#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int d1;
	int d2;
	struct node *link;
};
struct node *head;
int next_prime(int p);
void add_node(int v1,int v2);
void display();
void main()
{
	int s,i,j,f,ret,k;
	printf("enter size of the list :\t");
	scanf("%d",&s);
	int a[s],b[s];
	printf("enter elements: ");
	for(i=0;i<s;i++)
		scanf("%d",&a[i]);

	for (i = 0,k=0; i < s; i++) 
	{

		if (a[i] == 1 || a[i] == 0)
			continue;

		f = 1;

		for (j = 2; j <=  a[i] / 2; ++j) 
		{
			if (a[i] % j == 0) 
			{
				f = 0;
				break;
			}
		}
		if (f == 1)
		{	
			b[k] = a[i];
			k++;
		}
	} 
	k--;
	for(i=0;i<k-1;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(b[i]>b[j])
			{
				f=b[i];
				b[i] = b[j];
				b[j] = f;
			}
		}
	}
	for(i=0;i<=k;i++)
		printf("%d ",b[i]);
	for(i=0;i<=k-1;i++)
	{
		ret = next_p rime(b[i]);
		if(ret==b[i+1])
		{
			add_node(b[i],b[i+1]);
			i++;
		}
	}
	display();

}
int next_prime(int p)
{
	int i=p+1,j,f;
	for (i; ; i++) 
	{

		if (i == 1 || i == 0)
			continue;

		f = 1;

		for (j = 2; j <= i / 2; ++j) 
		{
			if (i % j == 0) 
			{
				f = 0;
				break;
			}
		}
		if (f == 1)
		{
			return i;
		}
	}
}
void add_node(int v1,int v2)
{
	struct node *temp;
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->d1=v1;
	ptr->d2=v2;
	ptr->link=NULL;
	if(head==NULL)
	{
		head=ptr;
		return;
	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=ptr;
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is Empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("\n%d,%d",temp->d1,temp->d2);
		temp=temp->link;
	}
	printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
struct number{
	int data1,data2;
	struct number *next;
};
struct number *create_list(struct number *,int);
void display(struct number *);
int main()
{
	struct number *head=NULL;
	int choice,i;
	int range=0;
	while(1)
	{

		printf("1 enter list 3 display 9 exit\n");

		printf("Enter the number your choice\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1 :
				printf("enter the range:\n");
				scanf("%d",&range);
				head = create_list( head,range); break;
				// case 2 : head = reverse_list(head); break;
			case 3 : display(head); break;
			case 9 : exit(0);
			default : printf("enter the correct number \n"); break;
		}
	}
}

void display(struct number *ptr)
{
	if(ptr == NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		while(ptr)
		{
			printf("( %d ,%d) \n",ptr-> data1,ptr-> data2);
			ptr=ptr->next;
		}
	}
	return;
}

struct number* create_list( struct number *ptr, int limit)
{
	int num1, num2 = 3, count, flag;  
	struct number 	*nu=NULL, *temp=NULL;
	while(limit)  
	{  
		for(num1 = 2; num1 <= num2; num1++)  
		{  
			for(count = 2; count <= num1; count++)  
			{  
				flag = 1;  
				if(num1 % count == 0 && num2 % count == 0)  
				{  
					flag = 0;  
					break;  
				}  
			}  
			if(flag)  
			{  
				//printf("(%d, %d) are co-prime numbers.\n", num1, num2); 
				nu= ( struct number*) calloc(1,sizeof (struct number * ));
				if (nu == NULL)
				{
					printf("list not created\n");
					return ptr;
				}
				nu -> data1=num1;
				nu -> data2=num2;

				if(ptr == NULL)
				{
					ptr=nu;
				}
				else
				{
					temp=ptr;
					while(temp->next)
					{
						temp= temp->next;
					}
					temp->next=nu;
				} 

				limit--;  

				if(limit == 0)  
				{  
					num1 = num2 + 10;  
				}  
			}  

		}  
		num2++;  
	}  
	return ptr;
}










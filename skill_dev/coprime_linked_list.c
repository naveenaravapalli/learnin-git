#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data1,data2;
	struct list *next;
};

int check_coprime(int , int);
void display(struct list *);
struct list *create_list(struct list *);

int main()
{
	int choice;
	struct list *head = NULL;
	while(1)
	{
		printf("1.create_list_for_coprime_numbers  2.display  3.exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head = create_list(head);
				break;
			case 2: display(head);
				break;
			case 3: exit(0);
			default : printf("please enter correct choice \n");
				  break;
		}
	}
}

void display(struct list *ptr)
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
			printf("(%d,%d)\n",ptr->data1,ptr->data2);
			ptr = ptr->next;
		}
	}
	return;
}

struct list *create_list(struct list *ptr)
{
	int data1,data2,i;
	struct list *temp = NULL, *nu = NULL;
	nu = (struct list *)malloc(sizeof(struct list *));
	if(nu == NULL)
	{
		printf("memory allocation failed\n");
		return ptr;
	}

		printf("enter the numbers to check coprime :");
		scanf("%d%d",&data1,&data2);
		i = check_coprime(data1,data2);
		if(!i)
		{
			printf("numbers %d and %d are not coprime numbers\n",data1,data2);
			return ptr;
		}
		
		nu->data1 = data1;
		nu->data2 = data2;
		if(ptr == NULL)
			ptr = nu;
		else
		{
		temp = ptr;
		while(temp -> next)
			temp = temp->next;
		temp->next = nu;
		}
		return ptr;
}

int check_coprime(int data1, int data2)
{
	int i, flag = 1, min;
	min = data1 > data2 ? data1 : data2;
	for(i = 2; i <= min; i++)
	{
		if(data1 % i == 0 && data2 % i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

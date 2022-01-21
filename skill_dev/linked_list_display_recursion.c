#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
};

struct list *create_list(struct list *);
void display(struct list *);

int main()
{
	int choice;
	struct list *head = NULL;
	while(1)
	{
		printf("1.create_list  2.display  3.exit\n");
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

struct list *create_list(struct list *ptr)
{
	struct list *nu = NULL, *temp = NULL;
	nu = (struct list*) malloc(sizeof(struct list *));
	if(nu == NULL)
	{
		printf("memory allocation fail\n");
		return ptr;
	}
	printf("enter the data : ");
	scanf("%d",&nu->data);
	if(ptr == NULL)
		ptr = nu;
	else
	{
		temp = ptr;
		while(temp -> next)
			temp = temp->next;
		temp -> next = nu;
		return ptr;
	}
}

void display(struct list *ptr)
{
	printf("%d\n",ptr->data);
	if(ptr->next == NULL)
		return;
	display(ptr->next);
}

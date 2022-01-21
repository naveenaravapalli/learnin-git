#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
};

struct list *create_list(struct list *);
struct list *reverse_list(struct list *);
void display(struct list *);

int main()
{
	int choice;
	struct list *head = NULL;
	while(1)
	{
		printf("1. create_list  2. reverse_list  3. display  4. exit \n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head = create_list(head);
				break;
			case 2: head = reverse_list(head);
				break;
			case 3: display(head);
				break;
			case 4: exit(0);
			default : printf("please enter correct choice : \n");
				  break;
		}
	}
}

struct list * create_list(struct list *ptr)
{
	struct list *nu = NULL, *temp = NULL;
	nu = (struct list *) malloc (sizeof(struct list *));
	if(nu == NULL)
	{
		printf("list not created\n");
		return ptr;
	}

	printf("enter the data ");
	scanf("%d",& nu -> data);

	if(ptr == NULL)
		ptr=nu;
	else
	{
		temp = ptr;
		while(temp -> next)
			temp = temp -> next;
		temp -> next = nu;
	}
return ptr;
}

void display(struct list *ptr)
{
	if(ptr == NULL)
	{
		printf("list is empty..\n");
		return;
	}
	 while(ptr)
	 {
		 printf("%d \n", ptr->data);
		 ptr = ptr -> next;
	 }
}

struct list *reverse_list(struct list *ptr)
{
	struct list *pptr=NULL, *cptr=NULL, *nptr=NULL;

	if(ptr == NULL)
	{
		printf("list is empty\n");
		return ptr;
	}

	nptr = ptr;
	while(nptr)
	{
		pptr = cptr;
		cptr = nptr;
		nptr = nptr -> next;
		cptr -> next = pptr;
	}
	ptr = cptr;
	return ptr;
}

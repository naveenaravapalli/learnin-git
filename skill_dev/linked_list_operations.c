#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
};

struct list *create_node(struct list *);
struct list *delete_node(struct list *);
struct list *reverse_list(struct list *);
void display(struct list *);
struct list *loop_create(struct list *);
void loop_detect_break(struct list *);
struct list * print_nth_node(struct list *);

int main()
{
	struct list *head = NULL;
	int choice;
	while(1)
	{
		printf("1.create_node  2.delete_node  3.reverse_list  4.display  5.loop_create  6.loop_detect_break  7.print_Nth_node  8.exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head = create_node(head);
				break;
			case 2: head = delete_node(head);
				break;
			case 3: head = reverse_list(head);
				break;
			case 4: display(head);
				break;
			case 5: head = loop_create(head);
				break;
			case 6: loop_detect_break(head);
				break;
			case 7: head = print_nth_node(head);
				break;
			case 8: exit(0);
			default : printf("enter correct choice \n");
				  break;
		}
	}
}

struct list *create_node(struct list *ptr)
{
	struct list *nu = NULL, *temp = NULL;
	nu = (struct list *)malloc(sizeof(struct list));
	if(nu==NULL)
	{
		printf("memory allocation failed for node \n");
		return ptr;
	}
	printf("enter the data : ");
	scanf("%d",&nu -> data);
	if(ptr==NULL)
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

struct list *delete_node(struct list *ptr)
{
	int num,cnt = 0;
	if(ptr == NULL)
	{
		printf("list is empty\n");
		return ptr;
	}
	struct list *temp = NULL, *pptr = NULL;
	printf("enter the data to delete\n");
	scanf("%d",&num);
	temp = ptr;
		if((temp -> data) == num)
		{
			ptr = temp -> next;
			free(temp);
			return ptr;
		}
		pptr = temp;
		temp = temp -> next;
	while(temp)
	{
			if((temp -> data) == num)
			{
				pptr -> next = temp -> next;
				free(temp);
				break;
			}
			pptr = temp;
			temp = temp -> next;
			if(!temp)
				printf("entre the existing data in the list \n");
	}
	return ptr;
}

struct list *reverse_list(struct list *ptr)
{
	struct list *pptr = NULL, *cptr = NULL, *nptr = NULL;
	if((ptr == NULL) || (ptr->next == NULL))
	{
		return ptr;
	}
	nptr=ptr;
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
			printf("%d\n",ptr -> data);
			ptr = ptr -> next;
		}
	}
	return;
}

struct list *loop_create(struct list *ptr)
{
	int num,cnt = 0;
	struct list *temp = NULL, *pptr = NULL;
	if(ptr == NULL)
	{
		printf("list is empty\n");
		return ptr;
	}
	printf("enter the node number to create loop : ");
	scanf("%d",&num);
	temp = ptr;
	while(temp)
	{
		cnt++;
		if(cnt == num)
		{
			pptr = temp;
			while(temp -> next)
				temp = temp -> next;
			temp -> next = pptr;
			break;
		}
		temp = temp -> next;
		if(!temp)
			printf("enter existing node number \n");
	}
	return ptr;
}

void loop_detect_break(struct list *ptr)
{
	if(ptr == NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct list *sptr = ptr, *fptr = ptr;
	while(sptr && fptr -> next)
	{
		sptr = sptr -> next;
		fptr = fptr -> next -> next;
		if(sptr == fptr)
			sptr -> next = NULL;
	}
	return;
}

struct list * print_nth_node(struct list *ptr)
{
	int num,cnt = 0;
	struct list *temp = NULL;
	if(ptr == NULL)
	{
		printf("list is empty\n");
		return ptr;
	}
	printf("enter the node number to print data : ");
	scanf("%d",&num);
	temp = ptr;
	while(temp)
	{
		cnt++;
		if(cnt == num)
		{
			printf("data for %dth node : %d\n",num,temp -> data);
			break;
		}
		temp = temp -> next;
		if(!temp)
			printf("enter the existing node\n");
	}
	return ptr;
}

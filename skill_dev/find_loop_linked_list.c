#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
};

void display(struct list *);
struct list *create_list(struct list *);
void loop_detect_break(struct list *);
void loop_break(struct list *, struct list *);
void loop_list(struct list *);

int main()
{
	int choice;
	struct list *head = NULL;
	while(1)
	{
		printf("1.create_list  2.loop_detect_break  3.display  4.exit  5.create_loop\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head = create_list(head);
				break;
			case 2: loop_detect_break(head);
				break;
			case 3: display(head);
				break;
			case 4: exit(0);
			case 5: loop_list(head);
				break;
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
			printf("%d\n",ptr->data);
			ptr = ptr->next;
		}
	}
	return;
}

struct list *create_list(struct list *ptr)
{
	struct list *temp = NULL, *nu = NULL;
	nu = (struct list *)malloc(sizeof(struct list *));
	if(nu == NULL)
	{
		printf("memory allocation failed\n");
		return ptr;
	}

	printf("enter the data into list ");
	scanf("%d",&nu->data);
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
/*
   struct list *create_loop(struct list *ptr)
   {
   int n,cnt = 0;
   struct list *temp = NULL, *pptr = NULL;
   if(ptr == NULL)
   {
   printf("list is empty\n");
   return ptr;
   }
   else
   {
   temp = ptr;
   while(temp->next)
   {
   temp = temp->next;
   cnt++;
   }
   cnt = cnt+1;
   temp = ptr;
p1:		printf("enter the node number to start loop\n");
scanf("%d",&n);
if((n <= cnt) && (n > 0))
{
while(temp)
{
pptr = temp;
temp = temp -> next;
cnt1++;
if(n == cnt1)
}

}
else
{
printf("pleae enter the node number in the range of 1  to  %d\n",cnt+1);
goto p1;
}

}
}
*/

void loop_detect_break(struct list *ptr)
{
	struct list *fptr = ptr, *sptr = ptr;
	while(sptr && fptr && fptr -> next)
	{
		sptr = sptr -> next;
		fptr = fptr -> next -> next;

		if(sptr == fptr)
		{
			//loop_break(sptr,ptr);
			sptr -> next ->next = NULL;
			return;
		}
	}
	return;
}

void loop_break(struct list *sptr, struct list *ptr)
{
	struct list *temp = ptr, *dptr = sptr;
/*	
	int n = 1;
	while (temp->next != dptr)
	{
		temp = temp->next;
		n++;
	}
	temp = ptr;
	dptr = ptr;
	for(int i = 0; i<n; i++)
		temp = temp->next;
	while(temp != dptr)
	{
		temp = temp -> next;
		dptr = dptr -> next;
	}

	while(temp -> next != dptr)
		temp = temp -> next;
	temp -> next = NULL;
*/
/*	while(dptr->next != temp -> next)
	{
		dptr = dptr->next;
		temp = temp ->next;
	}
*/
	dptr -> next = NULL;
	return;
}

void loop_list(struct list *ptr)
{
	struct list *a,*b,*temp;
	int op,g=0,flag=0;
	if(ptr == NULL  &&  ptr->next == NULL)
	{
		return;
	}
	else
	{
		printf("at which position u want to loop\n");
		scanf("%d",&op);
		temp=ptr;
		while(temp!=NULL)
		{
			g++;
			if(g==op)
			{
				a=temp;
				flag=1;
			}
			b=temp;

			temp=temp->next;
		}
	}
	if(flag==1)
	{
	b->next=a;
	}
	return;
}

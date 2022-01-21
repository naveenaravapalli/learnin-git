#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top = -1;
char *stack = NULL;

char *sort(char *);
void push(char *);
void pop(void);
int isempty(void);

int main()
{
	char *buf = NULL, *data = NULL;
	int i = 0;
	printf("enter the data : ");
	do
	{
		buf = realloc(buf, i + 1);
		buf[i] = getchar();
	} while (buf[i++] != '\n');
	buf[i-1] = '\0';
	data = sort(buf);
	push(data);
	pop();
	//printf("%s",data);
}

void push(char *ptr)
{
	int len = strlen(ptr), i = 0;
	stack = (char*) malloc(len);
	if(stack == NULL)
	{
		printf("stack is full\n");
		return;
	}
	while(i<len)
	stack[++top] = ptr[i++];
}

void pop(void)
{
	if(isempty())
	{
		printf("stack is empty\n");
		return;
	}
	else
	{
		while(top != -1)
		printf("%c\n",stack[top--]);
	}
	return;
}

int isempty(void)
{
	if(top == -1 )
		return 1;
	return 0;
}

char *sort(char *data)
{
	int l = strlen(data);
	char temp;
	for(int i = 1; i<l;i++)
	{
		for(int j = 0; j<l-1;j++)
		{
			if(data[j]>data[j+1])
			{
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	return data;
}

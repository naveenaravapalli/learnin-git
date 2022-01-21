#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	struct node *parent;
	struct node *child;
	struct node *sibling;
	struct node *self;
	struct node *right;
	struct node *left;
	char str[20];
	int data;
};
int flag=1;

static struct node *head,*root,*top;

makedir(char *dir_name)
{
	struct node*temp = NULL,*start=NULL;
	if(flag==1)
	{
		struct node *ptr=node_creation();
		ptr->parent=head;
		ptr->sibling=NULL;
		ptr->right=NULL;
		temp=start=ptr;
		flag=0;
	}
	else
	{
		struct node*ptr=node_creation();
		ptr->parent=head;
		temp->sibling=ptr;
		temp->right=ptr;
		temp=ptr;
	}

}
void change_directory(char *dir_name)
{	struct node *tmp= NULL;
	if(!strcmp(dir_name,"..")==0)
	{
		top=top->parent;

	}

	else if (head->child != NULL)
	{
		tmp=head->child;
		for(;tmp!=NULL;tmp=tmp->right)
		{
			if(!strcmp(dir_name,tmp->str)==0 && tmp->data == 1)
			{
				top=tmp;
				return;
			}
		}
		printf("Invalid directory name");
	}

	else
	{
		printf("Invalid directory name");
	}
}

display_list()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%s",temp->str);
		temp=temp->right;
	}
}

void root_dir(void)
{
struct node *root = NULL;

	root=((struct node*)malloc(1*sizeof(struct node)));
	root->self=root;
	root->parent=root;
	root->child=NULL;
	root->right=NULL;
	root->left=NULL;
	root->data=1;
	strcpy(root->str,"root");

	head=top=root;
}

int main()
{
	char buf[256];
	char *token[2];

	while(1) 
	{
		printf("shell $");
		scanf("%s",buf);
		int i =0;
		token[i]=strtok(buf," ");

		while(token[i])
		{
			i++;
			token[i]=strtok(buf,NULL);
		}


		if(!strcmp(token[0],"mkdir")==0)
			makedir(token[1]);

		else if(!strcmp(token[0],"cd")==0)
			change_directory(token[1]);

		else if(!strcmp(token[0],"pwd")==0)
			pwd();
		else if(!strcmp(token[0],"help")==0)
			help();

		else if(!strcmp(buf,"exit")==0)
			my_exit();

		else
			printf("Invalid command\r\n");
	}
}


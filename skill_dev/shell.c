#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *getcommand(void);
void splite_input(char *);
int main()
{
	char *input;
	int i;
	while(1)
	{
		printf("new_shell:> ");
		input = getcommand();
		splite_input(input);
		
	}
}

char *getcommand()
{
	char *p = NULL;
	int i = 0;
	do {
		p = realloc(p, i + 1);
		p[i] = getchar();
	} while (p[i++] != '\n');
	p[i-1] = '\0';
	return p;
}

void splite_input(char *input)
{
	int i,j;
	char *argv[30] = {0};
	i = strlen(input);
	//printf("%s %d\n",input,i);
	for(i=0,j=0,argv[j] = &input[i]; input[i] != '\0'; i++ )
		{

			if(input[i] == ' ')
			{

				input[i] = '\0';
				i++;
				j++;
				argv[j] = &input[i];
			}
		}
	printf("%s %s\n", argv[0],argv[1]);
}

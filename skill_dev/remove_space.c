#include<stdio.h>
#include<stdlib.h>

void remove_space(char *);

int main()
{
	char *buf = NULL;
	int i = 0;
	printf("enter the string : ");
	do
	{
		buf = realloc(buf, i + 1);
		buf[i] = getchar();
	} while (buf[i++] != '\n');
	buf[i-1] = '\0';
	remove_space(buf);
}

void remove_space(char *str)
{
	int i = 0,cnt = 0;
	for(i = 0; str[i]; i++)
	{
		if(str[i]!= ' '&&str[i] != '\t')
			str[cnt++] = str[i];
		        
	}
	str[cnt]= '\0';
	printf("string after remove space : %s\n", str);
}

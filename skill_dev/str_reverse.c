#include<stdio.h>
#include<stdlib.h>
void str_reverse(char *);
int str_length(char *);
int main()
{
	char *str;
	int i = 0;
	printf("enter the string : ");
	do 
	{
		str = realloc(str, i + 1);
		str[i] = getchar();
	} while (str[i++] != '\n');
	str[i-1] = '\0';
	str_reverse(str);
}

void str_reverse(char *ptr)
{
	int l = 0, i = 0;
	char temp;
	l = str_length(ptr);
	for(i = 0; i < l/2; i++)
	{
		temp = ptr[i];
		ptr[i] = ptr[l-1-i];
		ptr[l-1-i] = temp;
	}
	printf("reverse string : %s\n",ptr);
}

int str_length(char *str)
{
	int len = 0,i = 0;
	while(str[i++])
		len++;
	return len;
}

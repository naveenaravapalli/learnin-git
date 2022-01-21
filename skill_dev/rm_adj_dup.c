#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* remove_adj_dup(char * , int );

int main()
{
	//char str1[] = "abssbe",*str;
	char *buf = NULL,*str;
	int i=0;
	printf("enter the string :");
		do {
			buf = realloc(buf, i + 1);
			buf[i] = getchar();
		} while (buf[i++] != '\n');
		buf[i-1] = '\0';
	str = remove_adj_dup(buf, strlen(buf));
	printf("after remove dups : ");
	printf("%s\n",str);
}


char* remove_adj_dup(char * s, int n)
{
	int i,k = 0;

	for (i=1; i< n; i++)
	{
		if (s[i-1] != s[i])
			s[k++] = s[i-1];
		else
			while (s[i-1] == s[i])
				i++;
	}
	s[k++] = s[i-1];
	s[k] =  '\0';

	if (k != n)
		remove_adj_dup(s, k);
	else 
		return s;
} 

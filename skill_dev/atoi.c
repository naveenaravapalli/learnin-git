#include <stdio.h>
#include<string.h>

char *remove_space(char *str)
{
	int i = 0,cnt = 0;
	for(i = 0; str[i]; i++)
	{
		if(str[i]!= ' '&&str[i] != '\t')
			str[cnt++] = str[i];
		        
	}
	str[cnt]= '\0';
	return str;
}

int AtoI(char* str)
{
	int sum = 0, sign = 1, i = 0,flag = 0;
	if (str[0] == '-')
                {
                        sign = -1;
                        i++;
                }
	for(;i<strlen(str);i++)
	{
		if((str[i] >='0')&&(str[i] <='9'))
		{}
		else
			flag = 1;
	}
	i = 0;
	if(!flag)
	{
		if (str[0] == '-')
		{
			sign = -1;
			i++;
		}
		for (; str[i] != '\0'; ++i)
			sum = sum * 10 + str[i] - '0';
		return sign * sum;
	}
	else
	{
		printf("invalid data for atoi function\n");
		return 0;
	}
}

int main()
{
	char str[] = "-7875";
	for(i = 0; str[i]; i++)
        {
                if(str[i]!= ' '&&str[i] != '\t')
                        str[cnt++] = str[i];

        }

	int val = AtoI(str);
	printf("%d \n", val);
	return 0;
}


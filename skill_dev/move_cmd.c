#include<stdio.h>
#include<string.h>

int main(int argc, char*argv[])
{
	if(argc < 3)
	{
		printf("enter proper input\n");
		return 1;
	}
	char ch;
	FILE *fd1,*fd2;
	fd1 = fopen(argv[1],"r");
	if(fd1 == NULL)
	{
		printf("file %s opening failed\n",argv[1]);
		return 1;
	}

	fd2 = fopen(argv[2],"w");
	while((ch = fgetc(fd1))!=EOF)
	{
		fputc(ch,fd2);
	}
	fclose(fd2);
	remove(argv[1]);
	
}

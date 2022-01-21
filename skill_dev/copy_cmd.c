#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
	if(argc < 3)
	{
		printf("enter proper input\n");
		return 1;
	}

	FILE *fd1,*fd2;
	char ch;
	fd1 = fopen(argv[1],"r");
	if(fd1 == NULL)
	{
		printf("file %s opening failed\n",argv[1]);
		return 1;
	}
	for(int i = 2 ; i<argc;i++)
	{
		fd2 = fopen(argv[i],"w");

		while((ch = fgetc(fd1))!=EOF)
		{

			fputc(ch,fd2);
		}
		rewind(fd1);
		fclose(fd2);
	}
	fclose(fd1);
	return 1;
}

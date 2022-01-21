#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int status;
	pid_t pid,id;
	char *argv[30];
	while(1)
	{
		memset(argv,0,sizeof(argv));
		int i=0,j=0,k=0;
		printf("new_shell:> ");
		char *buf = NULL;
		do {
			buf = realloc(buf, i + 1);
			buf[i] = getchar();
		} while (buf[i++] != '\n');
		buf[i-1] = '\0';
		if(strcmp(buf,"quit")==0)
			exit(0);
		for(i=0,j=0,argv[j] = &buf[i]; buf[i] != '\0'; i++ )
		{ 

			if(buf[i] == ' ')
			{

				buf[i] = '\0';
				i++;
				j++;
				argv[j] = &buf[i];
			}
		}
		pid=fork();
		if(pid==0)
		{

			execvp(argv[0],argv);
			exit(0);		
		}	
		pid = wait(&status);
	}

}

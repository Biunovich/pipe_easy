#include "mylib.h"
void main()
{
	int fd[2];
	pipe(fd);
	pid_t pid;
	char str[100] = "Hellow world",result[100];
	int len = strlen(str);
	pid = fork();
	if (pid > 0)
	{
		close(fd[0]);
		write(fd[1],str,len);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0],result,len);
		result[len] = '\0';
		printf("Children %s\n",result);
		close(fd[0]);
	}
	wait(0);
}
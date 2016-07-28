#include "mylib.h"
void main(int argc ,char* argv[])
{
	int i=0,j;
	pid_t pid;
	int fd[2];
	pipe(fd);
	char ** arg = calloc(sizeof(char*),argc);
	for (i=0;i<argc;i++)
		arg[i] = calloc(sizeof(char),100);
	i=0;
	while(i<argc)
	{
		if (argv[i][0] != '.')
			arg[i] = argv[i];
		else
			j=i+1;
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1],1);
		execlp("ls"," ","-l",NULL);
	}
	else
	{
		char str[100];
		pid_t pid2;
		pid2 = fork();
		if (pid2 == 0)
		{
			close(fd[1]);
			dup2(fd[0],0);
			execlp("cut"," ","-f","1",NULL);
			exit(0);
		}
		else
		{
			wait(0);
		}
	}
	wait(0);
}
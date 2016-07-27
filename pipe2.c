#include "mylib.h"
void main()
{
	int fd,len;
	char text[100];
	mkfifo("/home/buin/pipe",0777);
	fd = open("/home/buin/pipe",O_RDWR,0777);
	while(1)
	{
		scanf("%s",text);
		write(fd,text,100);
	}
}
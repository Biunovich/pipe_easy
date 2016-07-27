#include "mylib.h"
void main()
{
	char str[100];
	int fd = open("/home/buin/pipe",O_RDWR,0777);
	while(1)
	{
		read(fd,str,100);
		    printf("%s\n",str);
	}
}
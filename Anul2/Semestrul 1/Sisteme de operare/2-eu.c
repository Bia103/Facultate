#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int f1=open("f1.txt", O_RDONLY);
	int f2=open("f2.txt", O_WRONLY);
	char c; ssize_t r;
	while( read(f1, &c, 1)) write(f2, &c, 1);

	return 0;
}

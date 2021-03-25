#include <stdlib.h>
#include <stdio.h>
#include <sys/errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int n,i;
	for(i = 1; i < argc; i++)
	{
		pid_t pid = fork();
		n = atoi(argv[i]);
		if(pid < 0)
			return errno;
		else
			if(pid == 0)
			{
				printf("%d: %d",n,n);
				while(n != 1)
				{
					if(n % 2 == 0)
						n = n/2;
					else
						n = n*3 + 1;
				printf("%d ",n);
				}
				printf("Parent %d Child %d",getppid(), getpid());
				perror(NULL);
				return 1;
			}
		else
		wait(NULL);
	}
return 0;
}


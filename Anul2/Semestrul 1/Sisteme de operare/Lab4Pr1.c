#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/errno.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
        return errno;
    if(pid == 0)
    {
        printf("Parinte: %d, Copil: %d",getppid(),getpid());
        char *argv[]={"pwd",NULL};
        execve("/bin/pwd", argv, NULL);
        perror(NULL) ;

    }
    else
    {
        wait(NULL);
    }
}

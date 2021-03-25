#include<stdlib.h>
#include<stdio.h>
#include<sys/errno.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid=fork();                                   // pid_t reprezinta un tip de date care este capabil sa reprezinte ID-ul unui proces (in GNU C este un int)
	if(pid<0)                                           // fork() este functia de sistem prin care se creeaza procese noi, copil care ruleaza concomitent cu procesul care chiama fork(), adica cu parintele. Dupa ce va fi conceput copilul , ambele procese vor executa instructiunile dupa fork
        return errno;                                   // se returneaza o eroare (numarul ultimei erori)
	else if(pid==0)                                     // noul copil a fosr creat cu succes
	{
		printf("Child %d finished.\n", getpid());       // se afiseaza pidul copilului (functia getpid() returneaza ID-ul procesului)
		char *argv[]={"ls", NULL};
		execve("/bin/ls", argv, NULL);
		perror(NULL);
	}
	     else
	     {
		wait(NULL);
		printf("My PID: %d, Child PID: %d\n", getppid(), getpid());
	     }
	return 0;
}

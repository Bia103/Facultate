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
		pid_t pid = fork();             // pid_t reprezinta un tip de date care este capabil sa reprezinte ID-ul unui proces (in GNU C este un int)
		n = atoi(argv[i]);              // elementele citite ca siruri de caractere sunt transformate in int-uri
		if(pid < 0)                     // daca valoarea din variabila pid este 0, atunci creearea copilului nu a avut succes
			return errno;               // se returneaza o eroare (numarul ultimei erori)
		else
			if(pid == 0)                // noul copil a fosr creat cu succes
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
				printf("Parent %d Child %d",getppid(), getpid());   // se afiseaza pidul copilului (functia getpid() returneaza ID-ul procesului, iar getpid() returneaza id-ul parintelui )
				perror(NULL);            // daca in paranteza nu era NULL, perror() afisa un mesaj standard ce descria ultima eroare intampinata
				return 1;                // impiedica copilul sa faca fork()
			}
		else                            // suntem in parinte
		wait(NULL);                     // asteapta copilul
	}
return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/errno.h>

int main()
{
	int n;
	pid_t pid = fork();                 // pid_t reprezinta un tip de date care este capabil sa reprezinte ID-ul unui proces (in GNU C este un int)
                                        // fork() este functia de sistem prin care se creeaza procese noi, copil care ruleaza concomitent cu procesul care chiama fork(), adica cu parintele. Dupa ce va fi conceput copilul , ambele procese vor executa instructiunile dupa fork
	if(pid < 0){                        // daca valoarea din variabila pid este 0, atunci creearea copilului nu a avut succes
		return errno;                   // se returneaza o eroare (numarul ultimei erori)
	}
	else
	if(pid == 0)                        // noul copil a fosr creat cu succes
	{
		printf("Child %d finished \n",getpid());    // se afiseaza pidul copilului (functia getpid() returneaza ID-ul procesului)
		scanf("%d",&n);
		printf("%d: %d",n,n);           // se face collatz
		while(n != 1)
		{
			if(n % 2 == 0)
				n = n/2;
			else n = n*3 +1;
		printf("%d ", n);
		}

		perror(NULL);                   // daca in paranteza nu era NULL, perror() afisa un mesaj standard ce descria ultima eroare intampinata
	}
	else                                // suntem in parinte
		wait(NULL);                     // asteapta copilul

	return 0;
}

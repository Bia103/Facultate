#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <pthread.h>
// -pthread
void *inv(void *args)
{
	int i,k = 0;
	char *s = args;
	char *copy = (char*)malloc(strlen(s));
	for(i = strlen(s)-1; i >= 0; i--)   // parcurgem sirul de caractere s in sens invers, iar in acelasi timp putem in copie in ordne noemala, obtinand astfel in copie sirul de caractere inversat
		copy[k++] = s[i];
	return copy;                        // returneaza copia in care lierele sunt inversate
}

int main(int argc, char *argv[])
{
	char *s = argv[1];                  // s ia primul argument
	pthread_t tid;                      // firele de executie sunt implementate prin variabile de tip pthread_t
	pthread_create(&tid,NULL,inv,s);    // incepe un nou thread in proces
                                        // NULL face procesul sa porneasca cu atribute default
	char *t;
	pthread_join(tid,&t);               // asteapta ca thread-ul specificat sa se termine
	printf("%s \n",t);
	return 0;
}

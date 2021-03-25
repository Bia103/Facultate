//sem_wait -> decrementeaza cu 1; daca e 0, asteapta pana va putea
//sem_post -> incrementeaza
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <semaphore.h>
#include <pthread.h>
#define NTHRS 5         // numarul firelor de executie

sem_t sem;
pthread_mutex_t mtx;
int S=0;

void barrier_point()
{
        int S_local;
        pthread_mutex_lock(&mtx);       // un singur thread va avea dretputul exclusiv de executie
        S++;
        pthread_mutex_unlock(&mtx);     // elibereaza mutex-ul
        S_local=S;

        if(S_local<NTHRS)
        {
            if(sem_wait(&sem))             // decrementeaza  semaforul sem (blocheaza)
            {
                perror(NULL); return errno;
            }
        }
        else for(int i=0; i<NTHRS; ++i)
            sem_post(&sem);                 //  incrementeaza semaforul sem (deblochiaza)
}

void *tfun(void *v)
{
	int *tid=(int *)v;
	printf("%d reached the barrier \n",*tid);
	barrier_point();
	printf("%d passed the barrier \n", *tid);
}

int main()
{
	pthread_t thr[100];
	int i;
	if(sem_init(&sem,0,S))                          // initializeaza un semafor la adresa sem, iar S este valoarea initiala a acestuia
	{perror(NULL); return errno;}                   // 0 inseamna ca semaforul este impartit intre procese

	if(pthread_mutex_init(&mtx,NULL))               // va fi creat un obiect de tip mutex, iar daca aceasta operatiune esueaza se returnoeaza o eroare, daca al 2-lea argument e NULL, vor fi folosite atributele implicite pt mutex
	{perror(NULL); return errno;}

	for(i=0; i<NTHRS; i++)
	{
        int *k=(int *)malloc(1);
        *k=i;
		if(pthread_create(&thr[i],NULL,tfun,k))     // incepe un nou thread in proces
        {perror(NULL); return errno;}
	}

	void  *rezultat=(void *)malloc(1);
    for(i=0;i<NTHRS;i++)
        if(pthread_join(thr[i],&rezultat))          // asteapta ca thread-ul specificat sa se termine
        {perror(NULL); return errno;}

    sem_destroy(&sem);                              // distruge semaforul de la adresa sem

	return 0;
}

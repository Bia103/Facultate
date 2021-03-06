#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#define MAX_RESOURCES 5

int available_resources = MAX_RESOURCES;
pthread_mutex_t mtx;

int decrease(int count)
{
    pthread_mutex_lock(&mtx);               // un singur thread va avea dretputul exclusiv de executie
    if (available_resources<count)
        {
        pthread_mutex_unlock(&mtx);         // elibereaza mutex-ul
        return -1;
        }
    else
        available_resources -= count ;
    printf("Get %d resources, remaining %d resources\n",count,available_resources);
    pthread_mutex_unlock(&mtx);             // se deblocheaza (demarcheaza zona cririca)
    return 0;
}

int increase(int count)
{
    pthread_mutex_lock(&mtx);
    available_resources += count ;
    printf("Release %d resources, remaining %d resources\n",count,available_resources);
    pthread_mutex_unlock(&mtx);
    return 0;
}

void *fct(void *k)
{
    int *n = (int*) malloc(1);
    *n = *((int *)k);

    if(*n > available_resources)
        increase(*n);
    else decrease(*n);

    return n;
}

int main()
{
    if ( pthread_mutex_init(&mtx, NULL))        // va fi creat un obiect de tip mutex, iar daca aceasta operatiune esueaza se returnoeaza o eroare, daca al 2-lea argument e NULL, vor fi folosite atributele implicite pt mutex
    {
          perror (NULL);
          return errno ;
    }
    pthread_t tid[20];                          // implementam firele de executie
    int i;
    int *result;
    for(i = 0; i < 10; ++i)
    {
        int *p=(int *)malloc(1);
       *p=i%3+1;
       pthread_create(&tid[i],NULL,fct,p);      // facem un nou fir de executie si apelam functia cu argumantul p care se presupune a fi un numar random
       pthread_join(tid[i],&result);            // asteptam finalizarea executiei unui thread, si daca rezultat nu e NULL, atunci va fi pus in result rexultatul functiei
    }
    return 0;
}

#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **matrixA, **matrixB;
struct mat
{
	// poz i curent, poz j curent, dimensiunea p
	int i, j, p;
};

void *produs(void *v)
{
    struct mat *arg=v;
    int *sum=(int *)malloc(sizeof(int));
    *sum=0;
    for(int k=0; k<arg->p; k++)
        *sum+=matrixA[arg->i][k] * matrixB[k][arg->j];

	return sum;
}

int main()
{
	int m, n, p, i, j, k=0;
	void *result;


	printf("Dimensiune pentru prima matrice: ");
	scanf("%d %d", &m, &p);                                 // se citeste numarul de linii si de coloane
	matrixA=(int**)malloc(sizeof(int*)*m);
	for(i=0; i<m; i++)                                      // citirea primei matrice
    {
		matrixA[i]=(int *)malloc(sizeof(int)*p);
		for(j=0; j<p; j++)
		{
			int x;
			scanf("%d", &x);
            matrixA[i][j]=x;
		}
	}


	printf("Dimensiune pentru a 2-a matrice (primul arg sa fie acelasi ca ultimul arg de la prima matrice) : ");
	scanf("%d %d", &p, &n);
    matrixB=(int**)malloc(sizeof(int*)*p);                  // se citeste numarul de linii si de coloane
    for(i=0; i<p; i++)
    {
        matrixB[i]=(int *) malloc(sizeof(int)*n);
        for(j=0; j<n; j++)
        {
            int x;
            scanf("%d", &x);
            matrixB[i][j]=x;
        }
    }

    pthread_t thr[n*m];                                     // firele de executie sunt implementate prin variabile de tip pthread_t, si se fac n*m fire de executie pt fiecare termen din matrice
	int resMatrix[m][n];
	for(i=0; i<m; i++)
    {
		for(j=0; j<n; j++)
		{
		    struct mat *arg=(struct mat*)malloc(sizeof(struct mat));    // facem o structura prin care retinem linia, coloana si numarul de coloane din prima matrice(adica si numarul de linii din a 2-a matrice)
            arg->i=i;
            arg->j=j;
            arg->p=p;
			if(pthread_create(&thr[k++], NULL, produs, arg))    // incepe un nou thread in proces
			{                                                   // NULL face procesul sa porneasca cu atribute default
				perror(NULL);
                return errno;
			}
		}
	}

	k=0;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
        {
            if(pthread_join(thr[k++], &result))                 // asteapta ca thread-ul specificat sa se termine
            {
				perror(NULL);
				return errno;
			}
			resMatrix[i][j]=*((int*)result);
        }

	//Afisare Matrice Rezultata
    printf("\n\nREZULTAT:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++) printf("%d ", resMatrix[i][j]);
        printf("\n");
    }

    //Dezalocarea memoriei
    for(i=0; i<m; i++) free(matrixA[i]);
    for(i=0; i<p; i++) free(matrixB[i]);

    return 0;
}

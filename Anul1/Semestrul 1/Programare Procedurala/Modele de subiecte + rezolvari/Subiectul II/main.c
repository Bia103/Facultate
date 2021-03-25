#include <stdio.h>
#include <stdlib.h>
int **tablou(int n)
{
    int **p=(int**)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
        p[i]=(int*)malloc(sizeof(int)*n);
    int l=0;
    for(int i=0;i<n;i++)
    {
        p[n-1][i]=n-i;
        //printf("%d ",p[n-1][i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        l++;
        for(int j=0;j<=n-l-1;j++)
            {
                if(j==0)
                    p[i][j]=i+1;
                else{
                    p[i][j]=p[i][j-1]+p[i+1][j]+p[i+1][j-1];
                }
            }
        }
        l=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
                printf("%d ",p[i][j]);
            printf("\n");
        }
        return p;
}
int main()
{

    int **a=tablou(4);
    return 0;
}

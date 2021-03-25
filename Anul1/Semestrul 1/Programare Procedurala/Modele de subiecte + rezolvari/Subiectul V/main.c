#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int x=*(int *)a;
    int y=*(int *)b;
    if(x=y)
        return 0;
    if(x<y)
        return -1;
    return 1;
}
void fifi(char *nume)
{
    int *p=(int *)malloc(4);
    FILE *f=fopen(nume,"rb");
int    i=1,s;
    while(fread(&s,1,4,f))
    {
       // printf("- %d -",s);
        int *aux=(int *)realloc(p,i*sizeof(int));
        aux[i-1]=s;
        p=aux;
        i++;
    }
qsort(p,i-1,4,cmp);
 for(int j=0;j<i-1;j++)
        printf("%d ",p[j]);
}

int main()
{
    FILE *f=fopen("da.bin","wb");
    int x=3;
    fwrite(&x,1,4,f);
    x=6;
    fwrite(&x,1,4,f);
     x=5;
    fwrite(&x,1,4,f);
    fclose(f);
    fifi("da.bin");
    return 0;
    bsearch()
}

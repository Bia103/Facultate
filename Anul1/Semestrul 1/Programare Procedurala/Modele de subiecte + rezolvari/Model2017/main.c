#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char ro[101],ls[101];
}dictionar;
int cmp(const void *a,const void *b)
{
    dictionar x=*(dictionar*)a;
    dictionar y=*(dictionar*)b;
   if(strlen(x.ro)==strlen(y.ro))
    return 0;
   if(strlen(x.ro)<strlen(y.ro))
    return -1;
    return 1;
}
dictionar* incarc_dict(char* nume)
{
    FILE *f=fopen(nume,"r");
    int n;
    fscanf(f,"%d",&n);
    //printf("%d    ",n);
    dictionar *g=(dictionar*)malloc(sizeof(dictionar)*n);
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%s",g[i].ro);
        fscanf(f,"%s",g[i].ls);
    }
   /* for(int i=0;i<n;i++)
    {
        printf("%s ",g[i].ro);
        printf("%s\n",g[i].ls);
    }*/
    qsort(g,n,sizeof(dictionar),cmp);
    /* for(int i=0;i<n;i++)
    {
        printf("%s ",g[i].ro);
        printf("%s\n",g[i].ls);
    }*/
    return g;
}
char *traduc(char *cuvant,dictionar *g,int n)
{
    char aux[1010];
    for(int i=0;i<n;i++)
    {
        if(strcmp(cuvant,g[i].ro)==0)
            return g[i].ls;
        else
        {
            int nr=0;
            for(int j=0;j<strlen(cuvant);j++)
            {
               if(cuvant[j]!=g[i].ro[j])
                break;
               nr++;
            }
            if(n/2<=nr)
                strcpy(aux,g[i].ls);
        }
    }
    //printf("%s\n", aux );
    if(strlen(aux))
    {
        // printf("%s\n", aux );
        return aux;}
    return NULL;
}
int main()
{
    dictionar *v=incarc_dict("dictionar_engl.txt");
    const char *a=traduc("muncitorii",v,12);
    printf("%s",a);
    return 0;
}

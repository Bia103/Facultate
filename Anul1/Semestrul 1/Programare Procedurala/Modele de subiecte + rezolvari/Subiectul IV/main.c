#include <stdio.h>
#include <stdlib.h>
void fif(char *nume)
{
    FILE *f=fopen(nume,"r");
    int a[1001],v[1001],i;
    FILE *fout=fopen("cuvinte.out","w");
    char *w=(char*)malloc(101),*s=(char*)malloc(101);
    for(i=97;i<=140;i++)
            {v[i]=0;}fgets(w,101,f);
    for(i=0;i<strlen(w);i++)
      {
          v[w[i]]++;
      }

    while(fgets(s,101,f)!=NULL)
    {
       char *p=strtok(s," .!,");
        while(p)
        {
            int ok=1;
            for(i=97;i<=140;i++)
            {a[i]=0;}
            for(i=0;i<strlen(p);i++)
                a[p[i]]++;
            for(i=97;i<=140;i++)
                if(a[i]!=v[i])
                    {ok=0;
                  //  printf("%d %d ...",a[i],v[i]);
                    }
                  //  printf("\n");
            if(ok)
            {
                fprintf(fout,"%s\n",p);
            }
            p=strtok(NULL," .!,");
        }
    }
    //printf("%s",w);
}
int main()
{
    fif("cuvinte.txt");
    return 0;
}

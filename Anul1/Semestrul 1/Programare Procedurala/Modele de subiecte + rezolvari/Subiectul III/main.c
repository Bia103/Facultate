#include <stdio.h>
#include <stdlib.h>
#include<stdarg.h>
int nr(int x,...)
{
    va_list lp;
    int mi=x,y;
    va_start(lp,x);
    while((y=va_arg(lp,int)))
        if(y<mi)
          {
              mi=y;printf("%d \n",mi);
          }
    va_end(lp);
    printf("\n");
    return mi;
}
int main()
{
   // int x=nr(4,5,3,1,7,0);
    int ok=1,a=9,b=7,c=6,d=1;
    if(b!=nr(a,b,0))
        ok=0;
    if(c!=nr(a,b,c,0))
        ok=0;
    if(d!=nr(a,b,c,d,0))
        ok=0;
    printf("%d",ok);
    return 0;
}

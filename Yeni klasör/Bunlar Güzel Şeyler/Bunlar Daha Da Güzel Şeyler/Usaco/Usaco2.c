/*
PROG:gift1
LANG:C
NAME:mmmeeed1
*/
#include<stdio.h>
#include<stdlib.h>
struct kisi{
     char isim[30];
     int mevcut;   
};
int main()
{
     int x,i;
     FILE *f1,*f2;
     f1=fopen("gift1.in","r");
     f2=fopen("gift1.out","w");
     fscanf(f1,"%d",&x);
     struct kisi kisi[x];
     for(i=0;i<x;i++)
     {
          fscanf(f1,"%s",kisi[i].isim);
          kisi[i].mevcut=0;
     }
     int u;
     for(u=0;u<x;u++)
     {
          char s[30];
          fscanf(f1,"%s",s);
          for(i=0;i<x;i++)
               if(!strcmp(s,kisi[i].isim))
               {
                    int verilen;
                    fscanf(f1,"%d",&verilen);
                    int a;
                    fscanf(f1,"%d",&a);
                    if(a!=0) kisi[i].mevcut-=(verilen/a)*a;
                    int j;
                    char u[30];
                    int y;
                    for(j=0;j<a;j++)
                    {
                         fscanf(f1,"%s",u);
                         for(y=0;y<x;y++)
                         {
                              if(!strcmp(u,kisi[y].isim))
                              if(a!=0) kisi[y].mevcut+=verilen/a;
                         }
                    }
               }
     }
     for(i=0;i<x;i++)
     fprintf(f2,"%s %d\n",kisi[i].isim,kisi[i].mevcut);
     return 0;
}

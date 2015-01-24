#include<stdio.h>
#define MAX 1000
char s[MAX];
void temizle(int x)
{
     int i;
         for(i=0;i<x;i++) s[i]=' ';
}
int main()
{
     int n,x,i,j,u;
     int sol=0,sag=0;
     int islem_yapildi;
     int sayac;
     system("cls");
     scanf("%d",&n);
     char c[n];
     for(i=0;i<n;i++)
     {
          islem_yapildi=0;
          sayac=0;
          scanf("%d",&x);
          scanf("%s",s);
          if(x%2!=0) { c[i]='i'; continue; }
          if(s[0]=='<') { c[i]='i'; continue; }
          if(s[x-1]=='>') { c[i]='i'; continue; }
          
          for(j=0;j<x;j++)
          {
               if(s[j]=='<') sol++;
               else sag++;
          }
          if(sag!=sol){ c[i]='i'; continue; }
          
          while(1)
          {
     zzz:
               for(j=0;j<x-1;j++)
               {
                    if(s[j]=='>')
                    {
                         u=j+1;
                         while(s[u]!='<')
                         {
                              u++;
                              if(u>x-1){ c[i]='i'; goto pff; }
                         }
                         islem_yapildi=1;
                         s[j]=' ';
                         s[u]=' ';
                         sayac++;
                         goto zzz;
                    } 
               }
               if(sayac==x/2) { c[i]='l'; break; }
               if(islem_yapildi==0) { c[i]='i'; break; }
          }
     pff:
          temizle(x);
     }
     
     for(i=0;i<n;i++) 
          if(c[i]=='l') printf("legal\n");
          else printf("illegal\n");
          getch();
          
}

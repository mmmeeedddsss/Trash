#include <stdio.h>
int sag,sol;
int *p;
/*
void basla(int *p,int n)
{
     sag+=*(p+(n-1));
     sol+=*(p+(n-2));
     dagit(n-1);
}
*/
int dagit(int n)
{
     if(n<0) return 0;
     else if(sag>sol) sol+=p[n];
     else if(sol>sag) sag+=p[n];
     else if(sag==sol) sol+=p[n];
     printf("%d  %d\n",sag,sol);
     dagit(n-1);
}
void adam_buble_akar(int n)
{
     int i,j;
     int save;
     for(i=0;i<n;i++)
          for(j=i;j<n;j++)
          {
               if(p[i]>p[j])
               {
                    save=p[i];
                    p[i]=p[j];
                    p[j]=save;    
               }
          }
}
int main()
{
     int n,i;
     scanf("%d",&n);
    p=malloc(sizeof(int)*n);
     
     for(i=0;i<n;i++)
          scanf("%d",(p+i));
          
     adam_buble_akar(n);
     
     for(i=0;i<n;i++)
          
     sag=sol=0;
     dagit(n-1);
     printf("\n\n%d  %d",sag,sol);
     getch();
}

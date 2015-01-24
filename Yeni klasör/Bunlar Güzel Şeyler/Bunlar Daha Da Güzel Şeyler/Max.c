#include <stdio.h>
#include <stdlib.h>
int *s;
int x;
int max(int a,int b)
{
     return a>b?a:b;
}
int f(int y1,int x1)
{
     int a=0,b=0;
     if(y1==0&&x1==0) return *s;
     if(x1) a=f(y1,x1-1);
     if(y1) b=f(y1-1,x1);
     return max(a,b)+*((s+(y1*x))+x1);
}
int main()
{
     int i,j;
     scanf("%d",&x);
     s=(int*)malloc(sizeof(int)*x);
     for(i=0;i<x;i++)
          for(j=0;j<i;j++)
               scanf("%d",s+x);
     printf("\n%d\n",f();
     getch();
}

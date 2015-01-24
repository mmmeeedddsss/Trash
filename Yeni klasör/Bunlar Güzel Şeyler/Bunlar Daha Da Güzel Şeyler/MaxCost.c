#include <stdio.h>
#include <stdlib.h>
int *s;
int x,y;
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
     scanf("%d%d",&x,&y);
     s=(int*)malloc(sizeof(int)*(x*y));
     for(i=0;i<y;i++)
          for(j=0;j<x;j++)
               scanf("%d",(s+(i*x)+j));
     printf("\n%d\n",f(j-1,i-1));
     getch();
}

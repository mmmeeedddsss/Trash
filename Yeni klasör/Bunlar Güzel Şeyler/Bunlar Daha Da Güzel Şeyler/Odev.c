#include<stdio.h>

int horner(p,n,x)
{
         int m=p[n];
         
         for(i=n-1;i>=0;i--)
          p=(x*m)+p[i];
          
          return m;
}

multiply(y,z,n,x)
{
          for(i=1;i<=n;i++)
               for(j=1;j<=n;j++)
                    x[i,j]=0;
                    for(k=1;k<=n;k++)
                         x[i][j]=s[i][j]+y[i][k]*z[i][j];
          return x;
}

int main()
{
     int i,r=0,a,j,k,l;
     scanf("%d",&a);
          for(i=1;i<=a;i++)
               for(j=1;j<=i;j++)
                    for(k=j;k<=i+j;k++)
                         for(l=1;l<i+j-k;l++)
                              r++;
      printf("%d",r);
      getch();
      
      
}

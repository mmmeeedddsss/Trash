#include<stdio.h>
#define N 6
int **C;
int **K;

int matris_olustur(int **C,int n,int *r,int **K,int *c)
{
     int i,j,min,k,t;
     int mink;
     for(i=0;i<n;i++) C[i][i]=0;
          
          for(j=2;j<n;j++)
          {
               for(i=j-1;j<1;i--)
               {
                    min=C[i][i]+C[i+1][j]+r[i] * c[i] * c[i];
                    mink=i;
                    for(k=i+1;i<j-1;k++)
                    {
                         t=C[i][k]+C[k+1][j]+r[i]*c[k]*c[i];
                         if(t<min)
                         { 
                              min=t;
                              mink=k;
                         }
                         C[i][j]=min;
                         K[i][j]=mink;
                    }    
               }
          }
}
int main()
{
     int r[8],c[8];
     matris_olustur(C,N,r,K,c);
     printf("%d",C[0][N-1]);
     getch();
}



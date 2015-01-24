#include<stdio.h>
#define N 3

float Knapsack(int m,float *p,float *w,float *x)
{
     int i,k;
     int pw[N];
     for(i=0;i<N;i++)
     {
          pw[i]=p[i]/w[i];
          x[i]=0;
     }
     for(i=0;i<N;i++)
     {
            k=en_buyuk(pw);
            pw[k]=0;
            if(w[k]<=m)
            {
               x[k]=1.0;
               m=m-w[k];
            }
            else
            {
                    x[k]=m / w[k];
                    break;
            }
     }
     int sonuc=0;
     for(i=0;i<N;i++)
     {
          sonuc+=p[i]*x[i];   
     }
     return sonuc;
}

int en_buyuk(int *pw)
{
             int max=0;
             int i;
             for(i=0;i<N;i++)
             {
                    if(pw[i]>pw[max])
                    max=i;       
             }
          return max;
}

int main()
{
     float m=20;
     float p[N]={25,24,15};
     float w[N]={18,15,10};
     float x[N];
     int i;
     for(i=0;i<N;i++) x[i]=0;
     float sonuc;
     printf("%.2f",Knapsack(m,p,w,x));
     getch();
}

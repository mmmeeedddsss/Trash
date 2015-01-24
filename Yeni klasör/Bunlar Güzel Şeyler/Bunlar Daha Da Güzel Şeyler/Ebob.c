#include <stdio.h>
#define M 100000000
//#include <windows.h>
int s[M];

int ebob(int x,int y)
{
     if(!y) return x;
     return ebob(y,x%y);    
}
void fill_array()
{
     srand(time(NULL));
      int i,a;
      for(i=0;i<M;i++)
      {
          //Sleep(10);
          a=rand()%100;
          s[i]=a;
      }
}
int buble_sort()
{
     fill_array();
     int i,j;
     short flag;
     for(i=0;i<M-1;i++)
     {
          flag=0;
          for(j=0;j<(M-1-i);j++)
               if(s[j]>s[j+1])
               {
                    swap(&s[j],&s[j+1]);
                    flag=1;
               }
          if(!flag) break;
     }
     for(i=0;i<M;i++) printf("--> %d\n",s[i]);
}
int swap(int *a,int *b)
{
     int temp;
     temp=*a;
     a=b;
     *b=temp;    
}
int min(int x,int y)
{
     return x>y?y:x;    
}
int s_r(int n)
{
     if(n==1) return 1;
     return s_r(n-1) + n*n*n;    
}
int s_l(int n)
{
     int cevap=1;
     while(n>0)
     {
          cevap+= n*n*n;    
     }
     return cevap;
}
int fib(int x)
{
     if(x==1||x==2) return 1;
     return fib(x-1)+fib(x-2);    
}
int ebob_lit(int x,int y)
{
     int s=min(x,y);
     while(s>0)
     {
          if(x%s==0&&y%s==0)
               return s;
               s--;    
     }    
}
void prime(int x)
{
     int i;
     FILE *f1;
     f1=fopen("asal.txt","w");
     for(i=3;i<x;i+=2)
     {
          if(is_prime(i)) fprintf(f1,"%d\n",i);
     }
}
int is_prime(int x)
{
     if(x==2) return 1;
     //if(!x%2) return 0;
     int j;
     for(j=3;(j*j)<x+1;j+=2)
          if(!(x%j)) return 0;
     return 1;
}
int unique_elements(int *p,int n)
{
     int i,j,a[n];
     for(i=0;i<n-1;i++)
          for(j=i+1;j<n;j++)
               if(a[i]=a[j])
                    return 0;
     return 1;
}
/*
void a_prime(int n)
{
     int i,a[n],p,j;
     for(i=2;i<=n;i++)
              a[n]=n;
              
     for(i=2;i*i<n+1;i++)
          if(a[p]!=0)
          {
               j=p*p;
               while(j<=n)
               {
                    a[j]=0;
                    j+=p;    
               }
          }
          i=0;
          int L[n];
     for(j=2;i<=n;i++)
          if(a[p]!=0)
          {
               L[i]=a[j];
               i++;
               printf("%d\n",L[i]);
          }
         
}
*/
int main()
{
          srand(time(NULL));
          //printf("%d\n",ebob_lit(36,20));
          //printf("%d\n",ebob(36,20));
          //prime(1000000);
          buble_sort();
          getch();
}

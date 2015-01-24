#include<stdio.h>
unsigned long long int komb_hesapla(int x,int y)
{
         unsigned long long int ust=1,alt=1;
         if((x/2)<y) y=x-y;
         int i;
         
         for(i=0;i<y;i++)
         {
               ust*=x;
               x--;
         }
         for(;y>1;y--)
         {
               alt*=y;
         }
         return ust/alt;
}
int main()
{
     int i,j,x;
     scanf("%d",&x);
     if(x>15) x=15;
     for(i=0;i<x;i++)
     {
          for(j=0;j<i+1;j++)
          {
               printf("%llu  ",komb_hesapla(i,j));    
          }
          puts("");
     }
     getch();
}

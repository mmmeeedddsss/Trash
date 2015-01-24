#include<stdio.h>
#include<stdlib.h>
struct item{
     int value,weight;   
};

struct item item[4];

int f(int *s,int n,int max)
{
     int toplam=0,i;
     int agirlik=0;
     for(i=0;i<4;i++)
     {
          if(s[i]==1) 
          {
                   toplam+=item[i].value;
                   agirlik+=item[i].weight;
                   if(agirlik>max) return 0;
          }
     }
     return toplam;
}

int main()
{
     int x,i,j;
     int s[4],en_buuk;
     for(i=0;i<4;i++)
     {
              scanf("%d",&item[i].value);
              scanf("%d",&item[i].weight);
     }
     int max;
     scanf("%d",&max);
     scanf("%d",&x);
     for(i=0;i<x;i++)
     {
          en_buuk=0;
          for(j=0;j<4;j++)
          {
               scanf("%d",&s[j]);    
          }   
          if(f(s,4,max)>en_buuk) en_buuk=f(s,4,max);
     }
     
     printf("%d",en_buuk);
     getch();
}

#include<stdio.h>
int selection(int *s,int x)
{
     int i,j;
     int min=s[0];
     int temp,p;
     for(j=0;j<x;j++)
     {
          for(i=j+1;i<x;i++) 
                    if(s[i]<s[j])
                    {
                         temp=s[j];
                         s[j]=s[i];
                         s[i]=temp;
                    }
          for(p=0;p<x;p++) printf("%5d ",s[p]);
          puts("\n");
     }
}

int insertion(int *s,int n)
{
     int i,j,temp;
         for(i=1;i<n;i++)
               for(j=0;j<i;j++)
                    if(s[i]>s[j])
                    {
                          kaydir();   
                    }
}

void kaydir(int n,int b,int *s)
{
         int i,j;
         int temp2;
         int deger=s[b];
         for(i=0;i<b;i++)
         {
               int temp=s[i];
               if(deger<s[i])
               {
                    s[i]=deger;
                    for(j=i+1;j<=b;j++)
                    {
                         s[j+1]=s[j];    
                    }
                    return;
               }
         }
}

int f(int *s,int b,int n)
{
     int i,min;
     min=s[b];
     for(i=b+1;i<n;i++) if(min>s[i]) min=s[i];
     printf("Min --> %d",min);
     puts("");
}
int main()
{
     int x,i;
     scanf("%d",&x);
     int s[x];
     for(i=0;i<x;i++) scanf("%d",&s[i]);
     //selection(s,x);
     insertion(s,n);
     //getch();
     //int z;
     //scanf("%d",&z);
     //f(s,z,x);
     getch();
}

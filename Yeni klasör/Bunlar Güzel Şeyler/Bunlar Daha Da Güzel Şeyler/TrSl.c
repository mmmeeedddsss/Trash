#include<stdio.h>
#include<conio.h>
#define N 3
int s[3][3];
int min(int x,int y)
{
     return x>y?x:y;    
}
int hesapla(int x)
{
     if(x==0) return s[0][0];
     return min(hesapla(x-1)+s[x][N-x],s[x][N-x]); // 
}

int main()
{
     int i,j;
     for(i=0;i<N;i++)
          for(j=i;j<N;j++)
               scanf("%d",&s[i][j]);
     printf("%d\n",hesapla(N));
     getch();
}

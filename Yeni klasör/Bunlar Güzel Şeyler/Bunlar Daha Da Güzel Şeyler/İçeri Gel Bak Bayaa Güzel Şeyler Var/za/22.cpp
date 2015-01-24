#include<iostream>
#include<conio.h>
#define MAX 25
int array[MAX][MAX];
int max(int x,int y)
{
     return x>y?x:y;     
}

int solve(int n) // dik üçgen þeklinde girilen girdide üst noktaya en çok puan toplayarak ulaþma .. sorular.pdf soru 22
{
     if( n == 0 ) return array[0][0];
     int m = 0;
     while(m<n)
     {
          array[n-1][m] += max( array[n][m] , array[n][m+1]  );
          m++;
     }
     return solve(n-1);
}

int main()
{
     int n;
     system("cls");
     scanf("%d",&n);
     for(int i=0;i<n;i++)
          for(int j=0;j<=i;j++)
               scanf("%d",&array[i][j]);
     printf("\n -- %d --\n",solve(n-1));
     getch();
}

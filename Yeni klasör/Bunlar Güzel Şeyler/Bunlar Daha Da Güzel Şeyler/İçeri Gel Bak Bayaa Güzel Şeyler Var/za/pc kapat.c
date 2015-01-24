#include<stdio.h>
#include<windows.h>

int main()
{
     int n,i=0;
     printf("Kac Dakika Sonra Pc kapatlsin ?\n");
     scanf("%d",&n);
     while( i < n )
     {
          system("cls");
          printf("Pc Kapanmasina %d Dakika Kaldi ..\n",n-i);
          sleep( 1000 * 60 );
          i++;
     }
     system("cls");
     
     system("shutdown -h now");
}

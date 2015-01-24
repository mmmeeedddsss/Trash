#include<stdio.h>
#include<windows.h>

int main()
{
     int n,i=0;
     printf("Kac Dakika Sonra Alarm Calsin ?\n");
     scanf("%d",&n);
     while( i < n )
     {
          system("cls");
          printf("Alarmin Calmasina %d dakika kaldi..\n",n-i);
          sleep( 1000 * 60 );
          i++;
     }
     system("cls");
     printf( "Alarm !!!" );
     while( !kbhit() ) {  printf("\a"); Sleep(500); }
}

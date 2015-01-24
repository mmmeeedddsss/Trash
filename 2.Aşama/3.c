#include<stdio.h> // Kütüphanemi Ekledim

int palmi( char array[] ,int uzunluk )
{
     int i,j;
     j = uzunluk - 1;
     for( i=0; i<j; i++ )
     {
          if( array[i] != array[j] )
               return 0;
          j--;
     }
     return 1;
}

int main() // Ana Fonksiyon
{
     int uzunluk;
     scanf("%d ",&uzunluk);
     char arry[uzunluk];
     int i;
     for( i=0; i<uzunluk; i++ )
          scanf("%c",&arry[i]);
          
     if( palmi( arry , uzunluk ) == 1 )
          printf("Girilen Deger Palindromdur.");
     else
          printf("Girilen Deger Palindrom Degildir.");
          
     getch(); // Programýn Kapanmadan Önce Beklemesi Ýçin Bir Fonksiyon.
}

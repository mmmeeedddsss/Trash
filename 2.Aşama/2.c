#include<stdio.h> // K�t�phanemi Ekledim
int main() // Verimli Yol
{
     int n; // n say�s�n� tan�mlad�m, 
     scanf("%d",&n); // n e de�er ald�m
     printf("%.1f",((float)(n+1))/2); // 1 den n e kadar say�lar�n ortalamas� k�saca (n+1)/2 ile bulunur.
     getch(); // Program�n Kapanmadan �nce Beklemesi ��in Bir Fonksiyon.
}

int main() // �stenmeyen Yol �le
{
     int n,i,toplam=0; //de�i�kenleri tan�mlad�m
     scanf("%d",&n); //n e de�er ald�m
     for( i=1; i<=n; i++ ) // 1 den n e kadar d�nen d�ng�
     {
          toplam = toplam + i; // 1 den n e kadar say�lar�n her birini toplama ekliyoruz. ayn� zamanda toplam += i yaz�labilirdi.
     }
     printf("%.1f",(float)toplam/n); // 1 den n e kadar say�lar�n toplam�n� say� say�s�na yani n e b�l�p ekrana sonucu bast�r�yruz.
     getch(); // Program�n Kapanmadan �nce Beklemesi ��in Bir Fonksiyon.
}

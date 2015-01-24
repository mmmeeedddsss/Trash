#include<stdio.h> // Kütüphanemi Ekledim
int main() // Verimli Yol
{
     int n; // n sayýsýný tanýmladým, 
     scanf("%d",&n); // n e deðer aldým
     printf("%.1f",((float)(n+1))/2); // 1 den n e kadar sayýlarýn ortalamasý kýsaca (n+1)/2 ile bulunur.
     getch(); // Programýn Kapanmadan Önce Beklemesi Ýçin Bir Fonksiyon.
}

int main() // Ýstenmeyen Yol Ýle
{
     int n,i,toplam=0; //deðiþkenleri tanýmladým
     scanf("%d",&n); //n e deðer aldým
     for( i=1; i<=n; i++ ) // 1 den n e kadar dönen döngü
     {
          toplam = toplam + i; // 1 den n e kadar sayýlarýn her birini toplama ekliyoruz. ayný zamanda toplam += i yazýlabilirdi.
     }
     printf("%.1f",(float)toplam/n); // 1 den n e kadar sayýlarýn toplamýný sayý sayýsýna yani n e bölüp ekrana sonucu bastýrýyruz.
     getch(); // Programýn Kapanmadan Önce Beklemesi Ýçin Bir Fonksiyon.
}

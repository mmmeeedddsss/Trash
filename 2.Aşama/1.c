#include<stdio.h> // Kütüphanemi Ekledim
int main() // Ana Fonksiyon
{
     int a,b,c; // Sayýlarý Tamýnladým
     scanf("%d%d%d",&a,&b,&c); // Üç Sayýmýza Deðer Aldýk.
     printf("Toplamlari : %d\n",a+b+c); //a+b+c Deðerini Ekrana Bastýrdým
     printf("Carpimlari : %d\n",a*b*c); //a*b*c Deðerini Ekrana Bastýrdým
     printf("Ortalamalari : %d\n",(a+b+c)/3); // Sayýlarý Toplayýp Sayý Sayýsýna Bölerek Ortalamalarýný Buldum ve Bastýrdým.
     getch(); // Programýn Kapanmadan Önce Beklemesi Ýçin Bir Fonksiyon.
}

#include<stdio.h> // K�t�phanemi Ekledim
int main() // Ana Fonksiyon
{
     int a,b,c; // Say�lar� Tam�nlad�m
     scanf("%d%d%d",&a,&b,&c); // �� Say�m�za De�er Ald�k.
     printf("Toplamlari : %d\n",a+b+c); //a+b+c De�erini Ekrana Bast�rd�m
     printf("Carpimlari : %d\n",a*b*c); //a*b*c De�erini Ekrana Bast�rd�m
     printf("Ortalamalari : %d\n",(a+b+c)/3); // Say�lar� Toplay�p Say� Say�s�na B�lerek Ortalamalar�n� Buldum ve Bast�rd�m.
     getch(); // Program�n Kapanmadan �nce Beklemesi ��in Bir Fonksiyon.
}

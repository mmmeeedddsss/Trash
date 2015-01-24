#include<stdio.h> // Kütüphanemi Ekledim
struct urun{
     int fiyat;
     int no;   
};

int main()
{
     int n; // n i tanýmladým
     scanf("%d",&n); // n i aldým
     struct urun urunler[n]; // n tane ürün olduðundan n uzunluðunda bi dizi tanýmladým
     int i;
     for( i=0; i<n; i++ ) // deðerleri alýyorum
     {
          scanf("%d",&urunler[i].no);
          scanf("%d",&urunler[i].fiyat);
     }
     
     int toplamUcret = 0; //deðiþken tanýmlarý
     int istenenUrunNo,istenenMiktar; //deðiþken tanýmlarý
     int j; //deðiþken tanýmlarý
     for( i=0; i<n; i++ ) // n tane ürün için miktar bilgisi alýyorum
     {
          scanf("%d%d",&istenenUrunNo,&istenenMiktar); // ürün id , istenen miktar deðerlerini aldým
          for( j=0; j<n; j++ ) // aldýðým no deðeri hangi ürünün deðerine ait diye her ürünü aldýðým ürün no ile karþýlaþtýrýyorum
          {
               if( urunler[j].no == istenenUrunNo ) // eyer for ile dönen ürün no aldýðým no ya eþitse
               {
                    toplamUcret += ( urunler[j].fiyat * istenenMiktar );  // o ürünün fiyatý çarpý istenen miktarý ödemem gereken toplam ücrete ekliyorum
               }
          }
     }
     printf("%d\n",toplamUcret); // Toplam Ücteri Basýyorum
     getch(); // Programýn Durmasýný Saðlýyo.
         
}

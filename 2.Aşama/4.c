#include<stdio.h> // K�t�phanemi Ekledim
struct urun{
     int fiyat;
     int no;   
};

int main()
{
     int n; // n i tan�mlad�m
     scanf("%d",&n); // n i ald�m
     struct urun urunler[n]; // n tane �r�n oldu�undan n uzunlu�unda bi dizi tan�mlad�m
     int i;
     for( i=0; i<n; i++ ) // de�erleri al�yorum
     {
          scanf("%d",&urunler[i].no);
          scanf("%d",&urunler[i].fiyat);
     }
     
     int toplamUcret = 0; //de�i�ken tan�mlar�
     int istenenUrunNo,istenenMiktar; //de�i�ken tan�mlar�
     int j; //de�i�ken tan�mlar�
     for( i=0; i<n; i++ ) // n tane �r�n i�in miktar bilgisi al�yorum
     {
          scanf("%d%d",&istenenUrunNo,&istenenMiktar); // �r�n id , istenen miktar de�erlerini ald�m
          for( j=0; j<n; j++ ) // ald���m no de�eri hangi �r�n�n de�erine ait diye her �r�n� ald���m �r�n no ile kar��la�t�r�yorum
          {
               if( urunler[j].no == istenenUrunNo ) // eyer for ile d�nen �r�n no ald���m no ya e�itse
               {
                    toplamUcret += ( urunler[j].fiyat * istenenMiktar );  // o �r�n�n fiyat� �arp� istenen miktar� �demem gereken toplam �crete ekliyorum
               }
          }
     }
     printf("%d\n",toplamUcret); // Toplam �cteri Bas�yorum
     getch(); // Program�n Durmas�n� Sa�l�yo.
         
}

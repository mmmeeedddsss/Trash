#include <stdio.h>
#include <conio.h>
#include <math.h>

int kontrol(int sayi,int temp)
{
    int i,j,array1[4],array2[4];        
    int sayac1=0;       // + sayýsýný tutacak deðiþken
    int sayac2=0;       // eksi sayýsýný tutacak deðiþken
    for(i=0;i<4;i++)        //bu döngüde asýl sayý ve deðiþken sayýnýn karakterleri arraylara atýlýr
    {
        array1[i] = sayi%10;        
        array2[i] = temp%10;
        sayi/=10;
        temp/=10;
    }
    for(i=0;i<4;i++)        
    {
        for(j=0;j<4;j++)
        {
            if(array1[i] == array2[j])      //karakterin eþleþip eþleþmediði kontrol ediliyor
            {
                if(i==j)                    //eðer i ve j eþitse eþleþen karakterler ayný yerdedir
                    sayac1++;
                else                        //deðilse farklý yerdedir
                    sayac2++;
            }
        }
    }
    if(sayac1 == 4)
    {
        printf("Tebrikler!\n");             //eðer 4 artý basýlacaksa sayý bulunmuþ, oyun bitmiþtir
        return 1;                           
    }
    else
    {
    for(i=0;i<sayac1;i++)
        printf("+");                        //artý ve eksi basýlan kýsým
    for(i=0;i<sayac2;i++)
        printf("-");
    printf("\n");
    }
    return 0;
}
int main()
{
    int sayi,temp,i,ex;                      //deðiþkenler tanýmlanýr
    while(!(sayi<=9999)  && !(sayi>=1000))  //4 basamaklý rastgele bir sayý üretilir
        sayi = rand()%10000;
    printf("Mastermind oyununa hosgeldiniz\n");
    a:
    printf("Bir sayi giriniz\n");
    scanf("%d",&temp);
    ex = kontrol(sayi,temp); 
    if(ex != 1)
    {
          goto a;
    }
getche();
}

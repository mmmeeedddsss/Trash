#include <stdio.h>
#include <conio.h>
#include <math.h>

int kontrol(int sayi,int temp)
{
    int i,j,array1[4],array2[4];        
    int sayac1=0;       // + say�s�n� tutacak de�i�ken
    int sayac2=0;       // eksi say�s�n� tutacak de�i�ken
    for(i=0;i<4;i++)        //bu d�ng�de as�l say� ve de�i�ken say�n�n karakterleri arraylara at�l�r
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
            if(array1[i] == array2[j])      //karakterin e�le�ip e�le�medi�i kontrol ediliyor
            {
                if(i==j)                    //e�er i ve j e�itse e�le�en karakterler ayn� yerdedir
                    sayac1++;
                else                        //de�ilse farkl� yerdedir
                    sayac2++;
            }
        }
    }
    if(sayac1 == 4)
    {
        printf("Tebrikler!\n");             //e�er 4 art� bas�lacaksa say� bulunmu�, oyun bitmi�tir
        return 1;                           
    }
    else
    {
    for(i=0;i<sayac1;i++)
        printf("+");                        //art� ve eksi bas�lan k�s�m
    for(i=0;i<sayac2;i++)
        printf("-");
    printf("\n");
    }
    return 0;
}
int main()
{
    int sayi,temp,i,ex;                      //de�i�kenler tan�mlan�r
    while(!(sayi<=9999)  && !(sayi>=1000))  //4 basamakl� rastgele bir say� �retilir
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

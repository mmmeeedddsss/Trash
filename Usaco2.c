#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<denemeler.h>
struct gift
    {
       int mevcutpara;
       int id;
    };
int main ( )
{
    
    system("cls");
    int i,j,a,b,u,nekadarvercek,kackisiye;
    int kime,isim;
    printf("Kac Kisi Hakkinda Bilgi Gircen??\n");
    scanf("%d",&b);
    i=b;
    struct gift kisiler[b];  // --->  kisiler tanimlandi..
    b--;
    printf("Kisiler icin ID Giriniz(Numara..)\n");
    for(;b>-1;b--){         // isimler alindi...
                   scanf("%d",&kisiler[b].id);
                   kisiler[b].mevcutpara=0;
                   }
    for(b=0;b<i;b++){
                     system("cls");
                     printf("Sirayla : \n-  Kim? ,\n-  Kac Lirayi? ,\n-  Kac Kisiye Bolusturecek? ,\n-  Kimlere Vercek?\nSeklinde Girdi Veriniz..\n");
                     scanf("%d%d%d",&isim,&nekadarvercek,&kackisiye);
                     if(kackisiye==0||nekadarvercek==0){
                                                        goto zzz;
                                                        }
                     for(j=0;j<kackisiye;j++){
                                              scanf("%d",&kime);
                     for(j=0;j<(i+1);j++){
                                          if(kime==kisiler[j].id){
                                                                  kisiler[j].mevcutpara+=(nekadarvercek/kackisiye);
                                                                  break;
                                                                  }
                                          }
                     }
                     for(j=0;j<(i+1);j++){
                                          if(isim==kisiler[j].id){
                                                                  kisiler[j].mevcutpara-=nekadarvercek;
                                                                  break;
                                          }
                     }
                     zzz:
                     continue;
    }
    for(j=0;j<i;j++){
                     printf("%d ID ye Sahip Kisinin Son Parasi --> %d\n",kisiler[j].id,kisiler[j].mevcutpara);
                     }                                                      
system("pause");
}










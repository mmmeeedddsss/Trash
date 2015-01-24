#include<stdio.h>
int main ( void )

{
    int i,j,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0,m=0,gecici,toplam=0;
    
    printf("1 Den Baslayarak Verdiin Sayiya Kadar\n"
    " Olan Sayilarin Rekamlari Toplamini Toplayan\n"
    "Program(Guzel Konu Kadirden :D ! :D)(Vercein Sayi 999 dan Buuk Olamas ...)\n\n\n\n\n");
    scanf("%d",&j);
    if(j<1){
         printf("Adam Gibi Sayi Ver .. \n"); goto mal; }
    for(i=1;i<j;i++){
                      
          gecici=i;
          a=gecici%10;
          gecici/=10;
          
          if(gecici!=0){
          b=gecici%10;
          gecici/=10;
          }
          else{
          b=0; 
          }
          if(gecici!=0){
          c=gecici%10;
          gecici/=10;
          }
          else{
          c=0; 
          }
          if(gecici!=0){
          d=gecici%10;
          gecici/=10;
          }
          else{
          d=0;
           }
          if(gecici!=0){
          e=gecici%10;
          gecici/=10;
          }
          else {
          e=0; 
          }
          if(gecici!=0){
          f=gecici%10;
          gecici/=10;
          }
          else{
          f=0; }
          if(gecici!=0){
          g=gecici%10;
          gecici/=10;
          }
          else{
          g=0; 
          }
          if(gecici!=0){
          h=gecici%10;
          gecici/=10;
          }
          else{
          h=0; 
          }
          if(gecici!=0){
          k=gecici%10;
          gecici/=10;
          }
          else{
          k=0;
           }
          if(gecici!=0){
          l=gecici%10;
          gecici/=10;
          }
          else{
          l=0; 
          }
          if(gecici!=0){
          m=gecici%10;
          gecici/=10;
          }
          else{
          m=0;
          }
          toplam+=a;
          toplam+=b;
          toplam+=c;
          toplam+=d;
          toplam+=e;
          toplam+=f;
          toplam+=g;
          toplam+=h;
          toplam+=k;
          toplam+=l;
          toplam+=m;
          }
          printf("Sonuc --> %d \n",toplam);
          mal:
          getch ( );
}          

#include<conio.h>
int main( void )
{
    float ortalama,sayi1,sayi2,toplam,fark,carpim,bolum;
    char devam_mi,devam,zaa;
    int f1,f2,z,i,v;
    do
    {
 //-------------------------------------------------------------------         
    printf("Islem Yapilacak Sayilari Yaz >by Mert< \n");
    scanf("%f %f",&sayi1,&sayi2);
    toplam = ( sayi1 + sayi2 );
    fark = ( sayi1 - sayi2 );
    carpim = ( sayi1 * sayi2 );
    ortalama =(float) toplam / 2;
    f1 = 1;
    f2 = 1;
 //-------------------------------------------------------------------   
    printf
     ("Verdigin Sayilar --> %.2f ve %.2f ...\n"
     "=====================================================\n"
     "Toplamlari --> %.2f \n"
     "=====================================================\n"
     "Farklari --> %.2f \n"
     "=====================================================\n"
     "Carpimlari --> %.2f \n"
     "=====================================================\n"
     ,sayi1,sayi2,toplam,fark,carpim);
 //-------------------------------------------------------------------        
     if( sayi1 == 0 ) {
     printf("Bolumleri --> 0\n");
 
     goto zaa;
     }
     if( sayi2 == 0 ) {
     printf("Bolene 0 Degerini Verirsen Cevap Tanimsiz Olur ...\n");
     
     goto zaa;
     }
     else {
     bolum = ((float) sayi1 / sayi2 );
     printf("Bolumleri --> %.2f \n",bolum);
     
     }
     zaa:
     
 //-------------------------------------------------------------------       
     printf("=====================================================\n"
     "Ortalamasi Ise --> %.2f \n",ortalama);
    printf("=====================================================\n");
 //-------------------------------------------------------------------   

    
    if( sayi1 > 10 ) {
        printf("Hata: 1. Sayinin Faktoriyelin Sonucu "
        "Cok Buyuk Cikiyor !.\n"); 
        
        goto devam1;
        }
        
    if( sayi1 > 0) { 
        v=sayi1;
    for( v = v ; v > 0 ; v--)
     
         f1 *= v;
         
         printf("1. Sayinin Faktoriyeli --> %d\n",f1);
         
         }
         else
         printf("Faktoriyeli Alinan Sayi 0 veya"
         " 0 dan Az Olamaz...\n");
         
         
         devam1:
             
 //------------------------------------------------------------------- 
 printf("=====================================================\n");           
               if( sayi2 > 10 ) {
        printf("Hata:2. Sayinin Faktoriyelin Sonucu"
        " Cok Buyuk Cikiyor !.\n"); 
        
        goto devam2;
        }
        
    if( sayi2 > 0) { 
        z=sayi2;
    for( z = z ; z > 0 ; z--)
    
         f2 *= z;
         
         printf("2. Sayinin Faktoriyeli --> %d\n",f2);
         
         }
         else
         printf("Faktoriyeli Alinan Sayi 0 veya"
         " 0 dan Az Olamaz...\n");
         
         devam2:
                
printf("=====================================================\n");
//-------------------------------------------------------------------   

    if( sayi1 > sayi2 ){
    printf("1. Girilen Sayi > 2. Girilen Sayi\n");
    goto a;
}
    if( sayi1 < sayi2 ){
    printf("1. Girilen Sayi < 2. Girilen Sayi\n");
    goto a;
}

    if( sayi1 == sayi2 ){
    printf("2 Sayi Esittir.\n");
    goto a;
}
    else
    printf("Bilinmeyen Bir Hata Olustu\n");
    
    a:
                       
 //------------------------------------------------------------------- 
    
    printf("-----------------------------------------------------\n"
    "-----------------------------------------------------\n"
    "---------------------->Mert<-------------------------\n"
    "-----------------------------------------------------\n"
    "-----------------------------------------------------\n");
    	printf("Tekrar Denemek Ister Misin???\n"
        "Eger Istersen (E) Istemessen (N) Tusuna Bas ...");
//-------------------------------------------------------------------       	
		do {
			scanf("%c",&devam_mi);  
	   
//-------------------------------------------------------------------  
	   
		}while( devam_mi == '\n' );  
		
//-------------------------------------------------------------------
        
                      for( i=0 ; i < 25 ; i++ ){
              printf("\n");
              }	
//-------------------------------------------------------------------

	} while( devam_mi == 'E' || devam_mi == 'e' );

}

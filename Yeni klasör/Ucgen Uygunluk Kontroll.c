#include<stdio.h>
int main( void )
{
	int k1,k2,k3;
	
	printf("Ucgen Kuralina Uygunlugu Kontrol Icin 3 Sayi Gir!>byMert<\n");
	scanf("%d%d%d",&k1,&k2,&k3);
	
	int a=k1-k2;
	if(a < 0)( a = -a ) ;
	int b=k2-k3;
	if(b < 0)( b = -b ) ;
	int c=k1-k3;
	if(c < 0)( c = -c ) ;
	
	if( k1 + k2 > k3 || k1 + k2 == k3){
	   
	    if(k1 + k3 > k2 || k1 + k3 == k2){
              
              if (k2 + k3 > k1 || k2 + k3 == k1){
                     
                    if( a < k3 || a == k3){
              
                          if ( b < k1 || b == k1){
                    
                               if(c < k2 || c == k2){
                         
                                printf("Ucgen Kurallara Uygun Olarak Cizilebilir...\n");
                                goto devam2;
                                
                            }else
                            goto devam;
                         }else
                         goto devam;
                    }else
                   goto devam;
              }else
              goto devam;
          }else
          goto devam;
     }else
            devam:
                  printf("Bu Ucgen Kurallara Gore Cizilemez...\n");
                  devam2:
     getch ( );
}
     
	       
	

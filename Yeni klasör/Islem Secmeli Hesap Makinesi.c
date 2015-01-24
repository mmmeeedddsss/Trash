#include<stdio.h>
int main( void )

{
     
    int a,b,z,f2,j;
    char i,devam2;
    int cevap = 1;
   
    
    printf(":D Islemi Yaz\n");
    scanf("%d",&a);
    scanf("%c",&i);
    f2 = 1;
    f2=1;
//--------------------------------------------------------------------   
    if ( a == 0 )
        printf("Sayinin Faktoryeli --> 1 \n");
        
        else
    
    if ( i == '!') {
         
         if( a > 10 ) {
        printf("Hata:2. Sayinin Faktoriyelin Sonucu"
        " Cok Buyuk Cikiyor !.\n"); 
        
        goto devam2;
        }
        
    if( a > 0) { 
        z=a;
    for( z = z ; z > 0 ; z--)
    
         f2 *= z;
         
         printf("Sayinin Faktoriyeli --> %d\n",f2);
         goto devam2 ;
         }
         else
         printf("Faktoriyeli Alinan Sayi"
         " 0 dan Az Olamaz...\n");
         
         goto devam2 ;
         }
         
    scanf("%d",&b); 
    
//--------------------------------------------------------------------
    
    switch(i)
    {
           case '+' :
                printf("%d %c %d = %d\n",a,i,b, a + b); break ;
           case '-' :
                printf("%d %c %d = %d\n",a,i,b, a - b); break ;
           case '*' :
                printf("%d %c %d = %d\n",a,i,b, a * b); break ;
           case '/' :
                printf("%d %c %d = %d\n",a,i,b, a / b); break ;
           case '%' :
                printf("%d %c %d = %d\n",a,i,b, a % b); break ;
           case '^' :
                for( j=0 ; j < b ; j++ ){
                     
                     cevap = cevap * a;  
                     }
                printf("%d %c %d = %d\n",a,i,b,cevap);
                
                break ;
                 
                default :
                        printf("Hata !\n");
                }
                
                devam2 :
                       
           getch ( );
}

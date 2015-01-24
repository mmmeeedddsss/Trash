#include<stdio.h>
int main ( void )

{
    int a,b,i;
    int cevap = 1;
    
    printf("Sayilari Gir\n");
    scanf("%d%d",&a,&b);
    
    
             for( i=0 ; i < b ; i++ ){
                  
                  
              cevap = cevap * a;
              
               
           }
           
           printf("Cevap --> %d \n",cevap);

      getch ( );
}

#include<stdio.h>
int main ( void )

{
    
    int i,j,k,l,g,s;
    
        printf("Karenin Kenar Uzunluunu Giriniz...\n");
        scanf("%d",&g);
        
        g=g-2; // bunu s�rf K�z Diye Yapt�m :D :D
    for(i=0;i<(g+2);i++){ // Heyt Beee 2 Forla Yapt�m , Ustama Sevgilerle xD
                     printf("*  ");
                     
                     for(j=0;j<g;j++){
                                       
                     if(i==0 || i==(g+1)){
                                      printf("*  ");
                                      }
                     else {
                                      printf("   ");
                                      }
                     if(j==(g-1)){
                                      printf("*  ");
                                      }
                                      }
                                      printf("\n\n");
                     }

getch ( );
}

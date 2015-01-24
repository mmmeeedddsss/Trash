#include<stdio.h>
int main ( void )

{
      int a,i,j;
      char u;
      
      do
      {
      
      printf("Kac Satirli Ucgen Yapmak Istersin??\n");
      scanf("%d",&a);
      printf("Al Sana Ucgen  :D\n");
      
      
      for( i=0 ; i < a ; i++){
           
           for( j=0 ; j < i+1 ; j++) {
           
           printf("* ");
           }
      printf("\n");
      }
      
      printf("Tekrar Denemek Ister Misin??"
      "(Istersen E + Enter Bas ! xD)\n");
      
      do {
          scanf("%c",&u);
              } while( u == '\n');
              
              
              for( i=0 ; i < 25 ; i++ ){
              printf("\n");
              }
              
              } while( u == 'E' || u == 'e');
              
      
}     
      

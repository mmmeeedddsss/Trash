#include<stdio.h>
int main( void )
{
	int i,j,k,l,m,n;
	
	getch ( );
	    for(i=0;i<10;i++){
                          printf(" ");
                          for(k=0;k<10;k++){
                                         if(k==0||k==9||(i/2)==k||(i/2)+k==9){
                                               printf("* ");
                                               }
                                               else{
                                               printf("  ");
                                               }
                                               }
                                               printf("\n");
                                               }
                                               printf("\n\n\n\n");
                                               getch ( );
       for(i=0;i<10;i++){
                         printf(" ");
                         for(k=0;k<10;k++){
                                           if(k==0||i==0||i==5||i==9){
                                           printf("* ");
                                           }
                                           else{
                                                printf("  ");
                                                }
                                                }
                                                printf("\n");
                                                }
                                                printf("\n\n\n\n");
                                                getch( );
       for(i=0;i<10;i++){
                         printf(" ");
                         for(k=0;k<10;k++){
                                           if((i==k&&i>5)||k==0||i==0||i==5||(k==9&&i<6)){
                                           printf("* ");
                                           }
                                           else{
                                                printf("  ");
                                                }
                                                }
                                                printf("\n");
                                                }
                                                printf("\n\n\n\n");
                                                getch ( );
       for(i=0;i<10;i++){
                         printf(" ");
                         for(k=0;k<10;k++){
                                           if(k==4||i==0){
                                                          printf("* ");
                                                          }
                                           else{
                                                printf("  ");
                                                }
                                                }
                                                printf("\n");
                                                }
                                                printf("\n\n\n\n");
                                                getch ( );
       for(j=0;j<3;j++){
       
        for(i=0;i<10;i++){
                         printf(" ");
                         for(k=0;k<10;k++){
                                           if(k==0||k==9||i==6||i==0){
                                                          printf("* ");
                                                          }
                                           else{
                                                printf("  ");
                                                }
                                                }
                                                printf("\n");
                                                }
                                                printf("\n\n\n\n");
                                                getch ( );
                                                }
                                                
        for(i=0;i<10;i++){
                         printf(" ");
                         for(k=0;k<10;k++){
                                           if(k==0||i==9){
                                                          printf("* ");
                                                          }
                                           else{
                                                printf("  ");
                                                }
                                                }
                                                printf("\n");
                                                }
       getch ( );
       }
                                               
      
                                               

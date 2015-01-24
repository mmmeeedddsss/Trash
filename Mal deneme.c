#include<stdio.h>
int main( void )
{
	int i,j,s,a,b,z,m,u,f,v,p;
	
	for(i=0;i<6;i++){
                     printf(" ");
                     for(j=12;j>i;j--){
                                      printf(" ");
                                      }
                     for(s=0;s<i;s++){
                                      printf("* ");
                                      }
                     printf("\n");
                     }
   for(a=0;a<4;a++){
                    printf(" ");
                    for(b=0;b<a;b++){
                                     printf(" ");
                                     }
                    for(z=12;z>a;z--){
                                     printf("* ");
                                     }
                    printf("\n");
                    }
                    
  	for(i=0;i<5;i++){
                     printf(" ");
                     for(j=4;j>i;j--){
                                      printf(" ");
                                      }
                     for(s=0;s<8;s++){
                                      printf("* ");
                                      }
                     for(p=0;p<i;p++){
                                      printf("* ");
                                      }
                     printf("\n");
                     }
  	for(i=0;i<6;i++){
                     printf(" ");
                     for(j=0;j<7;j++){
                                      printf(" ");
                                      }
                     for(p=0;p<i;p++){
                                      printf(" ");
                                      }
                     for(s=5;s>i;s--){
                                      printf("* ");
                                      }
                     printf("\n");
                     }
 getch ( );
 
}

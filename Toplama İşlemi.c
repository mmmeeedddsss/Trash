#include<stdio.h>
int main( void )
{
	int i,j,s,a,b,z,m;
	
	printf("Kac Birimlik Baklava(!) Istersin??");
	scanf("%d",&m);
	
	for(i=0;i<m;i++){
                     printf(" ");
                     for(j=m;j>i;j--){
                                      printf(" ");
                                      }
                     for(s=0;s<i;s++){
                                      printf("* ");
                                      }
                     printf("\n");
                     }
   for(a=0;a<m;a++){
                    printf(" ");
                    for(b=0;b<a;b++){
                                     printf(" ");
                                     }
                    for(z=m;z>a;z--){
                                     printf("* ");
                                     }
                    printf("\n");
                    }
 getch ( );
 
}

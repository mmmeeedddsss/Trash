#include<stdio.h>
int fkadir(unsigned long long int x,int y)
{
           int s[999],toplam,j,i,z=x;
           if(x/10==0){
                       goto kadir;
                       }
           for(j=0;x>0;j++){
                            s[j]=x%10;
                            x/=10;
                            }
							toplam=0;
           for(i=0;i<j;i++){
			   toplam+=s[i];
                                 toplam*=10;
                            }
                            toplam/=10;
           if(toplam==z&&z>i){
                         kadir:
                         printf("%d\n",z);
                         }
}     
int main ( void )
{
    
    
    int s[320000],a[9999],b[9999],c[9999],d[9999],e[9999];
    unsigned long long int i,j,k=1,l,z,asal=1,m,kadir;
    printf("1. Sayiyi Gir..\n");
    scanf("%d",&i);
    printf("2. Sayiyi Gir..\n");
    scanf("%d",&j);
    s[0]=2;
    for(l=3;l<j;l+=2){
                      if((l*l)%12!=1){
                                 asal=0;
                                 goto psfe;  
                                 }   
                  for(z=3;z<l/2;z++){
                                   if(l%z==0){
                                              asal=0;
                                              break;
                                              }
                                   }
                  if(asal==1){
                              s[k]=l;
                              k++;
                              
                              }
                  else{
                       psfe:
                       asal=1;
                       }
    }
    for(kadir=0;kadir<k;kadir++){
                                 fkadir(s[kadir],i);
                                 }
 getch ( );
}

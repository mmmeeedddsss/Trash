#include<stdio.h>
int sayiya_cevir(char x)
{
       int deer=0,d[7],*p,i;
       enum c[24]={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,y,z};
       
       
       for(i=0;i<30;i++){
            if(c[i]==x)
            deer=i;
            }
       p = &deer;
       
       return 1;
       }
int main ( )

{
    char a[7],b[7],c[7],k;
    unsigned long long int i,*p,toplam1=0,toplam2=0,deer;
    printf("Meraba ! :D Arasinda Bosluk Birakarak 2 Kelime"
    " Yaz Ve Bu Kelimelerin Harf Sayisi 6 Yi Gecmesin ..\n");
    
    scanf("%s",a);
    scanf("%s",b);
    
    for(i=0;i<6;i++){
       sayiya_cevir(a[i]);
       toplam1+=p;
       }
    for(i=0;i<6;i++){
       sayiya_cevir(b[i]);
       toplam2+=p;
       }
      if((toplam1%47)==(toplam2%47)){
                           printf("Go !\n");
      else
                           printf("Stay !\n");
    getch ( );
}

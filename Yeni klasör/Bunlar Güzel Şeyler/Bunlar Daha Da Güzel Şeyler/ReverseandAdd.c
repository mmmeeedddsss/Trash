#include<stdio.h>
unsigned long long int cevir(unsigned long long int sayi)
{   
       unsigned long long int temp=0;
       while(sayi>0)
       {
                   temp+=sayi%10;
                   sayi/=10;
                   temp*=10;
       }
       return temp/10;
}

unsigned long long int pal_mi(unsigned long long int sayi)
{
       if(cevir(sayi)==sayi) return 1;
       return 0;
}

unsigned long long int sayinin_tersi_ile_sayiyi_topla(unsigned long long int sayi)
{
    return sayi+cevir(sayi);
}
    
int main()
{
    
    unsigned long long int x,u;
    scanf("%llu",&x);
    for(u=0;;u++)
    {
     x=sayinin_tersi_ile_sayiyi_topla(x);
     if(pal_mi(x)) break;
    }
    printf("%llu  %llu",++u,x);
    getch();
}

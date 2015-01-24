#include<stdio.h>
int min(int x,int y)
{
     return x>y?x:y;    
}
int hesapla(unsigned long long int x,int sayac)
{
     if(x==1) return sayac;
     if(x%2==1) return hesapla((3*x)-1,++sayac);
     else return hesapla(x/2,++sayac);
}
int main()
{
     int x,y;
     scanf("%d%d",&x,&y);
     printf("%d",min(hesapla(x,0),hesapla(y,0)));
     getch();    
}

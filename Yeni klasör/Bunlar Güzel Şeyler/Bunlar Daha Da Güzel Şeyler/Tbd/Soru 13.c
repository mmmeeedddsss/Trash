/*
     Ubuntuda Gcc Ýle Derlenebilmesi Ýçin Lütfen -lm yi de Ekleyerek Derleyiniz ..
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct direk{
    int x,y,h;  
};

struct direk *direkler;

int min(int x,int y)
{
    return x>y?y:x;   
}
int max(int x,int y)
{
    return x>y?x:y;   
}
int mutlak(int x)
{
     return x>0?x:(-x);    
}
int Hazirla(int i,int j,char c)
{
    if(c=='x')
        return (mutlak(direkler[j].x-direkler[i].x));
    else if(c=='h') return(mutlak(direkler[j].h-direkler[i].h));
    else
        return (mutlak(direkler[j].y-direkler[i].y));
}
int AralariBosMu(int x,int y,int n)
{
    int i;
    int kisa=(direkler[x].h>direkler[y].h)?y:x;
    int uzun=(direkler[x].h>direkler[y].h)?x:y;
    for(i=0;i<n;i++)
    {
        if(x==i||y==i)
            continue;
        if((Hazirla(x,y,'x')/(float)Hazirla(x,y,'y'))!=(Hazirla(x,i,'x')/(float)Hazirla(x,i,'y')))
            continue;
        if((max(direkler[x].x,direkler[y].x)<direkler[i].x)||(min(direkler[x].x,direkler[y].x)>direkler[i].x))
            continue;
        if((max(direkler[x].y,direkler[y].y)<direkler[i].y)||(min(direkler[x].y,direkler[y].y)>direkler[i].y))
            continue;
        if(kisa>direkler[i].h)
            continue;
        if(uzun<direkler[i].h)
            return 0;
    }
    return 1;
}
float MesafeHesapla(int i,int j)
{
     return sqrt(Hazirla(i,j,'x')*Hazirla(i,j,'x')+Hazirla(i,j,'y')*Hazirla(i,j,'y')+Hazirla(i,j,'h')*Hazirla(i,j,'h'));
}
int main()
{
    int n;
    scanf("%d",&n);
    direkler=(struct direk*)malloc(sizeof(struct direk)*n);
    int i,j;
    for(i=0;i<n;i++)
    {
           scanf("%d%d%d",&direkler[i].x,&direkler[i].y,&direkler[i].h);
    }
    float min=1000000;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(min>MesafeHesapla(i,j)&&AralariBosMu(i,j,n))
                min=MesafeHesapla(i,j);
    printf("\n%f\n",min);
}

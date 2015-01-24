#include <stdio.h>
#include<stdlib.h>
int palkelime(char s[])
{
    int i=0,j,pal=1;
    while(s[i]!='\0'){
        i++;
    }
    i--;
    for(j=0;j<i;j++){
        if(s[j]!=s[i]){
            pal=0;
            break;
        }
        i--;
    }
    if(pal==1){
        return 1;
    }
    else
        return 0;
}

int kare(int x)
{   
    return x*x;
}

int mutlak(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

void kareciz(int x)
{
    int i,j;
    for(i=0;i<x;i++){
        printf("\n");
        for(j=0;j<10;j++){
            printf("* ");
        }
    }
}

void ucgen(int x)
{
    int i,j;
    for(i=0;i<x;i++){
        printf("\n");
        for(j=0;j<i;j++){
            printf("* ");
        }
    }
}

void asal(int x)
{
    int i,j,s[99999],u=0;
    FILE *f1;
    f1=fopen("Asal.txt","w");
    printf("Bulunuan Sonuclar Asal.txt Icine Yazilacaktir...\n");
    printf("Hesaplaniyor..\n");
    for(i=3;i<x;i+=2){
        if((i*i)%12!=1){
            continue;
        }
        for(j=0;s[j]!='\0';j++){
            if(i%s[j]==0){
            goto zzz;
            }
        }
            s[u]=i;
            u++;
            fprintf(f1,"%d\n",i);
            zzz:
            continue;
    }
printf("Bitti ...\n");
getch();
}

void pal(int x){
    int i,j,u,s[900],gecici,toplam;
    FILE *f1;
    f1=fopen("Pal.txt","w");
    printf("Bulunuan Sonuclar Pal.txt Icine Yazilacaktir...\n");
    system("pause");
    printf("Hesaplanýyor\n");
    for(i=0;i<x;i++){
        gecici=i;
        u=0;
        while(gecici>0){
            s[u]=gecici%10;
            gecici/=10;
        }
        u--;
        toplam=0;
        while(u>-1){
            toplam+=s[u];
            toplam*=10;
        }
        if((toplam/10)==i){
            fprintf(f1,"%d\n",i);
        }
    }
    printf("Bitti ..\n");
}

int fktryl(int x)
{
    int sonuc=1;
    while(x>1){
        sonuc*=x;
        x--;
    }
    return sonuc;
}

int karekok(int x)
{
    int i;
    for(i=1;(i*i)<(x+1);i++){
        if(x==(i*i)){
            return i;
        }
    }
    return -1;
}

char characevir(int x)
{
    return (char)x;
}

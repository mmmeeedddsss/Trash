#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<denemeler.h>
#define sayi 1000000

int s[sayi];

void sayilariuret()
{
    unsigned long long int i,j;
    for(i=0;i<sayi;i++) { j=rand()%10000; s[i]=j;}
}

void diz ()
{
    unsigned long long int i,j,say,save;
    for(i=0;i<sayi;i++) 
    { 
        say=0; 
        
        for(j=0;j<sayi;j++)
        { 
            if(s[i]<s[j]) say++;  
        }
        save=s[say];
        s[say]=s[i];
        s[i]=save;
    }
    
}

void yazdir()
{
     FILE *f1;
     f1=fopen("Sirali Hali.txt","w");
     unsigned long long int i;
     for(i=0;i<sayi;i++) fprintf(f1,"%d\n",s[i]);
    
}
int main ( )
{
    int i,j;
    printf("sayilar uretiliyor..\n");
    sayilariuret();
    printf("Enter Basarak Sayilari Hesaplamaya Baslayiniz..\n");
    getch();
    printf("Hesaplaniyor..\n");
    diz();
    printf("Tamamlandi..Simdi Dosyaya Yazilacak ..\n");
    yazdir();
    printf("Buda Tamam .. Dosya Hazir..\n");
system("pause");
}

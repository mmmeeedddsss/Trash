#include <stdio.h>
#include <stdlib.h>
int main()
{
    char sorucevabi[30],a,b='e',sahtecevaplar[45]="Mert,Sana Sorduum Soruyu Lutfen Cevapla..";
    int i,j,sayac,bilmiyokiii;
    while(b=='e')
    {
                 sayac=1;
                 bilmiyokiii=0;
    system("cls");
    printf("Gizli Soruyu Yaziniz..\n");
    a=getch();
    system("cls");
    if(a==';')
    {
        for(i=0;i<41;i++)
        {
            if(sayac==1)
            {
                sorucevabi[i]=getch();
                //system("cls");
            }
            if(sayac==0)
            {
                b=getch();
            }
            printf("%c",sahtecevaplar[i]);
            if(sorucevabi[i]==';')
            {
                sayac=0;
            }
        }
    }
    else
    {
        bilmiyokiii=1;
        printf("%c",a);
        while(a!='\n')
        {
            scanf("%c",&a);
        }
    }
    printf("\nSimdi Sorunu Yaz Bende Cevapliim :D(? isareti ile bitirmelisin..\n\n\n");
    
    while(a!='?')
    {
        scanf("%c",&a);
    }
    printf("\n");
    if(bilmiyokiii==1)
    {
        printf("Sen Mert Diilsin ! \n");
    }
    else
    {
        printf("Cevabin ---> ");
    for(i=0;sorucevabi[i]!=';';i++)
    {
        printf("%c",sorucevabi[i]);
    }
    }
    printf("\n\nTekrar Denemek Ister Misin??\n");
        scanf("\n%c",&b);
        
}
        getch();
    return 0;
}

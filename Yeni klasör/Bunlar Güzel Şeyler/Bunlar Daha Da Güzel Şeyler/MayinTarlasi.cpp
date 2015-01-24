#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include"MayinTarlasi.h"

using namespace std;

void introduction()
{
    cout<<"Mayin Tarlasina Hos Geldiniz.."<<endl<<"Oyunu Oynamak Icin;"<<endl<<"- w,s,a,d Yon,"<<endl;
    cout<<"- b Bayrak Koymak,"<<endl<<"- i Bulundugunuz Karenin Cevresinde Kac Mayin Oldugunu Ogrenmek Icin"<<endl<<endl;
    cout<<"Eger Oyunun Bittigini Dusunuyorsaniz t ile Kontroll Edeblirsiniz.."<<endl;
    cout<<endl<<"Devam Etmek Icin Bir Tusa Basiniz.."<<endl;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t>>By Mert<<";
    getch();
    system("cls");
}

int main()
{
    char a;
    introduction();
    Mayintarlasi x;
    while(1)
    {       
             a=getch();
             x.parcala(a);
    }
}

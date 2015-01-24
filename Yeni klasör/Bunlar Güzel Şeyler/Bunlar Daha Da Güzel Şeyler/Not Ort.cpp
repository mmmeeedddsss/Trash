#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int x,y,top_not=0,top_saat=0;
    cout<<"Ders Saatine ve Ders Notuna 0 Girene Kadar Notlari Alir Ve Size Ort. Soler.."<<endl<<endl;
    system("pause");
    system("cls");
    while(x!=0)
    {
                cout<<endl<<"\tOnce Ders Saati Sonra Ders Ort. Gir.."<<endl;
                cin>>x>>y;
                top_not+=x*y;
                top_saat+=x;
                system("cls");
    }   
    cout<<"Ortalaman --> "<<top_not/top_saat<<endl;
    getch();
}

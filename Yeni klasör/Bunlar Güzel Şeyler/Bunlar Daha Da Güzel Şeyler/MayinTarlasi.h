#include<iostream>
#include<windows.h>
#include<conio.h>
#define en 11
#define boy 11
#include<stdlib.h>

using namespace std;

class Mayintarlasi
{
      public:      
             Mayintarlasi()
             {             
                           srand(time(NULL));
                           imlecin_altinda_ne_var=' ';
                           imlecx=imlecy=5;    //((en-4*boy)*2)/(en-4*(boy/2));
                           tahtalari_bosalt(); 
                           cout<<"Kac Mayinla Oynamak Istersin?"<<endl; cin>>zorluk;
                           if(zorluk>(en-1)*boy) zorluk=15;
                           bayrak_sayisi=zorluk;
                           mayinlari_yerlestir();
                           tahta_yanlarini_mayinla_cevir();
                           system("color 8");
                           tahtayi_bastir();
             }
             void parcala(char m)
             {
                  switch(m)
                  {
                           case 'i': karsilastir(); imlecin_altinda_ne_var=tahta[imlecy][imlecx];/*tahta[imlecy][imlecx]=karsilastir()+'0'; imlecin_altinda_ne_var=karsilastir()+'0';  */ break;
                           case 'b': if(tahta[imlecy][imlecx]==-30+' '||imlecin_altinda_ne_var==-30+' ') cout<<"\a"; else if(bayrak_sayisi&&tahta[imlecy][imlecx]!=-30+' ') { tahta[imlecy][imlecx]=-30+' '; imlecin_altinda_ne_var=-30+' '; bayrak_sayisi--; } break;
                           case 't': adam_tamam_diyomus(); break;
                           //case'p': pause();
                           default: imleci_oynat(m);
                  }
                  tahtayi_bastir();
             }
             
      private:
             char tahta[boy][en];
             char mayinlar[boy][en];
             unsigned int bayrak_sayisi;
             unsigned short zorluk;
             int imlecx,imlecy;
             char imlecin_altinda_ne_var;
             
             void imleci_oynat(char x)
             {
                  tahta[imlecy][imlecx]=imlecin_altinda_ne_var;
                  
                  switch(x)
                  {
                  case'w': imlecy--; if(imlecy<0) imlecy=0; break;
                  case's': imlecy++; if(imlecy>(boy-1)) imlecy=(boy-1); break;
                  case'a': imlecx--; if(imlecx<0) imlecx=0; break;
                  case'd': imlecx++; if(imlecx>(en-2)) imlecx=(en-2); break;
                  default: cout<<"\a";
                  }
                  imlecin_altinda_ne_var=tahta[imlecy][imlecx];
                  tahta[imlecy][imlecx]='X';
             }
             
             void tahtalari_bosalt()
             {
                  short i,j;
                  for(i=0;i<boy;i++)
                  for(j=0;j<en;j++)
                  {
                                    mayinlar[i][j]=' ';
                                    tahta[i][j]=' ';
                  }
             }
             void mayinlari_yerlestir()
             {
                  int i,j;
                      for(;zorluk>0;zorluk--)
                      {
                           zzz:
                           i=rand()%boy;
                           j=rand()%en;
                           if(i>9||j>9) goto zzz;
                           if(mayinlar[i][j]=='*') goto zzz;
                           mayinlar[i][j]='*';
                      }
                  
             }
             void gameover()
             {
                  sontahta();
                  getch();
                  system("cls");
                  cout<< "\n\n\n\n\n\t\t\tBidahaki Sefere Ins. xD"<<endl;
                  getch();
                  exit(1);
              }
             
             
             int say(int y,int x)
             {
                              unsigned short i=0;
              
                                                   if(mayinlar[y+1][x]=='*') i++;
		                                           if(mayinlar[y][x+1]=='*') i++;
		                                           if(mayinlar[y-1][x]=='*') i++;
		                                           if(mayinlar[y][x-1]=='*') i++;
		                                           if(mayinlar[y+1][x+1]=='*') i++;
		                                           if(mayinlar[y-1][x-1]=='*') i++;
		                                           if(mayinlar[y+1][x-1]=='*') i++;
		                                           if(mayinlar[y-1][x+1]=='*') i++;
                             //if(!i) tahta[y][x]=' ';
                             tahta[y][x]=i+'0';
                             if(!i) adam_sifir_bulmus(y,x);
             }
             
             void adam_sifir_bulmus(int y,int x)
             {
                   if(tahta[y+1][x]==' '||tahta[y+1][x]=='X') say(y+1,x);
                   if(tahta[y][x+1]==' '||tahta[y][x+1]=='X') say(y,x+1);
                   if(tahta[y-1][x]==' '||tahta[y-1][x]=='X') say(y-1,x);
                   if(tahta[y][x-1]==' '||tahta[y][x-1]=='X') say(y,x-1);
                   if(tahta[y+1][x+1]==' '||tahta[y+1][x+1]=='X') say(y+1,x+1);
                   if(tahta[y-1][x-1]==' '||tahta[y-1][x-1]=='X') say(y-1,x-1);
                   if(tahta[y+1][x-1]==' '||tahta[y+1][x-1]=='X') say(y+1,x-1);
                   if(tahta[y-1][x+1]==' '||tahta[y-1][x+1]=='X') say(y-1,x+1);
             } 
             
             int karsilastir()
             {
                  if(imlecin_altinda_ne_var==-30+' ') bayrak_sayisi++;
                  if(mayinlar[imlecy][imlecx]=='*') gameover();
                  say(imlecy,imlecx);
             }
             
             void adam_tamam_diyomus()
             {
                  tahta[imlecy][imlecx]=imlecin_altinda_ne_var;
                  int i,j;
                  char isim[40];
                  for(i=0;i<boy;i++)
                  for(j=0;j<en;j++)
                  {
                                   if(mayinlar[i][j]=='*'&&tahta[i][j]!=-30+' ') gameover();
                  }
                  system("cls");
                  cout<< "\n\n\n\n\t\t\tAferin ! xD Kazandin.."<<endl;
                  getch();
                  system("cls");
                  cout<<"Lutfen Adinizi Giriniz.."<<endl;
                  cin>>isim;
                  cout<<"Sevindin Demi :D Ama Iste Urasmak Istemedim Yazmadim High Score lari xD";
                  getch();
                  exit(1);
             }
             
             void sontahta()
             {
                  int i,j;
                  for(i=0;i<boy;i++)
                  for(j=0;j<en;j++)
                  {
                                   if(mayinlar[i][j]=='*'&&tahta[i][j]!= -30+' ') tahta[i][j]='*';
                                   if(tahta[i][j]==-30+' '&&mayinlar[i][j]!='*') tahta[i][j]='Y';
                  }
                  tahtayi_bastir();
             }
             
             void tahta_yanlarini_mayinla_cevir()
             {
             unsigned int i;
                  for(i=0;i<boy;i++)
                  {
                          tahta[i][10]='a';
                          mayinlar[i][10]='a';
                  }
                  for(i=0;i<en;i++)
                  {
                          tahta[10][i]='a';
                          mayinlar[10][i]='a';
                  }
             }
             
             void tahtayi_bastir()
             {
                  int i,j;
                  system("cls");
                  cout<<"\n\t\tKalan Bayrak Sayisi --> "<<bayrak_sayisi<<endl<<endl;
                  cout<<"\t-----------------------------------------"<<endl;
                  for(i=0;i<10;i++)
                  {
                                    
cout<<"\t| "<<tahta[i][0]<<" | "<<tahta[i][1]<<" | "<<tahta[i][2]<<" | "<<tahta[i][3]<<" | "<<tahta[i][4]<<" | ";
cout<<tahta[i][5]<<" | "<<tahta[i][6]<<" | "<<tahta[i][7]<<" | "<<tahta[i][8]<<" | "<<tahta[i][9]<<" ";

                  cout<<"|"<<endl<<"\t-----------------------------------------"<<endl;
                  }
             }
};

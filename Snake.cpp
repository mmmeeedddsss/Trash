#include <conio.h>
#include <iostream>
#include "Snake_cls.h"
#include <windows.h>

using namespace std;

     void Snake::first_position()
     {
          srand(time(NULL));
          Snake_xy[1][0]=5;
          Snake_xy[1][1]=7;
          Snake_xy[2][0]=5;
          Snake_xy[2][1]=8;
          
     }
     
     void Snake::feed()
     {
          int x,y;
          x=rand()%75;
          y=rand()%23;
          feedx=x;
          feedy=y;
          s[feedx][feedy]='X';
     }
     
     void Snake::clean()
     {
          int i,j;
          for(i=0;i<80;i++)
               for(j=0;j<25;j++)
               {
                    s[i][j]=' ';    
               }
     }
     void Snake::New_s()
     {
          int i,j;
          for(i=0;i<120;i++)
               for(j=0;j<2;j++)
                    Snake_xy[i][j]=0;    
     }
     void Snake::printf2()
     {
          system("cls");
          int i,j;
          for(i=0;i<24;i++)
          {
               for(j=0;j<79;j++)
               {
                    cout<<s[j][i];
               }
               cout<<endl;
          }
     }
     
     void Snake::gameover()
     {
          printf2();
          system("cls");
          cout<< "\n\n\n\n\n\n\t\t\t\tYilan Bok Oldu .."<<endl;
          getch();
          exit(1);
     }
     
     void Snake::move()
     {
          if(kbhit()) dir=getch();
          int i,j;
          switch(dir)
          {
               case's': heady++; if(s[headx][heady]=='*') return gameover(); s[headx][heady]='*'; break;
               case'w': heady--; if(s[headx][heady]=='*') return gameover(); s[headx][heady]='*'; break;
               case'd': headx++; if(s[headx][heady]=='*') return gameover(); s[headx][heady]='*'; break;
               case'a': headx--; if(s[headx][heady]=='*') return gameover(); s[headx][heady]='*'; break;
               default: cout<<"\a";
          }
          
          if(headx==feedx&&heady==feedy){ length++; cout<<"\a"; feed(); s[headx][heady]='*'; } 
          
          /*for(i=0;i<length;i++)
               if(headx==Snake_xy[i][0]&&heady==Snake_xy[i][1])
                              gameover();
                              */
          s[Snake_xy[1][0]][Snake_xy[1][1]]=' ';
                  
           //New_s();
               
          for(i=1;i<length;i++)
               for(j=0;j<2;j++)
               {
                    s[Snake_xy[i][0]][Snake_xy[i-1][1]]='*';
               }
          
          printf2();
     }
     
int main()
{
     Snake x;
     while(1)
     {
          x.move();
          //Sleep(50);
     }    
}

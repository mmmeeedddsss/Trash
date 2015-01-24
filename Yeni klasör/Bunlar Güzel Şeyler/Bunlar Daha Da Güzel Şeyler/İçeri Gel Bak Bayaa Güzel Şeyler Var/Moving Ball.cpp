#include<windows.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

void gotoxy (int x, int y)
{
    COORD coord; // coordinates
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates
}

struct top{
     int x,y;
     char dir1,dir2;   
};

struct top *top;

void top_oynat()
{
     //
     //  Deletes Last Ball
     //
     gotoxy(top->x,top->y);
          cout<<" ";
     //
     //  Updates the Ball's Coords
     //
     if(top->dir1 == 'w' )
     {
          if(top->dir2 == 'a' )
          {
               top->x--;
               top->y--;
          }
          else if(top->dir2 == '0')
          {
               top->y--;    
          }
          else
          {
               top->x++;
               top->y--;
          }    
     }
     else
     {
          if(top->dir2 == 'a' )
          {
               top->x--;
               top->y++;
          }
          else if(top->dir2 == '0')
          {
               top->y++;    
          }
          else
          {
               top->x++;
               top->y++;
          }
     }
     //
     //  Controls is the Ball Crashed
     //
     if(top->x == 0 )
          top->dir2 = 'd';
     if(top->y == 0 )
          top->dir1 = 's';
     if(top->y == 24 )
          top->dir1 = 'w';
     if(top->x == 79 )
          top->dir2 = 'a';
     //
     //  Draws New Ball
     //
     gotoxy(top->x,top->y);
     cout<<"*";
}

void init()
{
     top = new struct top;
     top->dir1 = 'w';
     top->dir2 = 'd';
     top->x = 50;
     top->y = 23;
}

int main()
{
     init();     
     while(1)
     {
          Sleep(20);
          top_oynat();
     }    
}

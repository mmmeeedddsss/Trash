#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstring>
using namespace std;

void gotoxy (int x, int y)
{
    COORD coord; // coordinates
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates
}

class Node{
     public:
          int x,y;
          Node *nextbyCoord,*next,*prev;
          Node(int i,int j)
          {
               x=i;
               y=j;
               next=NULL;
               prev=NULL;
               nextbyCoord=NULL;
          }
          ~Node()
          {
            //Delete this! :D    
          }
};
class Feed{
     public:
          int x,y;
          
          Feed()
          {
               x=y=0;   
          }
          void Set_Point()
          {
               x=1+rand()%77;
               y=1+rand()%22;    
          }
};

class LinkedSnake{
     private:
          char dir;
          int time;
          unsigned long long int Score;
          Feed feed;
          bool isEatedFeed;
          bool ScoreBoard;
          Node *byCoord,*byHead,*last;
     public:
          LinkedSnake()
          {
               time = 20;
               ScoreBoard = true;
               feed.Set_Point();
               isEatedFeed = false;
               Score=0;
               dir='d';
               //
               //  First 3 Node Inithilize ...
               //
               Node *head = new Node(5,3);
               byHead = head;
               head->next = new Node(5,2);
               head->next->prev = head;
               head->next->nextbyCoord = head;
               head->next->next = new Node(5,1);
               head->next->next->nextbyCoord = head->next;
               head->next->next->prev = head->next;
               byCoord = head->next->next;
               last = byCoord;
               //
               //  Starting Game ...
               //
               Show_Menu();
          }
          void Show_Menu();
          void Move();
          void Draw_Snake();
          void Runtime();
          char Game_Over();
          void Show_Options();
};

char LinkedSnake::Game_Over()
{
     system("cls");
     gotoxy(20,10);
     cout<<"Game Over Dostum ! :D Skorun : "<<Score<<endl;
     gotoxy(65,24);
     cout<<"Gorusuruk :D";
     getch();
     exit(1);
}

void LinkedSnake::Runtime()
{
     while(1)
     {
          Sleep(time);
          if(kbhit())
          {
               char temp;
               temp = getch();
               switch(temp)
               {
                    case'w': if(dir != 's') dir = temp; break;
                    case's': if(dir != 'w') dir = temp; break;
                    case'a': if(dir != 'd') dir = temp; break;
                    case'd': if(dir != 'a') dir = temp; break;
                    case' ': Score += 10000;
                    default: cout<<"\a";
               }
          }
          Move();
          Draw_Snake();
     }    
}

void LinkedSnake::Move()
{
     int x,y,x2,y2;
     x=byHead->x;
     y=byHead->y;
     //
     //  Move Head..
     //
     switch(dir)
     {
          case'w': byHead->y--; break;
          case's': byHead->y++; break;
          case'a': byHead->x--; break;
          case'd': byHead->x++; break;
          default: cout<<"\a";
     }
     //
     //  Is Eated Feed
     //
     if(byHead->x==feed.x&&byHead->y==feed.y)
     {
          Score+=feed.x+feed.y+327;
          feed.Set_Point();
          isEatedFeed=true;
     }
     //
     // Is Crach Itself
     //
     Node *temp = byHead->next;
     while( temp->next != NULL )
     {
          if(temp->x==byHead->x&&temp->y==byHead->y)
          {
               Game_Over();    
          }
          else temp = temp->next;
     }
     if(temp->x==byHead->x&&temp->y==byHead->y)
     {
               Game_Over();    
     }
     //
     //  Is Out Of Bounds 
     //
     if(byHead->x>79||byHead->y>24||byHead->x<0||byHead->y<0)
     {
          Game_Over();    
     }
     //
     //  Move the Snake !
     //
     temp = byHead;
     while( temp->next != NULL )
     {
          x2=temp->next->x;
          y2=temp->next->y;
          temp->next->x=x;
          temp->next->y=y;
          x=x2;
          y=y2;
          temp=temp->next;
     }
     if(isEatedFeed==true)
     {
          isEatedFeed=false;
          temp->next = new Node(temp->x,temp->y);
          temp->next->prev = temp;
          temp->x=x;
          temp->y=y;
     }
     /*
     else
     {
          temp->prev->next = NULL;
          delete temp;  
     }
     */
     Draw_Snake();
}

void LinkedSnake::Draw_Snake()
{
     system("cls");
     if(ScoreBoard==true)
     {
          gotoxy(62,24);
          cout<<"Score --> "<<Score;
     }
     gotoxy(feed.x,feed.y);
     cout<<"*";
     Node *temp=byHead;
     while(temp->next != NULL )
     {
          gotoxy(temp->x,temp->y);
          cout<<"x";
          temp = temp->next;
     }
     gotoxy(temp->x,temp->y);
     cout<<"x";
}

void LinkedSnake::Show_Options()
{
     system("cls");
     cout<<"Hiz Degistirmek Icin H ,"<<endl;
     cout<<"Score Ac Kapa Icin S Basiniz.."<<endl;
     char a=getch();
     if(a=='h')
     {
          cout<<endl<<"0 ile 5 arasi bi seviye seciniz .."<<endl;
          int i=getch();
          if(i<6&&i>-1)
               time = 50-i*10;
          Show_Menu();
     }
     else if(a=='s')
     {
          system("cls");
          cout<<"Kapatmak Istediine Eminsen d ye Bas ..";
          a=getch();
          if(a=='d')
               ScoreBoard=true;
          else Show_Menu();
     }
}

void LinkedSnake::Show_Menu()
{
     system("cls");
     cout<<"Snake'ye Hosgeldiniz .."<<endl;
     cout<<"Lutfen Yapmak Istediinizi Seciniz ;"<<endl;
     cout<<" - Oyunu Baslatmak Icin B ye ,"<<endl;
     cout<<" - Ayarlari Gormek Icin A ya ,"<<endl;
     cout<<" - Cikmak Icin Ise C ye Basiniz ...";
     char a=getch();
     if(a=='b')
          Runtime();
     else if(a=='a')
          Show_Options();
     else if(a=='c')
          exit(1);
}
int main()
{
     srand(time(NULL));
     LinkedSnake *x = new LinkedSnake();
     x->Show_Menu();
     return 0;
}


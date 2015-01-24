#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstring>
using namespace std;

void gotoxy (int x, int y) // console ekranýnda x,y koordinatlarýna imleci getiriyo
{
    COORD coord; // coordinates
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates
}

class Node{
     public:
          int x,y;
          Node *next,*prev;
          Node(int i,int j)
          {
               x=i;
               y=j;
               next=NULL;
               prev=NULL;
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
          long long int Score;
          Feed feed;
          bool isEatedFeed;
          bool ScoreBoard;
          Node *byHead,*last;
          int snake_type;
     public:
          LinkedSnake()
          {
               snake_type = 0;
               time = 15;
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
               head->next->next = new Node(5,1);
               head->next->next->prev = head->next;
               last = head->next->next;
               //
               //  Starting Game ...
               //
               Show_Menu();
          }
          void Show_Menu();
          void Move();
          void Draw_Snake();
          void Runtime();
          void Reverse();
          void Game_Over();
          void Show_Options();
          
          ~LinkedSnake()
          {
               delete byHead,last;
          }
};

void LinkedSnake::Reverse()
{
     Node *temp=byHead,*tmp;
     while(temp->next != NULL)
     {
          tmp=temp->next;
          temp->next=temp->prev;
          temp->prev=tmp;
          temp=temp->prev;
     }
     tmp=temp->next;
     temp->next=temp->prev;
     temp->prev=tmp;
     
     temp=byHead;
     byHead=last;
     last=temp;
     switch(dir)
     {
          case'w': dir='s'; break;
          case's': dir='w'; break; 
          case'a': dir='d'; break; 
          case'd': dir='a'; break; 
     }
}

void LinkedSnake::Game_Over()
{
     Sleep(40);
     system("cls");
     gotoxy(20,10);
     cout<<"Game Over Dostum ! :D Skorun : "<<Score<<endl;
     gotoxy(65,24);
     cout<<"Zaaaa ! xD";
     getch();
     gotoxy(15,15);
     cout<<"Bidaha Oynamak Istersen t ye (veya Space ye) Bas \n\t\t\t\tCikcaksan c ye Bas ..";
xxx:
     char a=getch();
     if(a=='t'||a==' ')
     {
          LinkedSnake *x = new LinkedSnake();
          free(this);
          x->Show_Menu();
     }
     else if(a=='c')
          exit(1);
     else goto xxx;
}

void LinkedSnake::Runtime()
{
     while(1)
     {
          if(kbhit())
          {
               int temp;
               temp = getch();
               //
               //  Is Pressed Key Is An Arrow Key
               //
               if(temp==224)
               {
                    int temp2 = getch();
                    switch(temp2)
                    {
                         case 72: temp = 'w'; break;
                         case 80: temp = 's'; break;
                         case 75: temp = 'a'; break;
                         case 77: temp = 'd'; break;
                    }    
               }
               char tmp=dir;
               switch(temp)
               {
                    case'w': if(dir != 's') dir = temp; break;
                    case's': if(dir != 'w') dir = temp; break;
                    case'a': if(dir != 'd') dir = temp; break;
                    case'd': if(dir != 'a') dir = temp; break;
                    case'r': Reverse(); break;
                    case'p': gotoxy(30,1); cout<<"Paused !"; while(!kbhit()); gotoxy(30,1); cout<<"        "; break;
                    case'm': Score += 13845;
                    gotoxy(1,0); cout<<"Adam Hacker Beyler Daalin :D";
                    default: cout<<"\a";
               }
               /*
                    if((dir=='w'||dir=='s')&&(tmp=='a'||tmp=='d')) time=time+5;
                    if((dir=='a'||dir=='d')&&(tmp=='s'||tmp=='w')) time=time-5;
               */
          }
          Move();
          Draw_Snake();
     }    
}

void LinkedSnake::Move()
{
     //
     //  Move Head..
     //
     /*
     if(snake_type==1||snake_type==2)
     {
          gotoxy(byHead->x,byHead->y);
          cout<<"x";
     }
     */
     Node *m = new Node(byHead->x,byHead->y);
     m->prev = byHead;
     m->next = byHead->next;
     byHead->next->prev = m;
     byHead->next = m;
     switch(dir)
     {
          case'w': byHead->y--; break;
          case's': byHead->y++; break;
          case'a': byHead->x--; break;
          case'd': byHead->x++; break;
     }
     gotoxy(byHead->x,byHead->y);
     //if(snake_type==0)
     //{
          cout<<"x";
     //}
     /*
     else if(snake_type==1)
     {  
          if(dir=='d') cout<<">";
          else if(dir=='a') cout<<"<";
          else if(dir=='w') cout<<"^";
          else if(dir=='s') cout<<"v";
     }
     else if(snake_type==2)
     {
          cout<<(char)2;   
     }
     */
     //
     //  Did Eat Feed
     //
     if(byHead->x==feed.x&&byHead->y==feed.y)
     {
          Score+=feed.x+feed.y+327+(20-time)*30;
          feed.Set_Point();
          isEatedFeed=true;
          gotoxy(feed.x,feed.y);
          cout<<"*";
     }
     //
     // Is Crashed by Itself
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
     //  Is Outed Of Bounds 
     //
     if(byHead->x>79||byHead->y>24||byHead->x<0||byHead->y<0)
     {
          Game_Over();    
     }
     //
     //  Move the Snake !
     //
     gotoxy(last->x,last->y);
     cout<<" ";
     last = last->prev;
     last->next = NULL;
     /*
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
     */
     if(isEatedFeed==true)
     {
          isEatedFeed=false;
          last->next = new Node(last->x,last->y);
          last->next->prev = last;
          last = last->next;
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
     Sleep(time);
     //system("cls");
     if(ScoreBoard==true)
     {
          gotoxy(62,24);
          cout<<" Score --> "<<Score;
     }
     /*
     gotoxy(feed.x,feed.y);
     cout<<"*";
     Node *temp=byHead;
     */
     /*
     while(temp->next != NULL )
     {
          gotoxy(temp->x,temp->y);
          cout<<"x";
          temp = temp->next;
     }
     gotoxy(temp->x,temp->y);
     cout<<"x";
     */
}

void LinkedSnake::Show_Options()
{
     system("cls");
     cout<<"Hiz Degistirmek Icin H ,"<<endl;
     cout<<"Score Ac Kapa Icin S Basiniz.."<<endl;
     cout<<"Yilanin Kafasini Deistirmek Icin K ye Basinz ..."<<endl;
     char a=getch();
     if(a=='h')
     {
          cout<<endl<<"0 ile 50 arasi --bekleme-- suresini milisaniye cinsinden seciniz .."<<endl;
          int i;
          cin>>i;
          if(i<51&&i>-1)
               time = i;
          Show_Menu();
     }
     else if(a=='k')
     {
          gotoxy(10,17); cout<<"- Duz Yilan Icin 0";
          gotoxy(10,18); cout<<"- Kafali Yilan Icin 1"; 
          gotoxy(10,19); cout<<"- Gulen Yilan Icin 2"; 
          gotoxy(60,20); cout<<"Basiniz ...";
               int asd;
               cin>>asd;
                    if(asd>-1&&asd<3)
                         snake_type = asd;
     }
     else if(a=='s')
     {
          system("cls");
          cout<<"Kapatmak Istediine Eminsen d ye Bas ..";
          a=getch();
          if(a=='d')
               ScoreBoard=false;
          else Show_Menu();
     }
}

void LinkedSnake::Show_Menu()
{
     system("cls");
     cout<<"Snake'e Hosgeldiniz .."<<endl;
     cout<<"Lutfen Yapmak Istediinizi Seciniz ;"<<endl;
     cout<<" - Oyunu Baslatmak Icin B - veya Space - ye ,"<<endl;
     cout<<" - Ayarlari Gormek Icin A ya ,"<<endl;
     cout<<" - Cikmak Icin Ise C ye Basiniz ...(Pause Eklenmistir :D 'P')";
     char a=getch();
     system("cls");
     gotoxy(feed.x,feed.y);
     cout<<"*";
     if(a=='b'||a==' ')
          Runtime();
     else if(a=='a')
          Show_Options();
     else if(a=='c')
          exit(1);
}
int main()
{
     /*
     while(1)
     {
     int ch;
	ch = getch();
	cout<<ch<<endl;
	ch = getch();
	cout<<ch<<endl<<endl;
     }
     */
     srand(time(NULL));
     LinkedSnake *x = new LinkedSnake();
     x->Show_Menu();
     return 0;
}

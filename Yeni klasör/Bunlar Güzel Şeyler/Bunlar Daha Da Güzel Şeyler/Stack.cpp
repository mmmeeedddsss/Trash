#include<iostream>
#include<list>
#include<conio.h>
#define MAX 125
using namespace std;

class Stack
{
     private:
          int elemanlar[MAX];
          int son_sira;
     public:
          Stack()
          { son_sira=0; }
          void pop();
          void push();
          void display();
};

     void Stack::display()
     {
          if(!son_sira) cout<<"There is No Obj. in Class.."<<endl;
          while(son_sira)
          {
               cout<<elemanlar[--son_sira]<<endl;
          }
     }
     void Stack::push()
     {
          if(son_sira<MAX)
          {
               int a;
               cin>>a;
               elemanlar[son_sira++]=a;
          }
          else cout<<"The Steak is Full.."<<endl;
     }
     void Stack::pop()
     {
          if(son_sira)
          {
          cout<<elemanlar[--son_sira]<<endl;
          }
          else cout<<"There is No Obj. in Class.."<<endl;
     }
     
int main()
{
         Stack s;
         int x,i;
         char j;
         while(1)
         {
               cin>>j;
               if(j=='k') s.push();
               if(j=='a') s.pop();
               if(j=='d') s.display();
               if(j=='c') system("cls");
          }
         //getch();
}

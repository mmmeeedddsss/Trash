#include <iostream>
#include <conio.h>
#include <stdio.h>
#define MAX 100
using namespace std;

class Queue
{
     private:
          int front,rear;
          int values[MAX];
     public:
          Queue()
          { front=0; rear=0; }
          void enqueue();
          void dequeue();
          void isFull();
          void isEmpty();
          void display();
};

     void Queue::display()
     {
               int x;
               x=front; 
               while(x!=rear)
               {    
                    cout<<values[x]<<endl;
                    x++;
               }
     }
     
     void Queue::enqueue()
     {
          if(((rear+1)%MAX)!=front)
          {
              int x;
              cout<<"Please Enter a Value.."; cin>>x;
              values[rear]=x;
              rear++;
          }
     }
     void Queue::dequeue()
     {
          if(front!=rear)
          {
              cout<<values[front]<<" Dequeued.."<<endl;
              values[front]=0;
              front++;
          }
     }
     void Queue::isEmpty()
     {
          if(front==rear) cout<<"Queue is Empty .."<<endl;
          else cout<<"Queue isn't Empty .."<<endl;
     }
     void Queue::isFull()
     {
          if(((rear+1)%MAX)==front) cout<<"Queue is Full .."<<endl;
          else cout<<"Queue isn't Full .."<<endl;
     }
     
     int main()
     {
          Queue x;
          char c;
          while(1)
          {
                 cin>>c;
                 if(c=='b')   x.isEmpty();
                 if(c=='f')   x.isFull();
                 if(c=='c')   x.dequeue();
                 if(c=='e')   x.enqueue();
                 if(c=='d')   x.display();
          }
          getch();
     }

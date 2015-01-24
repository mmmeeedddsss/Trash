#include <iostream>
#include <conio.h>

using namespace std;

class Node
{
     public:
          int value;
          Node *next;
          Node(int i)
          {
               value=i;
               next=NULL;
          }
          ~Node()
          {
               //delete this;
          }
};

class LinkedList
{
     private:
          Node *next;
     public:
          LinkedList()
          {
               next=NULL;
          }
          void insert();
          void _delete();
          void display();
          void info();
          void parcala(char x);
          void insert_at();
          void multiple_insert();
          Node& operator [](int x);
};
     Node& LinkedList::operator [](int x)
     {
          x++;
          Node *iterator=next;
          while(x>1&&iterator!=NULL){ iterator=iterator->next; x--; }
          return *iterator;
     }
     void LinkedList::insert_at()
     {
          int w,x;
          cout<<"Where do You Want to Add ??"<<endl;
          cin>>w;
          cout<<"And What do You Want to Add??"<<endl;
          cin>>x;
          Node *iterator,*temp;
          iterator=next;
          temp=new Node(x);
          if(w==1)
          {
               temp->next=next;
               next=temp;
               return;
          }
          iterator=&iterator[w];
          temp->next=iterator->next;
          iterator->next=temp;
          
     }
     void LinkedList::multiple_insert()
     {
          int w;
          cout<<"How Much Value do You Want to Insert??"<<endl;
          cin>>w;
          for(int i=0;i<w;i++) insert();
          cout<<"Values Are Added Your List..."<<endl;;
     }
     void LinkedList::_delete()
     {
          int x;
          cout<<"Which One Do You Want to Delete??"<<endl;
          cin>>x;
          Node *iterator,*temp;
          iterator=next;
          if(x==1)
          { 
               cout<<next->value<<" Deleted.."<<endl;
               next=next->next;
               return; 
          }
          if(x==2)
          {
               cout<<next->next->value<<" Deleted.."<<endl;
               next->next=next->next->next;
               return;
          }
		  while(iterator->next!=NULL&&x>2) { iterator=iterator->next; x--; }
          if(iterator!=NULL) if(iterator->next!=NULL) cout<<endl<<iterator->next->value<<" Deleted.."<<endl;
          if(iterator!=NULL&&iterator->next!=NULL) iterator->next=iterator->next->next;
          //delete temp;
     }
     void LinkedList::display()
     {
          Node *iterator;
          iterator=next;
          //cout<<value<<endl;
          int i=0;
          while(iterator->next!=NULL) 
          {
               i++;
               cout<<i<<". Value is "<<iterator->value<<endl;
               iterator=iterator->next;
          }
          cout<<++i<<". Value is "<<iterator->value<<endl;
     }
     void LinkedList::insert()
     {
          int x;
          cout<<"What Do You Want to Insert??"<<endl;
          cin>>x;
          Node *temp;
          temp=next;
          if(next==NULL)
          {
               next = new Node(x);
               return;
          }
          while(temp->next!=NULL) temp=temp->next;
          temp->next = new Node(x);
     }
     void LinkedList::info()
     {
          cout<<"What do you want to do?"<<endl;
          cout<<"Insert?? -Press i"<<endl;
          cout<<"Print the List?? -Press p"<<endl;
          cout<<"Delete an Value?? -Press d"<<endl;
          cout<<"Multiple Add?? -Press m"<<endl;
          cout<<"If You Want to See This Info Again :D,Press -h";
          getch();
          system("cls");
     }
     void LinkedList::parcala(char x)
     {
          switch(x)
          {
               case'a': insert_at(); break;
               case'i': insert(); break;
               case'p': display(); break;
               case'h': info(); break;
               case'd': _delete(); break;
               case'm': multiple_insert(); break;
               case'c': system("cls"); break;
          }    
     }
     
int main()
{
     for(int i=0;i<100;i++)
     {
          if(i%10==0) cout<<i/10;
          else cout<<" ";
     }
     LinkedList head;
     char x;
     head.info();
     while(1)
     {
            cin>>x;
            head.parcala(x);
            //head[2].value = 98;  
     }
}

#include<iostream>
#include<conio.h>
#define MAX 20
#define INF 9999
#define MIN -9999
using namespace std;

struct tag{
     int cost;
     int from;    
};

class Node{
     private:
          int number;
          bool isok;
          bool istagsetted;
          struct tag tagg;
     public:
          Node(int nmbr)
          {
               tagg.cost = -1;
               tagg.from = -1;
               isok = false;
               number = nmbr;
               istagsetted = false;
          }
          Node()
          {
               
          }
          void set_as_ok()
          {
               isok = true;    
          }
          bool is_ok()
          {
               if( isok == false )
                    return false;
               return true;    
          }
          bool is_tag_setted()
          {
               return istagsetted;    
          }
          void setTag(int cost,int from)
          {
               istagsetted = true;
               tagg.cost = cost;
               tagg.from = from;  
          }
          struct tag getTag()
          {
               return tagg;    
          }
};

Node *Nodes;
int Last_Added;
int array[MAX][MAX];
int calc_cost(int i)
{
     if( i == 0 ) return 0;
     if( Nodes[i].is_tag_setted() )
          return Nodes[i].getTag().cost + calc_cost( Nodes[i].getTag().from );
     else return 0;
}

void init(int n)
{
     Nodes = new Node[n+1];
     for(int i=0;i<n;i++) Nodes[i] = Node(i);
     Nodes[0].set_as_ok();
     Last_Added = 0;
}

void solve(int n)
{
     int sayac = 0;
     while(sayac < n) // ?
     {
          sayac++;
          int i = Last_Added;
          int min = MAX;
          int min_nmbr = -1;
          for(int j=0;j<n;j++)
          {
               //cout<<array[i][j]<<" ";
               if( array[i][j] != -1 )
               {
                    if( array[i][j] < min )
                    {
                         min = array[i][j];
                         min_nmbr = j;
                    }
               }
          }
          //cout<<"     "<<min<<"     "<<min_nmbr<<endl;
          Nodes[min_nmbr].set_as_ok();
          Nodes[min_nmbr].setTag(min,i);
          Last_Added = min_nmbr;
     }
}

int main()
{
     system("cls");
     int n;
     cin>>n;
     
     for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
               scanf("%d",&array[i][j]);
     
     init(n);
     solve(n);
     
     for( int i=0;i<n;i++ )
          cout<<Nodes[i].getTag().cost;
          //cout<<i<<" --> "<<calc_cost(i)<<endl;


     getch();
}

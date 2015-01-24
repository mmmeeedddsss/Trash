#include<iostream>
#include<conio.h>
using namespace std;

int min(int x,int y)
{
     return x>y?y:x;    
}

int array[3][3];

int solve(int len,int x,int y)
{
     if(y == 0) return array[0][0];
     
     return min( solve(len,x-1,y-1) , array[x][y] );
}

int main()
{
     int len=3;                         // 2 
     for(int i=0;i<len;i++)  
     {           // 1 2
          for(int j=0;j<i+1;j++)
          {
               cin>>array[i][j]; 
          }
     }
     for(int i=0;i<len;i++)             // 1 2
          for(int j=0;j<i;j++)          // 5 2 3 
               cout<<array[i][j];       // 2 3 8 8
     cout<<solve(len,len-1,len-1);
     getch();
}

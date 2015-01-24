#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

bool isok( int ** table )
{
     for( int i=0; i<9; i++ )
          for( int j=0; j<9; j++ ) 
               if( table[i][j] == 0 )
                    return false;
     return true;
}

int* returnAvaibleNumbers(int **table,int x, int y)
{
     int *nums = new int[9];
     for( int i=0; i<9; i++ )
          nums[i] = i+1;
     for( int i=0; i<9; i++ )
     {
          if( table[x][i] != 0 )
               nums[table[x][i] - 1] = 0;
          if( table[i][y] != 0 )
               nums[table[i][y] - 1] = 0;
     }
     for( int i=(x/3)*3; i<((x/3)*3)+3; i++ )
          for( int j=(y/3)*3; j<((y/3)*3)+3; j++ )
               if( table[i][j] != 0 )
                    nums[table[i][j] - 1] = 0;
     return nums;
}

int calc( int xo, int yo, int **table )
{
     int x,y;
     for( int i=(xo+(yo*9)); i<81; i++ )
          if( table[(i%9)][(i/9)] == 0  )
          {
               x = (i % 9);
               y = (i / 9);
               break;
          }
     int *nums = returnAvaibleNumbers(table,x,y);
     for( int i=0; i<9; i++ )
     {
          //cout<<nums[i]<<" ";
          if( nums[i] != 0 )
          {
               //cout<<nums[i]<<endl;
               table[x][y] = nums[i];
               if( isok(table) )
               {
                    for( int i=0; i<9; i++ )
                    {
                         for( int j=0; j<9; j++ )
                              cout<<table[i][j]<<" ";
                         cout<<endl;
                    }
                    return 1;
               }
               if( calc(x,y,table) == 1 )
               {
                    return 1;
               }
          }
     }
     table[x][y] = 0;
     return 0;
}

int main()
{
     system("");
     FILE *f1 = fopen("Sudoku3.in","r");
     int **table = new int*[9];
     for( int i=0; i<9; i++ )
          table[i] = new int[9];
     for( int i=0; i<9; i++ )
          for( int j=0; j<9; j++ )
               fscanf(f1,"%d",&table[i][j]);
     calc(0,0,table);
     getch();
     return 0;
}

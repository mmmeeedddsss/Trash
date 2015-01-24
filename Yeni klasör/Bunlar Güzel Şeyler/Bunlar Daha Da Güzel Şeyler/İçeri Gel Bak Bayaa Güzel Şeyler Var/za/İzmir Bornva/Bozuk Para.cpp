#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
     int n; // bozuk para tür sayýsý , j
     cin>>n;
     int d[n]; // bozuk paralar
     for( int i=0; i<n; i++ )
          cin>>d[i];
     int m; // amaçlanan para , i
     cin>>m;
     int a[m][n+1];
     for( int i=0; i<m; i++ )
          a[i][0] = 0;
     for( int i=0; i<n+1; i++ )
          a[0][i] = i;
     for( int i=1; i<m; i++ )
     {
          for( int j=0; j<n+1; j++ )
          {
               int min = a[i-1][j];
               if( j - d[i] >= 0 && min > 1 + a[i][j-d[i]] ) // 4,3
                    min = 1 + a[i][j-d[i]];
               a[i][j] = min;
          }
     }
     for( int i=0; i<n+1; i++ )
     {
          for( int j=0; j<m; j++ )
          {
               cout<<a[i][j]<<" ";
          }
          cout<<endl;
     }
     getch();
     return 0;
}

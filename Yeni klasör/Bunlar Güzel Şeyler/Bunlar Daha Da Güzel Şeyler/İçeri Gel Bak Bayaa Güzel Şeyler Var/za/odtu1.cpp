#include<iostream>
using namespace std;

int main()
{
     unsigned long long int n,j;
     cin>>n;
     for( int i=(n+1);i<(n*2);i++ )
     {
          j = n * i;
          if( j % ( i - n ) == 0 )
               cout<<i<<" - "<<(j/(i-n))<<endl;
     }
     system("pause");
}

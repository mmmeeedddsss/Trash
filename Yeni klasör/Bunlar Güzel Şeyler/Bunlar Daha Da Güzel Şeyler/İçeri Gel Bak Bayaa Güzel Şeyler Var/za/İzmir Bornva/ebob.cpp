#include <iostream>
#include <conio.h>
#include "kutuhane.h"
using namespace std;
int fibo[1000];
int fib( int n )
{
     printf("%d\n",n);
     if( n == 0 || n == 1 )
          return 1;
     else
          return fib(n-1) + fib(n-2);
}
int dinfib( int n )
{
     if( n == 0 || n == 1 )
          return 1;
     if( fibo[n] == 0 )
          fibo[n] = dinfib( n - 1 ) + dinfib( n - 2 );  
     return fibo[n];  
}
int main()
{
    // printf("%d\n",fib(2000));
    float f = 0.33;
     if(f) printf("anan");
     getch();    
}

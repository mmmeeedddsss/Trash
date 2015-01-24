#include <stdio.h>
int ebob(int m, int n)
{
     if( n == 0 )
          return m;
     else
          return ebob( n, m % n );
}

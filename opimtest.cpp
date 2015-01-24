#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
     
     
     
     int m=0;
     for( int a=1; a<=5; a++ )
          for( int b=1; b<=5; b++ )
               for( int c=01; c<=5; c++ )
                    m+=a+b+c;
     cout<<m<<endl<<endl; //1125
     
     m=0;
     for( int a=1; a<=5; a++ )
          for( int b=1; b<=5; b+=2 )
               for( int c=1; c<=5; c+=3 )
                    m+=a+b+c; 
     cout<<m<<endl<<endl; //255
     
      m=0;
     for( int a=1; a<=5; a++ )
          for( int b=0; b<=5; b+=2 )
               for( int c=0; c<=5; c+=3 )
                    m++; 
     cout<<m<<endl<<endl; //30
     
     m=0;
     for( int a=1; a<=5; a++ )
          for( int b=a; b<=5; b++ )
               for( int c=b; c<=5; c++ )
                    m++; 
     cout<<m<<endl<<endl;  // 35    

   m=0;
     for( int a=1; a<=5; a++ )
          for( int b=a; b<=5; b++ )
               for( int c=b; c<=5; c++ )
                    m+=a+b+c;
     cout<<m<<endl<<endl;   // 315
     getch();
}

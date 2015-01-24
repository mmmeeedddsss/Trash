#include<iostream>
#include<conio.h>
using namespace std;

void controll( int*  numAsArray ) // int alýp, dictdeki her satýr için uygun mu diye bakýyo
{
     int len = lenArray(numAsArray);
     int line = 100;
     bool flag=false;
     for( int i=0; i<line; i++ )
     {
          char* line = read;
          if( lenArray( line ) != len )
              continue;
          flag = false;
          for( int j=0; j<len; j++ )
          {
               if( getInt( line[j] ) != numAsArray[j] )
               {
                   flag = true;
                   break;
               }
          }
          if( flag == false ) 
              cout<<line;
     }
}

int getInt( char x )
{
    switch( x )
    {
            case 'A':case'B':case'C': return 2;
            case 'D':case'E':case'F': return 3;
            case 'G':case'H':case'I': return 4;
            case 'J':case'K':case'L': return 5;
            case 'M':case'N':case'O': return 6;
            case 'P':case'R':case'S': return 7;
            case 'T':case'U':case'W': return 8;
            case 'W':case'X':case'Y': return 9;
            
    } 
}

int lenArray( int* x ) // OK !!!
{
	int i=0;
	while( x[i] != '\n' )
		i++;
	return i;
}

int lenInt( int x ) // OK !!!
{
	int i=1,j=0;
	while( x/i > 0 )
	{
		i*=10;
		j++;
    }
	return j;
}

int* parseNum( int num )
{
      int* array = new int[lenInt(num)];
      int i=0;
      while( num > 0 )
      {
             array[i++] = num%10;
             num /= 10;
      }
      array[i] = '\n';
      return array;
}

int main()
{
    /*
	int num;
	cin>>num;
	int *numAsArray = parseNum( num );
	*/
	int* array = parseNum(1091);
	for( int i=0; i<lenArray( array ); i++ )
	     cout<<array[i];
	
	getch();
	
}

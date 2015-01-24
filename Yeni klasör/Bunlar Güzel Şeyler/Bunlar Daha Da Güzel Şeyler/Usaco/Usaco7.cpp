/*
ID:mmmeeed1
TASK:namenum
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

int *digits;
char numtochar[8][3];// [ number ][ comb ]

int parse(int num,int digitcount)
{
	digits = new int[digitcount];
	int u = 0;
	while( num > 0 )
	{
		digits[u++] = num%10;
		num /= 10;
	}
	int j=digitcount-1;
	for( int i=0; i<j; i++ )
	{
		int temp = digits[i];
		digits[i] = digits[j];
		digits[j--] = temp;
	}
	/*
	for( int i=0; i<digitcount; i++ )
	cout<<digits[i];
	*/
}

int getdigits(int num)
{
	int u = 0;
	while( num > 0 )
	{
		num /= 10;
		u++;
	}
	return u;
}

int ff( int x, int y )
{
	if( y == 0 ) return 1;
	return x * ff( x , y - 1 );
}

string calccombfori(int x,int digitcount)
{
	char array[digitcount];
	for( int i=0; i<digitcount; i++ )
	{
		array[i] = numtochar[ digits[i] - 2 ][ x % 3 ];
		x /= 3;
	}
	return string( array );
}

void calccombs(int digitcount)
{
	numtochar[0][0] = 'A';
	numtochar[0][1] = 'B';
	numtochar[0][2] = 'C';
	numtochar[1][0] = 'D';
	numtochar[1][1] = 'E';
	numtochar[1][2] = 'F';
	numtochar[2][0] = 'G';
	numtochar[2][1] = 'H';
	numtochar[2][2] = 'I';
	numtochar[3][0] = 'J';
	numtochar[3][1] = 'K';
	numtochar[3][2] = 'L';
	numtochar[4][0] = 'M';
	numtochar[4][1] = 'N';
	numtochar[4][2] = 'O';
	numtochar[5][0] = 'P';
	numtochar[5][1] = 'R';
	numtochar[5][2] = 'S';
	numtochar[6][0] = 'T';
	numtochar[6][1] = 'U';
	numtochar[6][2] = 'V';
	numtochar[7][0] = 'W';
	numtochar[7][1] = 'X';
	numtochar[7][2] = 'Y';
	
	int f = ff( 3 , digitcount );
	bool flag = false;
	FILE *f3 = fopen("dict.txt","r");
	FILE *f2 = fopen("namenum.out","w");
	for( int u=0; u<f; u++ )
	{
		string combfori = calccombfori( u , digitcount );
		for( int i=0; 1; i++ )
		{
		    char cline[15];
		    if( fscanf(f3,"%s",cline) == EOF )
				break;
		    string line = cline;
		    if( line == combfori )
		    {
				fprintf(f2,"%s\n",line.c_str());
				flag = true;
			}
		}
		rewind(f3);
	}
	if( !flag )
		fprintf(f2,"NONE\n");
	fflush(f2);
}

int main()
{
	FILE *f1 = fopen("namenum.in","r");
	int num;
	fscanf(f1,"%d",&num);
	int digitcount = getdigits(num);
	parse(num,digitcount);
	calccombs(digitcount);
	return 0;
}

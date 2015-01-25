#include<iostream>
#include<fstream>
using namespace std;
char **m;

typedef struct _pair2{
	int v;
	int k;
}pair2;

int a,b;

pair2 calc(int x, int y )
{
	pair2 n;
	n.v=0;
	n.k=0;
	if( x >= a || x < 0 || y >= b || y < 0 )
		return n;
	if( m[x][y] != 'X' )
	{

		if( m[x][y] == '#' )
			return n;
		if( m[x][y] == 'v' )
			n.v++;
		else if( m[x][y] == 'k' )
			n.k++;
		m[x][y] = 'X';

		pair2 temp = calc(x+1,y);
		n.v += temp.v;
		n.k += temp.k;
		temp = calc(x-1,y);
		n.v += temp.v;
		n.k += temp.k;	
		temp = calc(x,y+1);
		n.v += temp.v;
		n.k += temp.k;
		temp = calc(x,y-1);
		n.v += temp.v;
		n.k += temp.k;			
		
	}
	return n;
	
}



int main()
{
	int k=0,v=0;
	ifstream fin("koze.gir");
	ofstream fout("koze.cik");
	fin>>a>>b;
	m = new char*[a];
	for( int i=0; i<a; i++ )
		m[i] = new char[b];

	for( int i=0; i<a; i++ )
		for( int j=0; j<b; j++ )
			fin>>m[i][j];
	for( int i=0; i<a; i++ )
		for( int j=0; j<b; j++ )
		{
			pair2 a = calc(i,j);
			if(a.k > a.v)
				k += a.k;
			else
				v += a.v;
		}
	fout<<k<<" "<<v;
	fout.close();	
}

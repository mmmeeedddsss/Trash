#include<iostream>
#include<fstream>
using namespace std;
char **m;
int yr,xr;

int calc(int x, int y )
{
	//cout<<x<<y<<endl;
	if( m[x][y] == 'X' ) return 0;
	int temp = 0;
	if( x+1 < xr && x+1 >= 0 && m[x+1][y] == '.' ) temp++;
	if( x-1 < xr && x-1 >= 0 && m[x-1][y] == '.' ) temp++;
	if( y+1 < yr && y+1 >= 0 && m[x][y+1] == '.' ) temp++;
	if( y-1 < yr && y-1 >= 0 && m[x][y-1] == '.' ) temp++;
	
	if( temp == 1 )
	{
		return -1;
	}
	else
		return 1;
	
}

int main()
{
	ifstream in("okret.gir");
	ofstream out("okret.cik");
	in>>xr>>yr;
	
	m = new char*[xr];
	for( int i=0; i<xr; i++ )
		m[i] = new char[yr];
		
	
	for( int i=0; i<xr; i++ )
		for( int j=0; j<yr; j++ )
			in>>m[i][j];

	
	int res = 0;
	for( int i=0; i<xr; i++ )
		for( int j=0; j<yr; j++ )
			if( calc(i,j) == -1 )
			{
				res = 1;
				goto x;
			}
	x:	
	out<<res;
	return 0;
}

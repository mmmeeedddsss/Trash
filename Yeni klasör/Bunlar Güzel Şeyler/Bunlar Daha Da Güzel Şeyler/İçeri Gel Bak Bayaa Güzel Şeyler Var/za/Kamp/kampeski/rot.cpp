#include<iostream>
#include<fstream>
using namespace std;

char **a;
int n,m;

int abs(int x)
{
	return ( (x<0) ? -x : x );
}

void rotate90()
{
	char **temp = new char*[m];
	for( int i=0; i<m; i++ )
		temp[i] = new char[n];

	for( int i=0; i<n; i++ )
		for( int j=0; j<m; j++ )
			temp[m-j-1][i] = a[i][j];
	a = temp;
	int z = n;
	n = m;
	m = z;
}

void rotate45AndPrint() // n == height
{
	ofstream out("Rot.cik");
	int k = n-1;
	for( int i=0; i<n+m-1; i++, k-- )
	{
		for( int j=0; j<abs(k); j++ )
			out<<" ";
		int x = ( (i<n)?0:i-n +1 );
		int y = ( (i<n)?i:n-1 );
		out<<a[y][x];
		y--;
		x++;
		while( y >= 0 && x < m )
		{
			out<<" "<<a[y][x];
			y--;
			x++;
		}
		out<<endl;
	}
}

int print()
{
	ofstream out("Rot.cik");
	for( int i=0; i<n; i++ )
	{
		for( int j=0; j<m; j++ )
			out<<a[i][j];
		out<<endl;
	}
}


int main()
{
	ifstream in("Rot.gir");
	in>>n>>m;
	a = new char*[n];
	for( int i=0; i<n; i++ )
		a[i] = new char[m];

	for( int i=0; i<n; i++ )
		for( int j=0; j<m; j++ )
			in>>a[i][j];//cin>>a[j][i];
	int rot;
	in>>rot;
	int c90 = rot/90;
	int c45 = ( (rot-(c90*90)) == 0 ? 0 : 1 );
	
	c90 %= 4;
	c90 = 4 - c90;
	
	for( int i=0; i<c90; i++ )
		rotate90();
	if( c45 == 1 )
		rotate45AndPrint();
	else
		print();
	
}

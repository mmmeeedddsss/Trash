/*
PROG:clocks
LANG:C++
NAME:mmmeeed1
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class p{
	public:
		int state;
		int way;
		p( int s , int w )
		{
			state = s;
			way = w;
		}
};

int poww( int x, int y )
{
	int r = 1;
	for( int i=0; i<y; i++ )
		r*=x;
	return r;
}

bool contr( int n, int b )
{
	if( (n/poww(10,b-1))%10 == 4 ) //!
		return true;
	return false;
}

int turn( int n, int b )
{
    b = 10-b;
	if( contr( n, b ) )
		n -= 4 * poww( 10, b-1 );
	n += poww( 10, b-1 );
	return n;
}

int addM( int n, int b )
{
	return ( n+poww(10,b-1) );
}

p m1( p x )
{
	int n = x.state; // !
	n = turn(n,1);
	n = turn(n,2);
	n = turn(n,4);
	n = turn(n,5);
	x.way = addM( x.way, 1 );
	x.state = n;
	return x;
}

p m2( p x )
{
	int n = x.state; // !
	n = turn(n,1);
	n = turn(n,2);
	n = turn(n,3);
	x.way = addM( x.way, 2 );
	x.state = n;
	return x;
}
p m3( p x )
{
	int n = x.state; // !
	n = turn(n,2);
	n = turn(n,3);
	n = turn(n,6);
	n = turn(n,5);
	x.way = addM( x.way, 3 );
	x.state = n;
	return x;
}
p m4( p x )
{
	int n = x.state; // !
	n = turn(n,1);
	n = turn(n,4);
	n = turn(n,7);
	x.way = addM( x.way, 4 );
	x.state = n;
	return x;
}
p m5( p x )
{
	int n = x.state; // !
	n = turn(n,2);
	n = turn(n,4);
	n = turn(n,5);
	n = turn(n,6);
	n = turn(n,8);
	x.way = addM( x.way, 5 );
	x.state = n;
	return x;
}
p m6( p x )
{
	int n = x.state; // !
	n = turn(n,3);
	n = turn(n,6);
	n = turn(n,9);
	x.way = addM( x.way, 6 );
	x.state = n;
	return x;
}
p m7( p x )
{
	int n = x.state; // !
	n = turn(n,5);
	n = turn(n,4);
	n = turn(n,7);
	n = turn(n,8);
	x.way = addM( x.way, 7 );
	x.state = n;
	return x;
}
p m8( p x )
{
	int n = x.state; // !
	n = turn(n,7);
	n = turn(n,8);
	n = turn(n,9);
	x.way = addM( x.way, 8 );
	x.state = n;
	return x;
}
p m9( p x )
{
	int n = x.state; // !
	n = turn(n,9);
	n = turn(n,8);
	n = turn(n,6);
	n = turn(n,5);
	x.way = addM( x.way, 9 );
	x.state = n;
	return x;
}

bool isok( int n )
{
	if( n == 444444444 )
		return true;
	return false;
}

bool isbad( int n )
{
	while( n > 0 )
	{
		if( n%10 == 4 )
			return true;
		n /= 10;
	}
	return false;
}

int calc( int n )
{
	queue<p> q;
	map<int,bool> m;
	int temp = 000000000; //!
	q.push( p(n,temp) );
	while( true )
	{
		p curr = q.front();
		q.pop();
		if( !m.count( curr.way ) )
		{
			m[ curr.way ] = true;
			if( isok(curr.state) )
				return curr.way;
			if( !isbad(curr.way) )
			{
				q.push( m1( curr ) );
				q.push( m2( curr ) );
				q.push( m3( curr ) );
				q.push( m4( curr ) );
				q.push( m5( curr ) );
				q.push( m6( curr ) );
				q.push( m7( curr ) );
				q.push( m8( curr ) );
				q.push( m9( curr ) );
			}
		}
	}
}

int main()
{
	ifstream in("clocks.in");
	ofstream out("clocks.out");
	int t;
	int s = 0;
	for( int i=0; i<9; i++ )
	{
		in>>t;
		t/= 3;
		s*=10;
		s+= t;
	}
    int a = calc(s);
    vector<int> v;
	for( int i=0; i<9; i++ )
		for( int j=0; j<((a/poww(10,i))%10); j++ )
			v.push_back(i+1);
	for( int i=0; i<v.size()-1; i++ )
		out<<v[i]<<" ";
	out<<v[v.size()-1];
	out<<endl;
	out.close();
    return 0;
}

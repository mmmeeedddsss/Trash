#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> carpanlar( int n )
{
    vector<int> c;
	for( int i=2; n>1; i++ )
	{
		if( !(n%i) )
		{
			n /= i--;
			c.push_back( i+1 );
		}
	}
	return c;
}

long poww( int x, int y )
{
	int a = 1;
	for( int i=0; i<y; i++ )
		a *= x;
	return a;
}

int bolenler( vector<int> c )
{
    set<int> s;
    int sz = c.size();
	for( long i=0; i<poww(2,sz); i++ )
	{
		long t = i;
		long b = 1;
		for( int j=0; j<sz; j++ )
		{
			if( t%2 )
				b *= c[j];
			t/=2;
		}
		s.insert(b);
	}
	for (set<int>::iterator it=s.begin(); it!=s.end(); it++ )
        cout<<*it<<" ";
}

int main()
{
	int n;
	cin>>n;
	bolenler(carpanlar(n));
	cin>>n;
	return 0;
}

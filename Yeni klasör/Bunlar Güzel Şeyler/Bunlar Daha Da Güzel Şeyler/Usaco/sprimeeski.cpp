/*
PROG:sprime
LANG:C++
NAME:mmmeeed1
*/
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
using namespace std;

map<int,bool> m;
vector<int> v;
bool a[1000000000];

bool isprime( int x )
{
	if( x == 2 )
		return true;
	if( x % 2 == 0 )
		return false;
	if( m.count(x) == 0 )
		return false;
	return true;
}

bool isprimeforgen( int x )
{
	if( x == 2 )
		return true;
	if( x % 2 == 0 )
		return false;
	for( int i=0; (v.size()>i)&&(v[i]*v[i]<= x); i++ )
		if( x % v[i] == 0 )
			return false;
	v.push_back(x);
	return true;
}

int generatePrimes( int lim )
{
	for( int i=3; i<lim; i+=2 )
		if( isprimeforgen(i) )
			m[i] = true;
	cout<<"a";
}

int poww( int x, int y )
{
	int r = 1;
	for( int i=0; i<y; i++ )
		r*=x;
	return r;
}

int main()
{
	ifstream in("sprime.in");
	ofstream out("sprime.out");
    int n;
	cin>>n;
	n--;
	int lim = poww(10,n+1);
	generatePrimes(lim);
	for( int i=(2*poww(10,n))+1; i<lim; i+=2 )
	{
		int t = i;
		while( isprime(t) && t > 0 )
			t/=10;
		if( t == 0 )
			cout<<i<<endl;
	}
	out.close();
	cin>>n;
	return 0;
}

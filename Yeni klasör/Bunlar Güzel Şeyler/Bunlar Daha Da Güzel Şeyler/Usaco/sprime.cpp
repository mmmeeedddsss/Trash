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

bool isprime( int x )
{
	if( x < 2 )
		return false;
	if( x == 2 )
		return true;
	if( x % 2 == 0 )
		return false;
	for( int i=3; i*i<=x+1; i+=2 )
		if( x % i == 0 )
			return false;
	return true;
}

int poww( int x, int y )
{
	int r = 1;
	for( int i=0; i<y; i++ )
		r*=x;
	return r;
}

int contains2(int x)
{
	while( x > 2 )
	{
		if( x % 2 == 0 )
			return true;
		x/= 10;
	}
	return false;
}
	
int main()
{
	ifstream in("sprime.in");
	ofstream out("sprime.out");
    int n;
	in>>n;
	n--;
	int div = poww(10,n);
	int lim = poww(10,n+1);
	for( int i=(2*poww(10,n))+1; i<lim; i+=2 )
	{
		if( contains2(i/10) )
			continue;
		if( i/div == 9 )
			continue;
		int t = i;
		while( isprime(t) && t > 0 )
			t/=10;
		if( t == 0 )
			out<<i<<endl;
	}
	out.close();
	return 0;
}

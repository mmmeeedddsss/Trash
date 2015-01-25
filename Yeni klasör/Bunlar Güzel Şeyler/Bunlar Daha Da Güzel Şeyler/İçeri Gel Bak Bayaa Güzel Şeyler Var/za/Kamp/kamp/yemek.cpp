#include<iostream>
#include<fstream>
using namespace std;

struct mypair{
	long a,e;
};

mypair *a;
long minn = 999999999;
int n;

int poww( int base, int pow )
{
	int mult = 1;
	for( int i=0; i<pow; i++ )
		mult*=base;
	return mult;
}

long abs( long x )
{
	return ( (x>0)?x:(-x) );
}

int calc()
{
	int powN = poww(2,n);
	int temp,comb;
	for( int i=1; i<powN; i++ )
	{
		long ac = 0, ek = 1;
		temp = i;
		for( int j=0; j<n; j++ )
		{
			comb = 0;
			if( temp%2 )
				comb = 1;
			temp/=2;
			
			if( comb == 1 )
			{
				ac += a[j].a;
				ek *= a[j].e;
			}
		}
		if( abs( ac - ek ) < minn )
		{
			minn = abs( ac - ek );
		}
	}
}

int getInput()
{
	ifstream in("perket.gir");
	in>>n;
	a = new struct mypair[n];
	for( int i=0; i<n; i++ )
		in>>a[i].e>>a[i].a;
}

int main()
{
	ofstream out("perket.cik");
	getInput();
	calc();
	out<<minn;
	out.close();
}
